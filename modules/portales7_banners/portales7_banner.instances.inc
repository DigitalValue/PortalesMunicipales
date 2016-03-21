<?php
$instances = array(
  'portales7_banners_image' => array(
    'field_name' => 'portales7_banners_image',
    'label' => 'Banner Image',
    'required' => FALSE,
    'widget' => array(
      'type' => 'image_image',
      'weight' => 9,
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'imce' => 'imce',
            'upload' => 0,
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
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
        'styles' => array(
          'banner-200' => 'banner-200',
          'banner-250' => 'banner-250',
          'banner-300' => 'banner-300',
        ),
      ),
    ),
  ),
  'portales7_banners_group' => array(
    'label' => 'Group',
    'widget' => array(
      'weight' => 3,
      'type' => 'term_reference_tree',
      'settings' => array(
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
        'weight' => 5,
      ),
    ),
    'required' => 1,
    'description' => 'Select which groups this banner belongs to.',
    'field_name' => 'portales7_banners_group',
  ),
  'portales7_banners_node' => array(
    'label' => 'Node',
    'widget' => array(
      'weight' => 6,
      'type' => 'node_reference_autocomplete',
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'node_reference_default',
        'weight' => 8,
      ),
    ),
    'field_name' => 'portales7_banners_node',
  ),
  'portales7_banners_weight' => array(
    'label' => 'Weight',
    'widget' => array(
      'weight' => 7,
      'type' => 'options_select',
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'required' => 1,
    'default_value' => array(
      0 => array(
        'value' => 10,
      ),
    ),
    'field_name' => 'portales7_banners_weight',
  ),
  'portales7_banners_overlay' => array(
    'label' => 'Overlay',
    'widget' => array(
      'weight' => 8,
      'type' => 'text_textarea',
      'settings' => array(
        'rows' => 15,
      ),
    ),
    'settings' => array(
      'text_processing' => 1,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'field_name' => 'portales7_banners_overlay',
  ),
  'portales7_banners_target' => array(
    'label' => 'Target',
    'widget' => array(
      'weight' => 5,
      'type' => 'options_select',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'required' => 1,
    'default_value' => array(
      0 => array(
        'value' => '_self',
      ),
    ),
    'field_name' => 'portales7_banners_target',
  ),
  'portales7_banners_url' => array(
    'label' => 'Link',
    'widget' => array(
      'weight' => 4,
      'type' => 'text_textfield',
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_plain',
        'weight' => 2,
      ),
    ),
    'field_name' => 'portales7_banners_url',
  ),
);