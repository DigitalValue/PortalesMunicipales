<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');

$plugin = array(
  'title' => t('Images list by type'),
  'description' => t('Shows images of content.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_listado_imagenes_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_listado_imagenes_content_type_render',
// The default context.
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('type' => '', 'fields' => '', 'possible_image_styles' => 'imagen-100')),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_listado_imagenes_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_listado_imagenes_content_type_admin_info',
  'admin title' => 'portales7_listado_imagenes_content_type_admin_title',
// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_imagenes_content_type_render($subtype, $conf, $panel_args, $context) {
dpm($node);  
$pane=new stdClass();
  $fields = $conf['fields'];
    if (!empty($conf['possible_image_styles'])) {
      $fields = str_replace('images:imagen-100', 'images:' . $conf['possible_image_styles'], $fields);
    }
  $classes = $conf['classes'];
  if (is_array($conf['classes'])){
    $classes = join(' ', $conf['classes']);
  }
  $type = array();
  if ($conf['type'] > 0) {
    if (is_array($conf['type'])) {
      foreach ($conf['type'] as $t){
        $type[$t] = $t;
      }
    }
    else {
      $type = array($conf['type'] => $conf['type']);
    }
  }
  if ($conf['type'] == -2) {
    //el type ve dels arguments del panell
    $type_name = array_shift($panel_args);
    module_load_include('util.inc', 'portales7');
    if ($term = dvtoolbox_get_taxonomy_term_by_name($type_name,'type',FALSE)){
      $type = array($term->tid => $term->tid);
    }
    else {
      array_unshift($panel_args, $type_name);
    }
  }
  foreach ($type as $tid) {
    if ($term = taxonomy_term_load($tid)) {
      $classes .= ' portales7_listado-' . transliteration_get($term->name, '-');
    }
  }
  $arguments = array();
  if (!empty($conf['arguments'])) {
    $arguments = explode('/', $conf['arguments']);
  }
  if ($conf['include_path']){
    $arguments = array_merge($arguments, $panel_args); 
  }
  $pane->content = '';
  if (count($type) > 0 || count($arguments) > 0) {
    $view = _portales7_listado_prepare_view($type, $arguments, $fields, $conf['items'], $conf['offset']);
    _portales7_listado_add_generic_sort($view->display['default']->handler, 'sticky', 'DESC');
    if (!empty($_GET['sort'])) $conf['sort'] = $_GET['sort'];
    if (!empty($conf['sort'])) {
      list($field, $order) = explode(':', $conf['sort']);
      if (preg_match('/^portales7_/', $field)) {
        _portales7_listado_add_sort_by_field($view->display['default']->handler, $field, $order);
      }
      else {
        _portales7_listado_add_generic_sort($view->display['default']->handler, $field, $order);
      }
    }
    if ($conf['promoted']) {
      _portales7_listado_add_generic_filter($view->display['default']->handler, 'promote', 1);
    }
    if ($conf['pager']) {
      _portales7_listado_add_pager($view->display['default']->handler, array('items_per_page' => $conf['items'], 'id' => 1, 'offset' => $conf['offset']));
    }
    if (!empty($conf['og_group']) && $conf['og_group'] != 'any') {
      if ($conf['og_group'] == 'url' && !empty($_SESSION['og_context'])) {
        _portales7_listado_add_og_filter($view->display['default']->handler, $_SESSION['og_context']);
      }
      else if($conf['og_group'] > 0) {
        _portales7_listado_add_og_filter($view->display['default']->handler, $conf['og_group']);
      }
    }
    $view->name .= '_imagenes';
    $output = $view->execute_display('default',$arguments);
    if (!empty($view->result)) {
      $prefix = "<div class=\"portales7_listado {$view->name}\"><div class=\"{$classes}\">";
      $suffix = '</div></div>';
      $more_link = '';
      if (!empty($conf['more_link']) && count($view->result) >= $conf['items']) {
        $more_link = '<div class="more-link">' . l(t('More'), $conf['more_link']) . '</div>';
      }
      $pane->content = $prefix . $output . $more_link . $suffix;
    }
  }
  $pane->title = t('Portales 7 images');
  $types = array();
  foreach ($type as $t) {
    if ($term = taxonomy_term_load($t)){
      $types[] = $term->name;
    }
  }
  if (!empty($types)) {
    $pane->title = t('Images of @types', array('@types' => join(', ', $types)));
  }
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_imagenes_content_type_edit_form($form, &$form_state) {
  // The current configuration
  dpm($node);
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
  '#default_value' => 'images:imagen-100,title',
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

function portales7_listado_imagenes_content_type_edit_form_submit(&$form, &$form_state) {
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


function portales7_listado_imagenes_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_listado_imagenes_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function portales7_listado_imagenes_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  module_load_include('util.inc', 'portales7');
  $options = _portales7_listado_content_types();
  return t('List of images', array('@type' => $options[$conf['type']]));
}
