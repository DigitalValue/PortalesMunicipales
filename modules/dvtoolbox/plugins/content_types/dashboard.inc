<?php
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Dashboard pane'),
  'description' => t('A pane with dashboard panes'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('dvtoolbox_dashboard_content_type'),
// Name of a function which will render the block.
  'render callback' => 'dvtoolbox_dashboard_content_type_render',
// The default context.
  'defaults' =>array('sets' => array()),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'dvtoolbox_dashboard_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_dvtoolbox.png',
  'category' => t('DV toolbox'),
  
  'admin title' => 'dvtoolbox_dashboard_content_type_admin_title',

);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvtoolbox_dashboard_content_type_render($subtype, $conf, $panel_args, $context) {
  $panes = module_invoke_all('dashboard_panes', $conf['sets']);
  drupal_alter('dashboard_panes', $panes);
  uksort($panes, 'drupal_sort_weight');
  $pane = new stdClass();
  $pane->title = '';
  $pane->content = '';
  foreach($panes as $item) {
    $pane->content .= $item['content'];
  }
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function dvtoolbox_dashboard_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $sets = module_invoke_all('dashboard_sets');
  drupal_alter('dashboard_sets', $sets);
  $form['sets'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Pane sets'),
    '#description' => t('Select wich pane sets will be displayed on this pane'),
    '#options' => $sets,
    '#default_value' => $conf['sets'],
    '#required' => TRUE,
  ); 
  return $form;
}

function dvtoolbox_dashboard_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = array();
  $form_state['values']['sets'] = array_filter($form_state['values']['sets']);
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key]))
      $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dvtoolbox_dashboard_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('Dashboard pane');
}

function dvtoolbox_dashboard_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = dvtoolbox_dashboard_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
