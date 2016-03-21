<?php
function dvtoolbox_field_create_instances($entity_type, $new_instances) {
  $msgs = array();
  $t = get_t();
  foreach ($new_instances as $bundle => $instances) {
    $existing = array_map(function ($a) { return $a['field_name'];}, field_read_instances(array('entity_type' => $entity_type, 'bundle' => $bundle)));
    foreach ($instances as $field_name => $instance) {
      $instance['field_name'] = $field_name;
      $instance['entity_type'] = $entity_type;
      $instance['bundle'] = $bundle;
      try {
        if (!field_read_instance($instance['entity_type'], $field_name, $instance['bundle'])) {
          field_create_instance($instance);
          $msgs[] = $t('Created field instance !field in !bundle', array('!field' => $instance['field_name'], '!bundle' => $instance['bundle']));
          drupal_set_message($t('Created field instance !field in !bundle', array('!field' => $instance['field_name'], '!bundle' => $instance['bundle'])), 'status');
        }
        elseif (in_array($field_name, $existing)){
          field_update_instance($instance);
          $msgs[] = $t('Updated field instance !field in !bundle', array('!field' => $instance['field_name'], '!bundle' => $instance['bundle']));
        }
      }
      catch (Exception $e) {
        $message = $t("Exception !e on field instance !bundle:!field", array('!e' => $e->getMessage(), '!field' => $instance['field_name'], '!bundle' => $instance['bundle']));
        drupal_set_message($message, 'error');
        $msgs[] = $message;
        if (empty($_SESSION['skip_instance_errors'])) throw $e;
      }
    }
  }
  return $msgs;
}

function dvtoolbox_field_create_fields($fields) {
  $msgs = array();
  $t = get_t();
  foreach ($fields as $field_name => $field) {
    try {
      $field['field_name'] = $field_name;
      if (!$existing = field_read_field($field['field_name'])) {
        field_create_field($field);
        $msgs[] = $t('Created field !field', array('!field' => $field['field_name']));
      }
      else {
        if ($existing['type'] != $field['type']) {
          switch($existing['type']) {
            case 'text_with_summary':
            	 db_update('field_config')->fields(array('type' => $field['type']))->condition('id', $existing['id'])->execute();
            break;
          }
        }
        if (!empty($existing['settings']['max_length']) && !empty($field['settings']['max_length']) && ($existing['type'] == 'text') && ($existing['settings']['max_length'] < $field['settings']['max_length'])) {
          drupal_set_message('Editando campo ' . $field['field_name'], 'status');
          db_query("alter table field_data_{$field['field_name']} change column {$field['field_name']}_value {$field['field_name']}_value varchar({$field['settings']['max_length']})");
          $r = db_select('field_config', 'f')->fields('f')->condition('field_name', $field['field_name'])->execute()->fetch();
          $r->data = unserialize($r->data);
          $r->data['settings']['max_length'] = $field['settings']['max_length'];
          db_update('field_config')->fields(array('data' => serialize($r->data)))->condition('id', $existing['id'])->execute();
        }
        field_cache_clear();
        field_update_field($field);
        $msgs[] = $t('Updated field !field', array('!field' => $field['field_name']));
      }
    }
    catch (Exception $e) {
      drupal_set_message($t("Exception !e on field: !field", array('!e' => $e->getMessage(), '!field' => $field['field_name'])), 'error');
      throw $e;
    }
  }
  return $msgs;
}

function dvtoolbox_field_create_groups($entity_type, $new_groups) {
  $msgs = array();
  if (module_exists('field_group') && function_exists('ctools_include')) {
    $default_field_group = variable_get('default_field_group', array());
    $t = get_t();
    ctools_include('export');
    foreach ($new_groups as $bundle => $group_mode) {
      foreach ($group_mode as $mode => $groups) {
        foreach ($groups as $group_name => $group) {
          try {
            $group->group_name = $group_name;
            $group->entity_type = $entity_type;
            $group->bundle = $bundle;
            $group->mode = $mode;
            $group->identifier = $group_name . '|' . $entity_type . '|' . $bundle . '|' . $mode;
            if ($old_group = field_group_load_field_group($group->group_name, $group->entity_type, $group->bundle, $group->mode)) {
              $old_group->label = $group->label;
              $old_group->children = array_unique(array_merge((array)$old_group->children, (array)$group->children));
              $old_group->mode = $group->mode;
              $old_group->weight = $group->weight;
              $old_group->format_type = $group->format_type;
              $old_group->format_settings = $group->format_settings;
              field_group_group_save($old_group);
              //dpm(array('merged' => array_merge((array)$old_group->children, (array)$group->children), 'old_group' => $old_group->children, 'group' => $group->children), $group->group_name);
              $msgs[] = $t('Updated group %group on %bundle (%mode)', array('%group' => $old_group->group_name, '%bundle' => $old_group->bundle, '%mode' => $old_group->mode));
            }
            else {
              $group->is_new = TRUE;
              $group->id = 0;
              field_group_group_save($group);
              $msgs[] = $t('Saved group %group on %bundle', array('%group' => $group->group_name, '%bundle' => $group->bundle));
            }
          }
          catch (Exception $e) {
            drupal_set_message($t("Exception !e on group %bundle: %group", array('!e' => $e->getMessage(), '%group' => $group->group_name, '%bundle' => $group->bundle)), 'error');
            throw $e;
          }
          if (isset($group->disabled)) {
            $default_field_group[$group->identifier] = $group->disabled;
          }
          else {
            unset($default_field_group[$group->identifier]);
          }
        }
      }
    }
    variable_set('default_field_group', $default_field_group);
  }
  return $msgs;
}
