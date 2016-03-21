<?php
/**
 * @file
 * Admin functions for Portales7 AMET modle
 */
function portales7_aemet_admin() {
  $defaults = _portales7_aemet_defaults();
  $form['portales7_aemet_days'] = array(
    '#type' => 'select',
    '#title' => t('Days'),
    '#description' => t('Number of days to show'),
    '#options' => array( 1 => 1, 2 => 2, 3 => 3, 4 => 4),
    '#required' => TRUE,
    '#default_value' => variable_get('potales7_aemet_days', $defaults['days']),
    '#multiple' => FALSE,
  );
  $form['portales7_aemet_options'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Options'),
    '#options' => array(
      'estado_cielo' => t('Show sky status'),
      'prob_precipitacion' => t('Chance of rain'),
      'temperatura' => t('Temperature'),
      'sens_termica' => t('Wind chill'),
      'humedad_relativa' => t('Humidity'),
      'viento' => t('Wind'),
      'racha_max' => t('Wind burst'),
      'uv_max' => t('UV Max'),
    ),
    '#default_value' => variable_get('portales7_aemet_options', $defaults['options']),
  );
  $form['portales7_aemet_show_variables'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show variables'),
    '#default_value' => variable_get('portales7_aemet_show_variables', $defaults['show_variables']),
  );
  $form['portales7_aemet_skip_proxy'] = array(
    '#type' => 'radios',
    '#title' => t('Skip proxy'),
    '#default_value' => variable_get('portales7_aemet_skip_proxy', 0),
    '#description' => t('Skip proxy and connect directly to AEMET server, this can cause denial of service if too many connections are made'),
    '#options' => array(0 => t('No'), 1 => t('Yes')),
  );
  return system_settings_form($form);
}

