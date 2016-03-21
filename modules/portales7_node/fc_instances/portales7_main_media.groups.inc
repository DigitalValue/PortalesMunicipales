<?php
$groups = array(
  'portales7_main_media' => array(
    'form' => array(
      'group_image' => (object)array(
        'mode' => 'form',
        'parent_name' => 'group_main_media',
        'type' => 'Normal',
        'label' => 'Image',
        'weight' => 1,
        'children' => array(
          0 => 'portales7_mm_image',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'label' => 'Image',
          'instance_settings' => array(
            'required_fields' => 1,
            'id' => '',
            'classes' => 'group-image field-group-htab',
            'description' => '',
          ),
          'formatter' => 'closed',
        ),
      ),
      'group_main_media' => (object)array(
        'mode' => 'form',
        'parent_name' => '',
        'type' => 'Normal',
        'label' => 'Main Media',
        'weight' => 0,
        'children' => array(
          0 => 'group_image',
          1 => 'group_video',
          2 => 'group_video_url',
        ),
        'format_type' => 'htabs',
        'format_settings' => array(
          'label' => 'Main Media',
          'instance_settings' => array(
            'classes' => 'group-main-media field-group-htabs',
          ),
        ),
      ),
      'group_video' => (object)array(
        'mode' => 'form',
        'parent_name' => 'group_main_media',
        'type' => 'Normal',
        'label' => 'Video',
        'weight' => 2,
        'children' => array(
          0 => 'portales7_mm_video',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'label' => 'Video',
          'instance_settings' => array(
            'required_fields' => 1,
            'id' => '',
            'classes' => 'group-video field-group-htab',
            'description' => '',
          ),
          'formatter' => 'closed',
        ),
      ),
      'group_video_url' => (object)array(
        'mode' => 'form',
        'parent_name' => 'group_main_media',
        'type' => 'Normal',
        'label' => 'Media URL',
        'weight' => 3,
        'children' => array(
          0 => 'portales7_mm_video_url',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => 'group-video-url field-group-htab',
            'required_fields' => 1,
            'id' => '',
          ),
        ),
      ),
    ),
  ),
);
