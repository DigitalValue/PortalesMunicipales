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
  'title' => t('Advanced carousel'),
  'description' => t('Provides an owl carousel of several nodes using view modes.'),
  'single' => TRUE,
  'content_types' => array('portales7_slideshow_advcarousel_content_type'),
  'render callback' => 'portales7_slideshow_advcarousel_content_type_render',
  'defaults' => array_merge(_portales7_listado_pane_defaults(), array('id' => '', 'style_name' => 'original','showcontrols' => TRUE, 'autoplay' => 0, 'itemsInitial' => 1, 'itemsDesktop' => '[1000, 1]', 'itemsDesktopSmall' => '[900, 1]', 'itemsTablet' => '[600, 1]', 'itemsMobile' => 'false')),
  'edit form' => 'portales7_slideshow_advcarousel_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_slideshow_advcarousel_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['subtype'] = 'pane';
  
  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  $conf['fields'] = array('media');
  $p7list = new P7ListController($subtype, $conf, $panel_args, $context);
  $elements['items'] = array();
  $elements['conf'] = $conf;
  foreach($p7list->getResult() as $r) {
    foreach($r->field_portales7_media as $fc_media) {
      $fc_items = entity_load('field_collection_item', array($fc_media['raw']['value']));
      $fc_item = array_shift($fc_items);
      if (!empty($fc_item->portales7_images['und'])) {
        foreach ($fc_item->portales7_images['und'] as $image) {
          $image['nid'] = $r->nid;
          $image['path'] = $image['uri'];
          if (!empty($conf['style_name'])) {
            $image['style_name'] = $conf['style_name'];
            $elements['items'][] = theme('image_style', $image);
          }
          else {
            $elements['items'][] = theme('image', $image);
          }
          
        }
      }
    }
  }
  $elements['class'] = array('portales7-advcarousel', 'portales7-advcarousel-' . $conf['image_style']);
  $pane = new stdClass();
  $pane->content = theme('portales7_slideshow_carousel', $elements);
  return $pane;
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_slideshow_advcarousel_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  module_load_include('panels.inc', 'portales7_listado');
  module_load_include('util.inc', 'portales7');
  module_load_include('util.inc', 'portales7_listado');
  _portales7_listado_pane_default_edit_form($form, $conf);

  if (is_numeric($conf['type']) && ($conf['type'] > 0) && ($t = taxonomy_term_load($conf['type']))) {
    $conf['type'] = $t->name;
  }
  $form['fieldset_arguments']['type'] = array(
  '#type' => 'select',
  '#title' => t('Type'),
  '#description' => t('Content type to show'),
  '#options' => _portales7_listado_content_type_names(),
  '#default_value' => $conf['type'],
  '#empty_option' => t('Any'),
  '#empty_value' => 'all',
  '#weight' => 1,
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
  $form['autoplay'] = array(
    '#type' => 'textfield',
    '#title' => t('Autoplay'),
    '#description' => t('Enter a number of miliseconds to wait. 0 disables autoplay.'),
    '#default_value' => $conf['autoplay'],
  );
  $form['showcontrols'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show controls'),
    '#default_value' => $conf['showcontrols'],
  );
  
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );

  $image_styles = image_style_options(TRUE);
  $form['style_name'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['style_name'],
    '#description' => t('Select the image style to use with images'),
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

function portales7_slideshow_advcarousel_content_type_edit_form_submit(&$form, &$form_state) {
  // For each part of the form defined in the 'defaults' array set when you
  // defined the content type, copy the value from the form into the array
  // of items to be saved. We don't ever want to use
  // $form_state['conf'] = $form_state['values'] because values contains
  // buttons, form id and other items we don't want stored. CTools will handle
  // the actual form submission.
  //foreach (array_keys($form_state['plugin']['defaults']) as $key) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function portales7_slideshow_advcarousel_content_type_admin_title($subtype, $conf, $context) {
  return t('Advanced carousel') . (!empty($conf['admin_title']) ? ': ' . $conf['admin_title'] : '');
}

function portales7_slideshow_advcarousel_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_slideshow_advcarousel_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}
