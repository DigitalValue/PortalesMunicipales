<?php
function _portales7_node_field_update_needed() {
  require(dirname(__FILE__) . '/portales7_node.instances.inc');
  $existing = field_read_instances(array('entity_type' => 'node', 'bundle' => 'portales7_node'));
  $messages = array();
  foreach ($existing as $instance) {
    if (!empty($instances[$instance['field_name']])) {
      $message = "Updated field instance " . $instance['field_name'];
      $instance['weight'] = $instances[$instance['field_name']]['weight'];
      $instance['label'] = $instances[$instance['field_name']]['label'];
      $instance['description'] = $instances[$instance['field_name']]['description'];
      $instance['settings'] = $instances[$instance['field_name']]['settings'];
      $instance['widget'] = $instances[$instance['field_name']]['widget'];
      unset($instance['display']['portales7_entity_building']);
      unset($instance['display']['portales7_entity_person']);
      foreach ($instances[$instance['field_name']]['display'] as $k => $v) {
        $instance['display'][$k] = $v;
      }
      field_update_instance($instance);
      unset($instances[$instance['field_name']]);
      $messages[] = $message;
    }
  }

  require(dirname(__FILE__) . '/fc_instances/portales7_media.instances.inc');
  $existing = field_read_instances(array('entity_type' => 'field_collection_item', 'bundle' => 'portales7_media'));
  $messages = array();
  foreach ($existing as $instance) {
    if (!empty($instances[$instance['field_name']])) {
      $message = "Updated field instance " . $instance['field_name'];
      $instance['weight'] = $instances[$instance['field_name']]['weight'];
      $instance['label'] = $instances[$instance['field_name']]['label'];
      $instance['description'] = $instances[$instance['field_name']]['description'];
      $instance['settings'] = $instances[$instance['field_name']]['settings'];
      $instance['widget'] = $instances[$instance['field_name']]['widget'];
      unset($instance['display']['portales7_entity_building']);
      unset($instance['display']['portales7_entity_person']);
      foreach ($instances[$instance['field_name']]['display'] as $k => $v) {
        $instance['display'][$k] = $v;
      }
      field_update_instance($instance);
      unset($instances[$instance['field_name']]);
      $messages[] = $message;
    }
  }
  
  module_load_include('field.inc', 'dvtoolbox');
  module_load_include('node.inc', 'portales7_node');
  dvtoolbox_field_create_groups('node', _portales7_node_installed_field_groups());
  return join("\n", $messages);
}
