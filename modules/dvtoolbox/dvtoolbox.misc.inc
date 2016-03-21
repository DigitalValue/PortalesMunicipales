<?php
function dvtoolbox_menu_alter(&$items) {
   $items['admin/config/dvtoolbox'] = array(
    'title' => t('DVToolbox'),
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('access administration pages'),
    'position' => 'left',
    'weight' => -99,
    'type' => MENU_NORMAL_ITEM,
  );
  $items['admin/config/dvtoolbox/field_export'] = array(
    'title' => t('Field export'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_fields_export'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
  );
  if (module_exists('update')) {
    $items['admin/config/dvtoolbox/tarballs'] = array(
      'title' => t('List tarballs'),
      'page callback' => 'dvtoolbox_get_tarballs',
      'access arguments' => array('administer portales7'),
      'type' => MENU_NORMAL_ITEM,
    );
  }
  $items['admin/config/dvtoolbox/variable_export'] = array(
    'title' => t('List variables'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_variable_export'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
  );
  $items['admin/config/dvtoolbox/permissions/import'] = array(
    'title' => t('Import permissions'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_permissions_import'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 11,
  );
  $items['admin/config/dvtoolbox/permissions/export'] = array(
    'title' => t('Export permissions'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_permissions_export'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 10,
  );
  $items['admin/config/dvtoolbox/files/import'] = array(
    'title' => t('Import files'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_files_import'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 12,
  );
  $items['admin/config/dvtoolbox/taxonomy/export'] = array(
    'title' => t('Export taxonomies'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_taxonomy_export'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 13,
  );
  $items['admin/config/dvtoolbox/ckeditor/export'] = array(
    'title' => t('Export ckeditor settings'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_ckeditor_export'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 13,
  );
  $items['dvtoolbox/megaimport'] = array(
    'title' => t('MegaImport'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_megaimport'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 13,
    'file' => drupal_get_path('module', 'dvtoolbox') . '/dvtoolbox.megaimport.inc',
  );
  $items['admin/config/dvtoolbox/nodes/export'] = array(
    'title' => t('Export nodes'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_nodes_export'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 14,
  );
  $items['admin/config/dvtoolbox/nodes/import'] = array(
    'title' => t('Import nodes'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('dvtoolbox_misc_nodes_import'),
    'access arguments' => array('administer portales7'),
    'type' => MENU_NORMAL_ITEM,
    'weight' => 15,
  );
}

function dvtoolbox_misc_ckeditor_export($form, &$form_state) {
  $settings = db_select('ckeditor_settings', 'cs')->fields('cs')->execute()->fetchAll(PDO::FETCH_ASSOC);
  
  foreach ($settings as &$v) {
    $v['settings'] = base64_encode($v['settings']);
  }
  $form['ckeditor_settings'] = array(
    '#type' => 'textarea',
    '#title' => 'Settings',
    '#rows' => 50,
    '#default_value' => "\$fields = " .dvtoolbox_var_export($settings) . ';',
    '#disabled' => TRUE,
    '#attributes' => array('wrap' => 'soft'),
  );
  return $form;
}
function dvtoolbox_misc_nodes_export($form, &$form_state) {
  $nids = db_select('node', 'n')->fields('n', array('nid'))->execute()->fetchCol();
  $nodes = array();
  module_load_include('inc', 'portales7_json', 'includes/raw');
  portales7_json_entity_load_recursive('node', $nids, $nodes, 1);
  $form['nodes'] = array(
    '#type' => 'textarea',
    '#title' => 'Nodes',
    '#rows' => 50,
    '#default_value' => json_encode($nodes, JSON_PRETTY_PRINT),
    '#disabled' => TRUE,
  );
  return $form;
}

function dvtoolbox_misc_nodes_import($form, &$form_state) {
  $form['nodes'] = array(
    '#type' => 'textarea',
    '#title' => 'Nodes',
    '#rows' => 50,
    '#default_value' => '',
    '#description' => t('Paste your json containing exported nodes here'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );
  return $form;
}

function dvtoolbox_misc_nodes_import_submit($form, &$form_state) {
  if ($nodes = json_encode($form_state['values']['nodes'])) {
    foreach ($nodes as $node) {
      $node->nid = 0;
      $node->is_new = TRUE;
      node_save($node);
      drupal_set_message(t('Saved node %nid: %title', array('%nid' => $node->nid, '%title' => $node->title)), 'status');
    }  
  }
}

function dvtoolbox_misc_permissions_export($form, &$form_state) {
  $form = array();
  $roles = user_roles();
  $roles[1] = 'anonymous user';
  $roles[2] = 'authenticated user';
  $user_role_permissions = user_role_permissions($roles);
  $permissions = array();
  foreach($roles as $rid => $name) {
    $permissions[$name] = $user_role_permissions[$rid];
  }
  $form['permissions'] = array(
    '#type' => 'textarea',
    '#title' => 'Permissions',
    '#rows' => 50,
    '#default_value' => '$permissions = ' . dvtoolbox_var_export($permissions) . ';',
    '#disabled' => TRUE,
  );
  return $form;
}

function dvtoolbox_misc_permissions_import($form, &$form_state) {
  $form = array();
  $roles = user_roles();
  $roles[1] = 'anonymous user';
  $roles[2] = 'authenticated user';
  $user_role_permissions = user_role_permissions($roles);
  $permissions = array();
  foreach($roles as $rid => $name) {
    $permissions[$name] = $user_role_permissions[$rid];
  }
  $form['permissions'] = array(
    '#type' => 'textarea',
    '#title' => 'Permissions',
    '#rows' => 10,
    '#default_value' => '$permissions = ' .dvtoolbox_var_export($permissions) . ';',
    '#readonly' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function dvtoolbox_misc_permissions_import_submit($form, &$form_state) {
  eval($form_state['values']['permissions']);
  dpm($permissions, 'permissions');
  dvtoolbox_grant_permissions($permissions, FALSE);
}


function dvtoolbox_misc_variable_export($form, &$form_state) {
  $form['variable'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => '',
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Export'),
  );
  if (!empty($form_state['temporary']['variable'])) {
    $desc = $output = '';
    $res = db_select('variable', 'v')->fields('v', array())->condition('name', $form_state['temporary']['variable'], 'LIKE')->execute()->fetchAll();
    foreach ($res as $row) {
      $output .= "variable_set('" . $row->name . "', " . dvtoolbox_var_export(unserialize($row->value)) . ");\n";
    }
    $desc = t('Variable output for @variable', array('variable' => $form_state['temporary']['variable']));
    $form['output' . $_SERVER['REQUEST_TIME']] = array(
      '#type' => 'textarea',
      '#title' => t('Output'),
      '#default_value' => $output,
      '#description' => $desc,
      '#rows' => 20,
      
    ); 
  }
  return $form;
}

function dvtoolbox_misc_variable_export_submit(&$form, &$form_state) {
  $form_state['temporary'] = array('variable' => $form_state['values']['variable']);
  $form_state['rebuild'] = TRUE;
}

function dvtoolbox_misc_fields_export($form, &$form_state) {
  $content_types = db_select('field_config_instance', 'f')->fields('f', array('entity_type'))->distinct()->execute()->fetchCol();
  $bundles = db_select('field_config_instance', 'f')->fields('f', array('bundle'))->distinct()->execute()->fetchCol();
  $form['type'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc($content_types),
    '#title' => t('Content type'),
    '#default_value' => 'node',
    '#required' => TRUE,
  );
  $form['bundle'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc($bundles),
    '#default_value' => 'portales7_node',
    '#title' => t('Bundle'),
    '#required' => TRUE,
  );
  $form['object'] = array(
    '#title' => t('Export'),
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array('fields', 'instances', 'groups', 'view_modes')),
    '#required' => TRUE,
    '#default_value' => 'instances',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Export'),
  );
  if (!empty($form_state['temporary']['type']) && !empty($form_state['temporary']['bundle']) && !empty($form_state['temporary']['object'])) {
    $desc = $output = '';
    switch($form_state['temporary']['object']) {
      case 'fields':
        $output = "<?php\n\$fields = " . dvtoolbox_var_export(dvtoolbox_field_read_fields($form_state['temporary']['type'], $form_state['temporary']['bundle'])) . ";\n";
        $desc = t('Put this content on a file called %filename on corresponding module', array('%filename' => $form_state['temporary']['bundle'] . '.' . $form_state['temporary']['object']. '.inc'));
        break;
      case 'instances':
        $output = "<?php\n\$instances = " . dvtoolbox_var_export(dvtoolbox_field_read_instances($form_state['temporary']['type'], $form_state['temporary']['bundle'])) . ";\n";
        $desc = t('Put this content on a file called %filename on corresponding module', array('%filename' => $form_state['temporary']['bundle'] . '.' . $form_state['temporary']['object']. '.inc'));
        break;
      case 'groups':
        $output = "<?php\n\$groups = " . dvtoolbox_var_export(dvtoolbox_field_read_groups($form_state['temporary']['type'], $form_state['temporary']['bundle'])) . ";\n";
        $desc = t('Put this content on a file called %filename on corresponding module', array('%filename' => $form_state['temporary']['bundle'] . '.' . $form_state['temporary']['object']. '.inc'));
        break;
      case 'view_modes':
        $output = "<?php\n\$view_modes = " . dvtoolbox_var_export(dvtoolbox_field_read_view_modes($form_state['temporary']['type'], $form_state['temporary']['bundle'])) . ";\n";
        $desc = t('Put this content on a file called %filename on corresponding module', array('%filename' => $form_state['temporary']['bundle'] . '.' . $form_state['temporary']['object']. '.inc'));
        break;
    }
    $form['output' . $_SERVER['REQUEST_TIME']] = array(
      '#type' => 'textarea',
      '#title' => t('Output'),
      '#default_value' => $output,
      '#description' => $desc,
      '#rows' => 20,
      
    ); 
  }
  return $form;
}

function dvtoolbox_misc_fields_export_submit(&$form, &$form_state) {
  $form_state['temporary'] = array('type' => $form_state['values']['type'], 'bundle' => $form_state['values']['bundle'], 'object' => $form_state['values']['object']);
  $form_state['rebuild'] = TRUE;
}

function dvtoolbox_field_read_instances($entity_type, $bundle) {
  $is = field_read_instances(array('entity_type' => $entity_type,'bundle' => $bundle));
  foreach ($is as $i) {
    $fn = $i['field_name'];
    foreach (array('id', 'field_id', 'entity_type', 'field_name', 'bundle', 'deleted') as $k) unset($i[$k]);
    if (isset($i['settings'], $i['settings']['user_register_form']) && !$i['settings']['user_register_form']) unset($i['settings']['user_register_form']);
      $instances[$fn] = $i;
    }
  return $instances;
}

function dvtoolbox_field_read_fields($entity_type, $bundle) {
  $is = field_read_fields(array('entity_type' => $entity_type,'bundle' => $bundle));
  foreach ($is as $i) {
    $fn = $i['field_name'];
    foreach (array('entity_types', 'translatable', 'storage', 'foreign keys', 'indexes', 'id', 'field_name', 'module', 'active', 'locked', 'deleted', 'columns') as $k) unset($i[$k]);
    if (($i['type'] == 'text') && ($i['setttings']['max_length'] == 255)) unset($i['settings']['max_length']);
    if (empty($i['settings'])) unset($i['settings']);
      $instances[$fn] = $i;
    }
  return $instances;
}

function dvtoolbox_field_read_groups($entity_type, $bundle = NULL, $mode = NULL, $reset = FALSE) {
  $info =field_group_info_groups($entity_type, $bundle, $mode, $reset);
  if (!empty($mode)) {
    $info = array($mode => $info);
  }
  if (!empty($bundle)) {
    $info = array($bundle => $info);
  }
  foreach ($info as $bundle => &$info3) {
    foreach ($info3 as $mode => &$info2) {
      foreach ($info2 as $gn => &$v) {
        foreach (array('id', 'identifier', 'group_name', 'bundle', 'table', 'disabled', 'entity_type', 'export_type') as $k) unset($v->$k);
      }
    }
  }
  return $info;
}

function dvtoolbox_field_read_view_modes($entity_type, $bundle) {
  $entity_info = entity_get_info($entity_type);
  $view_mode_settings = field_view_mode_settings($entity_type, $bundle);
  $view_modes = array();
  foreach ($entity_info['view modes'] as $view_mode_name => $view_mode_info) {
    if (!empty($view_mode_settings[$view_mode_name]['custom_settings'])) {
      $view_modes[$view_mode_name] = array('label' => $view_mode_info['label'], 'custom_settings' => TRUE);
    }
  }
  return $view_modes;
}

function dvtoolbox_grup_entitats(){
    module_load_include('node.inc', 'portales7_directory');
    module_load_include('field.inc', 'dvtoolbox');
    $groups = _portales7_directory_installed_field_groups();
    dpm($groups, 'groups');
    $res = dvtoolbox_field_create_groups('node', $groups);
    print join("\n", $res);
    dpm(field_group_info_groups('node', 'portales7_entity', 'form', TRUE), 'field_group_info_groups:form');
    dpm(field_group_info_groups('node', 'portales7_entity', 'default', TRUE), 'field_group_info_groups:default');
}

function dvtoolbox_query_locale_export_get_strings_alter($query) {
  if ($query->hasTag('locale_export_get_strings')) {
    $query->isNull('translation');
    //$query->where('length(source) < 10');
    $order = &$query->getOrderBy();
    unset($order);
    $query->orderBy('length(source)');
    $offset = 0;
    $items = 200;
    if (!empty($_SESSION['locale_export_strings_offset'])) $offset = $_SESSION['locale_export_strings_offset'];
    if (!empty($_SESSION['locale_export_strings_limit'])) $items = $_SESSION['locale_export_strings_limit'];
    $query->range($offset, $items);
  }
}

function dvtoolbox_update_groups($bundle) {
  module_load_include('field.inc', 'dvtoolbox');
  module_load_include('node.inc', $bundle);
  $groups = call_user_func('_' . $bundle . '_installed_field_groups');
  unset($groups['portales7_node']['form']);
  dpm($groups, __FUNCTION__);
  return dvtoolbox_field_create_groups('node', $groups);
}

function dvtoolbox_extract_permissions() {
  $webmaster = user_role_load_by_name('webmaster');
  $redactor = user_role_load_by_name('redactor');
  $perms = user_role_permissions(array($redactor->rid => 'redactor', $webmaster->rid => 'webmaster'));
  $output = array();
  if (!empty($perms[$webmaster->rid])) {
    $output['webmaster'] = array_keys($perms[$webmaster->rid]);
  }
  if (!empty($perms[$redactor->rid])) {
    $output['redactor'] = array_keys($perms[$redactor->rid]);
  }
  return $output;
}

function dvtoolbox_filter_empty($var) {
  return empty($var);
}

function dvtoolbox_get_tarballs() {
  module_load_include('compare.inc', 'update');
  $projects = update_get_projects();
  $output = '';
  foreach ($projects as $project) {
    if ($project['project_status']) {
      $output .= "http://www.drupal.org/files/projects/" . $project['info']['project'] . '-' . $project['info']['version'] . '.tar.gz' . "\n";
    }
  }
  print '<pre>' . $output . '</pre>';
}

function _dvtoolbox_misc_scan_files($path = 'public://') {
  return $files = file_scan_directory($path, '/.*/');
}

function dvtoolbox_misc_files_import($form_state) {
  $files = _dvtoolbox_misc_scan_files();
  dpm($files, __FUNCTION__);
  $form = array();
  $form['info'] = array(
    '#type' => 'markup',
    '#markup' => theme('item_list', array('#items' => $files)),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );
  return $form;
}

function dvtoolbox_misc_files_import_submit($form, &$form_state) {
  $files = _dvtoolbox_misc_scan_files();
  foreach ($files as $file) {
    if (false) {
      //TODO: import the file
      
    }
  }
}


function dvtoolbox_misc_taxonomy_export() {
  $vocabularies = entity_load('taxonomy_vocabulary', FALSE);
  $form['instances'] = array(
    '#type' => 'textarea',
    '#title' => t('Vocabularies'),
    '#default_value' => '<?php $vocabularies = ' . dvtoolbox_var_export($vocabularies),
    '#description' => t('Put this text on a file called portales7_node.vocabularies.inc'),
    '#rows' => 20,
  );
  return $form;
}
