<?php
$formatter = array(
  'name' => 'embedded_video',
  'info' => array(
    'label' => t('Portales 7 embedded video'),
    'field types' => array('embedded_video'),
    'description' => t('Show title under image'),
    'settings' => array(
      'class' => '',
    ),
  ),
);

function embedded_video_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $form = colorbox_field_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
  $form['class'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#description' => t('Class for the wrapper element'),
    '#default_value' => $settings['class'],
  );
  return $form;
}

function embedded_video_settings_summary($field, $instance, $view_mode) {
  $sumary = '';
  return $summary;
}

function embedded_video_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = '';
  return $output;
}