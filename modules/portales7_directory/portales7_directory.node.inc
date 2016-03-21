<?php
function portales7_directory_default_view_modes() {
  $filename = dirname(__FILE__) . '/portales7_entity.view_modes.inc';
  $view_modes = array();
  if (file_exists($filename)) {
    include($filename);
  }
  return $view_modes;
}

/**
 * Implements hook_node_info()
 */
function _portales7_directory_node_info() {
  return array(
    'portales7_entity' => array(
      'name' => 'Portales 7 Entity',
      'base' => 'node_content',
      'description' => 'A content type for entities',
      'title_label' => 'Title',
      'locked' => TRUE,
      'view_modes' => portales7_directory_default_view_modes(),
    ),
  );
}

/**
 * Implements hook_node_type_insert().
 */
function _portales7_directory_node_type_insert($content_type) {
  $view_modes = array();
  foreach($content_type->view_modes as $vm => $name) {
    $view_modes[$vm] = array('custom_settings' => TRUE);
  }
  field_bundle_settings('node', 'portales7_entity', array('view_modes' => $view_modes));
  module_load_include('fc.inc', 'portales7_directory');
  module_load_include('field.inc', 'dvtoolbox');
  foreach (_portales7_directory_installed_vocabularies() as $voc_name => $voc) {
    $voc->machine_name = $voc_name;
    if (!taxonomy_vocabulary_machine_name_load($voc->machine_name)) {
      taxonomy_vocabulary_save($voc);
    }
  }

  foreach (_portales7_directory_installed_terms() as $voc => $terms){
    foreach ($terms as $parent => $childs) {
      if (!is_numeric($parent)) {
        $pt = dvtoolbox_get_taxonomy_term_by_name($parent, $voc, TRUE, 0);
        $parent = $pt->tid;
      }
      foreach ($childs as $t) {
        dvtoolbox_get_taxonomy_term_by_name($t, $voc, TRUE, $parent);
        //drupal_set_message(t('Term @term has been created on @voc', array('@term' => $t, '@voc' => $voc)), 'status');
      }
    }
  }

  _portales7_directory_setup_title_field();
  // Create all the fields we are adding to our content type.
  dvtoolbox_field_create_fields(_portales7_directory_installed_fields());
  _portales7_directory_create_fc_fields();
  // Create all the instances for our fields.
  field_cache_clear();
  $instances = _portales7_directory_installed_instances();
  //unset($instances['title_field']);
  dvtoolbox_field_create_instances('node', array('portales7_entity' => $instances));
  _portales7_directory_create_fc_field_instances();
  dvtoolbox_field_create_groups('node', _portales7_directory_installed_field_groups());
  _portales7_directory_create_fc_groups();
  
  $se_types = variable_get('save_edit_node_types', array());
  $se_types['portales7_entity'] = 'portales7_entity';
  variable_set('save_edit_node_types', $se_types);
  variable_set('node_submitted_portales7_entity', FALSE);
  // Actualisem el camp portales7_event_type per a que puga referenciar l'entitat
  if ($field = field_read_field('portales7_event_place')) {
    $field['settings']['referenceable_types']['portales7_entity'] = 'portales7_entity';
    field_update_field($field);
  }
}

function _portales7_directory_setup_title_field() {
  variable_set('title_node', 
    array(
      'auto_attach' => array(
        'title' => 'title',
      ),
      'hide_label' => array(
        'page' => 'page',
        'entity' => 0,
      ),
    )
  );
  title_field_replacement_toggle('node', 'portales7_entity', 'title');
  title_field_replacement_batch_set('node', 'portales7_entity', 'title');
}


function _portales7_directory_installed_fields() {
  include(dirname(__FILE__) . '/portales7_entity.fields.inc');
  return $fields;
}

function _portales7_directory_installed_instances() {
  include(dirname(__FILE__) . '/portales7_entity.instances.inc');
  foreach ($instances as $field_name => &$instance) {
    if (!empty($instance['widget']['type']) && $instance['widget']['type'] == 'image_image')
      $instance['settings']['epsacrop']['styles'] = dvtoolbox_epsacrop_styles(portales7_image_default_styles());
  }
  return $instances;
}

function _portales7_directory_installed_vocabularies() {
  return array(
    'entity_type' => (object) array(
      'vid' => 0,
      'name' => 'Entity type',
      'description' => 'A vocabulary for Portales 7 Entity types',
      'hierarchy' => 0,
      'module' => 'portales7_directory',
      'i18n_mode' => 1,
    ),
    'entity_category' => (object) array(
      'vid' => 0,
      'name' => 'Entity category',
      'description' => 'A vocabulary for Portales 7 Directory categories',
      'hierarchy' => 0,
      'module' => 'portales7_directory',
      'i18n_mode' => 1,
    ),
  );
}

function _portales7_directory_installed_terms() {
  return array(
    'entity_type' => array(),
    'entity_category' => array(
      0 => array('telefonos de interes'),
    ),
  );
}

function _portales7_directory_installed_field_groups() {
  include(dirname(__FILE__) . '/portales7_entity.groups.inc');
  return $groups;
}
