<?php
$formatter = array(
  'name' => 'target_blank',
  'info' => array(
    'label' => t('Portales 7 Target _Blank'),
    'field types' => array('file'),
    'description' => t('Opens attachments in a new tab'),
    'settings' => array(
      'class_title' => '',
    ),
  ),
);


function target_blank_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element = array();
  $element['target'] = array(
    '#type' => 'radios',
    '#title' => t('Target'),
    '#description' => t('Select target destination'),
    '#default_value' => $settings['target'],
    '#options' => array('normal' => t('Open on the same tab'), 'blank' => t('Open on a new tab')),
    '#required' => TRUE,
  );
  return $element;
}

function target_blank_settings_summary($field, $instance, $view_mode) {
  return t('Choose the target of the file');
}

function target_blank_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $output = array();
  foreach($items as $item) {
    $file = $item;
    if (empty($file['fid'])) {
        return '';
    }
    $path = $file['uri'];
    $url = file_create_url($path);
    $variables = array('path' => file_icon_path($file));
    $icon = theme_image($variables);
    $options = array(
      'attributes' => array(
        'type' => $file['filemime'] . '; length=' . $file['filesize'],
      ),
    );
    if (empty($file['description'])) {
      $link_text = $file['filename'];
    }
    else {
      $link_text = $file['description'];
      $options['attributes']['title'] = $file['filename'];
    }
    $options['attributes']['target'] = '_blank';
    $output[] = array('#markup' => '<div class="filefield-file clear-block">'. $icon . l($link_text, $url, $options) .'</div>');
  }

  return $output;
}
