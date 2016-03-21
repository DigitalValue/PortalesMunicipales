<?php
function _portales7_p7vars_required() {
  return  array(
    'p7vars_corporacion_municipal',
    'p7vars_oficina_virtual',
    'p7vars_buzon_ciudadano',
    'p7vars_cita_previa',
    'p7vars_pgou',
    'p7vars_portal_transparencia',
    'p7vars_perfil_contratante',
    'p7vars_pago_proveedores',
    'p7vars_listin',
    'p7vars_slider_principal',
    'p7vars_twitter',
    'p7vars_facebook',
    'p7vars_youtube',
  );
}
function portales7_p7vars_form() {
  $required_vars =  _portales7_p7vars_required();
  $vars = db_select('variable', 'v')->fields('v', array('name'))->condition('name', 'p7vars_%', 'LIKE')->execute()->fetchCol();
  $vars = array_unique(array_merge($required_vars, $vars));
  sort($vars);
  $form = array();
  $form['old_vars'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('p7vars-old')),
  );
  foreach($vars as $name) {
    $form['old_vars'][$name] = array(
      '#type' => 'textfield',
      '#title' => $name,
      '#default_value' => variable_get($name, ''),
    );
  }
  $form['new_vars'] = array(
    '#type' => 'fieldset',
    '#title' => t('New variables'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
  );
  for ($i = 0; $i < 5; $i++) {
    $form['new_vars']['new_p7vars_name_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t('Variable name'),
      '#field_prefix' => 'p7vars_',
      '#prefix'  => '<div class="p7vars-inline-container">',
    );
    $form['new_vars']['new_p7vars_value_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t('Variable value'),
      '#suffix' => '</div>',
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#prefix' => '<div style="clear: both;">',
    '#suffix' => '</div>',
  );
  drupal_add_css(drupal_get_path('module', 'portales7') . '/css/p7vars.css', array('preprocess' => FALSE));
  return $form;
}


function portales7_p7vars_form_validate($form, &$form_state) {
  for ($i = 0; $i < 5; $i++) {
    if (!empty($form_state['values']['new_p7vars_name_' . $i])) {
      $name = $form_state['values']['new_p7vars_name_' . $i];
      if (!preg_match('/^[a-z0-9_]+$/', $name)) {
        form_set_error('new_p7vars_name_' . $i, t('Invalid variable name, please use only alphanumeric characters and underscores'));
      }
    }
  }
}

function portales7_p7vars_form_submit($form, &$form_state) {
  for ($i = 0; $i < 5; $i++) {
    if (!empty($form_state['values']['new_p7vars_name_' . $i]) && !empty($form_state['values']['new_p7vars_value_' . $i])) {
      $name = $form_state['values']['new_p7vars_name_' . $i];
      $value = $form_state['values']['new_p7vars_value_' . $i];
      variable_set('p7vars_' . $form_state['values']['new_p7vars_name_' . $i], $form_state['values']['new_p7vars_value_' . $i]);
      drupal_set_message("$name => $value", 'status');
    }
    unset($form_state['values']['new_p7vars_name_' . $i]);
    unset($form_state['values']['new_p7vars_value_' . $i]);
    
  }
  
  foreach ($form_state['values'] as $name => $value) {
    if (preg_match('/p7vars_.*/', $name)) {
      if (!empty($value)) {
        variable_set($name, $value);
      }
      else {
        variable_del($name);
      }      
    }
  }
}
