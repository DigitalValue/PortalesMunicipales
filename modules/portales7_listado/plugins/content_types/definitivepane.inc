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
  'title' => t('Definitive Pane'),
  'description' => t('A pane to replace all.'),
  'single' => TRUE,
  'content_types' => array('portales7_listado_definitivepane_content_type'),
  'render callback' => 'portales7_listado_definitivepane_content_type_render',
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('id' => '', 'view_mode' => 'default')),
  'edit form' => 'portales7_listado_definitivepane_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_pane.png',
  'category' => t('Portales 7'),
);


// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_definitivepane_content_type_render($subtype, $conf, $panel_args, $context) {
  //Si el tipo es por argumento y el argumento no es un string, no hacemos nada.
  if (($conf['type'] == -2) && !is_string($panel_args[0])) {return;}
  if (is_string($conf['type']) && ($term = dvtoolbox_get_taxonomy_term_by_name($conf['type'], 'type'))) {
    $conf['type'] = $term->tid;
  }
  $conf['subtype'] = 'pane';
  module_load_include('inc', 'portales7_listado', 'includes/P7ListDefinitiveController');
  $p7list = new P7ListDefinitiveController($subtype, $conf, $panel_args, $context);
  if ((($conf['type'] == 'event') || ($term->name == 'event')) && preg_match('/[0-9]{4}\-[0-9]{2}\-[0-9]{2}/', end($panel_args))) {
    $p7list->prepare();
    $p7list->add_eventdate_argument();
  }
  elseif ($conf['sort'] == 'portales7_eventdate:ASC') {
    $p7list->prepare();
    $p7list->add_eventdate_end_filter();
  }
  $elements['items'] = array();
  $elements['conf'] = $conf;
  if (empty($p7list->getResult())) return;
  foreach($p7list->getResult() as $r) {
    $node = node_load($r->nid);
    $render = node_view($node, $conf['view_mode']);
    $elements['items'][] = drupal_render($render);
  }
  $elements['attributes']['class'] = array('portales7-definitivepane');
  $elements['attributes']['id'] = $conf['id'];
  $pane = new stdClass();
  $pane->title = $p7list->getTitle(NULL, array(), '@types');
  $pane->content = (empty($conf['hide_description']) ? $p7list->getDescription() : '') . theme('item_list', $elements);
  if (!empty($conf['pager']) && $p7list->getView() && $p7list->getView()->use_pager()) {
    $pane->content .= $p7list->getView()->query->pager->render();
  }
  if (!empty($conf['more_link'])) {
    $pane->content .= '<div class="more-link">' . l(t('More'), $conf['more_link']) . '</div>';
  }
  return $pane;
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_definitivepane_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  module_load_include('panels.inc', 'portales7_listado');
  module_load_include('util.inc', 'portales7');
  module_load_include('util.inc', 'portales7_listado');
  $types = dvtoolbox_get_taxonomy_options('type');
  _portales7_listado_pane_default_edit_form($form, $conf);
  
  if (is_numeric($conf['type']) &&($term = taxonomy_term_load($conf['type']))) {
    $conf['type'] = $term->name;
  }
  
  $form['fieldset_arguments']['type'] = array(
  '#type' => 'select',
  '#title' => t('Type'),
  '#description' => t('Content type to show'),
  '#options' => _portales7_listado_content_type_names(),
  '#default_value' => $conf['type'],
  '#weight' => 1,
  );
  $form['id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#description' => t('Panel identifier'),
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
  return $form;

}

function portales7_listado_definitivepane_content_type_edit_form_submit(&$form, &$form_state) {
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  _portales7_listado_pane_default_edit_form_submit($form, $form_state);
}

function portales7_listado_definitivepane_content_type_admin_title($subtype, $conf, $context) {
  return !empty($conf['admin_title']) ? $conf['admin_title'] : t('Definitive pane');
}

function portales7_listado_definitivepane_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  if (is_numeric($conf['type']) &&($term = taxonomy_term_load($conf['type']))) {
    $conf['type'] = $term->name;
  }
  $pane->title = portales7_listado_definitivepane_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}
