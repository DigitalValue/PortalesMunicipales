<?php
$formatter = array(
  'name' => 'fc_relations',
  'info' =>  array(
    'label' => t('Portales 7 FC Related'),
    'field types' => array('field_collection'),
    'description' => t('Formatter for main media field_collection'),
    'settings' => array(
      'image_style' => 'original',
      'video_width' => 'default',
    ),
  ),
);

function fc_relations_settings_summary($field, $instance, $view_mode) {
  return t('Style for images: @style, width for videos: @width', array('@style' => $settings['image_style'], '@width' => $settings['video_width']));
}

function fc_relations_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  //if (!empty($_SESSION['DEBUG']) && 'portales7_related_article' == $field['field_name']) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__ . ' ' . $field['field_name']);
  $fn = ($field['field_name'] == 'portales7_related_article') ? 'portales7_r_node' : 'portales7_re_entities';
  $output = array();
  foreach($items as $delta => $item) {
    if (is_a($item, 'FieldCollectionItemEntity')) {
      $data = $item;
    }
    else {
      $data = entity_load('field_collection_item', array($item['value']));
      $data = $data[$item['value']];
    }
    if (empty($data->{$fn}['und'])) continue;
    $output[$delta] = array('#markup' => theme('portales7_related_entity', array('item' => $data)));
  }
  return $output;
}
