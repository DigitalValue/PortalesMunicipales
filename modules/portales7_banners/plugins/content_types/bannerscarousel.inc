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
  'title' => t('Banners carousel'),
  'description' => t('Provides an owl carousel of several banners using view modes.'),
  'single' => TRUE,
  'content_types' => array('portales7_banners_bannerscarousel_content_type'),
  'render callback' => 'portales7_banners_bannerscarousel_content_type_render',
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('group' => '', 'id' => '', 'view_mode' => 'default','showcontrols' => TRUE, 'itemsInitial' => 1, 'itemsDesktop' => '[1000, 5]', 'itemsDesktopSmall' => '[900, 3]', 'itemsTablet' => '[600, 2]', 'itemsMobile' => 'false')),
  'edit form' => 'portales7_banners_bannerscarousel_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_banners_bannerscarousel_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['subtype'] = 'pane';
  module_load_include('inc','portales7_banners', 'portales7_banners.util');
  if ((!is_numeric($conf['group'])) && ($term = dvtoolbox_get_taxonomy_term_by_name($conf['group'], 'banners', FALSE, 0))) {
    $conf['group'] = $term->tid;
  }
  $arguments = array();
  $view = _portales7_banners_get_view();
  $view->name .= '_banners';
  //Afegir numero d'elements i paginacio
  _portales7_banners_set_num_items($view->display['default']->handler, $conf['items'], $conf['offset']);
  if (!empty($conf['pager'])) {
    _portales7_banners_add_pager($view->display['default']->handler, array('items_per_page' => $conf['items'], 'id' => 1, 'offset' => $conf['offset']));
  }
  //Afegir camps
  _portales7_banners_generic_filefield_add('portales7_banners_image', $view->display['default']->handler, $conf['image_style']);
  
  //Afegir filtres
  if ($conf['group']) {
    _portales7_banners_add_tid_filter($view->display['default']->handler, 'portales7_banners_group', 'banners', array($conf['group'] => $conf['group']));
  }
  if ($conf['promoted']) {
    _portales7_banners_add_generic_filter($view->display['default']->handler, 'promote', 1);
  }
  
  
  if (function_exists('portales7_og_add_og_filter')) {
    portales7_og_add_og_filter($view->display['default']->handler, $conf['og_group']);
  }
  
  //Afegir ordenacio
  //_portales7_banners_add_sort_by_field($view->display['default']->handler, 'field_peso', 'ASC');
  $fields = array('link','title');
  if (empty($conf['image_style'])){
    $conf['image_style'] = 'original';
  }
  $pane=new stdClass();
  $classes = $conf['classes'];
  if (is_array($conf['classes'])){
    $classes = join(' ', $conf['classes']);
  }
  $output = $view->execute_display('default',$arguments);
  if (!empty ($view->result)) {
    $elements['items'] = array();
    $elements['conf'] = $conf;
  
    drupal_add_css(drupal_get_path('module', 'portales7_banners') . '/portales7_banners.css', array('type' => 'file'));
    $prefix = "<div class=\"portales7_banners {$view->name} {$view->name}-{$conf['group']} {$view->name}-{$conf['image_style']}\"><div class=\"{$classes}\">";
    $suffix= '</div></div>';
    $more_link = '';
    
    if (!empty($conf['more_link']) && count($view->result) > $conf['items']) {
      $more_link = '<div class="more-link">' . l(t('More'), $conf['more_link']) . '</div>';
    }
    foreach($view->result as $r) {
      $elements['items'][] = theme('portales7_banners_banners', array('row' => $r, 'options' => $conf, 'view' => $view));
    }
    $elements['class'] = array('portales7-bannerscarousel', 'portales7-bannerscarousel-' . $conf['view_mode']);
    $output = theme('portales7_slideshow_carousel', $elements);
    //$output = theme('item_list', $elements);
    $pane = new stdClass();
    $pane->content = $prefix . $output . $more_link . $suffix;
    $pane->title = '';
    return $pane;
  }
  return NULL;
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_banners_bannerscarousel_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  module_load_include('panels.inc', 'portales7_listado');
  module_load_include('util.inc', 'portales7');
  module_load_include('util.inc', 'portales7_listado');
  _portales7_listado_pane_default_edit_form($form, $conf);

  $form['group'] = array(
    '#type' => 'select',
    '#title' => t('Banner group'),
    '#options' => dvtoolbox_get_taxonomy_options_text('banners'),
    '#default_value' => $conf['group'],
    '#multiple' => FALSE,
  );

  $form['id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#description' => t('Slideshow identifier'),
    '#default_value' => $conf['id'],
    '#required' => TRUE,
  );
  
  
  $form['itemsInitial'] = array(
    '#type' => 'textfield',
    '#title' => t('Default number of items above "itemsDesktop" setting'),
    '#default_value' => $conf['itemsInitial'],
    '#required' => TRUE,
  );
  $form['itemsDesktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Items in desktop mode'),
    '#default_value' => $conf['itemsDesktop'],
    '#required' => TRUE,
  );
  $form['itemsDesktopSmall'] = array(
    '#type' => 'textfield',
    '#title' => t('Items in small desktop mode'),
    '#default_value' => $conf['itemsDesktopSmall'],
    '#required' => TRUE,
  );
  $form['itemsTablet'] = array(
    '#type' => 'textfield',
    '#title' => t('Items in tablet mode'),
    '#default_value' => $conf['itemsTablet'],
    '#required' => TRUE,
  );
  $form['itemsMobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Items in mobile mode'),
    '#default_value' => $conf['itemsMobile'],
    '#required' => TRUE,
  );
  $form['showcontrols'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show controls'),
    '#default_value' => $conf['showcontrols'],
    '#required' => TRUE,
  );
  
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );

  $entity_info = entity_get_info('node');
  $view_modes = $entity_info['view modes'];
  $options_article = array('default' => t('Default'));
  $view_mode_article = field_view_mode_settings('node', 'portales7_banner');
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
  unset($form['options']['more_link']);
  return $form;

}

function portales7_banners_bannerscarousel_content_type_edit_form_submit(&$form, &$form_state) {
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

function portales7_banners_bannerscarousel_content_type_admin_title($subtype, $conf, $context) {
  return t('Banners carousel') . (!empty($conf['admin_title']) ? ': ' . $conf['admin_title'] : '');
}

function portales7_banners_bannerscarousel_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_banners_bannerscarousel_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}
