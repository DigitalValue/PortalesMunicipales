<?php


module_load_include('inc', 'portales7_listado','portales7_listado.panels');
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Old style banners'),
  'description' => t('Shows a pane with banners.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_listado_banners_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_listado_banners_content_type_render',
// The default context.
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('group' => '', 'image_style' => 'imagen-200', 'sort' => 'portales7_banner_weight:ASC')),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_listado_banners_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  
  'admin title' => 'portales7_listado_banners_content_type_admin_title',

);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_banners_content_type_render($subtype, $conf, $panel_args, $context) {
  if (variable_get('portales7_banners_imported', FALSE)) {
    module_load_include('inc', 'portales7_banners', 'plugins/content_types/banners74');
    $conf['sort'] = str_replace('portales7_banner_weight', 'portales7_banners_weight', $conf['sort']);
    return portales7_banners_banners_content_type_render($subtype, $conf, $panel_args, $context);
  }
  module_load_include('util.inc', 'portales7');
  $banner = dvtoolbox_get_taxonomy_term_by_name('banner', 'type', FALSE);
  $fields=array('link','title');
  if (!empty($conf['image_style'])){
    $fields[] = 'banner_image:' . $conf['image_style'];
  }
  else {
    $fields[] = 'banner_image';
  }
  $pane=new stdClass();
  $classes = $conf['classes'];
  if (is_array($conf['classes'])){
    $classes = join(' ', $conf['classes']);
  }
  
  $arguments = array();
  if (!empty($conf['arguments'])) {
    $arguments = explode('/', $conf['arguments']);
  }
  if ($conf['include_path']){
    $arguments = array_merge($arguments, $panel_args); 
  }
  $view = _portales7_listado_prepare_view(array($banner->tid => $banner->tid), $arguments, $fields, $conf['items'], $conf['offset']);
  if ($conf['group']) {
    _portales7_listado_add_tid_filter($view->display['default']->handler, 'portales7_banner_group', 'group', array($conf['group'] => $conf['group']));
  }
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
  //_portales7_listado_add_sort_by_field($view->display['default']->handler, 'portales7_banner_weight', 'ASC');
  if ($conf['promoted']) {
    _portales7_listado_add_generic_filter($view->display['default']->handler, 'promote', 1);
  }
  if (!empty($conf['pager'])) {
    _portales7_listado_add_pager($view->display['default']->handler, array('items_per_page' => $conf['items'], 'id' => 1, 'offset' => $conf['offset']));
  }
  if (function_exists('portales7_og_add_og_filter')) {
    portales7_og_add_og_filter($view->display['default']->handler, $conf['og_group']);
  }
  $view->name .= '_banners';
  $output = $view->execute_display('default',$arguments);
  if (!empty ($view->result)) {
    $prefix = "<div class=\"portales7_listado {$view->name} {$view->name}-{$conf['group']} {$view->name}-{$conf['image_style']}\"><div class=\"{$classes}\">";
    $suffix= '</div></div>';
    $more_link = '';
    if (!empty($conf['more_link']) && count($view->result) >= $conf['items']) {
      $more_link = '<div class="more-link">' . l(t('More'), $conf['more_link']) . '</div>';
    }
    $pane->content = $prefix . $output . $more_link . $suffix;
  }
  
  $pane->title = '';

  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_banners_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  _portales7_listado_pane_default_edit_form($form, $conf);
  
  $voc = taxonomy_vocabulary_machine_name_load('banners');
  $group_terms = taxonomy_get_tree($voc->vid);
  $banner_groups = array();
  foreach ($group_terms as $t){
    $banner_groups[$t->tid] = $t->name;
  }

  $form['group'] = array(
    '#type' => 'select',
    '#title' => t('Banner group'),
    '#options' => $banner_groups,
    '#default_value' => $conf['group'],
    '#multiple' => FALSE,
  );

  $image_styles = image_style_options(TRUE);
  //$image_styles[''] = t('Left blank for original size');
  
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
    '#description' => t('Select the image style to use with banners'),
  );
  $form['options']['sort']['#options'] += array(
    'portales7_banner_weight:ASC' => t('Banner weight ascendant'),
    'portales7_banner_weight:DESC' => t('Banner weight descendant'),
  );

  return $form;
}

function portales7_listado_banners_content_type_edit_form_submit(&$form, &$form_state) {
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

function portales7_listado_banners_content_type_admin_title($subtype, $conf, $context = NULL) {
  $group = taxonomy_term_load($conf['group']);
  return t('DEPRECATED') . ' '. t('Banners from group @group', array('@group' => $group->name));
}

function portales7_listado_banners_content_type_admin_info($subtype, $conf, $context = NULL) {
  drupal_set_message(t('You are using old style banners on your template.'), 'error');
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $group = taxonomy_term_load($conf['group']);
  $pane = new stdClass();
  $pane->title = portales7_listado_banners_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}