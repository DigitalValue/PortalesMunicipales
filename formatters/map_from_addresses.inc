<?php
$formatter = array(
  'name' => 'map_from_adressess',
  'info' => array(
    'label' => t('Portales 7 map from field adessess'),
    'field types' => array('geofield'),
    'description' => t('Displays a google map.'),
    'settings' => array(
      'include_map' => 1,
      'include_static_map' => 0,
      'include_link' => 0,
      'include_text' => 0,
      'iframe_height' => 200,
      'iframe_width' => 200,
      'zoom_level' => 14,
      'information_bubble' => 1,
      'link_text' => t('View larger map'),
      'map_type' => 'm',
      'langcode' => 'es',
    ),
  ),
);


function map_from_adressess_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  return simple_gmap_field_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
}

function map_from_adressess_settings_summary($field, $instance, $view_mode) {
  return simple_gmap_field_formatter_settings_summary($field, $instance, $view_mode);
}

function map_from_adressess_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  foreach ($items as $delta => &$item){
    $item['value'] = $item['lat'] . ',' . $item['lon'];
  }
  return simple_gmap_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display);
}
