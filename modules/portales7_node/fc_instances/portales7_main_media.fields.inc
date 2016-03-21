<?php
$fields = array(
  'portales7_mm_image' => array(
    'settings' => array(
      'uri_scheme' => 'public',
      'default_image' => 0,
      'display_field' => 0,
      'display_default' => 1,
    ),
    'type' => 'image',
    'cardinality' => 1,
  ),
  'portales7_mm_video' => array(
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
    'cardinality' => 1,
  ),
  'portales7_mm_video_url' => array(
    'type' => 'video_embed_field',
    'cardinality' => 1,
  ),
);
