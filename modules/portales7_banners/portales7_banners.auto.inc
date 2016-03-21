<?php
function portales7_banners_auto_form() {
  drupal_add_css(drupal_get_path('module', 'portales7_banners') . '/css/auto.css');
  $fids = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->condition('uri', PORTALES7_RESOURCEDIR . '/imagenes/carteles/%', 'LIKE')
    ->execute()
    ->fetchCol();
  
  $languages = language_list();
  $files = file_load_multiple($fids);
  //$files = array_slice($files, 0, 1);
  $banners = variable_get('portales7_banners_auto', array());
  
  $groups = array(
    '#type' => 'select',
    '#title' => t('Banner group'),
    '#options' => dvtoolbox_get_taxonomy_options('banners', 0),
    '#default_value' => 2,
  );
  
  foreach ($files as $file) {
    $form['fid_' . $file->fid] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => $file->filename,
      '#attributes' => array('class' => array('portales7-banners-auto-banner')),
    );
    $form['fid_' . $file->fid]['image'] = array(
      '#type' => 'markup',
      '#markup' => theme('image', array('path' => $file->uri, 'style_name' => 'original', 'title' => $file->filename)),
      '#title' => $file->uri,
      '#prefix' => '<div class="banner-auto-image">',
      '#suffix' => '</div>'
    );
    foreach ($languages as $code => $lang) {
      if (!$lang->enabled) continue;
      $form['fid_' . $file->fid][$code] = array(
        '#type' => 'fieldset',
        '#title' => $lang->native,
        '#tree' => TRUE,
        '#attributes' => array('class' => array('portales7-banners-auto-lang')),
      );
      if (!empty($banners[$file->uri][$code]) && ($node = node_load($banners[$file->uri][$code]))) {
        $form['fid_' . $file->fid][$code] = array(
          '#type' => 'markup',
          '#markup' => $lang->native . ': ' . $node->title . ' ' . l(t('Edit node'), 'node/' . $banners[$file->uri][$code], array('query' => array('destination' => $_GET['q']))),
          '#prefix' => '<div class="banner-auto-exists">',
          '#suffix' => '</div>'
        );
      }
      else {
        $form['fid_' . $file->fid][$code]['image'] = array(
          '#type' => 'hidden',
          '#value' => $file->fid,
        );
        $form['fid_' . $file->fid][$code]['uri'] = array(
          '#type' => 'hidden',
          '#value' => $file->uri,
        );
        $form['fid_' . $file->fid][$code]['path'] = array(
          '#type' => 'textfield',
          '#title' => t('Path'),
          '#default_value' => '',
        );
        $form['fid_' . $file->fid][$code]['title'] = array(
          '#type' => 'textfield',
          '#title' => t('Title'),
          '#default_value' => '',
        );
        $form['fid_' . $file->fid][$code]['group'] = $groups;
        if (!empty($banners[$file->uri]['tnid'])) {
          $form['fid_' . $file->fid][$code]['tnid'] = array(
            '#type' => 'hidden',
            '#value' => $banners[$file->uri]['tnid'],
          );
        }
      }  
    }
  }
  
  /*$form['info'] = array(
    '#type' => 'markup',
    '#markup' => '<pre>' . print_r($files, 1) . '</pre>',
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );*/
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Crear'),
  );
  return $form;

}

function portales7_banners_auto_form_submit($form, $form_state) {
  $operations = array();
  foreach ($form_state['values'] as $k => $v) {
    if (preg_match('/^fid_[0-9]+/', $k)) {
      foreach ($v as $lang => $data) {
        if (!empty($data['path'])) {
          $operations[] = array('portales7_banners_auto_create', array($lang, $data));
        }
      }
    }
  }
  
  $batch = array(
    'title' => t('Creating banners'),
    'operations' => $operations,
    'finished' => '_portales7_banners_auto_batch_finished',
    'file' => drupal_get_path('module', 'portales7_banners') . '/portales7_banners.auto.inc',
  );
  
  if(!empty($operations)) {
    batch_set($batch);
    batch_process();
  }
}

function portales7_banners_auto_create($lang, $data, &$context) {
  module_load_include('migration.inc', 'portales7_banners');
  $fields = array(
    'portales7_banners_image' => array('und' => array(array('fid' => $data['image']))),
    'portales7_banners_group' => array('und' => array(array('tid' => $data['group']))),
    'portales7_banners_weight' => 0,
    'portales7_banners_url' => array('und' => array(array('value' => $data['path']))),
    'portales7_banners_overlay' => array('und' => array(array('value' => $data['title']))),
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

function _portales7_banners_auto_batch_finished($success, $results, $operations) {
  if ($success) {
    $banners = variable_get('portales7_banners_auto', array());
    foreach ($results as $uri => $data) {
      foreach ($data as $lang => $nid) {
        $banners[$uri][$lang] = $nid;
      }
    }
    variable_set('portales7_banners_auto', $banners);
    drupal_set_message(t('Banners created'), 'error');
    dpm($results, __FUNCTION__);
  }
  else {
    drupal_set_message(t('An error has occured while creating banners, please check logs'), 'error');
  }
}
