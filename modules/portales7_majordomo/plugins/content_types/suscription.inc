<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Subscribe'),
  'description' => t('Shows a subscription form.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_majordomo_pane_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_majordomo_pane_content_type_render',
// The default context.
  'defaults' => array('description' => FALSE, 'title' => FALSE),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_majordomo_pane_content_type_edit_form',

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
function portales7_majordomo_pane_content_type_render($subtype, $conf, $panel_args, $context) {
  global $plugin;
  $pane=new stdClass();
  $pane->content = drupal_get_form('portales7_majordomo_subscription',$conf);
  $pane->title = $plugin['title'];
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_majordomo_pane_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  $form['title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show title'),
    '#return_value' => TRUE,
    '#default_value' => $conf['title'],
   );
  
  $form['description'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show description'),
    '#return_value' => TRUE,
    '#default_value' => $conf['description'],
  );
  return $form;
}

function portales7_majordomo_pane_content_type_edit_form_submit(&$form, &$form_state) {
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

function portales7_majordomo_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $output = t('Majordomo');
  if ($conf['override_title'] && !empty($conf['override_title_text'])) {
    $output = filter_xss_admin($conf['override_title_text']);
  }
  return $output;
}

/**
 * Callback to provide administrative info (the preview in panels when building
 * a panel).
 *
 * In this case we'll render the content with a dummy argument and
 * a dummy context.
 */
function portales7_majordomo_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_footerlinks_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
