<?php

function portales7_home_switch_load_images() {
  $output = array();
  $path = PORTALES7_RESOURCEDIR . '/imagenes/portadas';
  $files = file_scan_directory($path, '/(\.png|\.jpg)$/');
  foreach ($files as $file) {
    $output[$file->name] = $file->uri;
  }
  $files = file_scan_directory('public://' . variable_get('portales7_frontpage_images', 'portadas'), '/(\.png|\.jpg)$/');
  foreach ($files as $file) {
    $output[$file->name] = $file->uri;
  }
  return $output;
}

function portales7_home_switch($form_status) {
  $form = array();
  ctools_include('export');
  $task = page_manager_get_task('page');
  // Tasks have arrays of handlers which we refer to in Panels as 'variants';
  $handlers = page_manager_load_sorted_handlers($task, 'portada', FALSE);
  $options = array();
  $default = '';
  $images = portales7_home_switch_load_images();
  foreach($handlers as $name => $handler) {
    if (!empty($images[$name])) {
      $vars = array('path' => $images[$name], 'style_name' => 'imagen-100', 'attributes' => array('class' => 'frontpage-preview'));
      $img = '<div class="variant-preview">' . theme('portales7_image_style_outside_files', $vars) . '</div>';
    }
    else {
      $img = '';
    }
    
    $options[$name] = '<div class="variant-name">' . $handler->conf['title'] . '</div>' . $img;
    
    if (empty($default) && (!isset($handler->disabled) || !$handler->disabled)) {
      $default = $name;
    }
  }
  $form['active'] = array(
    '#type' => 'radios',
    '#title' => t('Select active variant'),
    '#options' => $options,
    '#default_value' => $default,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Change'),
  );
  return $form;
}

function portales7_home_switch_submit($form, &$form_status) {
  ctools_include('export');
  $task = page_manager_get_task('page');
  // Tasks have arrays of handlers which we refer to in Panels as 'variants';
  $handlers = page_manager_load_sorted_handlers($task, 'portada', FALSE);
  foreach($handlers as $name => $handler) {
    if ($name == $form_status['values']['active']) {
      ctools_export_set_object_status($handler, FALSE); //el segundo parámetro es disabled = TRUE|FALSE
    }
    else {
      ctools_export_set_object_status($handler, TRUE); //el segundo parámetro es disabled = TRUE|FALSE
    }
  }
}
