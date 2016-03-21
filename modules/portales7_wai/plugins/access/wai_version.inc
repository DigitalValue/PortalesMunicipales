<?php

/**
 * @file
 * Plugin to provide access control based on evaluated PHP.
 */
 
$plugin = array(
  'title' => t("Accesible version"),
  'description' => t('Control access based on accessibility condition.'),
  'callback' => 'portales7_wai_version_ctools_access_check',
  'default' => array('description' => 'Accesible version', 'wai_version' => FALSE),
  'settings form' => 'portales7_wai_version_ctools_access_settings',
  'summary' => 'portales7_wai_version_ctools_acesss_summary',
  'all contexts' => TRUE,
);

/**
 * Settings form for the 'by perm' access plugin
 *
 * @todo Need a way to provide a list of all available contexts to be used by
 *       the eval-ed PHP.
 */
function portales7_wai_version_ctools_access_settings(&$form, &$form_state, $conf) {
  $perms = array();
  $options['wai_version'] = 'Accesible version';
  $form['settings']['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Administrative desc'),
    '#default_value' => $conf['description'],
    '#description' => t('A description for this test for administrative purposes.'),
  );
}

/**
 * Check for access.
 */
function portales7_wai_version_ctools_access_check($conf, $contexts) {
  return !empty($_SESSION['wai_version']);
}

/**
 * Provide a summary description based upon the checked roles.
 */
function portales7__wai_version_ctools_acesss_summary($conf, $contexts) {
  return check_plain($conf['description']);
}
