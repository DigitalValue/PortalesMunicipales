<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  
$plugin = array(
  'title' => t('List by type'),
  'description' => t('Shows a pane with content.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_listado_pane_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_listado_pane_content_type_render',
// The default context.
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('type' => '', 'fields' => '')),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_listado_pane_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_listado_pane_content_type_admin_info',
  'admin title' => 'portales7_listado_pane_content_type_admin_title',
// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_pane_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['subtype'] = 'pane';
  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  $p7list = new P7ListController($subtype, $conf, $panel_args, $context);
  return $p7list->getPane('List of @types', array(), '@types');
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_pane_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  module_load_include('util.inc', 'portales7');
  module_load_include('util.inc', 'portales7_listado');
  _portales7_listado_pane_default_edit_form($form, $conf);

  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('Type'),
  '#description' => t('Content type to show'),
  '#options' => _portales7_listado_content_types(),
  '#default_value' => $conf['type'],
  '#weight' => 1,
  );

  $form['fields'] = array(
  '#type' => 'textarea',
  '#title' => t('Fields'),
  '#description' => t('Fields to show separated by commas.'),
  '#default_value' => $conf['fields'],
  '#maxlength' => 4096,
  '#weight' => 3,
  );

  $form['possible_fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available fields'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
    '#description' => theme('table', _portales7_listado_available_fields_matrix()),
    '#weight' => 4,
  );
  
  $form['section']['#weight'] = 2;
  

  $image_styles = image_style_options(FALSE);
  $image_styles[''] = t('Left blank for original size');
  $styles = array();
  $styles['header'] = array(t('token'), t('field'));
  $styles['rows'] = array();
  foreach ($image_styles as $token => $description) {
    $styles['rows'][] = array($token, $description);
  }
  $form['possible_image_styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available image styles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Possible styles for image fields, use them as <em>"field:style"</em>: !styles', array('!styles' => theme('table', $styles))),
    '#weight' => 5,
  );
  
  
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );
  
  return $form;
}

function portales7_listado_pane_content_type_edit_form_submit(&$form, &$form_state) {
  // For each part of the form defined in the 'defaults' array set when you
  // defined the content type, copy the value from the form into the array
  // of items to be saved. We don't ever want to use
  // $form_state['conf'] = $form_state['values'] because values contains
  // buttons, form id and other items we don't want stored. CTools will handle
  // the actual form submission.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}


function portales7_listado_pane_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_listado_pane_content_type_admin_title($subtype, $conf, $context);
  $conf['fields'] = json_decode($conf['fields']);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function portales7_listado_pane_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  module_load_include('util.inc', 'portales7');
  $options = _portales7_listado_content_types();
  return t('List of type @type', array('@type' => $options[$conf['type']]));
}
