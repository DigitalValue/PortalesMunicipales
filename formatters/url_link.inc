<?php
$formatter = array(
  'name' => 'url_link',
  'info' =>  array(
    'label' => t('Portales 7 Taxonomy Link'),
    'field types' => array('taxonomy_term_reference'),
    'description' => t('Link a Taxonomy whith a custom link'),
    'settings' => array(
      'url_link' => '',
    ),
  ),
);


function url_link_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
   $element['url_link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#description' => t('url to link'),
    '#default_value' => $settings['url_link'],
  );
  return $element;
}

function url_link_settings_summary($field, $instance, $view_mode) {
  return t('Link whith custon URL');
}

function url_link_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  foreach($items as $item) {
    $term = taxonomy_term_load($item['tid']);
    $output[] = array('#markup' => '<a href="/'. $settings['url_link'] . '/' . $term ->name . '">' . $term ->name . '</a>');
  }

  return $output;
}

