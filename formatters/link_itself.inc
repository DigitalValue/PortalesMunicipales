<?php
$formatter = array(
  'name' => 'link_itself',
  'info' => array(
    'label' => t('Portales 7 Link itself'),
    'field types' => array('text'),
    'description' => t('Show text as a link'),
    'settings' => array(
      'newwindow' => 1,
    ),
  ),
);


function link_itself_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  $element['newwindow'] = array(
    '#type' => 'text',
    '#title' => t('New window'),
    '#description' => t('Open external links on new window'),
    '#default_value' => $settings['newwindow'],
  );
  return $element;
}

function link_itself_settings_summary($field, $instance, $view_mode) {
  return t('Show text as a link');
}

function link_itself_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  foreach($items as $item) {
    $target=(preg_match("@://@",$item['value']) && $settings['newwindow']) ? "_blank" : "_self";
    $output[] = array('#markup' => l($item['value'], $item['value'], array('attributes' => array('target' => $target, 'rel' => 'nofollow'))));
  }
  return $output;
}
