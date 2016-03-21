<?php
$formatter = array(
  'name' => 'fc_media',
  'info' =>  array(
    'label' => t('Portales 7 FC media'),
    'field types' => array('field_collection'),
    'description' => t('Formatter for media field_collection'),
    'settings' => array(
      'portales7_video_url' => array(),
      'portales7_videos' => array(),
      'portales7_images' => array(),
      'portales7_files' => array(),
      'display_fields' => array(
        'portales7_video_url' => 'portales7_video_url',
        'portales7_videos' => 'portales7_videos',
        'portales7_images' => 'portales7_images',
        'portales7_files' => 'portales7_files',
      ),
    ),
  ),
);

function _fc_media_display_fields_options(){
  return array('portales7_video_url' => t('Video URL'), 'portales7_videos' => t('Videos'), 'portales7_images' => t('Images'), 'portales7_files' => t('Files'));
}

function fc_media_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  //if (!empty($_SESSION['DEBUG'])) dpm($settings, __FUNCTION__ . ' settings');
  $element = array();
  $element['display_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display elements'),
    '#options' => _fc_media_display_fields_options(),
    '#default_value' => array_keys($settings['display_fields']),
  );
  //if (!empty($_SESSION['DEBUG'])) dpm(array('field' => $field, 'instance' => $instance, 'view_mode' => $view_mode, 'settings' => $settings), __FUNCTION__);
  
  $view_mode = 'default';
  foreach (array_keys(_fc_media_display_fields_options()) as $field_name) {
    $_field = field_read_field($field_name);
    $_instance = field_read_instance('field_collection_item', $field_name, 'portales7_media');
    $_display = $_instance['display']['default'];
    $_instance['display']['default']['settings'] = (array)$settings[$field_name];
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

function fc_media_settings_summary($field, $instance, $view_mode) {
  $settings = $instance['display'][$view_mode]['settings'];
  $display_fields = _fc_media_display_fields_options();
  $output = array();
  foreach ($settings['display_fields'] as $field_name => $active) {
    if (!$active) {
      unset($display_fields[$field_name]);
    }
  }
  $image_style = !empty($settings['portales7_images']['colorbox_node_style']) ? $settings['portales7_images']['colorbox_node_style'] : t('Unconfigured');
  $widthxheight = !empty($settings['portales7_videos']['widthxheight']) ? $settings['portales7_videos']['widthxheight'] : t('Unconfigured');
  $video_style = !empty($settings['portales7_video_url']['video_style']) ? $settings['portales7_video_url']['video_style'] : t('Unconfigured'); 
  return t('Active fields: @display_fields<br/>Style for images: @image_style<br/>Width for video urls: @widthxheight<br/>Style for videos: @video_style', array('@display_fields' => join(', ', array_values($display_fields)), '@image_style' => $image_style, '@widthxheight' => $widthxheight, '@video_style' => $video_style));
}

function fc_media_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  if (!empty($display['pane_settings']['formatter_settings'])) $display['settings'] = $display['pane_settings']['formatter_settings']; 
  //if (TRUE && !empty($items)) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__);
  $output = array();
  foreach($items as $delta => $item) {
    $output[$delta] = array();
    $data = entity_load('field_collection_item', array($item['value']));
    $element = $data[$item['value']];
    $vars['fc_name'] = !empty($element->portales7_fc_name['und'][0]['value']) ? $element->portales7_fc_name['und'][0]['value'] : '';
    $vars['fc_description'] = !empty($element->portales7_fc_description['und'][0]['value']) ? check_markup($element->portales7_fc_description['und'][0]['value'], $element->portales7_fc_description['und'][0]['format']) : '';
    
    /*
     * Este codic permet fer generic el formatejador i que agarre els valors de la configuracio del camp 
     */
    $vars['fc_items'] = array('#theme' => 'item_list', '#items' => array(), '#type' => 'ul');
    $rendered = array();
    foreach ($display['settings']['display_fields'] as $field_name => $active) {
      if (!$active || empty($element->{$field_name}['und'])) continue;
      $_field = field_read_field($field_name);
      $_instance = field_read_instance('field_collection_item', $field_name, 'portales7_media');
      $_display = $_instance['display']['default'];
      $_display['settings'] = $display['settings'][$field_name];
      $function = $_display['module'] . '_field_formatter_view';
      //if (!empty($_SESSION['DEBUG'])) dpm(array('function' => $function, '_field' => $_field, '_instance' => $_instance, '_display' => $_display), __FUNCTION__ . ' ' . $field_name);
      if (function_exists($function)) {
        $renderable = $function($entity_type, $entity, $_field, $_instance, $langcode, $element->{$field_name}['und'], $_display);
        $zebra = 'even';
        foreach ($renderable as $k => &$v) {
          $v['#prefix'] = '<div class="field-content field-' . $field_name . '"><div class="' . $field_name . '-item field-item ' . $zebra .'">' . (isset($v['#prefix']) ? $v['#prefix'] : '');
          $v['#suffix'] = (isset($v['#suffix']) ? $v['#suffix'] : '') . '</div></div>';
          $zebra = $zebra == 'even' ? 'odd' : 'even';
          $vars['fc_items']['#items'][] = drupal_render($v);
        }
      }
      else {
        watchdog('portales7', "Function @function doesn't exists", array('@function' => $function), WATCHDOG_ERROR);
      }
    }
    $vars['fc_classes'] = array(
      'video_style-' . $display['settings']['portales7_video_url']['video_style'],
      'widthxheight-'. $display['settings']['portales7_videos']['widthxheight'],
      'image_style-'. $display['settings']['portales7_images']['colorbox_node_style'],
      'fallback-' . $display['settings']['portales7_files']['fallback_formatter'],
    );
    $vars['fc_formatter'] = 'media';
    $vars['fc_items'] = drupal_render($vars['fc_items']);
    $output[$delta][] = array('#markup' => theme('portales7_fc_named_group', $vars));
  }
  return $output;
}
