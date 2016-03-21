<?php
define('P7B_CHAINED_MIGRATION', TRUE);

function portales7_banners_old_banners_count() {
  $banners = 0;
  if (db_table_exists('field_data_portales7_banner_group')) {
    $query = db_select('field_data_portales7_banner_group', 'f')
      ->fields( 'f', array('entity_id'))
      ->condition('bundle', 'portales7_node')
      ->execute();
    $banners = count($query->fetchAll());
  }
  return $banners;
}

function portales7_banners_list() {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_portales7_banners_weight', 'w', "n.nid = w.entity_id");
  $query->leftJoin('field_data_portales7_banners_group', 'g', 'n.nid = g.entity_id');
  $query->fields('n', array('nid', 'title', 'language', 'status'))
    ->fields('w', array('portales7_banners_weight_value'))
    ->fields('g', array('portales7_banners_group_tid'))
    ->condition('type', 'portales7_banner')
    ->orderBy('w.portales7_banners_weight_value');
  $res = $query->execute();
  $rows = array();
  foreach ($res as $row) {
    $term = taxonomy_term_load($row->portales7_banners_group_tid);
    if (!isset($rows[$row->nid])) {
      $rows[$row->nid] = array($row->nid, $row->title, $row->language, $row->portales7_banners_weight_value ? $row->portales7_banners_weight_value : 0, l(t('edit'), 'node/' . $row->nid . '/edit'), $term->name, $row->status? t('published') : t('unpublished'));
    }
    else {
      $rows[$row->nid][5] .= ' ' . $term->name;
    }
  }
  return $rows;
}

function portales7_banners_migration_page_form($form, &$form_state) {
  if (variable_get('portales7_banners_imported', FALSE)) {
    $rows = portales7_banners_list();
    $form['banners']['#tree'] = TRUE;
    foreach ($rows as $row) {
      $id = $row[0];
      $form['banners'][$id] = array(
        'weight' => array(
          '#type' => 'textfield',
          '#default_value' => $row[3],
          '#size' => 4,
        ),
        'nid' => array(
          '#markup' => $row[0],
        ),
        'title' => array(
          '#markup' => l($row[1], 'node/' . $row[0]),
        ),
        'language' => array(
          '#markup' => $row[2],
        ),
        'groups' => array(
          '#markup' => $row[5],
        ),
        'status' => array(
          '#markup' => $row[6],
        ),
        'operations' => array(
          '#markup' => l(t('Edit'), 'node/' . $row[0] . '/edit', array('query' => array('destination' => 'admin/portales7/banners'))),
        ),
      ); 
    }
    $form['banners']['#prefix'] = '<h3>' . format_plural(count($rows), 'One banner', '@count banners', array('@count' => count($rows))) . '</h3>';
    $form['update_weights'] = array(
      '#type' => 'submit',
      '#value' => t('Update weights'),
      '#prefix' => '<div class="clear-fix"></div>',
      '#suffix' => '<div class="clear-fix"></div>',
    );
  }
  
  $banners = 0;
  if (db_table_exists('field_data_portales7_banner_group')) {
    $query = db_select('field_data_portales7_banner_group', 'f')
      ->fields( 'f', array('entity_id'))
      ->condition('bundle', 'portales7_node')
      ->execute();
    $banners = count($query->fetchAll());
  }
  $text = $banners ? format_plural($banners, 'One old style banner found', '@count old style banners found', array('@count' => $banners)) : t('No old style banners found');
  $form['info'] = array(
    '#type' => 'markup',
    '#markup'=> $text,
    '#prefix' => '<div><h3>',
    '#suffix' => '</h3></div>',
  );

  $output = '';
  if ($banners > 0 && $banners < 25) {
    foreach ($query->fetchAllAssoc('entity_id') as $id => $row) {
      $node = node_load($id);
      $output .= $node->title . ' ' . l('Edit ' . $id, 'node/' . $id . '/edit') . '</br>';
      foreach ($node->portales7_type['und'] as $delta => $item) {
        $t = taxonomy_term_load($item['tid']);
        $output .= '<span>Type: ' . $t->name. '</span><br/>'; 
      }
    }
    $form['info2'] = array(
      '#type' => 'markup',
      '#markup' => $output,
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
  }
  if ($banners > 0) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import'),
      '#prefix' => '<div class="clear-fix"></div>',
    );
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete old'),
    );
  }
  //else { //Se canvia per atra comprovacio per a poder borrar els camps sense borrar els nodos
  if (variable_get('portales7_banners_imported', FALSE)) {
    $af = array('portales7_banner_group', 'portales7_banner_weight', 'portales7_banner_image', 'portales7_link');
    foreach ($af as $fn) {
      if ($f = field_read_instances(array('field_name' => $fn, 'bundle' => 'portales7_node'))) {
        $fields[$fn] = $f[0]['label'];
      }
    }
    if (!empty($fields)) {
      $form['fields'] = array(
       '#type' => 'checkboxes',
       '#title' => t('Fields'),
       '#description' => t('Choose fields to delte'),
       '#options' => $fields,
       '#default_value' => array_keys($fields),
      );
      $form['delete_fields'] = array(
        '#type' => 'submit',
        '#value' => t('Delete fields'),
      );
    }
    else {
      $form['fields'] = array(
        '#type' => 'markup',
        '#markup'=> t('No fields to delete'),
        '#prefix' => '<div><h3>',
        '#suffix' => '</h3></div>',
      );
    }
  }
  if (!empty($_SESSION['portales7_banners_migrate_batch_results'])) {
    $form['result'] = array(
      '#type' => 'markup',
      '#markup' => join('<br/>', $_SESSION['portales7_banners_migrate_batch_results']),
      '#prefix' => '<div class="messages warning clearfix"><h3>' . t('Results') . '</h3>',
      '#suffix' => '</div>',
    ); 
    unset($_SESSION['portales7_banners_migrate_batch_results']);
  }
  return $form;
}

function portales7_banners_migration_page_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    case t('Import'): 
      _portales7_banners_migration_do('import');
    break;
    case t('Delete old'):
      _portales7_banners_migration_do('delete_old');
    break;
    case  t('Delete fields'):
      _portales7_banners_migration_do('delete_fields', $form_state['values']['fields']);
    break;
    case t('Update weights'):
      _portales7_banners_migration_do('update_weights', $form_state['values']['banners']);
    break;
    default:
      drupal_set_message(t('Unknown operation @op', array('@op' => $form_state['values']['op'])), 'error');
  }
}

function _portales7_banners_migration_do($op, $options = array()) {
  if (in_array($op, array('import', 'delete_old'))) {
   $query = db_select('node', 'n');
    $query->join('field_data_portales7_banner_group', 'f', 'n.nid = f.entity_id');
    $query->leftjoin('field_data_portales7_banner_weight', 'w', 'w.entity_id = f.entity_id');
    $query->fields('f', array('entity_id'))
      ->fields('w', array('portales7_banner_weight_value'))
      ->condition('f.bundle', 'portales7_node')
      ->orderBy('n.changed', 'ASC');
    $res = $query->execute();
    $ids = $res->fetchCol();
    $res = $query->execute();
    $weights = $res->fetchCol(1);
    $weights = array_flip(array_unique(array_map(function ($a) {return ($a === NULL) ? 0 : $a;}, $weights)));
    ksort($weights);
    variable_set('portales7_banners_migration_weights', $weights);
    
    $output = t('Importing banners');
    $operations = array();
    foreach ($ids as $nid) {
      $operations[] = array('_portales7_banners_migration_' . $op . '_batch_do', array($nid));
    }
    $batch = array(
      'title' => $output,
      'operations' => $operations,
      'finished' => '_portales7_banners_migration_' . $op . '_batch_finished',
      'file' => drupal_get_path('module', 'portales7_banners') . '/portales7_banners.migration.inc',
    );
  }
  elseif ($op == 'delete_fields') {
    foreach ($options as $field_name) {
      $operations[] = array('_portales7_banners_migration_' . $op . '_batch_do', array($field_name));
    }
    $operations[] = array('_portales7_banners_migration_delete_field_group_batch_do', array('portales7_banner'));
    $batch = array(
      'title' => $output,
      'operations' => $operations,
      'finished' => '_portales7_banners_migration_' . $op . '_batch_finished',
      'file' => drupal_get_path('module', 'portales7_banners') . '/portales7_banners.migration.inc',
    );
  }
  elseif ($op == 'update_weights') {
    $operations = array();
    foreach ($options as $nid => $w) {
      $operations[] = array('_portales7_banners_migration_' . $op . '_batch_do', array($nid, $w['weight']));
    }
    $output = t('Updating weights');
    $batch = array(
      'title' => $output,
      'operations' => $operations,
      'finished' => '_portales7_banners_migration_' . $op . '_batch_finished',
      'file' => drupal_get_path('module', 'portales7_banners') . '/portales7_banners.migration.inc',
    );
  }
  else {
    drupal_set_message(t('Unknown operation @op', array('@op' => $op)), 'error');
    return FALSE;
  }
  
  batch_set($batch);
  batch_process('admin/portales7/banners');
  return $output;
}
function _portales7_banners_migration_update_weights_batch_do($nid, $weight, &$context) {
  $banner = node_load($nid);
  if (!is_numeric($weight)) $weight = 0;
  $banner->portales7_banners_weight['und'][0]['value'] = $weight;
  node_save($banner);
  $context['results'][]= t('Updated') . ' ' . l($banner->title,'node/' . $banner->nid) ;
  $context['message'] = check_plain($banner->title);
  $context['finished'] = 1;
}

function _portales7_banners_migration_import_batch_do($nid, &$context) {
  $weights = variable_set('portales7_banners_migration_weights', array());
  $context['message'] = '';
  $node = node_load($nid);
  $fields = array(
  'portales7_banners_image' => $node->portales7_banner_image,
  'portales7_banners_group' => $node->portales7_banner_group,
  'portales7_banners_weight' => isset($weights[$node->portales7_banner_weight]) ? $weights[$node->portales7_banner_weight]: $node->portales7_banner_weight,
  'portales7_banners_url' => $node->portales7_link,
  'status' => $node->status,
  );
  $banner = _portales7_banners_create_node($node->title, $node->language, $fields, $node->nid);
  node_save($banner);
  //$node->portales7_inline_banner['und'][] = array('target_id' => $banner->nid);
  //node_save($node);
  $context['results'][]= $node->title . ' => ' . l('Devel view','node/' . $banner->nid . '/devel'). " : ". l('Edit','node/' . $banner->nid . '/edit'). " : ". l($banner->title,'node/' . $banner->nid) ;
  $context['message'] = check_plain($banner->title);
  $context['finished'] = 1;
}

function _portales7_banners_migration_delete_old_batch_do($nid, &$context) {
  $context['message'] = '';
  $node = node_load($nid);
  $tb = dvtoolbox_get_taxonomy_term_by_name('banner', 'type', FALSE);
  if ((count($node->portales7_type['und']) == 1) && $node->portales7_type['und'][0]['tid'] == $tb->tid && empty($node->body['und'][0]['value']) && empty($node->portales7_files['und'])  && empty($node->portales7_images['und'])) {
    //Este portales7_node nomes esta per a proveir un banner, el borrem sencer
    node_delete($node->nid);
    $context['results'][] = t('Deleted node @nid : @title ', array('@nid' => $node->nid, '@title' => $node->title));
    $context['message'] = t('Deleted node @nid : @title ', array('@nid' => $node->nid, '@title' => $node->title));
  }
  else {
    foreach ($node->portales7_type['und'] as $delta => $item) {
      if ($item['tid'] == $tb->tid){
        drupal_set_message("unsetting portales7_type whith delta $delta", 'status');
        unset($node->portales7_type['und'][$delta]);
      } 
    }
    $node->portales7_banner_image = NULL;
    $node->portales7_banner_group = NULL;
    $node->portales7_banner_weight = NULL;
    $node->portales7_link = NULL;
    node_save($node);
    $context['results'][]= t('Updated') . ' ' . l('Devel view','node/' . $node->nid . '/devel'). " : ". l('Edit','node/' . $node->nid . '/edit'). " : ". l($node->title,'node/' . $node->nid) ;
    $context['message'] = t('Updated node @nid : @title ', array('@nid' => $node->nid, '@title' => $node->title));
  }
  
  #$context['sandbox']['progress']++;
  $context['finished'] = 1;
}

function _portales7_banners_migration_delete_fields_batch_do($field, &$context) {
  $instance = field_read_instance('node', $field, 'portales7_node');
  field_delete_instance($instance);
  $context['results'][] = t('Deleted field @field_name', array('@field_name' => $field));
  $context['message'] = t('Deleted field @field_name', array('@field_name' => $field));
  $context['finished'] = 1;
}

function _portales7_banners_migration_delete_field_group_batch_do($field_group, &$context) {
  $groups = field_group_read_groups(array('bundle' => 'portales7_node', 'entity_type' => 'node', 'mode' => 'form', 'group_name' => 'portales7_banner'));
  $group=$groups['node']['portales7_node']['form']['portales7_banner'];
  field_group_group_export_delete($group);
  $context['results'][] = t('Deleted field group @field_group', array('@field_group' => $field_group));
  $context['message'] = t('Deleted field @field_group', array('@field_group' => $field_group));
  $context['finished'] = 1;
}


function _portales7_banners_migration_delete_fields_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One field/group deleted.', '@count fields/groups deleted.', array('@count' => count($results)));
    drupal_set_message($message, 'status');
    $results = array_splice($results, 0 , 100);
    $_SESSION['portales7_banners_migrate_batch_results'] = $results;
  }
  else {
    drupal_set_message(t('Finished with an error.'), 'error');
  }
}

function _portales7_banners_migration_update_weights_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One banner updated.', '@count banners updated.', array('@count' => count($results)));
    drupal_set_message($message, 'status');
    $results = array_splice($results, 0 , 100);
    $_SESSION['portales7_banners_migrate_batch_results'] = $results;
  }
  else {
    drupal_set_message(t('Finished with an error.'), 'error');
  }
}


function _portales7_banners_migration_import_batch_finished($success, $results, $operations) {
  variable_del('portales7_banners_migration_weights');
  if ($success) {
    //dpm(func_get_args(), __FUNCTION__);
    variable_set('portales7_banners_imported', TRUE);
    $message = format_plural(count($results), 'One banner imported.', '@count banners imported.', array('@count' => count($results)));
    drupal_set_message($message, 'status');
    $results = array_splice($results, 0 , 100);
    $_SESSION['portales7_banners_migrate_batch_results'] = $results;
  }
  else {
    drupal_set_message(t('Finished with an error.'), 'error');
  }
  if (FALSE && P7B_CHAINED_MIGRATION) {
    _portales7_banners_migration_do('delete_old');
  }
}

function _portales7_banners_migration_delete_old_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One old banner deleted.', '@count old banners deleted.', array('@count' => count($results)));
    drupal_set_message($message, 'status');
    $results = array_splice($results, 0 , 100);
    $_SESSION['portales7_banners_migrate_batch_results'] = $results;
    if ($term = dvtoolbox_get_taxonomy_term_by_name('banner', 'type', 0, FALSE)) {
      taxonomy_term_delete($term->tid);
    }
  }
  else {
    drupal_set_message(t('Finished with an error.'), 'error');
  }
  if (FALSE && P7B_CHAINED_MIGRATION) {
    $options = array('portales7_banner_group', 'portales7_banner_weight', 'portales7_banner_image', 'portales7_link');
    _portales7_banners_migration_do('delete_fields', $options);
  }
}

function _portales7_banners_create_node($title, $lang = LANGUAGE_NONE, $fields = array(), $parent = 0) {
  $node = new stdClass();
  $node->type = 'portales7_banner';
  node_object_prepare($node);
  $node->language = $lang;
  $node->title = $title;
  foreach ($fields as $field_name => $value) {
    $node->$field_name = $value;
  }
  if (!empty($parent)) {
    $node->portales7_banners_node['und'][0]['nid'] = $parent;
  }
  return $node;
}

function theme_portales7_banners_migration_page_form($variables) {
  $form = $variables['form'];
  $rows = array();
  foreach (element_children($form['banners']) as $nid) {
    $form['banners'][$nid]['weight']['#attributes']['class']= array('banners-order-weight');
    $rows[] = array(
      'data' => array(
        array('class' => array('slide-cross')),
        drupal_render($form['banners'][$nid]['weight']),
        drupal_render($form['banners'][$nid]['nid']),
        drupal_render($form['banners'][$nid]['title']),
        drupal_render($form['banners'][$nid]['language']),
        drupal_render($form['banners'][$nid]['groups']),
        drupal_render($form['banners'][$nid]['status']),
        drupal_render($form['banners'][$nid]['operations']),
      ),
      'class' => array('draggable'),
    );
  }
  if (!empty($rows)) {
    $header = array('', t('weight'), t('nid'), t('title'), t('language'), t('groups'), t('status'), t('operations'));
    $form['banners']['#markup'] = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'banners-order')));
    drupal_add_tabledrag('banners-order', 'order', 'sibiling', 'banners-order-weight');
  }
  else {
    unset($form['banners']);
  }
  $output = drupal_render_children($form);
  
  return $output;
}
