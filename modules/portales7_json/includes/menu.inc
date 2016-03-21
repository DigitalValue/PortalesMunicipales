<?php
function portales7_json_menu_json($menu, $parent = 0, $depth = 0) {
  global $language;
  $cid = dvtoolbox_cid_generate(array('json-menu', $menu, $language->language, $parent, $depth));
  drupal_add_http_header('Content-Type', 'application/json');
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  if (empty($_GET['reset']) && ($cached = cache_get($cid, 'cache_menu'))) {
    $menu_tree_json = $cached->data;
  }
  else {
    $menu_tree = menu_tree_all_data($menu);
    portales7_json_menu_prune($menu_tree);
    $menu_tree_json = drupal_json_encode($menu_tree);
    cache_set($cid, $menu_tree_json, 'cache_menu', CACHE_PERMANENT, $_SERVER['REQUEST_TIME'] + 1800);
  }
  print $menu_tree_json;
}

function portales7_json_menu_prune(&$menu_tree) {
  foreach ($menu_tree as $k => &$item) {
    if ($item['link']['hidden']) {
      unset($menu_tree[$k]);
    }
    else {
      $item['link']['link_title'] = $item['link']['title'];
      portales7_json_menu_prune($item['below']);
    }
  }
}

function portales7_json_quicklinks() {
  drupal_add_http_header('Content-Type', 'application/json');
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  global $language;
  
  if ($links = i18n_menu_translated_tree(variable_get('portales_quicklinks_menu', 'menu-json-quicklinks'))) {
    $quicklinks = array();
    foreach(element_children($links, FALSE) as $mlid) {
      $skip = FALSE;
      $item = $links[$mlid];
      $ql = array();
      $ql['title'] = $item['#title'];
      if (strpos($item['#href'], 'app://') === 0) {
        $ql['href'] = substr($item['#href'], 6);
      }
      elseif (preg_match('@node/([0-9]+)@', $item['#href'], $matches)) {
        $ql['nid'] = $matches[1];
        $node_lang = db_select('node', 'n')->fields('n', array('language'))->condition('nid', $ql['nid'])->execute()->fetchField();
        if (($node_lang != 'und') && ($node_lang != $language->language)) $skip = TRUE;  
      }
      else {
        $ql['href'] = $item['#href'];
      }
      if (!empty($item['#localized_options']['attributes']['class'])) {
        foreach ($item['#localized_options']['attributes']['class'] as $class) {
          if (preg_match('/([^\ ]*Button)/', $class, $matches)) {
            $ql['icon'] = $matches[1] . '.png';
          }
          elseif (preg_match('/minVersion([0-9]+)/', $class, $matches)) {
            $ql['minVersion'] = (int)$matches[1];
          }
        }
      }
      else {
        $ql['options'] = $item['#localized_options'];
      }
      if (!$skip) $quicklinks[] = $ql;
    }
    print(json_encode($quicklinks, JSON_PRETTY_PRINT));
  }
  else {
    print(variable_get('portales7_json_quicklinks', ''));
  }
  
}

function portales7_json_quicklinks_admin() {
  $menu_name = variable_get('portales_quicklinks_menu', 'menu-json-quicklinks');
  if ($menu = menu_load($menu_name)) {
    $form[0]['add'] = array(
      '#markup' => l(t('Add link'), 'admin/structure/menu/manage/' . $menu_name . '/add', array('query' => array('destination' => $_GET['q']))),
      '#prefix'  => '<div>',
      '#suffix' => '</div>',
      '#weight' => -99,
    );
    module_load_include('admin.inc', 'menu');
    $form[1] = drupal_get_form('menu_overview_form', $menu);
  }
  else {
  	$form['info'] = array(
      '#type' => 'markup',
      '#markup' => t('You must configure JSON Quicklinks from menu administration pages, but a JSON Quicklinks menu was not found'),
      '#prefix'  => '<div>',
      '#suffix' => '</div>',
    );
    $form['create_menu'] = array(
      '#type' => 'submit',
      '#value' => t('Create menu'),
    );
    
  $form['portales7_json_quicklinks'] = array(
    '#title' => 'JSON Quicklinks',
    '#type' => 'textarea',
    '#default_value' => variable_get('portales7_json_quicklinks', ''),
    '#description' => t('Current JSON code for quicklinks'),
    '#rows' => 20,
    '#disabled' => TRUE,
  );
  }
  return $form;
}

function portales7_json_quicklinks_admin_submit($form, &$form_state) {
  $menu_name = variable_get('portales_quicklinks_menu', 'menu-json-quicklinks');
  if (!$menu = menu_load($menu_name)){
    $menu = array(
      'menu_name' => $menu_name,
      'title' => 'JSON Quicklinks',
      'description' => 'A menu to store JSON Quicklinks for mobile app',
      'language' => 'und',
      'i18n_mode' => 5,
    );
    menu_save($menu);
  }
  $quicklinks =  json_decode(variable_get('portales7_json_quicklinks', '{}'));
  foreach ($quicklinks as &$ql) {
    $item = array(
      'menu_name' => $menu_name,
      'link_title' => $ql->title,
      'options' => array('attributes' => array('class' => array())),
    );
    if (isset($ql->nid)) {
      $item['link_path'] = 'node/' . $ql->nid;
    }
    elseif (!empty($ql->href)) {
      $item['link_path'] = $ql->href;
    } 
    if (!empty($ql->icon)) {
      $item['options']['attributes']['class'][] = basename($ql->icon, '.png');
    }
    if (!empty($ql->minVersion)) {
      $item['options']['attributes']['class'][] = 'minVersion' . $ql->minVersion;
    }
    menu_link_save($item);
  }
  drupal_set_message(t('A new menu for JSON Quicklinks has been created'), 'status');
}

function _portales_municipales_json_variable($names) {
  $allowed = module_invoke_all('json_variables');
  drupal_add_http_header('Content-Type', 'application/json');
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  $vars = explode(',', $names);
  $data = array();
  foreach ($vars as $name) {
    if (isset($allowed[$name])) {
      if ($allowed[$name] == 'json') {
        $data[$name] = json_decode(variable_get($name, '[]'));
      }
      elseif ($allowed[$name] == 'php') {
        $data[$name] = variable_get($name, NULL);
      }
      elseif (function_exists($allowed[$name])){
        $data[$name] = $allowed[$name]($name);
      }
    }
  }
  print json_encode(array('variables' => $data));
}

