<?php
$instances = array(
  'portales7_images' => array(
    'label' => 'Images',
    'widget' => array(
      'weight' => 3,
      'type' => 'image_image',
      'module' => 'image',
      'active' => 1,
      'settings' => array(
        'progress_indicator' => 'throbber',
        'preview_image_style' => 'imagen-75',
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
        'type' => 'image_title',
        'weight' => 11,
        'settings' => array(
          'colorbox_node_style' => 'imagen-43-150',
          'colorbox_image_style' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'class_title' => 'nombre-imagen',
        ),
        'module' => 'portales7',
      ),
    ),
    'required' => 0,
    'description' => '',
  ),
  'portales7_fc_name' => array(
    'label' => 'Name',
    'widget' => array(
      'weight' => 0,
      'type' => 'text_textfield',
      'module' => 'text',
      'active' => 1,
      'settings' => array(
        'size' => 60,
      ),
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => 9,
        'settings' => array(),
        'module' => 'text',
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => NULL,
  ),
  'portales7_fc_description' => array(
    'label' => 'Description',
    'widget' => array(
      'weight' => 1,
      'type' => 'text_textarea',
      'module' => 'text',
      'active' => 1,
      'settings' => array(
        'rows' => 2,
      ),
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => 10,
        'settings' => array(),
        'module' => 'text',
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => NULL,
  ),
  'portales7_video_url' => array(
    'label' => 'Video URL',
    'widget' => array(
      'weight' => 8,
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
        'type' => 'video_embed_field_thumbnail_colorbox',
        'weight' => 13,
        'settings' => array(
          'video_style' => 'video_43_800',
          'image_style' => 'imagen-43-100',
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
  'portales7_videos' => array(
    'label' => 'Audio or video files',
    'widget' => array(
      'weight' => 7,
      'type' => 'video_upload',
      'module' => 'video',
      'active' => 1,
      'settings' => array(
        'progress_indicator' => 'throbber',
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
      'file_directory' => 'videos/original',
      'file_extensions' => 'mp4 ogg avi mov wmv flv ogv webm mp3',
      'max_filesize' => '',
      'default_dimensions' => '150x113',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'video_formatter_player',
        'weight' => 14,
        'settings' => array(
          'widthxheight' => '150x113',
          'poster_image_style' => '',
        ),
        'module' => 'video',
      ),
    ),
    'required' => 0,
    'description' => '',
  ),
  'portales7_files' => array(
    'label' => 'Files',
    'widget' => array(
      'weight' => 5,
      'type' => 'file_generic',
      'module' => 'file',
      'active' => 1,
      'settings' => array(
        'progress_indicator' => 'throbber',
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
          'source_imce' => array(
            'imce_mode' => 1,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
      ),
    ),
    'settings' => array(
      'file_directory' => '',
      'file_extensions' => 'txt pdf fla doc docx xls ppt pps odt ods zip rar tar.gz tbz2 tgz gz bz2 7z avi jpg png gif tiff jpeg',
      'max_filesize' => '',
      'description_field' => 1,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => 12,
        'settings' => array(),
        'module' => 'file',
      ),
    ),
    'required' => 0,
    'description' => '',
  ),
);
