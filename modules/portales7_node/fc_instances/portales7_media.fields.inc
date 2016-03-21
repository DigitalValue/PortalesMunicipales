<?php
$fields = array(
  'portales7_images' => array(
    'settings' => array(
      'uri_scheme' => 'public',
      'default_image' => 0,
      'display_field' => 0,
      'display_default' => 1,
    ),
    'type' => 'image',
    'cardinality' => -1,
  ),
  'portales7_fc_name' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_fc_description' => array(
    'type' => 'text_long',
    'cardinality' => 1,
  ),
  'portales7_video_url' => array(
    'type' => 'video_embed_field',
    'cardinality' => -1,
  ),
  'portales7_videos' => array(
    'settings' => array(
      'uri_scheme' => 'public',
      'uri_scheme_converted' => 'public',
      'uri_scheme_thumbnails' => 'public',
      'autoconversion' => 1,
      'thumbnail_format' => 'jpg',
      'autothumbnail' => 'manual_upload',
      'default_video_thumbnail' => array(
        'fid' => 0,
        'upload_button' => 'Upload',
        'remove_button' => 'Delete',
        'upload' => '',
      ),
      'preview_video_thumb_style' => 'thumbnail',
      'presets' => array(),
      'display_field' => 1,
      'display_default' => 1,
    ),
    'type' => 'video',
    'cardinality' => -1,
  ),
  'portales7_files' => array(
    'settings' => array(
      'display_field' => 1,
      'display_default' => 1,
      'uri_scheme' => 'public',
    ),
    'type' => 'file',
    'cardinality' => -1,
  ),
);
