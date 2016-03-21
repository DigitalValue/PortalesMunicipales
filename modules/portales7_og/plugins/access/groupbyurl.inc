<?php

/**
 * @file
 * Plugin to provide access control based upon active group taken
 * from first url argument.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Portales 7: Miniportal"),
  'description' => t('Control access by active OG.'),
  'callback' => 'portales7_og_groupbyurl_ctools_access_check',
  'default' => array('gid' => ''),
  'settings form' => 'portales7_og_groupbyurl_ctools_access_settings',
  'summary' => 'portales7_og_groupbyurl_ctools_access_summary',
);

/**
 * Settings form for the 'by role' access plugin.
 */
function portales7_og_groupbyurl_ctools_access_settings(&$form, &$form_state, $conf) {
  $options = array('any' => t('Any'));
  $groups = array_flip(portales7_og_available_groups());
  ksort($groups);
  foreach ( $groups as $v => $k) {
    $options[$k] = $v;
  }
  $form['settings']['gid'] = array(
    '#type' => 'select',
    '#title' => t('Group'),
    '#default_value' => $conf['gid'],
    '#options' => $options,
    '#description' => t('Only the selected group will be granted access.'),
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Check for access.
 */
function portales7_og_groupbyurl_ctools_access_check($conf, $context) {
  if (($og = og_context()) && (($conf['gid'] == 'any') ||  ($og['gid'] == $conf['gid']))) return TRUE;
  if ($cache = purl_active()) {
    $providers = $cache->get();
    if (!empty($providers['path'][0]->id) && (($conf['gid'] == 'any') || ($providers['path'][0]->id == $conf['gid']))) return TRUE;
  }
  return FALSE;
}

/**
 * Provide a summary description based upon the checked roles.
 */
function portales7_og_groupbyurl_ctools_access_summary($conf, $context) {
  if ($conf['gid'] == 'any') {
    $group = new stdClass();
    $group->title = t('Any');
  }
  else {
    $group = node_load($conf['gid']);
  }
  return t("Active group is %label", array('%label' => $group->title));
}

