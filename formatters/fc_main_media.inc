<?php
$formatter = array(
  'name' => 'fc_main_media',
  'info' =>  array(
    'label' => t('Portales 7 FC main media'),
    'field types' => array('field_collection'),
    'description' => t('Formatter for main media field_collection'),
    'settings' => array(
      'portales7_mm_video_url' => array(),
      'portales7_mm_video' => array(),
      'portales7_mm_image' => array(),
    ),
  ),
);


function fc_main_media_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  //if (!empty($_SESSION['DEBUG']) && !empty($items)) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__);
  
  $view_mode = 'default';
  foreach (array('portales7_mm_video_url', 'portales7_mm_video', 'portales7_mm_image') as $field_name) {
    $_field = field_read_field($field_name);
    $_instance = field_read_instance('field_collection_item', $field_name, 'portales7_main_media');
    $_display = $_instance['display']['default'];
    $function = $_display['module'] . '_field_formatter_settings_form';
    //if (TRUE && !empty($_SESSION['DEBUG'])) dpm(array('function' => $function, 'field' => $_field, 'instance' => $_instance, 'display' => $_display), __FUNCTION__);
    if (function_exists($function)) {
      $element[$field_name] = array_merge($function($_field, $_instance, $view_mode, $form, $form_state), array(
        '#title' => t('Settings for @field', array('@field' => $_instance['label'])),
        '#tree' => TRUE,
        '#type' => 'fieldset',
      ));
    }
    if (!empty($settings[$field_name])) {
      foreach ($settings[$field_name] as $k => $v) {
        $element[$field_name][$k]['#default_value'] = $v;
      }
    }
  }
  return $element;
}

function fc_main_media_settings_summary($field, $instance, $view_mode) {
  $settings = $instance['display'][$view_mode]['settings'];
  $output = array();
  $image_style = !empty($settings['portales7_mm_image']['image_style']) ? $settings['portales7_mm_image']['image_style'] : t('Unconfigured');
  $widthxheight = !empty($settings['portales7_mm_video']['widthxheight']) ? $settings['portales7_mm_video']['widthxheight'] : t('Unconfigured');
  $video_style = !empty($settings['portales7_mm_video_url']['video_style']) ? $settings['portales7_mm_video_url']['video_style'] : t('Unconfigured'); 
  return t('Style for images: @image_style<br/>Width for video urls: @widthxheight<br/>Style for videos: @video_style', array('@image_style' => $image_style, '@widthxheight' => $widthxheight, '@video_style' => $video_style));
}

function fc_main_media_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  //if (!empty($_SESSION['DEBUG']) && !empty($items)) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__);

  foreach($items as $delta => $item) {
    $output[$delta] = array();
    $data = entity_load('field_collection_item', array($item['value']));
    $element = $data[$item['value']];
    $vars['fc_name'] = !empty($element->portales7_fc_name['und'][0]['value']) ? $element->portales7_fc_name['und'][0]['value'] : '';
    
    /*
     * Este codic permet fer generic el formatejador i que agarre els valors de la configuracio del camp 
     */
    $vars['fc_items'] = array('#theme' => 'item_list', '#items' => array(), '#type' => 'ul');
    foreach (array('portales7_mm_video_url', 'portales7_mm_video', 'portales7_mm_image') as $field_name) {
      if (empty($element->{$field_name}['und'])) continue;
      $_field = field_read_field($field_name);
      $_instance = field_read_instance('field_collection_item', $field_name, 'portales7_main_media');
      $_display = $_instance['display']['default'];
      $_display['settings'] = (array)$display['settings'][$field_name];
      $function = $_display['module'] . '_field_formatter_view';
      if (function_exists($function)) {
        $renderable = $function($entity_type, $entity, $_field, $_instance, $langcode, $element->{$field_name}['und'], $_display); 
        $vars['fc_items']['#items'][] = drupal_render($renderable);
      }
      else {
        drupal_set_message('no existe la función ' . $function, 'error');
      }
      break;
    }
    $vars['fc_items'] = drupal_render($vars['fc_items']);
    $output[$delta][] = array('#markup' => theme('portales7_fc_named_group', $vars));
  }
  return $output;
}
