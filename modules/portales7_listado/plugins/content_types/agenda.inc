<?php

/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/

module_load_include('inc', 'portales7_listado','portales7_listado.panels');

$plugin = array(
  'title' => t('Agenda'),
  'description' => t('Shows a pane with events.'),
  'single' => TRUE,
  'content_types' => array('portales7_listado_agenda_content_type'),
  'render callback' => 'portales7_listado_agenda_content_type_render',
  'defaults' => array_merge(
    _portales7_listado_pane_defaults(),
    array(
    'calendar' => '',
    'date_style' => '',
    'hide_end_date' => FALSE,
    'image_style' => '',
    'sort' => 'portales7_eventdate:DESC')),
  'edit form' => 'portales7_listado_agenda_content_type_edit_form',
  'icon' => 'icon_banners.png',
  'category' => t('Portales 7'),
  'admin title' => 'portales7_listado_agenda_content_type_admin_title',
  'admin info' => 'portales7_listado_agenda_content_type_admin_info',

);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function portales7_listado_agenda_content_type_render($subtype, $conf, $panel_args, $context) {
  module_load_include('util.inc', 'portales7');
  $event = dvtoolbox_get_taxonomy_term_by_name('event', 'type', FALSE);
  $argument = $conf['arguments'];
  $fields = '{
    "title": {
      "link":1
    },
    "teaser": {},
    "event_type": {},
    "eventdate" : {
      "type" : "custom_date",
      "settings": {
        "class_title": "custom_date_newsdate"
      }
    },
    "eventcalendar" : {},
    "main_media" : {
      "formatter" : "fc_main_media",
      "settings": {
        "portales7_mm_image": {
          "colorbox_node_style":"' . $conf['image_style'] . '"
        }
      }
    }
  }';
  $pane=new stdClass();
  $df = NULL;
  if ($df = array_pop($panel_args)) {
    if (!strtotime($df)) {
      array_push($panel_args, $df);
      $df = NULL;
    }
  }
  if ($conf['calendar'] == '-1') {
    $calendar = array_shift($panel_args);
    if (($t = dvtoolbox_get_taxonomy_term_by_name($calendar, 'calendar', FALSE)) !== FALSE) {
      $conf['calendar'] = $t->tid;
    }
    else {
      $conf['calendar'] = 0;
    }
  }
  $arguments = array();
  if (!empty($conf['arguments'])) {
    $arguments = explode('/', $conf['arguments']);
  }
  if ($conf['include_path']){
    $arguments = array_merge($arguments, $panel_args); 
  }
  $view = _portales7_listado_prepare_view(array($event->tid => $event->tid), $arguments, $fields, $conf['items'], $conf['offset']);
  
  //$arguments[] = 'evento';
  //_portales7_listado_add_argument($view->display['default']->handler, 'tid_' . count($arguments), 'type');
  if ($conf['calendar']) {
    $pane->title = t('Events from %calendar calendar', array('%calendar' => taxonomy_term_load($conf['calendar'])->name));
    _portales7_listado_add_tid_filter($view->display['default']->handler, 'portales7_eventcalendar', 'calendar', array($conf['calendar'] => $conf['calendar']));
  }
  else {
    $pane->title = t('Events from all calendars');
  }
  $classes = $conf['classes'];
  if (is_array($conf['classes'])){
    $classes = join(' ', $conf['classes']);
  }
  if (!empty($_GET['sort'])) $conf['sort'] = $_GET['sort'];
  if (!empty($conf['sort'])) {
    list($field, $order) = explode(':', $conf['sort']);
    if (preg_match('/^portales7_/', $field)) {
      _portales7_listado_add_sort_by_field($view->display['default']->handler, $field, $order);
    }
    else {
      _portales7_listado_add_generic_sort($view->display['default']->handler, $field, $order);
    }
  }
  //_portales7_listado_add_sort_by_field($view->display['default']->handler, 'portales7_eventdate', 'ASC');
  _portales7_listado_add_generic_sort($view->display['default']->handler, 'sticky', 'DESC');
  if ($df) {
    array_push($arguments, $df);
    _portales7_listado_add_eventdate_argument($view->display['default']->handler);
  }
  else {
    _portales7_listado_add_eventdate_end_filter($view->display['default']->handler);
  }
  if ($conf['promoted']) {
    _portales7_listado_add_generic_filter($view->display['default']->handler, 'promote', 1);
  }
  if (function_exists('portales7_og_add_og_filter')) {
    portales7_og_add_og_filter($view->display['default']->handler, $conf['og_group']);
  }
  $view->name .= '_agenda';
  $view->pane_conf = $conf;
  
  if ($conf['pager']) {
    _portales7_listado_add_pager($view->display['default']->handler, array('items_per_page' => $conf['items'], 'id' => 1, 'offset' => $conf['offset']));
  }
  $output = $view->execute_display('default',$arguments);
  if (!empty ($view->result)) {
    $prefix = "<div class=\"portales7_listado {$view->name} {$view->name}-{$conf['image_style']}\"><div class=\"{$classes}\">";
    $suffix= '</div></div>';
    $more_link = '';
    if (!empty($conf['more_link']) && count($view->result) >= $conf['items']) {
      $more_link = '<div class="more-link">' . l(t('More'), $conf['more_link']) . '</div>';
    }
    $pane->content = $prefix . $output . $more_link . $suffix;
  }
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_listado_agenda_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  module_load_include('inc', 'portales7', 'portales7.util');
  _portales7_listado_pane_default_edit_form($form, $conf);

  $image_styles = image_style_options(TRUE);
  $image_styles['hidden'] = t('Hide image');
  $calendars = portales7_taxonomy_term_select('calendar');
  $calendars['-1'] = t('Get from path');
  $form['calendar'] = array(
    '#type' => 'select',
    '#title' => t('Calendar'),
    '#description' => t('Filter elements by calendar. Get from path chooses the first path element as calendar if available.'),
    '#options' => $calendars,
    '#default_value' => $conf['calendar'],
    '#multiple' => FALSE,
  );
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
    '#description' => t('Select the image style to use with main image'),
  );
  
  $form['date_style'] = array(
    '#type' => 'select',
    '#title' => t('Date format'),
    '#options' => _portales7_get_date_format_select(),
    '#default_value' => $conf['date_style'],
    '#description' => t('Format to use with displayed dates'),
  );
  
  $form['hide_end_date'] = array(
  '#type' => 'checkbox',
  '#title' => t('Hide end date'),
  '#description' => t('Mark to hide end date.'),
  '#default_value' => $conf['hide_end_date'],
  );
  $form['options']['sort']['#options'] += array(
    'portales7_eventdate:ASC' => t('Event date ascendant'),
    'portales7_eventdate:DESC' => t('Event date descendant'),
  );
  return $form;
}

function portales7_listado_agenda_content_type_edit_form_submit(&$form, &$form_state) {
  module_load_include('inc', 'portales7_listado','portales7_listado.panels');
  _portales7_listado_pane_default_edit_form_submit($form, $form_state);
}

function portales7_listado_agenda_content_type_admin_title($subtype, $conf, $context = NULL) {
  
  $pane = new stdClass();
  if ( $conf['calendar'] == -1) {
    $pane->title=t('Events from %calendar calendar', array('%calendar' => t('Get from path')));
  }
  elseif ($conf['calendar']) {
    $calendar_name = taxonomy_term_load($conf['calendar'])->name;
    $pane->title=t('Events from %calendar calendar', array('%calendar' => $calendar_name));
  }
  else {
    $pane->title=t('Events from all calendars');
  }

  return $pane->title;
}

function portales7_listado_agenda_content_type_admin_info($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $pane = new stdClass();
  $pane->title = portales7_listado_agenda_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
