<?php
function dvtoolbox_megaimport($form) {
  if (!file_exists('megaimport.json')) {
    drupal_set_message(t('Input file doesn\'t exist'), 'error');
    return;
  }
  if ($data = json_decode(file_get_contents('megaimport.json'))) {
    dpm($data, 'data');
  }
}


function dvtoolbox_megaimport_batch_prepare($file) {
  $data = json_decode(file_get_contents($file), TRUE);
  $callbacks = array(
    'vocabulary' => '_dvtoolbox_megaimport_vocabulary_batch_do',
    'role' => '_dvtoolbox_megaimport_role_batch_do',
    'grant' => '_dvtoolbox_megaimport_grant_batch_do',
    'translation' => '_dvtoolbox_megaimport_translation_do',
    'variable' => '_dvtoolbox_megaimport_variable_do',
    'menu' => '_dvtoolbox_megaimport_menu_do',
    'menu_link' => '_dvtoolbox_megaimport_menu_link_do',
  );
  $operations = array();
  foreach ($data as $item) {
    if (!isset($callbacks[$item['import_type']])) next;
    $operations[] = array($callbacks[$item['import_type']], array($item));
  }

  if (!empty($operations)) {
    $batch = array(
      'title' => t('Importing settings'),
      'operations' => $operations,
      'finished' => 'dvtoolbox_megaimport_batch_finished',
      'file' => drupal_get_path('module', 'dvtoolbox') . '/dvtoolbox.megaimport.inc',
    );
    return $batch;
  }
  return NULL;
}

function dvtoolbox_megaimport_import($file) {
  if ($batch = dvtoolbox_megaimport_batch_prepare($file)) {
    batch_set($batch);
    batch_process();
  }
}

function _dvtoolbox_megaimport_create_term($term, $voc, $parent = 0) {
  $t = new stdClass();
  $t->vid = $voc->vid;
  $t->vocabulary_machine_name = $voc->machine_name;
  $t->name = $term['en'];
  $t->parent = $parent;
  if (!empty($term['description_en'])) $t->description = $term['description'];
  if (!empty($term['weight'])) $t->weight = $term['weight'];

  if (!empty($term['synonyms'])) {
    if (empty($t->portales7_term_synonyms['und'])) $t->portales7_term_synonyms['und'] = array();
    foreach ($term['synonyms'] as $syn) {
      $t->portales7_term_synonyms['und'][] = array('value' => $syn);
    }
  }

  taxonomy_term_save($t);

  if (!empty($term->children)) {
    foreach($term->children as $child) {
      _dvtoolbox_megaimport_create_term($child, $voc, $t->tid);
    }
  }
}

function _dvtoolbox_megaimport_vocabulary_batch_do($voc, &$context) {
  if (!empty($_SESSION['DEBUG'])) watchdog('megaimport', __FUNCTION__ . ' !args', array('!args' => '<pre>' . print_r($voc,1) , '</pre>'), WATCHDOG_INFO);
  if (!$v = taxonomy_vocabulary_machine_name_load($voc['id'])) {
    $v = (object) array('vid' => 0, 'machine_name' => $voc['id'], 'name' => $voc['name']['en'], 'description' => !empty($voc['description']['en']) ? $voc['description']['en'] : NULL, 'i18n_mode' => !empty($voc['i18n_mode']) ? $voc['i18n_mode'] : 1);
    taxonomy_vocabulary_save($v);
  }
  foreach ($voc->terms as $term) {
    if (!$t = dvtoolbox_get_taxonomy_term_by_name($term->en, $v->vid)){
      _dvtoolbox_megaimport_create_term($term, $v);
    }
  }
  $context['message'] = t('Created vocabulary @vocname', array('@vocname' => $v->machine_name));
  $context['results']['vocabularies'][] = $context['message'];
}

function _dvtoolbox_megaimport_role_batch_do($role, &$context) {
  if (!empty($_SESSION['DEBUG'])) watchdog(__FUNCTION__, '!args', array('!args' => '<pre>' . print_r($role,1) , '</pre>'), WATCHDOG_INFO);
  if (!$r = user_role_load_by_name($role['id'])) {
    $r = (object) array('name' => $role['id']);
    user_role_save($r);
  }
  $new_perms = array($r->name => drupal_map_assoc($role->permissions));
  watchdog(__FUNCTION__, 'New permissions !permissions', array('!permissions' => print_r($new_perms, 1)), WATCHDOG_INFO);
  dvtoolbox_grant_permissions($new_perms);
  $context['message'] = t('Created role @rolename', array('@rolename' => $r->name));
  $context['results']['roles'][] = $context['message'];
}

function _dvtoolbox_megaimport_grant_batch_do($grant, &$context) {
  if (!empty($_SESSION['DEBUG'])) watchdog(__FUNCTION__, '!args', array('!args' => '<pre>' . print_r($grant,1) , '</pre>'), WATCHDOG_INFO);
  $new_perms = array($grant->id => drupal_map_assoc($grant->permissions));
  watchdog(__FUNCTION__, 'New permissions !permissions', array('!permissions' => print_r($new_perms, 1)), WATCHDOG_INFO);
  dvtoolbox_grant_permissions($new_perms);
  $context['message'] = t('Permissions assigned to role %rolename', array('%rolename' => $grant->id));
  $context['results']['grant'][] = $context['message'];
}

function dvtoolbox_megaimport_batch_finished($success, $results, $operations) {
  if ($success) {
    if (isset($results['vocabulary'])) drupal_set_message(format_plural(count($results['vocabulary']), '1 vocabulary imported', '@count vocabularies imported'), 'status');
    if (isset($results['roles'])) drupal_set_message(format_plural(count($results['roles']), '1 role imported', '@count roles imported'), 'status');
    if (isset($results['grant'])) drupal_set_message(format_plural(count($results['grant']), '1 grant imported', '@count grants imported'), 'status');
    if (isset($results['variables'])) drupal_set_message(format_plural(count($results['variables']), '1 variable imported', '@count variables imported'), 'status');
    if (isset($results['translations'])) drupal_set_message(format_plural(count($results['translations']), '1 translation imported', '@count translations imported'), 'status');
    if (isset($results['menu'])) drupal_set_message(format_plural(count($results['menu']), '1 menu imported', '@count menus imported'), 'status');
    if (isset($results['menu_links'])) drupal_set_message(format_plural(count($results['menu_links']), '1 menu link imported', '@count menu links imported'), 'status');
  }
  else {
    drupal_set_message(t('Something went wrong'), 'error');
  }
}


function _dvtoolbox_megaimport_translation_do($data, &$context) {
  if (file_exists($data['file'])) {
    require_once DRUPAL_ROOT . '/includes/locale.inc';
    $file = (object) array('filename' => basename($data['file']), 'uri' => $data['file']);
    $language = $data['language'];
    $type = isset($data['type']) ? $data['type'] : LOCALE_IMPORT_KEEP;
    $group = isset($data['group']) ? $data['group'] : "default";
    
    $sl = variable_get('i18n_string_source_language', FALSE);
    variable_set('i18n_string_source_language', 'en');
    _locale_import_po($file, $language, $type, $group);
    $message = t('Processed file %file', array('%file' => $file->uri));
    drupal_set_message($message, 'status');
    $context['message'] = $message;
    $context['results']['translations'][] = $context['message'];
    $context['finished'] = 1;
    if ($sl) variable_set('i18n_string_source_language', $sl);
  }
}


function _dvtoolbox_megaimport_variable_do($data, &$context) {
  static $valid_callbacks = array('dvtoolbox_to_array', 'dvtoolbox_get_role_ids', 'dvtoolbox_to_object');
  if (!empty($data['callback']) && in_array($data['callback'], $valid_callbacks)) $data['value'] = call_user_func($data['callback'], $data['value']);
  if (!empty($data['merge'])) $data['value'] = array_merge(variable_get($data['name'], array()), $data['value']);
  variable_set($data['name'], $data['value']);
  $context['message'] = t('Variable @name set', array('@name' => $data['name']));
  $context['results']['variables'][] = $context['message'];
  $context['finished'] = 1;
}

function dvtoolbox_to_array($value) {
  return (array) $value;
}

function dvtoolbox_to_object($value) {
  return (object) $value;
}

function dvtoolbox_get_role_ids($roles) {
  $ids = array();
  foreach ($roles as $name) {
    if ($r = user_role_load_by_name($name)) {
      $ids[$r->rid] = $r->rid;
    }
  }
  return $ids;
}

function _dvtoolbox_megaimport_menu_do($data, &$context) {
  $menu = array();
  $menu['menu_name'] = $data['id'];
  $menu['i18n_mode'] = !empty($data['i18n_mode']) ? $data['i18n_mode'] : 5;
  $menu['language'] = !empty($data['language']) ? $data['language'] : 'und';
  $menu['title'] = $data['title'];
  $menu['description'] = !empty($data['description']) ? $data['description'] : '';
  menu_save($menu);
  if (!empty($data['translations'])) {
    foreach ((array)$data['translations'] as $field => $translations) {
      foreach ((array)$translations as $langcode => $translation) {
        i18n_string_translation_update('menu:menu:' . $menu['menu_name'] . ':' . $field , $translation, $langcode);
      }
    }
  }
  $context['message'] = t('Menu @name saved', array('@name' => $menu['title']));
  $context['results']['menu'][] = $context['message'];
  $context['finished'] = 1;
}

function _dvtoolbox_megaimport_menu_link_do($data, &$context) {
  $menu_link = isset($context['menu_link']) ? $context['menu_link'] : array();
  $menu_link['menu_name'] = $data['menu'];
  $menu_link['language'] = !empty($data['language']) ? $data['language'] : 'und';
  $menu_link['link_title'] = $data['title'];
  $menu_link['link_path'] = $data['path'];
  $menu_link['options'] = !empty($data['options']) ? $data['options'] : array();
  if (isset($menu_link['localized_options'])) $menu_link['localized_options'] = $menu_link['options'];
  $menu_link['customized'] = TRUE;
  $menu_link['weight'] = !empty($data['weight']) ? $data['weight'] : 0;
  $menu_link['expanded'] = !empty($data['expanded']) ? 1 : 0;
  if (!empty($data['parent'])) {
    $menu_link['plid'] = !empty($context['results']['parents']['menu'][$data['parent']]) ? $context['results']['parents']['menu'][$data['parent']] : 0;
  }
  menu_link_save($menu_link);
  $context['results']['parents']['menu'][$data['id']] = $menu_link['mlid'];
  if (!empty($data['translations'])) {
    foreach ($data['translations'] as $field => $translations) {
      foreach ($translations as $langcode => $translation) {
        i18n_string_translation_update('menu:item:' . $menu_link['mlid'] . ':' . $field , $translation, $langcode, $data[$field]);
      }
    }
  }
  $context['message'] = t('Menu link @name saved', array('@name' => $menu_link['link_title']));
  $context['results']['menu_links'][] = $context['message'];
  $context['finished'] = 1;
}
