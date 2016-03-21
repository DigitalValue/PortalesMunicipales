<?php
$formatter = array(
  'name' => 'field_p7_place',
  'info' => array(
    'label' => t('Portales 7 place field'),
    'field types' => array('entityreference'),
    'description' => t('Displays the place field from a related entity.'),
    'settings' => array(
      'view_mode' => 'portales7_entity_building',
    ),
  ),
);

function field_p7_place_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $entity_info = entity_get_info('node');
  $view_modes = $entity_info['view modes'];
  $options_entity = array('default' => t('Default'));
  $view_mode_entity = field_view_mode_settings('node', 'portales7_entity');
  foreach ($view_modes as $view_mode_name => $view_mode_info) {
    if (!empty($view_mode_entity[$view_mode_name]['custom_settings'])) {
      $options_entity[$view_mode_name] = $view_mode_info['label'];
    }
  }
  $element = array();
  $element['view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View mode'),
    '#description' => t('View mode to use when rendering the place field'),
    '#default_value' => $settings['view_mode'],
    '#options' => $options_entity,
  );
  return $element;
}

function field_p7_place_settings_summary($field, $instance, $view_mode) {
  return t('Show place field content');
}

function field_p7_place_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  $children = array();
  //if (!empty($_SESSION['DEBUG'])) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__);
  foreach ($items as $delta => $v) {
    if (($node = node_load($v['target_id'])) && node_access('view', $node)) {
      $view = node_view($node, $settings['view_mode']);
      $children[] = drupal_render($view);
    }
  }
  if (!empty($children)) {
    $output[0][] = array('#markup' => theme('item_list', array('items' => $children)));
  }
  return $output;
}
