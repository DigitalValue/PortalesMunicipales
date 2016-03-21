<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Footer menu'),
  'description' => t('Shows a pane with a menu.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_footermenu_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_footermenu_content_type_render',
// The default context.
  'defaults' => array('menu' => 0, 'mlids' => array(), 'depth' => 1),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_footermenu_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_listado.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_footermenu_content_type_admin_info',
  'admin title' => 'portales7_footermenu_content_type_admin_title',

// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_footermenu_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;
  $pane=new stdClass();
  $items = array();
  $tlm = menu_tree_all_data($conf['menu'], NULL, $conf['depth'] + 1);
  $output = '';
  $width = 100 / count($conf['mlids']);
  foreach ($tlm as $key => $data){
    if (in_array($data['link']['mlid'], $conf['mlids'])){
      $item = $data['link'];
      $output .= '<div class="footer-menu-parent" id="footer-menu-' . $item['mlid'] . '" style="width: '. $width .'%; float: left;"><div class="menu-title">' . $item['title'] . '</div>';
      $output .= drupal_render(menu_tree_output($data['below']));
      $output .= '</div>';
    }
    else unset($tlm[$key]);
  }
  //$pane->content = drupal_render(menu_tree_output($tlm));
  $pane->content = $output;
  $pane->title = '';
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_footermenu_content_type_edit_form($form, &$form_state) {
  $menus = array();
  foreach (menu_load_all() as $name => $menu){
    $menus[$name] = $menu['title'];
  }
  
  $conf = $form_state['conf'];
  $items = _portales7_top_level_items($conf['menu']);
  $form['menu'] = array(
    '#type' => 'select',
    '#title' => t('Select menu'),
    '#options' => $menus,
    '#default_value' => $conf['menu'],
    '#description' => t('Select wich menu will be rendered.'),
    '#ajax' => array(
      'path' => 'footermenu_mlids' 
    ),
  );
  $form['mlids'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Parents shown'),
    '#description' => t('Select which top level menu items will be shown.'),
    '#options' => $items,
    '#default_value' => $conf['mlids'],
    '#validated' => TRUE,
  );
  
  $form['depth'] = array(
    '#title' => t('Menu depth'),
    '#description' => t('Menu depth, set to 0 to show the whole tree'),
    '#type' => 'textfield',
    '#default_value' => $conf['depth'],
  );
  
  return $form;
}

function portales7_footermenu_content_type_edit_form_submit(&$form, &$form_state) {
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
function portales7_footermenu_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $output = t('footermenu');
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
function portales7_footermenu_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_footermenu_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
