<?php
$formatter = array(
  'name' => 'text_summary_and_full_view',
  'info' => array(
    'label' => t('Portales 7 teaser and full view'),
    'field types' => array('text', 'text_with_summary'),
    'description' => t('Displays teaser view on top of full view.'),
    'settings' => array(
      'teaser_class' => 'embedded-teaser',
    ),
  ),
);


function text_summary_and_full_view_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  $element['teaser_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Class name'),
    '#description' => t('Class name for the teaser wrapper.'),
    '#default_value' => $settings['teaser_class'],
    '#required' => TRUE,
  );
  return $element;
}

function text_summary_and_full_view_settings_summary($field, $instance, $view_mode) {
  return t('Displays teaser view on top of full view.');
}

function text_summary_and_full_view_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  if (empty($items)) return;
  $body = check_markup($items[0]['value'], $items[0]['format']);
  $teaser = '';
  if (!empty($items[0]['safe_summary'])){
    $teaser = "<div class=\"{$display['settings']['teaser_class']}\">{$items[0]['safe_summary']}</div>";
  }
  return array(array('#markup'  => $teaser . $body));
}
