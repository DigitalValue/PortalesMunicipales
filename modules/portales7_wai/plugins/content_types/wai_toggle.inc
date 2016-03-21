<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('WAI toggle'),
  'description' => t('Shows toggle for WAI like.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_wai_pane_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_wai_pane_content_type_render',
// The default context.
  'defaults' => array(),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
//  'edit form' => 'portales7_wai_pane_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_majordomo.png',
  'category' => t('Portales 7'),

// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_wai_pane_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane=new stdClass();
  
  $enabled = !empty($_SESSION['wai_version']);
  $text = $enabled?t("Dynamic version"):t('Accessible version');
  $classes = sprintf("wai-toggle wai-toggle-%s",$enabled?"active":"inactive");
  $link = "wai-toggle/".($enabled?"disable":"enable");
  $pane->content = l($text,$link,array('attributes'=>array('class'=>$classes)));
  $pane->title = t('WAI Toggle');
  return $pane;
  
}


/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_wai_pane_content_type_edit_form($form, &$form_state) {
}

function portales7_wai_pane_content_type_edit_form_submit(&$form, &$form_state) {
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

