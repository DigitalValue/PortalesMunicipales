<?php
function portales7_banners_autoimport_form() {
  $csv = '';
  if (file_exists(drupal_get_path('module', 'portales7_banners') . '/banners-auto.csv')) {
    $csv = file_get_contents(drupal_get_path('module', 'portales7_banners') . '/banners-auto.csv');
  }
  $form['csv'] = array(
    '#type' => 'textarea',
    '#title' => 'CSV',
    '#default_value' => $csv,
    '#rows' => 20,
  );
  $form['import'] = array(
    '#type' => 'submit',
    '#value' => t('Import from CSV file'),
  ); 
  return $form;
}

function portales7_banners_autoimport_form_submit($form, $form_state) {
  if (!empty($form_state['values']['csv']) && ($csv = array_map('str_getcsv', array_map('trim', explode("\n", $form_state['values']['csv']))))) {
    if($batch = portales7_banners_autoimport_batch_prepare($csv)) {
      batch_set($batch);
      batch_process();
    }
  }
  else {
    drupal_set_message(t('Empty or invalid CSV'), 'error');
  }
}

function portales7_banners_autoimport_batch_prepare($csv) {
  $operations = array();
  $files = db_select('file_managed', 'f')
    ->fields('f', array())
    ->condition('uri', PORTALES7_RESOURCEDIR . '/imagenes/carteles/%', 'LIKE')
    ->execute()
    ->fetchAllAssoc('filename');
  foreach ($csv as $line) {
    if (count($line) != 8) {
      drupal_set_message(t('Skipping invalid line: %line', array('%line' => join(',', $line))), 'error');
      continue;
    }
    $path = $line[5];
    if (preg_match('/^p7vars_/', $line[5])) {
      $path = variable_get($line[5], NULL);
    }
    if (!$path) continue;
    $group = dvtoolbox_get_taxonomy_term_by_name($line[4], 'banners', TRUE, 0);
    $data = array(
      'uri' => $line[0],
      'image' => $files[$line[1]]->fid,
      'group' => $group->tid,
      'path' => $path,
      'title' => $line[3],
      'weight' => $line[6],
      'target' => $line[7],
    );
    $operations[] = array('portales7_banners_autoimport_create', array($line[2], $data));
  }
  
  if (empty($operations)) return FALSE;
  $batch = array(
    'title' => t('Creating banners'),
    'operations' => $operations,
    'finished' => '_portales7_banners_autoimport_batch_finished',
    'file' => drupal_get_path('module', 'portales7_banners') . '/portales7_banners.autoimport.inc',
  );
  return $batch;
}

function portales7_banners_autoimport_create($lang, $data, &$context) {
  module_load_include('migration.inc', 'portales7_banners');
  $fields = array(
    'portales7_banners_image' => array('und' => array(array('fid' => $data['image']))),
    'portales7_banners_group' => array('und' => array(array('tid' => $data['group']))),
    'portales7_banners_weight' => array('und' => array(array('value' => $data['weight']))),
    'portales7_banners_url' => array('und' => array(array('value' => $data['path']))),
    'portales7_banners_overlay' => array('und' => array(array('value' => $data['title']))),
    'portales7_banners_target' => array('und' => array(array('value' => $data['target']))),
    'status' => 1,
  );
  $banner = _portales7_banners_create_node($data['title'], $lang, $fields, 0);
  if (empty($context['results'][$data['uri']]['tnid'])) {
    if (!empty($data['tnid'])) {
      $banner->tnid = $data['tnid'];
      $context['results'][$data['uri']]['tnid'] = $banner->tnid;
      node_save($banner);
    }
    else {
      node_save($banner);
      $context['results'][$data['uri']]['tnid'] = $banner->nid;
    }
  }
    
  $banner->tnid = $context['results'][$data['uri']]['tnid'];
  node_save($banner);
  
  //$context['results'][$data['image']][$lang] = $data['title'] . ' => ' . $data['path'];
  $context['results'][$data['uri']][$lang] = $banner->nid;
  $context['finished'] = 1;
}

function _portales7_banners_autoimport_batch_finished($success, $results, $operations) {
    //dpm($results, __FUNCTION__);
  if ($success) {
    $banners = variable_get('portales7_banners_autoimport', array());
    foreach ($results as $uri => $data) {
      foreach ($data as $lang => $nid) {
        $banners[$uri][$lang] = $nid;
      }
    }
    variable_set('portales7_banners_autoimport', $banners);
    drupal_set_message(t('Banners created'), 'status');
    //dpm($results, __FUNCTION__);
  }
  else {
    drupal_set_message(t('An error has occured while creating banners, please check logs'), 'error');
  }
}

