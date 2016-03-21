<?php
/**
 * Implements hook_node_info()
 */

function _portales7_banners_node_info() {
  // We define the node type as an associative array.
  return array(
    'portales7_banner' => array(
      'name' => 'Portales 7 Banner',
      // 'base' tells Drupal the base string for hook functions.
      // This is often the module name; if base is set to 'mymodule',
      // Drupal would call mymodule_insert() or similar for node
      // hooks. In our case, the base is 'node_example'.
      'base' => 'node_content',
      'description' => 'A content type for banners',
      'title_label' =>'Title',
      // We'll set the 'locked' attribute to TRUE, so users won't be
      // able to change the machine name of our content type.
      'locked' => TRUE,
    ),
  );
}

/**
 * Implements hook_node_type_insert().
 */
function _portales7_banners_node_type_insert($content_type) {
  if ($content_type->type == 'portales7_banner') {
    // Create all the fields we are adding to our content type.
    module_load_include('field.inc', 'dvtoolbox');
    //field_cache_clear();
    dvtoolbox_field_create_fields(_portales7_banners_installed_fields());
    dvtoolbox_field_create_instances('node', array('portales7_banner' => _portales7_banners_installed_instances()));
    variable_set('node_submitted_portales7_banner', FALSE);
    variable_set('node_options_portales7_banner', array('status', 'promote'));
    
    //_node_types_build(TRUE);
    $new_perms = array(
      'redactor' => array(
        'create portales7_banner content',
        'delete any portales7_banner content',
        'delete own portales7_banner content',
        'edit any portales7_banner content',
        'edit own portales7_banner content',
      ),
      'webmaster' => array(
        'create portales7_banner content',
        'delete any portales7_banner content',
        'delete own portales7_banner content',
        'edit any portales7_banner content',
        'edit own portales7_banner content',
      ),
    );
    dvtoolbox_grant_permissions($new_perms);
  }
}

function _portales7_banners_installed_fields() {
  $fields = array (
    'portales7_banners_group' => array(
      'field_name' => 'portales7_banners_group',
      'type' => 'taxonomy_term_reference',
      'cardinality' => -1,
      'settings' => array(
        'allowed_values' => array (
          array('vocabulary' => 'banners', 'parent' => 0),
        ),
      ),
    ),
    'portales7_banners_image' => array(
      'field_name' => 'portales7_banners_image',
      'type' => 'image',
      'cardinality' => 1,
    ),
    'portales7_banners_node' => array(
      'settings' => array (
        'referenceable_types' => array(
          'portales7_node' => 'portales7_node',
          'portales7_entity' => 'portales7_entity',
          'webform' => 'webform',
        ),
      ),
      'field_name' => 'portales7_banners_node',
      'type' => 'node_reference',
      'module' => 'node_reference',
      'cardinality' => '1',
    ),
  'portales7_banners_weight' => array(
    'settings' => array(
      'allowed_values' => range(0, 20, 1),
    ),
    'field_name' => 'portales7_banners_weight',
    'type' => 'list_integer',
    'cardinality' => '1',
  ),
  'portales7_banners_overlay' => array(
    'field_name' => 'portales7_banners_overlay',
    'type' => 'text_long',
    'cardinality' => '1',
  ),
  'portales7_banners_target' => array(
    'settings' => array(
      'allowed_values' => array(
        '_blank' => 'New window',
        '_self' => 'Same window',
        '_top' => 'Top window',
      ),
    ),
    'field_name' => 'portales7_banners_target',
    'type' => 'list_text',
    'cardinality' => '1',
  ),
  'portales7_banners_url' => array(
    'settings' => array(
      'max_length' => '255',
    ),
    'field_name' => 'portales7_banners_url',
    'type' => 'text',
    'cardinality' => '1',
  ),
);
  return $fields;
}

function _portales7_banners_installed_instances() {
  include(dirname(__FILE__) . '/portales7_banner.instances.inc');
  foreach ($instances as $field_name => &$instance) {
    if (!empty($instance['settings']['epsacrop']['styles']))
      $instance['settings']['epsacrop']['styles'] = dvtoolbox_epsacrop_styles(portales7_banners_image_default_styles());
  }
  return $instances;
  $fields = array (
  'portales7_banners_image' => array(
    'field_name'  => 'portales7_banners_image',
    'label'       => 'Banner Image',
    'required'    => FALSE,
    'widget' => array(
      'type'    => 'image_image',
      'weight'  => 9,
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'imce' => 'imce',
            'upload' => 0,
          ),
          'source_imce' => array('imce_mode' => 1),
        ),
      ),
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'weight' => 0,
        'settings' => array(
          'image_style' => '',
          'image_link' => '',
        ),
        'module' => 'image',
      ),
    ),
    'settings' => array(
      'file_directory' => 'carteles/[current-date:custom:Ym]',
      'file_extensions' => 'png jpg jpeg gif tiff',
      'max_filesize' => '32MB',
      'alt_field' => 1,
      'title_field' => 1,
      'epsacrop' => array(
        'styles' => dvtoolbox_epsacrop_styles(portales7_banners_image_default_styles()),
      ),
    ),
  ),
  'portales7_banners_group' => array(
    'label' => 'Group',
    'widget' => array (
      'weight' => '3',
      'type' => 'term_reference_tree',
      'settings' => array (
        'start_minimized' => 0,
        'leaves_only' => 0,
        'select_parents' => 0,
        'cascading_selection' => 0,
        'filter_view' => '',
        'token_display' => '',
        'track_list' => 1,
        'max_depth' => '',
        'parent_term_id' => '',
      ),
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'weight' => '5',
      ),
    ),
    'required' => 1,
    'description' => 'Seleccione los grupos de carteles a los que pertenecerá este cartel.',
    'field_name' => 'portales7_banners_group',
  ),
  'portales7_banners_node' => array(
    'label' => 'Node',
    'widget' => array(
      'weight' => '6',
      'type' => 'node_reference_autocomplete',
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'node_reference_default',
        'weight' => '8',
      ),
    ),
    'field_name' => 'portales7_banners_node',
  ),
  'portales7_banners_weight' =>array(
    'label' => 'Weight',
    'widget' => array(
      'weight' => '7',
      'type' => 'options_select',
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'list_default',
        'weight' => '6',
      ),
    ),
    'required' => 1,
    'default_value' => array(0 => array('value' => '10'),
    ),
    'field_name' => 'portales7_banners_weight',
  ),
  'portales7_banners_overlay' => array(
    'label' => 'Overlay',
    'widget' => array(
      'weight' => '8',
      'type' => 'text_textarea',
      'settings' => array('rows' => '15'),
    ),
    'settings' => array(
      'text_processing' => '1',
    ),
    'display' => array (
      'default' => array (
        'label' => 'above',
        'type' => 'text_default',
        'weight' => '7',
      ),
    ),
    'field_name' => 'portales7_banners_overlay',
  ),
  'portales7_banners_target' => array(
    'label' => 'Target',
    'widget' => array(
      'weight' => '5',
      'type' => 'options_select',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'list_default',
        'weight' => '0',
      ),
    ),
    'required' => 1,
    'default_value' => array( array('value' => '_self')),
    'field_name' => 'portales7_banners_target',
  ),
  'portales7_banners_url' => array(
    'label' => 'Link',
    'widget' => array(
      'weight' => '4',
      'type' => 'text_textfield',
    ),
    'settings' => array(
      'text_processing' => '0',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_plain',
        'weight' => '2',
      ),
    ),
    'field_name' => 'portales7_banners_url',
  ),
);
  return $fields;
}
