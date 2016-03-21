<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Floating Banner'),
  'description' => t('Shows a floatting banner.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('floating_banner'),
// Name of a function which will render the block.
  'render callback' => 'floating_banner_render',
// The default context.
  'defaults' => array('left' => '', 'right' => ''),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'floating_banner_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_floating_banner.png',
  'category' => t('Portales 7'),

// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function floating_banner_render($subtype, $conf, $panel_args, $context) {
  #drupal_add_css(drupal_get_path('module','portales7_floating_banner') . '/floatingbanner.css');
  #drupal_add_js(drupal_get_path('module','portales7_floating_banner') . '/jquery.floatingbanner.js');
  drupal_add_js(drupal_get_path('module','portales7_floating_banner') . '/portales7_floating_banner.js');
  
  $pane=new stdClass();

  $output = '';
  if (!empty($conf['left']) && ($node = node_load($conf['left']))) {
    $output .= '<div id="skycraper-left" style="position: fixed; left:0; top:0;">';
    $output .= drupal_render(field_view_field('node',$node, 'body', array('label' => 'hidden')));
    $output .= '</div>';
  }
  if (!empty($conf['right']) && ($node = node_load($conf['right']))) {
    $output .= '<div id="skycraper-right" style="position: fixed; left:0; top:0;">';
    $output .= drupal_render(field_view_field('node',$node, 'body', array('label' => 'hidden')));
    $output .= '</div>';
  }

  $pane->content = $output; 
  $pane->title = NULL;
  return $pane;
  
}


/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function floating_banner_edit_form(&$form, &$form_state) {
  $conf = $form_state['values'];
  $form['left'] = array(
    '#type' => 'textfield',
    '#title' => t('Left'),
    '#description' => t('Node to display at left side of the content'),
    '#default_value' => $conf['left'],
  );
  $form['right'] = array(
    '#type' => 'textfield',
    '#title' => t('Right'),
    '#description' => t('Node to display at right side of the content'),
    '#default_value' => $conf['right'],
  );
  return $form;
}

function floating_banner_edit_form_submit(&$form, &$form_state) {
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

