<?php
function _portales7_directory_fc_instances() {
  $field_instances = array();
  $files = glob(dirname(__FILE__) . '/fc_instances/*.instances.inc');
  foreach($files as $file) {
    $instances = NULL;
    include($file);
    $field_instances[basename($file, '.instances.inc')] = $instances;
  }
  return $field_instances;
}

function _portales7_directory_fc_fields() {
  $field_fields = array();
  $files = glob(dirname(__FILE__) . '/fc_instances/*.fields.inc');
  foreach($files as $file) {
    $fields = NULL;
    include($file);
    $field_fields[basename($file, '.fields.inc')] = $fields;
  }
  return $field_fields;
}

function _portales7_directory_fc_groups() {
  $field_groups = array();
  $files = glob(dirname(__FILE__) . '/fc_instances/*.groups.inc');
  foreach($files as $file) {
    $groups = NULL;
    include($file);
    if (is_array($groups)) {
      $field_groups = array_merge($field_groups, $groups);
    }
  }
  return $field_groups;
}

function _portales7_directory_fc_view_modes($fieldname = '', $reset = FALSE) {
  $vms = &drupal_static(__FUNCTION__);
  if (empty($vms) || RESET) {
    $vms = array();
    $files = glob(dirname(__FILE__) . '/fc_instances/*.view_modes.inc');
    foreach($files as $file) {
      $view_modes = NULL;
      include($file);
      $vms[basename($file, '.view_modes.inc')] = $view_modes;
    }
  }
  if (!empty($fieldname)) return $vms[$fieldname];
  return $vms;
}

function _portales7_directory_create_fc_fields() {
  module_load_include('field.inc', 'dvtoolbox');
  foreach (_portales7_directory_fc_fields() as $bundle => $fields) {
    dvtoolbox_field_create_fields($fields);
  }
}

function _portales7_directory_create_fc_field_instances() {
  $m = array();
  module_load_include('field.inc', 'dvtoolbox');
  $fc_instances =  _portales7_directory_fc_instances();
  foreach ($fc_instances as $fieldname => $v) {
    $bs = field_bundle_settings('field_collection_item', $fieldname);
    if ($view_modes = _portales7_directory_fc_view_modes($fieldname)) {
      $bs['view_modes'] = $view_modes;
      field_bundle_settings('field_collection_item', $fieldname, $bs);
    }
  }
  $m += dvtoolbox_field_create_instances('field_collection_item', $fc_instances);
  return $m;
}

function _portales7_directory_create_fc_groups() {
  module_load_include('field.inc', 'dvtoolbox');
  dvtoolbox_field_create_groups('field_collection_item', _portales7_directory_fc_groups());
}
