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
  'title' => t('Slideshow'),
  'description' => t('Provides an slideshow of a given node.'),
  'single' => TRUE,
  'content_types' => array('portales7_slideshow_slideshow_content_type'),
  'render callback' => 'portales7_slideshow_slideshow_content_type_render',
  'defaults' => array('nid' => '', 'image_link' => '', 'image_style' => '', 'inlinetitle' => TRUE, 'effect' => 'blindX', 'speed' => 1000, 'timeout' => 4000, 'showcontrols' => FALSE),
  'edit form' => 'portales7_slideshow_slideshow_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_slideshow_slideshow_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($conf['nid'])) return FALSE;
  if (($node = node_load($conf['nid'])) && !empty($node->portales7_media['und'])) {
    $items = array();
    foreach ($node->portales7_media['und'] as $delta => $fc) {
      $data = entity_load('field_collection_item', array($fc['value']));
      $fci = $data[$fc['value']];
      foreach ($fci->portales7_images['und'] as $image) {
        $items[] = $image;
      }
    }
    $elements['items'] = $items;
    $elements['conf'] = $conf;
    $elements['node'] = $node;
    $node->portales2_slideshow_options = $conf;
    $pane = new stdClass();
    $pane->content = theme('portales7_slideshow', $elements);
    $pane->title=$node->title;
    return $pane;
  }
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_slideshow_slideshow_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['nid'] = array(
      '#type' => 'textfield',
      '#title' => t('Gallery node'),
      '#description' => t('Node ID of node gallery to show as slideshow'),
      '#default_value' => $conf['nid'],
      '#required' => TRUE,
  );
  $image_styles = image_style_options(TRUE);
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
    '#description' => t('Select the image style to use with main image'),
  );
  
  $form['inlinetitle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show image title'),
    '#description' => t('Show image title'),
    '#return_value' => 1,
    '#default_value' => $conf['inlinetitle'],
  );
  $form['effect'] = array(
      '#type' => 'select',
      '#multiple' => FALSE,
      '#title' => t('Transition effect'),
      '#description' => t('Choose wich transition effect slideshow will use'),
      '#options' => _portales7_slideshow_available_effects(),
      '#default_value' => $conf['effect'],
  );
  $form['timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Duration'),
      '#description' => t('How much time, in milliseconds, will be shown every item.'),
      '#default_value' => $conf['timeout'],
      '#required' => TRUE,
  );
  $form['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed'),
      '#description' => t('Duration, in milliseconds, of the transition effect.'),
      '#default_value' => $conf['speed'],
      '#required' => TRUE,
  );
  $form['showcontrols'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show controls'),
        '#description' => t('Show controls at the bottom of the slideshow'),
        '#defaullt_value' => 1,
        '#checked' => $conf['showcontrols'],
  );

  return $form;

}

function portales7_slideshow_slideshow_content_type_edit_form_submit(&$form, &$form_state) {
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

function portales7_slideshow_slideshow_content_type_admin_title($subtype, $conf, $context) {
  return t('Slideshow pane') . (!empty($conf['admin_title']) ? ': ' . $conf['admin_title'] : '');
}


function portales7_slideshow_slideshow_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_slideshow_slideshow_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}