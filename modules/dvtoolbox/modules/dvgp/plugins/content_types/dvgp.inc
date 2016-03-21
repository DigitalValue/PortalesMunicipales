<?php
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('DV Google Connect'),
  'description' => t('Shows a pane to login using Google Connect.'),
  'single' => TRUE,
  'content_types' => array('dvgpc'),
  'render callback' => 'dvgpc_render',
  'defaults' => array(),
  //'edit form' => 'dvgpc_edit_form',
  'icon' => 'icon_dvgpc.png',
  'category' => t('DV toolbox'),
  'admin title' => 'dvgpc_admin_title',
  'admin info' => 'dvgpc_admin_info',
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvgpc_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->title = '';
  $pane->content = theme('dvgp_user', array('image_style' => 'imagen-50'));
  $pane->content .= '<pre>' . print_r(dvgp_user(), 1) . '</pre>';
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function dvgpc_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  return $form;
}

function dvgpc_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dvgpc_admin_title($subtype, $conf, $context = NULL) {
  return t('DV FB Connect');
}

function dvgpc_admin_info($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $pane->title = dvgpc_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

