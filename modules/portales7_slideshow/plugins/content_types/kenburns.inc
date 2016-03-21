<?php
/**
 * @file
 * Provides a content-type plugin to show contents of imagefield field.
 * /

 * /**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Slideshow Ken Burns'),
  'description' => t('Provides an slideshow with Ken Burns effect of a given node.'),
  'single' => TRUE,
  'content_types' => array('portales7_slideshow_kenburns_content_type'),
  'render callback' => 'portales7_slideshow_kenburns_content_type_render',
  'defaults' => array(
    'nid' => '',
    'id' => '',
    'image_style' => '',
    'duration' => 5000,
    'ease3d' => 'ease-out',
    'fadeSpeed' => 500,
    'scale' => 1,
    'height' => 360,
    'width' => 960,
    ),
  'edit form' => 'portales7_slideshow_kenburns_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_slideshow_kenburns_content_type_render($subtype, $conf, $panel_args, $context) {
  if (preg_match('/^p7vars_/', $conf['nid']) && ($value = variable_get($conf['nid'], FALSE))) {
    if (preg_match('@node/([0-9]+)@', $value, $matches)) {
      $conf['nid'] = $matches[1];
    }
    elseif (is_numeric($value)) {
      $conf['nid'] = $value;
    }
    else {
      drupal_set_message(t('Invalid node for slideshow @id', array('@id' => $conf['id'])), 'error');
    	$conf['nid'] = NULL; 
    }
  }
  if (empty($conf['nid'])) return FALSE;
  if (($node = node_load($conf['nid'])) && !empty($node->portales7_media['und'])) {
    $items = array();
    foreach ($node->portales7_media['und'] as $fc) {
      $data = entity_load('field_collection_item', array($fc['value']));
      $element = $data[$fc['value']];
      foreach($element->portales7_images['und'] as $delta => $item) {
        $images[] = $item;
      }
    }
    $elements['items'] = $images;
    $elements['conf'] = $conf;
    $elements['class'] = array('portales7-advkenburns', 'portales7-advkenburns-' . $conf['view_mode']);
    $pane = new stdClass();
    $pane->content = theme('portales7_slideshow_kenburns', $elements);
    return $pane;
  }
}


/**
 * Returns an edit form for the custom type.
 */
function portales7_slideshow_kenburns_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Gallery node'),
    '#description' => t('Node ID of node gallery to show as slideshow, you can use <em>p7vars_</em> variables here.'),
    '#default_value' => $conf['nid'],
    '#required' => TRUE,
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
  
  

  return $form;

}

function portales7_slideshow_kenburns_content_type_edit_form_submit(&$form, &$form_state) {
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

function portales7_slideshow_kenburns_content_type_admin_title($subtype, $conf, $context) {
  return t('Slideshow Ken Burns') . (!empty($conf['admin_title']) ? ': ' . $conf['admin_title'] : '');
}


function portales7_slideshow_kenburns_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_slideshow_kenburns_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}