<?php
/**
 * @file
 * Provides a content-type plugin to show contents of imagefield field.
 * /

 * /**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
module_load_include('inc', 'portales7_listado','portales7_listado.panels');
$plugin = array(
  'title' => t('Definitive slideshow'),
  'description' => t('Provides an slideshow of several nodes using view modes.'),
  'single' => TRUE,
  'content_types' => array('portales7_slideshow_definitiveslide_content_type'),
  'render callback' => 'portales7_slideshow_definitiveslide_content_type_render',
  'defaults' => array_merge(_portales7_listado_pane_defaults(), _portales7_slideshow_pane_defaults(), array('id' => '', 'view_mode' => 'default')),
  'edit form' => 'portales7_slideshow_definitiveslide_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_slideshow_definitiveslide_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['subtype'] = 'pane';
  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  module_load_include('inc', 'portales7_listado', 'includes/P7ListDefinitiveController');
  $conf['pager'] = FALSE; //Forzamos quitar el paginador
  $p7list = new P7ListDefinitiveController($subtype, $conf, $panel_args, $context);
  $elements['items'] = array();
  $elements['conf'] = $conf;
  foreach($p7list->getResult() as $r) {
    $node = node_load($r->nid);
    $elements['items'][] = drupal_render(node_view($node, $conf['view_mode']));
  }
  $elements['class'] = array('portales7-definitiveslide', 'portales7-definitiveslide-' . $conf['view_mode']);
  $pane = new stdClass();
  $pane->content = theme('portales7_slideshow_definitive', $elements);
  return $pane;
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_slideshow_definitiveslide_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  module_load_include('panels.inc', 'portales7_listado');
  module_load_include('util.inc', 'portales7');
  module_load_include('util.inc', 'portales7_listado');
  _portales7_slideshow_pane_default_edit_form($form, $conf);
  _portales7_listado_pane_default_edit_form($form, $conf);

  $form['fieldset_arguments']['type'] = array(
  '#type' => 'select',
  '#title' => t('Type'),
  '#description' => t('Content type to show'),
  '#options' => _portales7_listado_content_types(),
  '#default_value' => $conf['type'],
  '#weight' => 1,
  );
  $form['id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#description' => t('Slideshow identifier'),
    '#default_value' => $conf['id'],
    '#required' => TRUE,
  );
  
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );

  $entity_info = entity_get_info('node');
  $view_modes = $entity_info['view modes'];
  $options_article = array('default' => t('Default'));
  $view_mode_article = field_view_mode_settings('node', 'portales7_node');
  foreach ($view_modes as $view_mode_name => $view_mode_info) {
    if (!empty($view_mode_article[$view_mode_name]['custom_settings'])) {
      $options_article[$view_mode_name] = $view_mode_info['label'];
    }
  }

  $form['view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View mode'),
    '#description' => t('View mode to use when rendering the nodes'),
    '#default_value' => $conf['view_mode'],
    '#options' => $options_article,
    '#required' => TRUE,
  );
  
  $form['fieldset_arguments']['section'] = $form['section'];
  $form['options']['#weight'] = 98;
  unset($form['section']);
  unset($form['classes']);
  unset($form['hide_description']);
  unset($form['options']['pager']);
  unset($form['options']['pager_id']);
  unset($form['options']['more_link']);
  return $form;

}

function portales7_slideshow_definitiveslide_content_type_edit_form_submit(&$form, &$form_state) {
  // For each part of the form defined in the 'defaults' array set when you
  // defined the content type, copy the value from the form into the array
  // of items to be saved. We don't ever want to use
  // $form_state['conf'] = $form_state['values'] because values contains
  // buttons, form id and other items we don't want stored. CTools will handle
  // the actual form submission.
  $form_state['conf'] = array();
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function portales7_slideshow_definitiveslide_content_type_admin_title($subtype, $conf, $context) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('Definitive slideshow');
}

function portales7_slideshow_definitiveslide_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_slideshow_definitiveslide_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}
