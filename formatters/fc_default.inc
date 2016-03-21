<?php
$formatter = array(
  'name' => 'fc_default',
  'info' =>  array(
    'label' => t('Portales 7 FC default formatter'),
    'field types' => array('field_collection'),
    'description' => t('Default formatter for field_collection_items'),
    'settings' => array(
      'fc_default' => '',
    ),
  ),
);


function fc_default_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
   $element['fc_default'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#description' => t('url to link'),
    '#default_value' => $settings['fc_default'],
  );
  return $element;
}

function fc_default_settings_summary($field, $instance, $view_mode) {
  return t('Link whith custon URL');
}

function fc_default_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  if (FALSE && !empty($items)) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__);
  $output = array();
  foreach ($items as $delta => $item) {
    if ($field_collection = field_collection_field_get_entity($item)) {
      $view_mode = $field_collection->portales7_fc_formatter['und'][0]['value'];
      $element['entity'] = $field_collection->view($view_mode);
      $element['#theme_wrappers'] = array('field_collection_view');
      $element['#attributes']['class'][] = 'field-collection-view';
      $element['#attributes']['class'][] = 'clearfix';
      $element['#attributes']['class'][] = drupal_clean_css_identifier('view-mode-' . $view_mode);
      $output[$delta] = array('#markup' => drupal_render($element));
    }
  }
  return $output;
}
