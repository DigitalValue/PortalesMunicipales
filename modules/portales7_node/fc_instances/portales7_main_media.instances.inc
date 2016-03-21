<?php
$instances = array(
  'portales7_mm_image' => array(
    'label' => 'Image',
    'widget' => array(
      'weight' => 2,
      'type' => 'image_image',
      'module' => 'image',
      'active' => 1,
      'settings' => array(
        'progress_indicator' => 'bar',
        'preview_image_style' => 'thumbnail',
        'filefield_sources' => array(
          'filefield_sources' => array(
            'imce' => 'imce',
            'upload' => 0,
            'remote' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'attach' => 0,
          ),
          'source_attach' => array(
            'path' => 'file_attach',
            'absolute' => 0,
            'attach_mode' => 'move',
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
        ),
      ),
    ),
    'settings' => array(
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => 0,
      'title_field' => 1,
      'default_image' => 0,
      'epsacrop' => array(
        'styles' => array(
          'banner-200' => 'banner-200',
          'banner-250' => 'banner-250',
          'banner-300' => 'banner-300',
          'imagen-43-100' => 0,
          'imagen-43-150' => 0,
          'imagen-43-200' => 0,
          'imagen-43-300' => 0,
          'imagen-43-400' => 0,
          'imagen-43-500' => 0,
          'imagen-43-600' => 0,
          'imagen-43-700' => 0,
          'imagen-43-800' => 0,
          'imagen-43-900' => 0,
          'imagen-43-1000' => 0,
          'imagen-43-1100' => 0,
          'imagen-43-1200' => 0,
          'imagen43crop' => 0,
        ),
      ),
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'weight' => 0,
        'settings' => array(
          'image_style' => 'imagen-300',
          'image_link' => '',
        ),
        'module' => 'image',
      ),
    ),
    'required' => 0,
    'description' => '',
  ),
  'portales7_mm_video' => array(
    'label' => 'Audio or video file',
    'widget' => array(
      'weight' => 4,
      'type' => 'video_upload',
      'module' => 'video',
      'active' => 1,
      'settings' => array(
        'progress_indicator' => 'throbber',
        'filefield_sources' => array(
          'filefield_sources' => array(
            'upload' => 0,
            'imce' => 'imce',
            'remote' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'attach' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
          'source_attach' => array(
            'path' => 'file_attach',
            'absolute' => 0,
            'attach_mode' => 'move',
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
        ),
      ),
    ),
    'settings' => array(
      'file_directory' => 'videos/original',
      'file_extensions' => 'mp4 ogg avi mov wmv flv ogv webm mp3',
      'max_filesize' => '',
      'default_dimensions' => '300x168',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'video_formatter_player',
        'weight' => 1,
        'settings' => array(
          'widthxheight' => '300x168',
          'poster_image_style' => 'imagen-300',
        ),
        'module' => 'video',
      ),
    ),
    'required' => 0,
    'description' => '',
  ),
  'portales7_mm_video_url' => array(
    'label' => 'Video URL',
    'widget' => array(
      'weight' => 6,
      'type' => 'video_embed_field_video',
      'module' => 'video_embed_field',
      'active' => 0,
      'settings' => array(),
    ),
    'settings' => array(
      'description_field' => 1,
      'description_length' => 255,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'video_embed_field',
        'weight' => 2,
        'settings' => array(
          'video_style' => 'video_300',
          'description' => 1,
          'description_position' => 'bottom',
        ),
        'module' => 'video_embed_field',
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => NULL,
  ),
);
