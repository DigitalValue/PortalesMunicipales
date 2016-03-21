<?php
/**
 * @file
 * Provides a ctools content_type plugin to show weather forecast
 * provided by AEMET
 */
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Weather forecast'),
  'description' => t('Shows a pane with the AMET forecast for a given city.'),

// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('aemet'),
// Name of a function which will render the block.
  'render callback' => 'aemet_render',
// The default context.
  'defaults' => _portales7_aemet_defaults(),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'aemet_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_aemet.png',
  'category' => t('Portales 7'),

// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
 * Output function for the 'author pane' content type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function aemet_render($subtype, $conf, $panel_args, $context) {
  $pane=new stdClass();
  $langcode = $conf['language'];
  if ($conf['language'] == 'default') {
    global $user;
    $lang = user_preferred_language($user);
    $langcode = $lang->language;

  }

  $ine = $conf['ine'];
  module_load_include('inc', 'portales7_aemet', 'portales7_aemet.util');
  $elements = _portales7_aemet_get_forecast($ine);
  $elements['conf'] = $conf;
  $pane->content = theme('aemet_widget', $elements);

  $pane->title = t('Weather prediction for %city', array('%city' => $elements['nombre']));
  return $pane;

}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function aemet_edit_form($form, &$form_state) {
  module_load_include('inc', 'portales7_aemet', 'portales7_aemet.provincias');
  $plugin = $form_state['plugin'];
  $conf = $form_state['conf'];
  $form['language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => array(
      'default' => t('Current user language'),
      'es' => 'Español',
      'ca' => 'Català',
      'eu' => 'Euskera',
      'gl' => 'Galego',
      'va' => 'Valencià',
      'en' => 'English',
      'fr' => 'Français',
    ),
    '#default_value' => !empty($conf['language']) ? $conf['language'] : $plugin['defaults']['language'],
  );

  $prov = isset($form_state['values']['provincia']) ? $form_state['values']['provincia'] : $conf['provincia'];
  $form['provincia'] = array(
    '#type' => 'select',
    '#title' => t('Provincia'),
    '#options' => _portales7_aemet_get_provincias(),
    '#default_value' => $prov,
    '#ajax' => array(
      'callback' => '_portales7_aemet_cargar_municipios_AJAX_ctools',
      'wrapper' => 'ine_div',
      'method' => 'replace',
      'effect' => 'fade',
    ),

  );

  $form['ine'] = array(
    '#type' => 'select',
    '#title' => t('Municipio'),
    '#prefix' => '<div id="ine_div">',
    '#suffix' => '</div>',
    '#options' => _portales7_aemet_cargar_municipios($prov),
    '#default_value' => $conf['ine'],
  );

  $form['days'] = array(
    '#type' => 'select',
    '#title' => t('Days'),
    '#description' => t('Number of days to show'),
    '#options' => array( 1 => 1, 2 => 2, 3 => 3, 4 => 4),
    '#required' => TRUE,
    '#default_value' => !empty($conf['days']) ? $conf['days'] : $plugin['defaults']['days'],
    '#multiple' => FALSE,
  );
  $form['fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('What to display'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['fields']['options'] = array(
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
    '#default_value' => !empty($conf['options']) ? $conf['options'] : $plugin['defaults']['options'],
  );
  $form['fields']['show_variables'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tags'),
    '#description' => t('Show field names'),
    '#default_value' => $conf['show_variables'],
  );

  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['display']['border'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show border'),
    '#default_value' => !empty($conf['border']) ? $conf['border'] : $plugin['defaults']['border'],
  );

  $form['display']['disposition'] = array(
    '#type' => 'radios',
    '#title' => t('Disposition'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['disposition']) ? $conf['disposition'] : $plugin['defaults']['disposition'],
    '#options' => array('v' => t('Vertical'), 'h' => t('Horizontal')),
  );
  $form['display']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['width']) ? $conf['width'] : $plugin['defaults']['width'],
  );
  $form['display']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('height'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['height']) ? $conf['height'] : $plugin['defaults']['height'],
  );

  $form['colors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Colors'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['colors']['primary_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary color'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['primary_color']) ? $conf['primary_color'] : $plugin['defaults']['primary_color'],
  );
  $form['colors']['second_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Secondary color'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['second_color']) ? $conf['second_color'] : $plugin['defaults']['second_color'],
  );
  $form['colors']['third_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Third color'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['third_color']) ? $conf['third_color'] : $plugin['defaults']['third_color'],
  );

  return $form;
}

function aemet_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

