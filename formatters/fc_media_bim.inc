<?php
$formatter = array(
  'name' => 'fc_media_bim',
  'info' =>  array(
    'label' => t('Portales 7 FC BIM'),
    'field types' => array('field_collection'),
    'description' => t('Formatter for BIM inside a field collection'),
    'settings' => array(
      'image_style' => '',
      'image_link' => 'file',
      'show_description' => TRUE,
      'tag' => 'div',
      'fallback_formatter' => FALSE
    ),
  ),
);



function fc_media_bim_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = pdfpreview_field_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
  return $element;
}

function fc_media_bim_settings_summary($field, $instance, $view_mode) {
  return t('Style for images: @style', array('@style' => $settings['image_style']));
}

function fc_media_bim_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  if (FALSE && !empty($_SESSION['DEBUG']) && !empty($items)) dpm(array('entity_type' => $entity_type, 'entity' => $entity, 'field' => $field, 'instance' => $instance, 'langcode' => $langcode, 'items' => $items, 'display' => $display), __FUNCTION__);
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
    foreach (array('portales7_files') as $field_name) {
      if (empty($element->{$field_name}['und'])) continue;
      $_field = field_read_field($field_name);
      $_instance = field_read_instance('field_collection_item', $field_name, 'portales7_media');
      $_display = $_instance['display']['default'];
      //$function = $_display['module'] . '_field_formatter_view';
      $function = 'pdfpreview_field_formatter_view';
      if (function_exists($function)) {
        $renderable = $function($entity_type, $entity, $_field, $_instance, $langcode, $element->{$field_name}['und'], $display);
        $zebra = 'even';
        foreach ($renderable as $k => &$v) {
          $v['#prefix'] = '<div class="field-content"><div class="' . $field_name . '-item field-item ' . $zebra .'">' . (isset($v['#prefix']) ? $v['#prefix'] : '');
          $v['#suffix'] = (isset($v['#suffix']) ? $v['#suffix'] : '') . '</div></div>';
          $zebra = $zebra == 'even' ? 'odd' : 'even';
          $vars['fc_items']['#items'][] = drupal_render($v);
        }
      }
      else {
        watchdog('portales7', "Function @function doesn't exists", array('@function' => $function), WATCHDOG_ERROR);
      }
    }
    $vars['fc_items'] = drupal_render($vars['fc_items']);
    $output[$delta][] = array('#markup' => theme('portales7_fc_named_group', $vars));
  }
  return $output;
}
