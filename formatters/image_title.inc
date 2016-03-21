<?php
$formatter = array(
  'name' => 'image_title',
  'info' => array(
    'label' => t('Portales 7 Image Title'),
    'field types' => array('image'),
    'description' => t('Show title under image'),
    'settings' => array(
      'colorbox_node_style' => '',
      'colorbox_image_style' => '',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'auto',
      'colorbox_caption_custom' => '',
      'class_title' => '',
    ),
  ),
);


function image_title_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = colorbox_field_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
  $element['class_title'] = array(
    '#type' => 'textfield',
    '#title' => t('class'),
    '#description' => t('Class for the div element'),
    '#default_value' => $settings['class_title'],
  );
  return $element;
}

function image_title_settings_summary($field, $instance, $view_mode) {
  return colorbox_field_formatter_settings_summary($field, $instance, $view_mode). '<br/>' . t('Title class') . ': ' . $instance['display'][$view_mode]['settings']['class_title'];
}

function image_title_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = '';
  foreach ($items as $item) {
    $element =array();
    $element['item'] = $item;
    $element['colorbox_caption'] = $item['title'];
    $element['field'] = $field;
    $element['node'] = $entity;
    $element['display_settings'] = $settings;
    $img_tag = theme('colorbox_image_formatter', $element);
    $class= '';
    if (!empty($settings['class_title'])) {
      $class = ' class="' . $settings['class_title'] . '"';
    }
    $output[] = array('#markup' => '<div class="field-content"><div class="image-title-item">' . $img_tag . '<div class="image-title-portada"' . $class . '>' . $element['item']['title'] . '</div></div></div>');
  }  
  return $output;
}
