<?php
$formatter = array(
  'name' => 'relationship',
  'info' =>  array(
    'label' => t('Portales 7 Relationship'),
    'field types' => array('taxonomy_term_reference'),
    'description' => t('Show relationships'),
    'settings' => array(
      'class_title' => '',
    ),
  ),
);


function relationship_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  $element['class_title'] = array(
    '#type' => 'textfield',
    '#title' => t('class'),
    '#description' => t('Class for the div element'),
    '#default_value' => $settings['class_title'],
  );
  return $element;
}

function relationship_settings_summary($field, $instance, $view_mode) {
  return t('Show related nodes');
}

function relationship_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  foreach($items as $item) {
    $term = taxonomy_term_load($item['tid']);
    if ($result = views_embed_view('portales7_relationship', 'default', $item['tid'], $entity->nid)) {
      if (!preg_match('/SIN RESULTADOS/', $result)) {
        $output[0][] = array('#markup' => '<div class="field-label">' . $term->name . '</div>');
        $output[0][] = array('#markup' => $result);
      }
    }
  }
  return $output;
}
