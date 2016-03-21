<?php
function portales7_json_deliver($page_callback_result) {
  if (!is_array($page_callback_result)) {
    drupal_deliver_html_page($page_callback_result);
  }
  if (isset($page_callback_result) && is_null(drupal_get_http_header('Content-Type'))) {
    drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  }

  // Send appropriate HTTP-Header for browsers and search engines.
  global $language;
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  drupal_add_http_header('Content-Language', $language->language);

  print json_encode($page_callback_result);
}

function portales7_json_node($node) {
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  drupal_json_output($node);
}

function portales7_json_listado($term = '') {
  module_load_include('util.inc', 'portales7');
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  if (!empty($_GET['type'])) $term = $_GET['type'];
  if ($t = dvtoolbox_get_taxonomy_term_by_name($term,'type',FALSE)){
    $type = array($t->tid => $t->tid);
  }
  else {
    drupal_json_output(array('error' => array('errno' => '1',
      'message' => format_string('@param paremeter is not set or has an invalid value', array('@param' => $term)),
      'localized_message' => t('@param paremeter is not set or has an invalid value', array('@param' => $term)),
      )));
      return;
  }
  $arguments = array();
  if (!empty($_GET['arguments'])) {
    $arguments = explode('/', $conf['arguments']);
  }

  module_load_include('util.inc', 'portales7_listado');

  if (!isset($_GET['fields'])) $_GET['fields'] = '';
  //$view = _portales7_json_prepare_view($type, $arguments, $_GET['fields'], $_GET['items'], $_GET['offset']);
  $view = _portales7_listado_prepare_view($type, $arguments, $_GET['fields'], $_GET['items'], isset($_GET['offset']) ? $_GET['offset'] : 0);

  _portales7_listado_generic_field_add($view->display['default']->handler, 'nid');
  if (!empty($_GET['sort'])) {
    list($field, $order) = explode(':', $_GET['sort']);
    if (preg_match('/^portales7_/', $field)) {
      _portales7_listado_add_sort_by_field($view->display['default']->handler, $field, $order);
    }
    else {
      _portales7_listado_add_generic_sort($view->display['default']->handler, $field, $order);
    }
  }
  if (!empty($_GET['promoted'])) {
    _portales7_listado_add_generic_filter($view->display['default']->handler, 'promote', 1);
  }
  if (module_exists('og') && !empty($_GET['og_group']) && is_numeric($_GET['og_group'])) {
    _portales7_listado_add_og_filter($view->display['default']->handler, $_GET['og_group']);
  }

  if (!empty($_GET['eventdate_filter'])) {
    _portales7_listado_add_eventdate_end_filter($view->display['default']->handler);
  }

  if (!empty($_GET['eventdate_from'])) {
    _portales7_listado_add_eventdate_from_filter($view->display['default']->handler, $_GET['eventdate_from']);
  }

  if (!empty($_GET['event_type_filter'])) {
    _portales7_listado_add_event_type_filter($view->display['default']->handler, $_GET['event_type_filter']);
  }

  if (!empty($_GET['eventcalendar_filter'])) {
    _portales7_listado_add_eventcalendar_filter($view->display['default']->handler, $_GET['eventcalendar_filter']);
  }

  _portales7_listado_add_generic_sort($view->display['default']->handler, 'sticky', 'DESC');
  $output = $view->execute_display('default',$arguments);
  $results = array();
  foreach ($view->result as $res) {
    $results[] = _portales7_json_get_node(node_load($res->nid));
    //$results[] = $res;
  }

  drupal_json_output(array('nodes' => $results));
}


function _portales7_json_prepare_view($type, $arguments, $fields, $numitems, $offset) {
  module_load_include('inc','portales7_listado', 'portales7_listado.util');
  if (!is_array($fields)) $fields = explode(',', $fields);
  $view = _portales7_json_get_view();
  foreach ($fields as $field) {
    $field = trim($field);
    if (!empty($field)) {
      $options = '';
      if (strpos($field, ':') !== FALSE ){
        list($field,$options) = explode(':', $field, 2);
      }
      if (function_exists("_portales7_listado_add_$field")){
        call_user_func_array("_portales7_listado_add_$field", array(&$view->display['default']->handler, $options));

      }
      else {
        drupal_set_message(t('@field Is not a valid field', array('@field' => $field)), 'error');
      }
    }
  }
  for ($i = 0; $i < count($type); $i++){
    _portales7_listado_add_tid_filter($view->display['default']->handler, 'portales7_type', 'type', $type);
  }
  for ($i = 0; $i < count($arguments); $i++){
    _portales7_listado_add_argument($view->display['default']->handler, 'tid_' . $i, 'category');
  }

  _portales7_listado_set_num_items($view->display['default']->handler, $numitems, $offset);
  return $view;
}

function _portales7_json_get_view() {
$view = new view();
$view->name = 'p7_json';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'p7 json';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
$handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
$handler->display->display_options['style_plugin'] = 'views_json';
$handler->display->display_options['style_options']['plaintext_output'] = 0;
$handler->display->display_options['style_options']['remove_newlines'] = 0;
$handler->display->display_options['style_options']['jsonp_prefix'] = '';
$handler->display->display_options['style_options']['using_views_api_mode'] = 1;
$handler->display->display_options['style_options']['object_arrays'] = 0;
$handler->display->display_options['style_options']['numeric_strings'] = 0;
$handler->display->display_options['style_options']['bigint_string'] = 0;
$handler->display->display_options['style_options']['pretty_print'] = 0;
$handler->display->display_options['style_options']['unescaped_slashes'] = 0;
$handler->display->display_options['style_options']['unescaped_unicode'] = 0;
$handler->display->display_options['style_options']['char_encoding'] = array();

$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = 'nid';

/* Filter criterion: Contenido: Publicado */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  return $view;
}
