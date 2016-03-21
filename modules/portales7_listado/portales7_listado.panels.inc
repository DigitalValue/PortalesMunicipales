<?php
function _portales7_listado_pane_default_edit_form_submit($form, &$form_state) {
  $form_state['conf'] = $form_state['plugin']['defaults'];
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function _portales7_listado_pane_default_edit_form(&$form, $conf) {
  module_load_include('inc', 'portales7_listado', 'available-classes');
  $form['classes'] = array(
    '#type' => 'select',
    '#title' => t('Class'),
    '#description' => t('Select wich type of list will be displayed'),
    '#options' => _portales7_listado_available_classes(),
    '#default_value' => $conf['classes'],
    '#multiple' => TRUE,
    '#weight' => 100,
  );
  
  $form['section'] = array(
    '#type' => 'select',
    '#title' => t('Section'),
    '#description' => t('Selecting a parent term does not include his sibilings, only contents tagged with given term.'),
    '#options' => dvtoolbox_get_taxonomy_options('sections', 0, FALSE, TRUE),
    '#empty_option' => t('Any'),
    '#empty_value' => 'any',
    '#default_value' => $conf['section'],
    '#weight' => 1,
  );
  $form['hide_description'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide description'),
    '#description' => t('Hide category term description.'),
    '#default_value' => $conf['hide_description'],
  );
  $form['fieldset_arguments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filters'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 98,
  );
  
  $form['fieldset_arguments']['calendar'] = array(
    '#type' => 'select',
    '#title' => t('Calendar'),
    '#description' => t('Calendar for event filtering'),
    '#default_value' => $conf['calendar'],
    '#weight' => 4,
    '#options' => dvtoolbox_get_taxonomy_options_text('calendar', 0, FALSE, TRUE),
    '#empty_option' => t('Any'),
    '#empty_value' => 'any',
  );
  
  $form['fieldset_arguments']['arguments'] = array(
  '#type' => 'textfield',
  '#title' => t('Arguments'),
  '#description' => t('Arguments to pass to the view'),
  '#default_value' => $conf['arguments'],
  '#weight' => 5,
  );
  
  $form['fieldset_arguments']['promoted'] = array(
  '#type' => 'checkbox',
  '#title' => t('Only promoted'),
  '#description' => t('Show only contents promoted to front page.'),
  '#default_value' => $conf['promoted'],
  '#weight' => 6,
  );
  
  $form['fieldset_arguments']['include_path'] = array(
  '#type' => 'checkbox',
  '#title' => t('Include path'),
  '#description' => t('Include path arguments on filter.'),
  '#default_value' => $conf['include_path'],
  '#weight' => 7,
  );
  
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 99,
  );
  
  $form['options']['pager'] = array(
    '#type' => 'select',
    '#title' => t('Use pager'),
    '#default_value' => $conf['pager'],
    '#options' => array('mini' => t('Mini'), 'full' => t('Full')),
    '#empty_option' => t('None'),
    '#empty_value' => '',
  );
  $form['options']['pager_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Pager ID'),
    '#default_value' => $conf['pager_id'],
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
  $form['options']['sort_by_url'] = array(
  '#type' => 'checkbox',
  '#title' => t('Sort by url'),
  '#description' => t('Allow sorting results using url params.'),
  '#default_value' => $conf['sort_by_url'],
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
      '#default_value' => empty($conf['og_group']) ? 'any' : $conf['og_group'],
      '#options' => _portales7_listado_available_groups(),
      '#required' => TRUE,
    );
  }
  drupal_alter('portales7_listado_pane_default_edit_form', $form);
  return $form;
}

function _portales7_listado_pane_defaults() {
  $defaults = array('type' => '-1',
    'arguments' => '',
    'items' => 10, 
    'classes' => NULL, 
    'include_path' => '', 
    'promoted' => '', 
    'offset' => 0, 
    'sort' => '',
    'sort_by_url' => FALSE,
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => 'any',
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => rand(1, 10),
    'calendar' => 'any',
  );
  drupal_alter('portales7_listado_pane_defaults', $defaults);
  return $defaults;
}

function _portales7_listado_list_types() {
  return array(
    'default' => t('Default'), 
    'page' => t('Page style'),
    'menu' => t('Menu style'),
    'galleries' => t('Gallery style'),
    'banners' => t('Banners box'),
    'agenda' => t('Agenda Style'),
  );
}

function _portales7_listado_available_classes() {
  return array(
    'clase1' => t('Clase 1'),
    'clase2' => t('Clase 2'),
    'clase3' => t('Clase 3'),
  );
}



function _portales7_listado_available_groups() {
  $gids = og_get_all_group();
  $groups = array('any' => t('Any'), 'url' => t('Get from path'));
  foreach ($gids as $gid) {
    $group = node_load($gid);
    $groups[$group->nid] = $group->title;
  }
  return $groups;
}
