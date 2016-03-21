<?php
function _portales7_banners_pane_default_edit_form(&$form, $conf) {
  module_load_include('inc', 'portales7_banners', 'available-classes');
  $form['classes'] = array(
    '#type' => 'select',
    '#title' => t('Class'),
    '#description' => t('Select wich type of list will be displayed'),
    '#options' => _portales7_banners_available_classes(),
    '#default_value' => $conf['classes'],
    '#multiple' => TRUE,
  );
  $form['fieldset_arguments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Arguments'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 98,
  );
  $form['fieldset_arguments']['arguments'] = array(
  '#type' => 'textfield',
  '#title' => t('Arguments'),
  '#description' => t('Arguments to pass to the view'),
  '#default_value' => $conf['arguments'],
  '#weight' => 5,
  );

  $form['fieldset_arguments']['include_path'] = array(
  '#type' => 'checkbox',
  '#title' => t('Include path'),
  '#description' => t('Include path arguments on filter.'),
  '#default_value' => $conf['include_path'],
  '#weight' => 6,
  );
  
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 99,
  );
  $form['options']['promoted'] = array(
  '#type' => 'checkbox',
  '#title' => t('Only promoted'),
  '#description' => t('Show only contents promoted to front page.'),
  '#default_value' => $conf['promoted'],
  );
  
  $form['options']['pager'] = array(
  '#type' => 'checkbox',
  '#title' => t('Pager'),
  '#description' => t('Use pager'),
  '#default_value' => $conf['pager'],
  );
  
  $form['options']['items'] = array(
  '#type' => 'textfield',
  '#title' => t('Items'),
  '#description' => t('Number of results to show'),
  '#default_value' => $conf['items'],
  );
  
  $form['options']['offset'] = array(
  '#type' => 'textfield',
  '#title' => t('Offset'),
  '#description' => t('Number of items to skip'),
  '#default_value' => $conf['offset'],
  );
  $form['options']['sort'] = array(
  '#type' => 'select',
  '#title' => t('Sort'),
  '#description' => t('Sort by'),
  '#default_value' => $conf['sort'],
  '#options' => array(
    'portales7_newsdate:DESC' => t('News date descendant'),
    'portales7_newsdate:ASC' => t('News date ascendant'),
    'title:ASC' => t('Title ascendant'),
    'title:DESC' => t('Title descendant'),
    'created:ASC' => t('Creation date ascendant'),
    'created:DESC' => t('Creation date descendant'),
    ),
  //'#required' => TRUE,
  );
  $form['options']['more_link'] = array(
    '#type' => 'textfield',
    '#title' => t('More link'),
    '#description' => t('Enter url of \'More\' link destination. Left blank to hide link.'),
    '#default_value' => $conf['more_link'],
  );
  $form['admin_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin title'),
    '#description' => t('This title will be used on edit page content as pane title'),
    '#default_value' => $conf['admin_title'],
    '#weight' => 99,
  );
  if (module_exists('og')) {
    $form['og'] = array(
      '#type' => 'fieldset',
      '#title' => t('Groups'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => FALSE,
      '#weight' => 50,
    );
    $form['og']['og_group'] = array(
      '#type' => 'select',
      '#title' => t('Group'),
      '#multiple' => FALSE,
      '#default_value' => $conf['og_group'],
      '#options' => _portales7_banners_available_groups(),
      '#required' => TRUE,
    );
  }
  

  return $form;
}

function _portales7_banners_pane_defaults() {
  return array('type' => '',
    'arguments' => '',
    'items' => 10, 
    'classes' => NULL, 
    'include_path' => '', 
    'promoted' => '', 
    'offset' => 0, 
    'sort' => '',
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => 'any',
    );
}

function _portales7_banners_list_types() {
  return array(
    'default' => t('Default'), 
    'page' => t('Page style'),
    'menu' => t('Menu style'),
    'galleries' => t('Gallery style'),
    'banners' => t('Banners box'),
    'agenda' => t('Agenda Style'),
  );
}

function _portales7_banners_available_classes() {
  return array(
    'clase1' => t('Clase 1'),
    'clase2' => t('Clase 2'),
    'clase3' => t('Clase 3'),
  );
}



function _portales7_banners_available_groups() {
  $gids = og_get_all_group();
  $groups = array('any' => t('Any'), 'url' => t('Get from path'));
  foreach ($gids as $gid) {
    $group = node_load($gid);
    $groups[$group->nid] = $group->title;
  }
  return $groups;
}
