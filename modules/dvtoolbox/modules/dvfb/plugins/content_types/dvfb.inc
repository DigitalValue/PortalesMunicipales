<?php
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('DV FB Connect'),
  'description' => t('Shows a pane to login using Facebook Connect.'),
  'single' => TRUE,
  'content_types' => array('dvfbc'),
  'render callback' => 'dvfbc_render',
  'defaults' => array(),
  //'edit form' => 'dvfbc_edit_form',
  'icon' => 'icon_dvfbc.png',
  'category' => t('DV toolbox'),
  'admin title' => 'dvfbc_admin_title',
  'admin info' => 'dvfbc_admin_info',
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvfbc_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->title = '';
  $pane->content = theme('dvfb_user', array('image_style' => 'imagen-50'));
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function dvfbc_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  return $form;
}

function dvfbc_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dvfbc_admin_title($subtype, $conf, $context = NULL) {
  return t('DV FB Connect');
}

function dvfbc_admin_info($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $pane->title = dvfbc_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

