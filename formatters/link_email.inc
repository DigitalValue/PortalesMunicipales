<?php
$formatter = array(
  'name' => 'link_email',
  'info' => array(
    'label' => t('Portales 7 Email'),
    'field types' => array('text'),
    'description' => t('Link an email'),
    'settings' => array(
      'linkemail' => 1,
    ),
  ),
);


function link_email_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  $element['linkemail'] = array(
    '#type' => 'text',
    '#title' => t('Link email'),
    '#description' => t('Link the text to send an e-mail'),
    '#default_value' => $settings['linkemail'],
  );
  return $element;
}

function link_email_settings_summary($field, $instance, $view_mode) {
  return t('Show email as a link');
}

function link_email_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  foreach($items as $item) {
    $output[] = array('#markup' =>'<a href="mailto:' . $item['value'] . "\" >" . $item['value'] . '</a>');
  }
  return $output;
}
