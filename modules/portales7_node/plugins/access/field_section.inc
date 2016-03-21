<?php
/**
 * @file
 * Access plugin definition file
 * @author Juanjo Garcia <juanjo@digitalvalue.es>
 * @author Digital Value, SL <info@digitalvalue.es>
 */

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */


$plugin = array(
  'title' => t('Web section'),
  'description' => t('Controls access by field_seccion_de_la_web value'),
  'callback' => 'portales7_node_field_section_ctools_access_check',
  'default' => array('field_seccion_de_la_web' => 0),
  'settings form' => 'portales7_node_field_section_ctools_settings',
  'summary' => 'portales7_node_field_section_ctools_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function portales7_node_field_section_ctools_access_check($conf, $context) {
  // If for some unknown reason that $context isn't set, we just want to be sure.
  if (empty($context) || empty($context->data) || empty($context->data->field_seccion_de_la_web)) {
    return FALSE;
  }
  // If the age set in the panels visibility rule settings is different from the field_age_value
  // access to the pane is denied.
  $seccion = $context->data->portales7_section['und'][0]['tid'];
  if ($seccion !== $conf['section']) {
    return FALSE;
  }
  return TRUE;
}

/**
 * Settings form for the 'field_age_value' access plugin.
 */
function portales7_node_field_section_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['section'] = array(
    '#type' => 'select',
    '#title' => t('Section'),
    '#description' => t('The pane will only be visible if the section field on the node, is the same as set in this field'),
    '#default_value' => $conf['section'],
    '#options' => dvtoolbox_get_taxonomy_options('sections'),
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Provide a summary description based upon the age.
 */
function portales7_node_field_section_ctools_summary($conf, $context) {
  $options = dvtoolbox_get_taxonomy_options('sections', 0, FALSE, FALSE);
  return t('Nodes with section @section', array('@section' => $options[$conf['section']]));
}
