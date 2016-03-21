<?php
$groups = array(
  'portales7_media' => array(
    'default' => array(
      'group_modo_media' => (object)array(
        'mode' => 'default',
        'parent_name' => '',
        'type' => 'Normal',
        'label' => '',
        'weight' => 0,
        'children' => array(
          0 => 'portales7_images',
          1 => 'portales7_fc_name',
          2 => 'portales7_fc_description',
          3 => 'portales7_video_url',
          4 => 'portales7_videos',
          5 => 'portales7_files',
        ),
        'format_type' => 'div',
        'format_settings' => array(
          'label' => '',
          'instance_settings' => array(
            'id' => '',
            'classes' => 'grup-relacionats grup-modo-media field-group-div',
            'description' => '',
            'show_label' => 1,
            'label_element' => 'h3',
            'effect' => 'none',
            'speed' => 'fast',
          ),
          'formatter' => 'open',
        ),
      ),
    ),
    'form' => array(
      'group_tabs' => (object)array(
        'mode' => 'form',
        'parent_name' => '',
        'type' => 'Normal',
        'label' => 'tabs',
        'weight' => 2,
        'children' => array(
          0 => 'group_tab_images',
          1 => 'group_tab_files',
          2 => 'group_tab_videos',
        ),
        'format_type' => 'htabs',
        'format_settings' => array(
          'formatter' => '',
          'instance_settings' => array(
            'classes' => 'group-tabs field-group-htabs',
          ),
        ),
      ),
      'group_tab_images' => (object)array(
        'mode' => 'form',
        'parent_name' => 'group_tabs',
        'type' => 'Normal',
        'label' => 'images',
        'weight' => 9,
        'children' => array(
          0 => 'portales7_images',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => 'group-tab-images field-group-htab',
            'required_fields' => 1,
            'id' => '',
          ),
        ),
      ),
      'group_tab_files' => (object)array(
        'mode' => 'form',
        'parent_name' => 'group_tabs',
        'type' => 'Normal',
        'label' => 'files',
        'weight' => 10,
        'children' => array(
          0 => 'portales7_files',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => 'group-tab-files field-group-htab',
            'required_fields' => 1,
            'id' => '',
          ),
        ),
      ),
      'group_tab_videos' => (object)array(
        'mode' => 'form',
        'parent_name' => 'group_tabs',
        'type' => 'Normal',
        'label' => 'video',
        'weight' => 11,
        'children' => array(
          0 => 'portales7_video_url',
          1 => 'portales7_videos',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => 'group-tab-videos field-group-htab',
            'required_fields' => 1,
            'id' => '',
          ),
        ),
      ),
    ),
  ),
);
