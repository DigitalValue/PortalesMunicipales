<?php

function portales7_node_fixfc_form($form_state) {
  $form = array();
  $form['info'] = array(
    '#type' => 'markup',
    '#prefix' => '<div>',
    '#suffix' => '</div>',
    '#markup' => t('This will fix the problem with field collections when updating nodes'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start'),
  );
  return $form;
}

function portales7_node_fixfc_form_submit($form, &$form_state) {
  if ($batch = _portales7_node_fixfc_batch_create()) {
    batch_set($batch);
    batch_process('admin/dashboard/portales7/fixfc');
  }
}

function _portales7_node_fixfc_batch_create() {
  $nids = array();
  foreach (array('portales7_related_entity', 'portales7_related_article', 'portales7_media', 'portales7_main_media') as $field_name) {
    $nids = array_merge($nids, db_query("select entity_id from field_data_$field_name where ${field_name}_value in (select ${field_name}_value from field_data_{$field_name} group by {$field_name}_value having count(*) > 1)")->fetchCol());
  }
  $nids = array_unique($nids);
  $operations = array_map(function ($nid) { return array('_portales7_node_fixfc_batch_do', array($nid));}, $nids);
  drupal_set_message('Total operations: ' . count($operations), 'status');
  //$operations = array_splice($operations, 0, 20);
  //dpm ($operations, 'operations');
  
  if (!empty($operations)) {
    $batch = array(
      'operations' => $operations,
      'title' => t('Fixing FC fields'),
      'finished' => '_portales7_node_fixfc_batch_finished',
      'file' => drupal_get_path('module', 'portales7_node') . '/portales7_node.fixfc.inc', 
    );
    return $batch; 
  }
  return FALSE;
}

function _portales7_node_fixfc_batch_do($nid, &$context) {
  $node = node_load($nid);
  foreach (array('portales7_related_entity', 'portales7_related_article', 'portales7_media', 'portales7_main_media') as $field_name) {
    _portales7_node_fixfc_field($node, $field_name);
  }
  //db_update('node')->fields(array('changed' => $changed))->condition('nid', $node->nid)->condition('vid', $node->vid);
  //db_update('node_revision')->fields(array('timestamp' => $changed))->condition('nid', $node->nid)->condition('vid', $node->vid);
  $context['finished'] = 1;
  $context['message'] = t('Node (%nid) %title updated', array('%nid' => $node->nid, '%title' => $node->title));
  $context['results'][] = $context['message'];
}

function _portales7_node_fixfc_media($node) {
  _portales7_node_fixfc_field($node, 'portales7_media');
}

function _portales7_node_fixfc_field($node, $field_name) {
  //dpm($node->{$field_name}['und'], $field_name . ' init');
  if (empty($node->{$field_name}['und'])) return;
  module_load_include('inc', 'uuid');
  //drupal_set_message(__FUNCTION__ . ' ' . $field_name . ' ' . $node->nid);
  foreach ($node->{$field_name}['und'] as $delta => $item) {
    $row = array(
      'field_name' => $field_name,
      'item_id' => 0,
      'revision_id' => 0,
      'archived' => 0,
      'uuid' => uuid_generate(),
    );
    drupal_write_record('field_collection_item', $row);
    $rev = array('item_id' => $row['item_id']);
    drupal_write_record('field_collection_item_revision', $rev);
    $row['revision_id'] = $rev['revision_id'];
    $update = array('item_id');
    drupal_write_record('field_collection_item', $row, $update);
    //dpm ($row, $row['item_id']);
    $fc = field_collection_item_load(array($item['value']));
    $new_field = array(
      'entity_type' => 'node',
      'bundle' => $node->type,
      'entity_id' => $node->nid,
      'revision_id' => $node->vid,
      'language' => LANGUAGE_NONE,
      'delta' => $delta,
      $field_name . '_value' => $row['item_id'],
      $field_name . '_revision_id' => $row['revision_id'],
    );
    db_delete('field_data_' . $field_name)->condition('entity_id', $node->nid)->condition($field_name . '_value', $item['value'])->execute();
    db_delete('field_revision_' . $field_name)->condition('entity_id', $node->nid)->condition($field_name . '_value', $item['value'])->execute();
    if ($fc) {
      drupal_write_record('field_data_' . $field_name, $new_field);
      drupal_write_record('field_revision_' . $field_name, $new_field);
      $new = field_collection_item_load(array($row['item_id']));
      foreach ($fc as $k => $v) {
        if (strpos($k, 'portales7_') === 0) {$new->{$k} = $v;}
      }
      $new->save(TRUE);
    }
  }
  db_query('truncate table {cache_field}');
}


function _portales7_node_fixfc_batch_finished($success, $results, $operations) {
  drupal_set_message(__FUNCTION__, 'status');
  if ($success) {
    drupal_set_message(format_plural(count($results), 'One node updated', '@count nodes updated'), 'status');
  }
  else {
    drupal_set_message(t('An error has occured while updating nodes, please check logs'), 'error');
  }
}

function _portales7_node_testfixnode() {
  $context = array();


foreach (array(1206) as $nid) {
$node = node_load($nid);
print_r(array('nid' => $node->nid, 'related entity' => $node->portales7_related_entity['und'][0]['value'], 'related article' => $node->portales7_related_article['und'][0]['value'], 'media' => $node->portales7_media['und'][0]['value'], 'main_media' => $node->portales7_main_media['und'][0]['value'], 'created' => date('Y-m-d H:i:s', $node->created), 'changed' => date('Y-m-d H:i:s', $node->changed)));
_portales7_node_fixfc_batch_do($nid, $context);
node_load($nid, TRUE);
$node = node_load($nid);

print_r(array('nid' => $node->nid, 'related entity' => $node->portales7_related_entity['und'][0]['value'], 'related article' => $node->portales7_related_article['und'][0]['value'], 'media' => $node->portales7_media['und'][0]['value'], 'main_media' => $node->portales7_main_media['und'][0]['value'], 'created' => date('Y-m-d H:i:s', $node->created), 'changed' => date('Y-m-d H:i:s', $node->changed)));
}

dpm($context, 'context');
}

function _portales7_node_fixfc_node($node) {
  $context = array();
  _portales7_node_fixfc_batch_do($node->nid, $context);
  drupal_set_message($context['message'], 'status');
  drupal_goto('node/' . $node->nid . '/edit');
}
