<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  
$plugin = array(
  'title' => t('Miniportal header'),
  'description' => t('Shows a header for the miniportal.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_og_header'),

// The default context.
  'defaults' => array('preset' => 'original', 'og_group' => 'url'),

// Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_og_header_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane=new stdClass();
  if ($conf['og_group'] == 'url') {
    $context = og_context();
    $gid = $context['gid'];
  }
  else {
    $gid = $conf['og_group'];
  }
  if (empty($gid)) {return $pane;}
  $node = node_load($gid);
  if (empty($node->portales7_og_header['und'][0]['uri'])) return NULL;
  $element=array();
  $image = array(
    'style_name' => $conf['preset'],
    'path' => $node->portales7_og_header['und'][0]['uri'],
    'alt' => $node->portales7_og_header['und'][0]['alt'],
    'title' => $node->portales7_og_header['und'][0]['title'],
  );
  $header_image = theme('image_style', $image);
  $output = '<div class="pm-miniportal-header">';
  $output .= $header_image;
  $output .= '</div>';
  $pane->content = $output;
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_og_header_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  module_load_include('util.inc', 'portales7');
  $groups = _portales7_listado_available_groups();
  unset($groups['any']);
  $image_styles = image_style_options(FALSE);
  $image_styles['original'] = t('original');
  $form['og_group'] = array(
    '#type' => 'select',
    '#title' => t('Group'),
    '#multiple' => FALSE,
    '#default_value' => $conf['og_group'],
    '#options' => $groups,
    '#required' => TRUE,
  );
  $form['preset'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#description' => t('Select image style for the header'),
    '#options' => $image_styles,
    '#default_value' => $conf['preset'],
  );
  return $form;
}

function portales7_og_header_content_type_edit_form_submit(&$form, &$form_state) {
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


function portales7_og_header_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = t('Miniportal header image');
  $pane->content = t('Using image style @style', array('@style' => $conf['style']));
  
  return $pane;
}

function portales7_og_header_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('Miniportal header image');
}
