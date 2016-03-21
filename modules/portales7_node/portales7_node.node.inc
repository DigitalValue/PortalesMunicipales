<?php
function portales7_node_default_view_modes() {
  $filename = dirname(__FILE__) . '/portales7_node.view_modes.inc';
  $view_modes = array();
  if (file_exists($filename)) {
    include($filename);
  }
  return $view_modes;
}


function portales7_node_default_extra_fields() {
  $filename = dirname(__FILE__) . '/portales7_node.extra_fields.inc';
  $extra_fields = array();
  if (file_exists($filename)) {
    include($filename);
  }
  return $extra_fields;
}


/**
 * Implements hook_node_info();
 */
function _portales7_node_node_info(){
  $view_modes = portales7_node_default_view_modes();

  $info = array(
    'portales7_node' => array (
      'name' => 'Portales 7 Article',
      'base' => 'node_content',
      'description' => 'This is the base content type for Portales 7.',
      'title_label' => 'Title',
      'locked' => TRUE,
      'view_modes' => $view_modes,
    ),
  );
  return $info;
}

/**
 * Implements hook_node_type_insert().
 */
function _portales7_node_node_type_insert($content_type) {
  $view_modes = array();
  foreach($content_type->view_modes as $vm => $name) {
      $view_modes[$vm] = array('custom_settings' => TRUE);
  }
  $extra_fields = array();
  foreach($view_modes as $view_mode => $info) {
    $extra_fields['display']['language'][$view_mode]['visible'] = FALSE;
  }
  $extra_fields['display']['language']['default'] ['visible'] = FALSE;
  field_bundle_settings('node', 'portales7_node', array('view_modes' => $view_modes, 'extra_fields' => $extra_fields));
  
  module_load_include('fc.inc', 'portales7_node');
  module_load_include('field.inc', 'dvtoolbox');
  
  //Create required vocabularies
  module_load_include('taxonomy.inc', 'portales7_node');
  _portales7_node_create_vocabularies();
  
  ctools_include('export');
  $t = get_t();

  _portales7_node_setup_title_field();

 
  //Set content type options
  variable_set('node_options_' . $content_type->type, array('status','promote'));
  variable_set('node_submitted_portales7_node', FALSE);
  
  //Configure pathauto
  variable_set('pathauto_node_portales7_node_pattern', '[node:portales7_section]/[node:portales7_type]/[node:title]');
  
  //Configure type for save_edit
  $se_types = variable_get('save_edit_node_types', array());
  $se_types['portales7_node'] = 'portales7_node';
  variable_set('save_edit_node_types', $se_types);
  
  
  
  //Configure link type
  $t = dvtoolbox_get_taxonomy_term_by_name('link', 'type', TRUE, 0);
  variable_set('portales7_node_link_tid', $t->tid);
  
  //Activem la plantilla de nodo
  variable_set('page_manager_node_view_disabled', 0);
  menu_rebuild();
  
  drupal_set_message(t('Portales 7 Node has been installed successfully'));
  module_load_include('translations.inc', 'portales7_profile');
  if ($batch = portales7_profile_update_translations_batch_prepare()){
    batch_set($batch);
  }
}



 /* 
 *//**
 * Returns a structured array defining the fields created by this content type.
 *
 * This is factored into this function so it can be used in both
 * portales7_node_install() and portales7_node_uninstall().
 *
 * @return
 *  An associative array specifying the fields we wish to add to our
 *  new node type.
 *
 * @ingroup portales7_node
 */
function _portales7_node_installed_fields() {
  include(dirname(__FILE__) . '/portales7_node.fields.inc');
  return $fields;
}

/**
 * Returns a structured array defining the instances for this content type.
 *
 * The instance lets Drupal know which widget to use to allow the user to enter
 * data and how to react in different view modes.  We are going to display a
 * page that uses a custom "portales7_node_list" view mode.  We will set a
 * cardinality of three allowing our content type to give the user three color
 * fields.
 *
 * This is factored into this function so it can be used in both
 * portales7_node_install() and portales7_node_uninstall().
 *
 * @return
 *  An associative array specifying the instances we wish to add to our new
 *  node type.
 *
 * @ingroup portales7_node
 */
function _portales7_node_installed_instances() {
  include(dirname(__FILE__) . '/portales7_node.instances.inc');
  foreach ($instances as $field_name => &$instance) {
    if (!empty($instance['widget']['type']) && $instance['widget']['type'] == 'image_image')
      $instance['settings']['epsacrop']['styles'] = dvtoolbox_epsacrop_styles(portales7_image_default_styles());
  }
  return $instances;
}

function _portales7_node_installed_field_groups() {
  include(dirname(__FILE__) . '/portales7_node.groups.inc');
  return $groups;
}


function _portales7_node_add_fields($newfields = array()) {
  $fields = _portales7_node_installed_fields();
  $instances = _portales7_node_installed_instances();
  $node_info = portales7_node_node_info();
  $portales7_node = $node_info['portales7_node'];
  $addfields = array();
  $addinstances = array();
  foreach ($newfields as $newfield) {
    if (!empty($fields[$newfield])){
      $addfields[$newfield] = $fields[$newfield];
    }
    if (!empty($instances[$newfield])) {
      $addinstances[$newfield] = $instances[$newfield];
    }
  }
  module_load_include('field.inc', 'dvtoolbox');
  dvtoolbox_field_create_fields($addfields);
  dvtoolbox_field_create_instances('node', array('portales7_node' => $addinstances));
}

function _portales7_node_fix_field_weight() {
  include(dirname(__FILE__) . '/portales7_node.instances.inc');
  foreach ($instances as $field_name => &$instance) {
    if ($oi = field_read_instance('node', $field_name, 'portales7_node')) {
      $update = FALSE;
      if ($oi['widget']['weight'] != $instance['widget']['weight']) {
        $oi['widget']['weight'] = $instance['widget']['weight'];
        $update = TRUE;
      }
      foreach (array('teaser', 'default') as $display) {
        if (isset($oi['display'][$display]['weight']) && isset($instance['display'][$display]['weight'])
            && ($oi['display'][$display]['weight'] != $instance['display'][$display]['weight'])) {
          $oi['display'][$display]['weight'] = $instance['display'][$display]['weight'];
          $update = TRUE;
        }
      }
      if ($update){
        drupal_set_message('updating '. $oi['field_name'], 'status');
        field_update_instance($oi);
      } 
    }
  }
  return $instances;
}
