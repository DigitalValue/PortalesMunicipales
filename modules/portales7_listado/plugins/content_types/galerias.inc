<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  
$plugin = array(
  'title' => t('Galleries list by type'),
  'description' => t('Shows a image with title.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_listado_galerias_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_listado_galerias_content_type_render',
// The default context.
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('type' => '', 'fields' => '', 'possible_image_styles' => 'imagen-100')),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_listado_galerias_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_listado_galerias_content_type_admin_info',
  'admin title' => 'portales7_listado_galerias_content_type_admin_title',
// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);


/**
 * Render function for the content type.
 */
function portales7_listado_galerias_content_type_render($subtype, $conf, $panel_args, $context){
  if (!empty($conf['possible_image_styles'])) {
    $conf['fields'] = str_replace('main_image:imagen-100', 'main_image:' . $conf['possible_image_styles'], $conf['fields']);
  }

  $pane=new stdClass();
  $conf['subtype'] = 'galerias';
  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  $p7list = new P7ListController($subtype, $conf, $panel_args, $context);
  $p7list->prepare();
  $p7list->execute();
  $pane->content = $p7list->render();

  $pane->title = t('Portales 7 Galleries');
  $types = array();
  foreach ($p7list->getTypes() as $t) {
    if ($term = taxonomy_term_load($t)){
      $types[] = $term->name;
    }
  }
  if (!empty($types)) {
    $pane->title = t('Galleries of @types', array('@types' => join(', ', $types)));
  }
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_galerias_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  module_load_include('util.inc', 'portales7');
  _portales7_listado_pane_default_edit_form($form, $conf);

  $info = _field_info_collate_fields();
  $fields_matrix['header'] = array(t('token'), t('field'));
  foreach ($info['instances']['node']['portales7_node'] as $field) {
    $fields_matrix['rows'][] = array (str_replace('portales7_', '', $field['field_name']), $field['label']);
  }
  array_unshift($fields_matrix['rows'], array('title', t('Title')));

  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('Type'),
  '#description' => t('Content type to show'),
  '#options' => _portales7_listado_content_types(),
  '#default_value' => $conf['type'],
  );

  $form['fields'] = array(
  '#type' => 'hidden',
  '#title' => t('Fields'),
  '#description' => t('Fields to show separated by commas.'),
  //'#default_value' => $conf['fields'],
  '#default_value' => 'main_image:imagen-100,title',
  '#maxlength' => 4096,
  );

  $form['possible_fields'] = array(
    '#type' => 'hidden',
    '#title' => t('Available fields'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
    '#description' => theme('table', $fields_matrix),
  );

  $image_styles = image_style_options(FALSE);
  $image_styles[''] = t('Left blank for original size');
  $styles = array();
  $styles['header'] = array(t('token'), t('field'));
  $styles['rows'] = array();
  foreach ($image_styles as $token => $description) {
    $styles['rows'][] = array($token, $description);
  }
  $form['possible_image_styles'] = array(
    '#type' => 'select',
    '#title' => t('Available image styles'),
    '#description' => t('Possible styles for image fields'),
    '#options' => image_style_options(),
    '#default_value' => $conf['possible_image_styles'],
  );
  

  return $form;
}

function portales7_listado_galerias_content_type_edit_form_submit(&$form, &$form_state) {
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


function portales7_listado_galerias_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_listado_galerias_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function portales7_listado_galerias_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  module_load_include('util.inc', 'portales7');
  $options = _portales7_listado_content_types();
  return t('List of galleries', array('@type' => $options[$conf['type']]));
}
