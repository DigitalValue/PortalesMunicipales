<?php
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Banners'),
  'description' => t('Shows a pane with banners.'),
  'single' => TRUE,
  'content_types' => array('portales7_banners_banners_content_type'),
  'render callback' => 'portales7_banners_banners_content_type_render',
  'defaults' => array('type' => '',
    'arguments' => '',
    'items' => 10, 
    'classes' => NULL, 
    'include_path' => '', 
    'promoted' => '', 
    'offset' => 0, 
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => 'any',
    'group' => '',
    'image_style' => 'original',
    'sort' => 'portales7_banner_weight:ASC'
    ),
  'edit form' => 'portales7_banners_banners_content_type_edit_form',
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin title' => 'portales7_banners_banners_content_type_admin_title',
  'admin info' => 'portales7_banners_banners_content_type_admin_info',
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_banners_banners_content_type_render($subtype, $conf, $panel_args, $context) {
  module_load_include('inc','portales7_banners', 'portales7_banners.util');
  if ((!is_numeric($conf['group'])) && ($term = dvtoolbox_get_taxonomy_term_by_name($conf['group'], 'banners', FALSE, 0))) {
    $conf['group'] = $term->tid;
  }
  $arguments = array();
  $view = _portales7_banners_get_view();
  $view->name .= '_banners';
  //Afegir numero d'elements i paginacio
  _portales7_banners_set_num_items($view->display['default']->handler, $conf['items'], $conf['offset']);
  if (!empty($conf['pager'])) {
    _portales7_banners_add_pager($view->display['default']->handler, array('items_per_page' => $conf['items'], 'id' => 1, 'offset' => $conf['offset']));
  }
  //Afegir camps
  _portales7_banners_generic_filefield_add('portales7_banners_image', $view->display['default']->handler, $conf['image_style']);
  
  //Afegir filtres
  if ($conf['group']) {
    _portales7_banners_add_tid_filter($view->display['default']->handler, 'portales7_banners_group', 'banners', array($conf['group'] => $conf['group']));
  }
  if ($conf['promoted']) {
    _portales7_banners_add_generic_filter($view->display['default']->handler, 'promote', 1);
  }
  
  
  if (function_exists('portales7_og_add_og_filter')) {
    portales7_og_add_og_filter($view->display['default']->handler, $conf['og_group']);
  }
  
  //Afegir ordenacio
  //_portales7_banners_add_sort_by_field($view->display['default']->handler, 'field_peso', 'ASC');
  $fields=array('link','title');
  if (empty($conf['image_style'])){
    $conf['image_style'] = 'original';
  }
  $pane=new stdClass();
  $classes = $conf['classes'];
  if (is_array($conf['classes'])){
    $classes = join(' ', $conf['classes']);
  }
  $output = $view->execute_display('default',$arguments);
  if (!empty ($view->result)) {
    drupal_add_css(drupal_get_path('module', 'portales7_banners') . '/portales7_banners.css', array('type' => 'file'));
    $prefix = "<div class=\"portales7_banners {$view->name} {$view->name}-{$conf['group']} {$view->name}-{$conf['image_style']}\"><div class=\"{$classes}\">";
    $suffix= '</div></div>';
    $more_link = '';
    if (!empty($conf['more_link']) && count($view->result) > $conf['items']) {
      $more_link = '<div class="more-link">' . l(t('More'), $conf['more_link']) . '</div>';
    }
    $pane->content = $prefix . $output . $more_link . $suffix;
  }
  
  $pane->title = '';

  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_banners_banners_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  $form['fieldset_arguments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Arguments'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 98,
  );
  $form['fieldset_arguments']['arguments'] = array(
  '#type' => 'textfield',
  '#title' => t('Arguments'),
  '#description' => t('Arguments to pass to the view'),
  '#default_value' => $conf['arguments'],
  '#weight' => 5,
  );

  $form['fieldset_arguments']['include_path'] = array(
  '#type' => 'checkbox',
  '#title' => t('Include path'),
  '#description' => t('Include path arguments on filter.'),
  '#default_value' => $conf['include_path'],
  '#weight' => 6,
  );
  
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 99,
  );
  $form['options']['promoted'] = array(
  '#type' => 'checkbox',
  '#title' => t('Only promoted'),
  '#description' => t('Show only contents promoted to front page.'),
  '#default_value' => $conf['promoted'],
  );
  
  $form['options']['pager'] = array(
  '#type' => 'checkbox',
  '#title' => t('Pager'),
  '#description' => t('Use pager'),
  '#default_value' => $conf['pager'],
  );
  
  $form['options']['items'] = array(
  '#type' => 'textfield',
  '#title' => t('Items'),
  '#description' => t('Number of results to show'),
  '#default_value' => $conf['items'],
  );
  
  $form['options']['offset'] = array(
  '#type' => 'textfield',
  '#title' => t('Offset'),
  '#description' => t('Number of items to skip'),
  '#default_value' => $conf['offset'],
  );
  $form['options']['sort'] = array(
  '#type' => 'select',
  '#title' => t('Sort'),
  '#description' => t('Sort by'),
  '#default_value' => $conf['sort'],
  '#options' => array(
    'portales7_banners_weight:ASC' => t('Banner weight ascendant'),
    'portales7_banners_weight:DESC' => t('Banner weight descendant'),
    'title:ASC' => t('Title ascendant'),
    'title:DESC' => t('Title descendant'),
    'created:ASC' => t('Creation date ascendant'),
    'created:DESC' => t('Creation date descendant'),
    ),
  //'#required' => TRUE,
  );
  $form['options']['more_link'] = array(
    '#type' => 'textfield',
    '#title' => t('More link'),
    '#description' => t('Enter url of \'More\' link destination. Left blank to hide link.'),
    '#default_value' => $conf['more_link'],
  );
  $form['admin_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin title'),
    '#description' => t('This title will be used on edit page content as pane title'),
    '#default_value' => $conf['admin_title'],
    '#weight' => 99,
  );
  if (module_exists('og')) {
    $groups = array('any' => t('Any'), 'url' => t('Get from path'));
    foreach (portales7_og_available_groups() as $k => $v) {
      $groups[$k] = $v;
    }
    $form['og'] = array(
      '#type' => 'fieldset',
      '#title' => t('Groups'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => FALSE,
      '#weight' => 50,
    );
    $form['og']['og_group'] = array(
      '#type' => 'select',
      '#title' => t('Group'),
      '#multiple' => FALSE,
      '#default_value' => $conf['og_group'],
      '#options' => $groups,
      '#required' => TRUE,
    );
  }

  $voc = taxonomy_vocabulary_machine_name_load('banners');
  $group_terms = taxonomy_get_tree($voc->vid);
  $banner_groups = array();
  foreach ($group_terms as $t){
    $banner_groups[$t->name] = $t->name;
  }

  $form['group'] = array(
    '#type' => 'select',
    '#title' => t('Banner group'),
    '#options' => $banner_groups,
    '#default_value' => $conf['group'],
    '#multiple' => FALSE,
  );

  $image_styles = image_style_options(TRUE);
  //$image_styles[''] = t('Left blank for original size');
  
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
    '#description' => t('Select the image style to use with banners'),
  );
  return $form;
}

function portales7_banners_banners_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function portales7_banners_banners_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  if ((!is_numeric($conf['group'])) && ($term = dvtoolbox_get_taxonomy_term_by_name($conf['group'], 'banners', FALSE, 0))) {
    $group = $term;
  }
  else {
    $group = taxonomy_term_load($conf['group']);
  }
  return t('Banners from group @group', array('@group' => $group->name));
}

function portales7_banners_banners_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_banners_banners_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}