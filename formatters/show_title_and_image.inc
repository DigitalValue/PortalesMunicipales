<?php
$formatter = array(
  'name' => 'show_title_and_image',
  'info' => array(
    'label' => t('Portales 7 CCLB show title & image'),
    'field types' => array('node_reference'),
    'description' => t('Displays the image and title of related item.'),
    'settings' => array(
      'clase' => '',
      'image_style' =>'',
      'show_title' => '',
    ),
  ),
);


function show_title_and_image_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  module_load_include('field.inc', 'image');
  $element = image_field_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
  unset($element['image_link']);
  $element['clase'] = array(
    '#type' => 'textfield',
    '#title' => t('Class'),
    '#description' => t('Class for the div element'),
    '#default_value' => $settings['clase'],
  );
  $element['show_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show title'),
    '#options' => array(0 => t('No'), 1 => t('Yes')),
    '#description' => t('Show title beside the logo'),
    '#default_value' => $settings['show_title'],
  );
  return $element;
}

function show_title_and_image_settings_summary($field, $instance, $view_mode) {
  return t('Displays a title & image of related content.');
}

function show_title_and_image_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = NULL;
  foreach ($items as $delta => $item) {
    if(!empty($item['nid'])){
      $node = node_load($item['nid']);
      $element =array();
      if (!empty ($node->field_imagen_principal['und'][0])){
        $element['item'] = $node->field_imagen_principal['und'][0];
        $element['image_style'] = $settings['image_style'];
        $img_tag = theme('image_formatter', $element);
        if (!empty ($settings['clase'])) {
          $clase = ' class="' . $settings['clase'] . '"';
        }
        $output[$delta][] = array('#markup' => '<div' . $clase . '>');
        if (!empty($node->field_url['und'][0]['value'])) $output[$delta][] = array('#markup' => '<a href="' . $node->field_url['und'][0]['value'] . '" target="_blank">');
        else $output[$delta][] = array('#markup' => '<a href="'. base_path() . drupal_get_path_alias('node/' . $node->nid) . '">');
        if ($settings['show_title']) {
          $output[$delta][] = array('#markup' => '<div class="relacionado-titulo">' . $node->title . '</div>');
        }
        $output[$delta][] = array('#markup' => '<div class="relacionado-logo">' . $img_tag . '</div>'); 
        $output[$delta][] = array('#markup' => '</a>');
        $output[$delta][] = array('#markup' => '</div>');
      }
    }
  }
  return $output;
}
