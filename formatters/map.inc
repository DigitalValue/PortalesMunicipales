<?php
$formatter = array(
  'name' => 'map',
  'info' => array(
    'label' => t('Portales 7 Map'),
    'field types' => array('google_map_field'),
    'description' => t('Show map as a link'),
    'settings' => array(
      'class_title' => '',
      'height' => '300px',
      'width' => '250px',
      'mode' => 'map',
    ),
  ),
);


function map_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  $element['class_title'] = array(
    '#type' => 'textfield',
    '#title' => t('class'),
    '#description' => t('Class for the div element'),
    '#default_value' => $settings['class_title'],
  );
  $element['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('Map width'),
    '#default_value' => $settings['width'],
  );
  $element['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Map height'),
    '#default_value' => $settings['height'],
  );
  $element['mode'] = array(
    '#type' => 'radios',
    '#title' => t('Mode'),
    '#description' => t('Mode of display'),
    '#default_value' => $settings['mode'],
    '#options' => array('map' => t('View as map'), 'link' => t('View as link')),
    '#required' => TRUE,
  );
  return $element;
}

function map_settings_summary($field, $instance, $view_mode) {
  if($instance['display'][$view_mode]['settings']['mode'] == 'link') {
    return t('Show map as a link'); 
  }
  else {
    return t('Show as map');
  }
}

function map_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  if (($entity_type == 'node' && isset($entity->field_ver_mapa)) || $entity->type == 'centro') {
    switch($entity->field_ver_mapa['und'][0]['value']) {
      case 'Ocultar Mapa': return; break;
      default:
        drupal_add_js(drupal_get_path('module', 'portales7'). '/js/portales7.map.js', 'file');
        drupal_add_js(array('portales7_map' => array('width' => $settings['width'], 'height' => $settings['height'])), 'setting');
        $display['type']='google_map_field_formatter_default';
        $mapa = google_map_field_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display);
        if($settings['mode'] == 'link') {
          if (!empty($settings['class_title'])) {
            $class = ' class="' . $settings['class_title'] . '"';
          }
          $output[0][] = array('#markup' => '<div' . $class . '>');
          $output[0][] = array('#markup' => '<div class="portales7-map-switch">Ver mapa</div>');
          $output[0][] = array('#markup' => '<div class="portales7-map-container" style="width: 0px; height: 0px; overflow: hidden;" >' . drupal_render($mapa) . '</div>');
          $output[0][] = array('#markup' => '</div>');
          return $output;
        }
        else {
          return $mapa;
        }
        
    }
  }
  $display['type']='google_map_field_formatter_default';
  return google_map_field_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display);
}
