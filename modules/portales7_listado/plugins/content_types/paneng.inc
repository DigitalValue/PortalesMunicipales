<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');
//canviat el nom de la variable
//TODO: change noplugin por plugin
$noplugin = array(
  'title' => t('List by type NG'),
  'no title override' => TRUE,
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('type' => '', 'fields' => '', 'subtype' => '','field_event_type' => '', 'fields' => '', 'possible_image_styles' => 'imagen-100', 'vocabulario' => '')),
  'add form' => array(
    'portales7_listado_paneng_content_type_add_form' => t('Select listing'),
    'portales7_listado_paneng_content_type_edit_form' => array(
      'default' => TRUE, // put wrapper here, not on the previous form.
      'title' => t('Configure listing'),
    ),
  ),
  'category' => t('Portales 7'),
  'single' => TRUE,
  'disabled' => TRUE,
);

function portales7_listado_paneng_content_type_add_form($form, &$form_state) {
  drupal_set_message(__FUNCTION__, 'status');
  $form['subtype'] = array(
    '#type' => 'select',
    '#title' => 'Type',
    '#options' => array(
      'pane' => t('Generic'),
      'agenda' => t('Agenda'),
      'archivos' => t('Files'),
      'completo' => t('Complete'),
      'eventos' => t('Events'),
      'galerias' => t('Galleries'),
      'imagenes' => t('Images'),
      'resumen' => t('Teasers'),
      'titulares' => t('Headlines'),
    ),
    '#required' => TRUE,
    '#default_value' => $conf['subtype'],
  );
  return $form;
}

function portales7_listado_paneng_content_type_add_form_submit($form, &$form_state) {
  drupal_set_message(__FUNCTION__, 'status');
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key]))
      $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_paneng_content_type_render($subtype, $conf, $panel_args, $context) {
  dpm($conf, __FUNCTION__);
  $pane=new stdClass();

  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  $p7list = new P7ListController($subtype, $conf, $panel_args, $context);
  $p7list->execute();
  $pane->content = $p7list->render();
  $pane->title = t('Portales 7 List');
  $types = array();
  if ($conf['subtype'] == 'pane') {
    foreach ($p7list->getTypes() as $t) {
      if ($term = taxonomy_term_load($t)){
        $types[] = $term->name;
      }
    }
    if (!empty($types)) {
      $pane->title = t('List of @types', array('@types' => join(', ', $types)));
    }
  }
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_paneng_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  dpm($conf, __FUNCTION__);
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  module_load_include('util.inc', 'portales7');
  _portales7_listado_pane_default_edit_form($form, $conf);

  $info = _field_info_collate_fields();
  $fields_matrix['header'] = array(t('token'), t('field'));
  foreach ($info['instances']['node']['portales7_node'] as $field) {
    $fields_matrix['rows'][] = array (str_replace('portales7_', '', $field['field_name']), $field['label']);
  }
  array_unshift($fields_matrix['rows'], array('title', t('Title')));

  $form['subtype'] = array(
  '#type' => 'hidden',
  '#value' => 'pane',
  );
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('Type'),
  '#description' => t('Content type to show'),
  '#options' => _portales7_listado_content_types(),
  '#default_value' => $conf['type'],
  );

  $form['fields'] = array(
  '#type' => 'textfield',
  '#title' => t('Fields'),
  '#description' => t('Fields to show separated by commas.'),
  '#default_value' => $conf['fields'],
  '#maxlength' => 4096,
  );

  $form['possible_fields'] = array(
    '#type' => 'fieldset',
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
    '#type' => 'fieldset',
    '#title' => t('Available image styles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Possible styles for image fields, use them as <em>"field:style"</em>: !styles', array('!styles' => theme('table', $styles))),
  );
  
  
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );
  

  return $form;
}

function portales7_listado_paneng_content_type_edit_form_submit(&$form, &$form_state) {
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


function portales7_listado_paneng_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_listado_paneng_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Subtype') . ': ' . $subtype . '</pre>';
  $pane->content .= '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function portales7_listado_paneng_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  module_load_include('util.inc', 'portales7');
  $options = _portales7_listado_content_types();
  return t('List of type @type', array('@type' => $options[$conf['type']]));
}
