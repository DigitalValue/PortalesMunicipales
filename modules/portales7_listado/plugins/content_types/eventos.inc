<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');
function portales7_listado_eventos_content_default_fields() {
return '{
    "main_media" : {
      "formatter" : "fc_main_media",
      "settings": {
        "portales7_mm_image": {"colorbox_node_style":"imagen-custom-300"}
       }
    },
    "title" : {
      "link" : 1
    },
    "teaser" : {
      "trim" : 300
    },
    "eventcalendar" : {},
    "eventdate" : {
      "format_type" : "sin_hora"
    }
  }';
}
$plugin = array(
  'title' => t('Events list by type'),
  'description' => t('Shows a title, teaser, image and data with content.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('portales7_listado_eventos_content_type'),
// Name of a function which will render the block.
  'render callback' => 'portales7_listado_eventos_content_type_render',
// The default context.
  'defaults' => array_merge(_portales7_listado_pane_defaults(), 
    array('future_events' => 1, 'field_event_type' => '', 'fields' => portales7_listado_eventos_content_default_fields(), 'possible_image_styles' => 'imagen-100', 'vocabulario' => '', 'sort' => 'portales7_eventdate:DESC')),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'portales7_listado_eventos_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_listado_eventos_content_type_admin_info',
  'admin title' => 'portales7_listado_eventos_content_type_admin_title',
// this example does not provide 'admin info', which would populate the
// panels builder page preview.
);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_eventos_content_type_render($subtype, $conf, $panel_args, $context) {
  unset($conf['pager']);
  
  $conf['fields'] = portales7_listado_eventos_content_default_fields();
  $conf['subtype'] = 'events';
  $event = dvtoolbox_get_taxonomy_term_by_name('event', 'type');
  $conf['type'] = array($event->tid);
  $conf['debug'] = 1;
  module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
  $p7list = new P7ListController($subtype, $conf, $panel_args, $context);
  $pane = new stdClass();
  $p7list->prepare();
  if (!empty($conf['future_events'])) $p7list->add_eventdate_end_filter();
  $p7list->execute();
  $pane->content = (empty($conf['hide_description']) ? $p7list->getDescription() : '') . $p7list->render();
  if (empty($panel_args)) {
    $pane->title = format_plural($p7list->getNumResults(), 'Event', 'Events', array());
  }
  else {
    $pane->title = format_plural($p7list->getNumResults(), 'Event of type @type', 'Events of type @type', array('@type' => join(',', $panel_args)));
  }
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_eventos_content_type_edit_form($form, &$form_state) {
  
  // The current configuration
  $conf = $form_state['conf'];
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  module_load_include('util.inc', 'portales7');
  _portales7_listado_pane_default_edit_form($form, $conf);

  $info = _field_info_collate_fields();
  $fields_matrix['header'] = array(t('token'), t('field'));
  foreach ($info['instances']['node']['portales7_node'] as $field) {
    $fields_matrix['rows'][] = array (str_replace('portales7_', '', $field['field_name']), $field['label']);
  }
  array_unshift($fields_matrix['rows'], array('title', t('Title')));

  $options = array(-2 => t('From panel arguments'), 0 => t('Any'));
  foreach (dvtoolbox_get_taxonomy_options($conf['vocabulario']) as $k => $v) {
    $options[$k] = $v;
  }
  
  $form['future_events'] = array(
    '#type' => 'checkbox',
    '#title' => t('Future events'),
    '#description' => t('Mark this if you want to show only events with end date in the future.'),
    '#default_value' => $conf['future_events'],
  );
  
  $form['field_event_type'] = array(
  '#type' => 'hidden',
  '#title' => t('Event type'),
  '#description' => t('Event type to show'),
  '#options' => $options,
  '#default_value' => $conf['field_event_type'],
  );

  $form['fields'] = array(
  '#type' => 'textarea',
  '#title' => t('Fields'),
  '#description' => t('Fields to show separated by commas.'),
  //'#default_value' => $conf['fields'],
  '#default_value' => $conf_fields,
  '#maxlength' => 4096,
  '#rows' => 10,
  );

  $form['possible_fields'] = array(
    '#type' => 'hidden',
    '#title' => t('Available fields'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
    '#description' => theme('table', $fields_matrix),
  );

  $image_styles = image_style_options(FALSE);
  $image_styles[''] = t('Left blank for original size');
  $styles = array();
  $styles['header'] = array(t('token'), t('field'));
  $styles['rows'] = array();
  foreach ($image_styles as $token => $description) {
    $styles['rows'][] = array($token, $description);
  }
  $form['possible_image_styles'] = array(
    '#type' => 'select',
    '#title' => t('Available image styles'),
    '#description' => t('Possible styles for image fields'),
    '#options' => image_style_options(),
    '#default_value' => $conf['possible_image_styles'],
  );
    
    $vocab_name['event_types'] = 'event_types';
    $vocab_name['calendar'] = 'calendar';
  
   $form['vocabulario'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('Taxonomy type to show'),
    '#options' => $vocab_name,
    '#default_value' => $conf['vocabulario'],
    );

   $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );
  

  return $form;
}

function portales7_listado_eventos_content_type_edit_form_submit(&$form, &$form_state) {
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  _portales7_listado_pane_default_edit_form_submit($form, $form_state);
}


function portales7_listado_eventos_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_listado_eventos_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function portales7_listado_eventos_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  module_load_include('util.inc', 'portales7');
  $options = _portales7_listado_content_types();
  return t('Events list of', array('@type' => $options[$conf['field_event_type']]));
}
