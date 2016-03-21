<?php
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Localizable text'),
  'description' => t('Shows localizable text.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('dvtoolbox_localizable_content_type'),
// Name of a function which will render the block.
  'render callback' => 'dvtoolbox_localizable_content_type_render',
// The default context.
  'defaults' =>array(),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'dvtoolbox_localizable_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_dvtoolbox.png',
  'category' => t('DV toolbox'),
  
  'admin title' => 'dvtoolbox_localizable_content_type_admin_title',

);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvtoolbox_localizable_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;
  $code = $language->language;
  $pane->title = '';
  $pane->content = check_markup($conf[$code]['text']['value'], $conf[$code]['text']['format']);
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function dvtoolbox_localizable_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  foreach (language_list() as $code => $lang) {
    if (!$lang->enabled) continue;
    $fs = $code;
    $form[$fs] = array(
      '#type' => 'fieldset',
      '#title' => $lang->native,
      '#tree' => TRUE,
    );
    $form[$fs]['text'] = array(
      '#type' => 'text_format',
      '#title' => t('Text'),
      '#default_value' => $conf[$fs]['text']['value'],
      '#format' => $conf[$fs]['text']['format'],
    );
  }
  return $form;
}

function dvtoolbox_localizable_content_type_edit_form_submit(&$form, &$form_state) {
  // For each part of the form defined in the 'defaults' array set when you
  // defined the content type, copy the value from the form into the array
  // of items to be saved. We don't ever want to use
  // $form_state['conf'] = $form_state['values'] because values contains
  // buttons, form id and other items we don't want stored. CTools will handle
  // the actual form submission.
  foreach (language_list() as $code => $lang) {
    $form_state['conf'][$code] = $form_state['values'][$code];
  }
}

function dvtoolbox_localizable_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('Localizable text');
}

function dvtoolbox_localizable_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = dvtoolbox_localizable_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
