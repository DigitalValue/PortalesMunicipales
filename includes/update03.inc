<?php
function portales7_update03_batch_prepare() {
  $res = db_select('node', 'n')->fields('n', array('nid'))->condition('type', 'portales7_node')->execute()->fetchCol();
  $operations = array();
  foreach ($res as $nid) {
    $operations[] = array('_portales7_update03_batch_do', array($nid));
  }
  if (!empty($operations)) {
    $operations[] = array('_portales7_update03_delete_fields', array());
    $batch = array(
      'title' => t('Updating nodes to 7.5.2+'),
      'operations' => $operations,
      'finished' => '_portales7_update03_batch_finished',
      'file' => drupal_get_path('module', 'portales7') . '/includes/update03.inc',
    );
    return $batch;
  }
  else {
    drupal_set_message('No operations', 'warning');
  }
}

function _portales7_update03_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One node updated.', '@count nodes updated.');
    drupal_set_message($message, 'status');
  }
  else {
    drupal_set_message(t('Finished with an error.'), 'error');
  }
}

function _portales7_update03_batch_do($nid, &$context) {
  if ($node = node_load($nid)) {
    $updated = FALSE;
    if (!empty($node->portales7_main_image['und'][0])) {
      $node->portales7_main_media['und'][0]['entity'] = entity_create('field_collection_item', array('field_name' => 'portales7_main_media'));
      $node->portales7_main_media['und'][0]['entity']->portales7_mm_image['und'][0] = $node->portales7_main_image['und'][0];
      $updated = TRUE;
      $node->portales7_main_image['und'] = NULL;
    }
    $portales7_media = entity_create('field_collection_item', array('field_name' => 'portales7_media'));
    if (!empty($node->portales7_files['und'])) {
      foreach ($node->portales7_files['und'] as $delta => $item) {
        $portales7_media->portales7_files['und'][$delta] = $item;
      }
      $node->portales7_files['und'] = NULL;
      $updated = TRUE;
    }
    if (!empty($node->portales7_images['und'])) {
      foreach ($node->portales7_images['und'] as $delta => $item) {
        $portales7_media->portales7_images['und'][$delta] = $item;
      }
      $updated = TRUE;
      $node->portales7_images['und'] = NULL;
    }
    if (!empty($node->portales7_videos['und'])) {
      foreach ($node->portales7_videos['und'] as $delta => $item) {
        $portales7_media->portales7_videos['und'][$delta] = $item;
      }
      $updated = TRUE;
      $node->portales7_videos['und'] = NULL;
    }
    if (!empty($node->portales7_video_url['und'])) {
      foreach ($node->portales7_video_url['und'] as $delta => $item) {
        $portales7_media->portales7_video_url['und'][$delta] = $item;
      }
      $updated = TRUE;
      $node->portales7_video_url['und'] = NULL;
    }
    if (!empty($portales7_media->portales7_files['und']) || !empty($portales7_media->portales7_video['und']) || !empty($portales7_media->portales7_images['und']))
    $node->portales7_media['und'][0]['entity'] = $portales7_media;
    
    if ($updated) {
      $changed = $node->changed;
      node_save($node);
      db_update('node')->fields(array('changed' => $changed))->condition('nid', $node->nid)->condition('vid', $node->vid)->execute();
      db_update('node_revision')->fields(array('timestamp' => $changed))->condition('nid', $node->nid)->condition('vid', $node->vid)->execute();
      $context['message'] = t('Updated node %nid: %title', array('%nid' => $node->nid, '%title' => $node->title));
      $context['results'][] = $context['message'];
      $context['finished'] = 1;
    }
  }
}

function _portales7_update03_delete_fields(&$context) {
  foreach (array('portales7_main_image', 'portales7_files', 'portales7_images', 'portales7_videos', 'portales7_video_url') as $field) {
    if ($instance = field_info_instance('node', $field, 'portales7_node')) {
      field_delete_instance($instance);
      $context['message'] = t('Deleted instance %field in %bundle', array('%field' => $field, '%bundle' => 'portales7_article'));
      $context['results'][] = $context['message'];
    }
  }
}
