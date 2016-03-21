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
  'title' => t('Advanced kenburns slideshow'),
  'description' => t('Provides an owl kenburns of several nodes using view modes.'),
  'single' => TRUE,
  'content_types' => array('portales7_slideshow_advkenburns_content_type'),
  'render callback' => 'portales7_slideshow_advkenburns_content_type_render',
  'defaults' => array_merge(_portales7_listado_pane_defaults(), 
      array(
        'id' => '',
        'image_style' => '',
        'duration' => 5000,
        'ease3d' => 'ease-out',
        'fadeSpeed' => 500,
        'scale' => 1,
        'height' => 360,
        'width' => 960,
        )),
  'edit form' => 'portales7_slideshow_advkenburns_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_slideshow_advkenburns_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['subtype'] = 'pane';
  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  module_load_include('inc', 'portales7_listado', 'includes/P7ListDefinitiveController');
  $p7list = new P7ListDefinitiveController($subtype, $conf, $panel_args, $context);
  $elements['items'] = array();
  $elements['conf'] = $conf;
  $images = array();
  foreach($p7list->getResult() as $r) {
    $node = node_load($r->nid);
    foreach ($node->portales7_media['und'] as $fc) {
      $data = entity_load('field_collection_item', array($fc['value']));
      $element = $data[$fc['value']];
      foreach($element->portales7_images['und'] as $delta => $item) {
        $images[] = $item;
      }
    }
  }
  if (empty($images)) return;
  $elements['items'] = $images;
  $elements['class'] = array('portales7-advkenburns', 'portales7-advkenburns-' . $conf['view_mode']);
  $pane = new stdClass();
  $pane->content = theme('portales7_slideshow_kenburns', $elements);
  return $pane;
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_slideshow_advkenburns_content_type_edit_form($form, &$form_state) {
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
  '#weight' => 1,
  );
  $form['id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#description' => t('Slideshow identifier'),
    '#default_value' => $conf['id'],
    '#required' => TRUE,
  );
  
  
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('Width in pixels'),
    '#default_value' => $conf['width'],
    '#required' => TRUE,
  );
  
  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Height in pixels'),
    '#default_value' => $conf['height'],
    '#required' => TRUE,
  );
  
  $form['scale'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale'),
    '#default_value' => $conf['scale'],
    '#required' => TRUE,
  );
  $form['duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Duration'),
    '#default_value' => $conf['duration'],
    '#description' => t('How much time, in milliseconds, each image will be shown'),
    '#required' => TRUE,
  );
  $form['fadeSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade speed'),
    '#default_value' => $conf['fadeSpeed'],
    '#description' => t('How much time, in milliseconds, will fading last'),
    '#required' => TRUE,
  );
  $form['ease3d'] = array(
    '#type' => 'select',
    '#title' => t('Ease 3d effect'),
    '#default_value' => $conf['ease3d'],
    '#options' => array('linear' => 'linear', 'ease' => 'ease', 'ease-in' => 'ease-in', 'ease-out' => 'ease-out', 'ease-in-out' => 'ease-in-out'),
    '#required' => TRUE,
  );
  $image_styles = image_style_options();
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
    '#description' => t('Select the image style to use with images'),
    '#empty_option' => t('Original'),
    '#empty_value' => '',
  );
  
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
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

function portales7_slideshow_advkenburns_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('width', 'height', 'scale', 'duration', 'fadeSpeed') as $k) {
    if (!is_numeric($form_state['values'][$k])) {
      form_set_error($k, t('You must enter a numeric value'));
    }
  }
}

function portales7_slideshow_advkenburns_content_type_edit_form_submit(&$form, &$form_state) {
  // For each part of the form defined in the 'defaults' array set when you
  // defined the content type, copy the value from the form into the array
  // of items to be saved. We don't ever want to use
  // $form_state['conf'] = $form_state['values'] because values contains
  // buttons, form id and other items we don't want stored. CTools will handle
  // the actual form submission.
  //$form_state['conf'] = array();
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function portales7_slideshow_advkenburns_content_type_admin_title($subtype, $conf, $context) {
  return t('Advanced kenburns slideshow') . (!empty($conf['admin_title']) ? ': ' . $conf['admin_title'] : '');
}

function portales7_slideshow_advkenburns_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_slideshow_advkenburns_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}
