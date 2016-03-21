<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Footer links'),
  'description' => t('Shows a pane with a series of links.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_footerlinks_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_footerlinks_content_type_render',
// The default context.
  'defaults' => array('active' => array('contact' => 'contact', 'legal_advice' => 'legal_advice', 'site_map' => 'site_map', 'privacy_policy' => 'privacy_policy', 'rss' => 'rss')),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_footerlinks_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_listado.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_footerlinks_content_type_admin_info',
  'admin title' => 'portales7_footerlinks_content_type_admin_title',

// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_footerlinks_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;  
  global $theme_path;

  $realm = variable_realm('language', $language->language);
  $options['language'] = $language;
  $items = array();
  if (!empty($conf['active']['contact'])) $items[] = l(t('Contact'), 'contact' , array('attributes' => array('class' => array('opcio-peu opcio-contacte'))));
  if (!empty($conf['active']['legal_advice']))$items[] = l(t('Legal advice'), 'node/' . variable_get_value('portales7_legal_advice', $options), array('attributes' => array('class' => array('opcio-peu opcio-legal'))));
  if (!empty($conf['active']['site_map']))$items[] = l(t('Site map'), 'sitemap', array('attributes' => array('class' => array('opcio-peu opcio-mapaweb'))));
  if (!empty($conf['active']['privacy_policy']))$items[] = l(t('Privacy policy'), 'node/' . variable_get_value('portales7_privacy_policy', $options), array('attributes' => array('class' => array('opcio-peu opcio-lopd'))));
  if (!empty($conf['active']['rss']))$items[] = l(t('RSS'), 'rss.xml', array('attributes' => array('class' => array('opcio-peu opcio-rss'))));

  $pane = new stdClass();
  $pane->content = !empty($items) ? theme('item_list', array('items' => $items, 'attributes' => array('class' => array('menu')))) : NULL;
  $pane->title = '';
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_footerlinks_content_type_edit_form($form, $form_state) {
  $conf = $form_state['conf'];
  $form['active'] = array(
    '#title' => t('Select items to display'),
    '#type' => 'checkboxes',
    '#options' => array('contact' => t('Contact'), 'legal_advice' => t('Legal advice'), 'site_map' => t('Site map'), 'privacy_policy' => t('Privacy policy'), 'rss' => t('RSS')),
    '#default_value' => $conf['active'],
  );
  return $form;
}

function portales7_footerlinks_content_type_edit_form_submit(&$form, &$form_state) {
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
function portales7_footerlinks_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $output = t('Footer links');
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
function portales7_footerlinks_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_footerlinks_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
