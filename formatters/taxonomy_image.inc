<?php
$formatter = array(
  'name' => 'taxonomy_image',
  'info' => array(
    'label' => t('Portales 7 Image from taxonomy term'),
    'field types' => array('taxonomy_term_reference'),
    'description' => t('Displays image from a taxonomy term'),
    'settings' => array(
      'clase' => '',
      'image_style' =>'',
      'show_title' => '',
      'url_link' => 'listado-evento',
    ),
  ),
);

function taxonomy_image_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  module_load_include('field.inc', 'image');
  $form = image_field_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
  $settings = $instance['display'][$view_mode]['settings'];
  $form['url_link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#description' => t('url to link'),
    '#default_value' => $settings['url_link'],
  );
  return $form;
}

function taxonomy_image_settings_summary($field, $instance, $view_mode) {
  return t('Show a Image of the taxonomy term');  
}

function taxonomy_image_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  foreach ($items as $item) {
    $term = taxonomy_term_load($item['tid']);
    $element=array();
    $element['item'] = $term->portales7_term_image['und'][0];
    $element['item']['title'] = $term ->name;
    $element['image_style'] = $settings['image_style'];
    $taxonomy_image = theme('image_formatter', $element);         
    $class= '';
    if (!empty($settings['class_title'])) {
      $class = ' class="' . $settings['class_title'] . '"';
    }
    $output[] = array('#markup' => '<div class="image-term-taxonomy ' .transliteration_clean_filename($term->name, '-') . $class . '">' . l($taxonomy_image, $settings['url_link'] . '/' . $term->name, array('html' => TRUE)) . '</div>');
  }
  return $output;
}
