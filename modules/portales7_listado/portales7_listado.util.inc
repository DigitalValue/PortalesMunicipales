<?php 
function _portales7_listado_available_fields_matrix() {
  $info = _field_info_collate_fields();
  $fields_matrix['header'] = array(t('token'), t('field'));
  foreach ($info['instances']['node']['portales7_node'] as $field) {
    $fn = str_replace('portales7_', '', $field['field_name']);
    if (function_exists('_portales7_listado_add_' . $fn)) {
      $fields_matrix['rows'][] = array ($fn , $field['label']);
    }
  }
  array_unshift($fields_matrix['rows'], array('title', t('Title')));
  return $fields_matrix;
}

function _portales7_listado_get_view(){
$view = new view;
$view->name = 'portales7_listado';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Portales 7 listado';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';

$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';

$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
//* Sort criterion: Contenido: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';

/* Filter criterion: Contenido: Publicado */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'portales7_node' => 'portales7_node',
);

/* Filter criterion: Traducción del contenido: Idioma */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  'und' => 'und',
);

$translatables['test'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reiniciar'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('listado/[portales7_type]'),
);
return $view;
}

function _portales7_listado_add_pager(&$handler, $options) {
  $handler->display->display_options['pager']['type'] = empty($options['type']) ? 'mini' : $options['type'];
  $handler->display->display_options['pager']['options']['items_per_page'] = $options['items_per_page'];
  $handler->display->display_options['pager']['options']['offset'] = $options['offset'];
  $handler->display->display_options['pager']['options']['id'] = $options['id'];
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  
}

function _portales7_listado_add_eventdate_end_filter(&$handler) {
  /* Filter criterion: Contenido: Event date - end date (portales7_eventdate:value2) */
  $handler->display->display_options['filters']['portales7_eventdate_value2']['id'] = 'portales7_eventdate_value2';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['table'] = 'field_data_portales7_eventdate';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['field'] = 'portales7_eventdate_value2';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['year_range'] = '-0:+10';
}


function _portales7_listado_add_eventdate_from_filter(&$handler, $timestamp = 0) {
  if ($timestamp <= 0) $timestamp = strtotime('3 month ago');
  /* Criterios de filtrado: Contenido: Event date - fecha de finalización (portales7_eventdate:value2) */
  $handler->display->display_options['filters']['portales7_eventdate_value2']['id'] = 'portales7_eventdate_value2';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['table'] = 'field_data_portales7_eventdate';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['field'] = 'portales7_eventdate_value2';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['portales7_eventdate_value2']['value']['value'] = date('Y-m-d', $timestamp);
}

function _portales7_listado_add_eventdate_argument(&$handler) {
  /* Filtro contextual: Contenido: Event date - fecha de inicio (portales7_eventdate) */
  $handler->display->display_options['arguments']['portales7_eventdate_value']['id'] = 'portales7_eventdate_value';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['table'] = 'field_data_portales7_eventdate';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['field'] = 'portales7_eventdate_value';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['portales7_eventdate_value']['granularity'] = 'day';
}

function _portales7_listado_add_og_filter(&$handler, $gid) {
  /* Filter criterion: Contenido: Group audience gid */
  $handler->display->display_options['filters']['group_audience']['id'] = 'group_audience';
  $handler->display->display_options['filters']['group_audience']['table'] = 'field_data_group_audience';
  $handler->display->display_options['filters']['group_audience']['field'] = 'group_audience_gid';
  $handler->display->display_options['filters']['group_audience']['value'] = array('value' => $gid);
}

function _portales7_listado_add_generic_filter(&$handler, $property, $value) {
  $handler->display->display_options['filters'][$property]['id'] = $property;
  $handler->display->display_options['filters'][$property]['table'] = 'node';
  $handler->display->display_options['filters'][$property]['field'] = $property;
  $handler->display->display_options['filters'][$property]['value'] = $value;
}

function _portales7_listado_add_tid_filter(&$handler, $field, $voc, $values) {
  /* Filter criterion: Contenido: Calendar (portales7_eventcalendar) */
  $handler->display->display_options['filters'][$field . '_tid']['id'] = $field . '_tid';
  $handler->display->display_options['filters'][$field . '_tid']['table'] = 'field_data_' . $field;
  $handler->display->display_options['filters'][$field . '_tid']['field'] = $field . '_tid';
  $handler->display->display_options['filters'][$field . '_tid']['value'] = $values;
  $handler->display->display_options['filters'][$field . '_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters'][$field . '_tid']['vocabulary'] = $voc;
  $handler->display->display_options['filters'][$field . '_tid']['type'] = 'select';
}

function _portales7_listado_add_generic_sort(&$handler, $property, $order = 'DESC') {
  $handler->display->display_options['sorts'][$property]['id'] = $property;
  $handler->display->display_options['sorts'][$property]['table'] = 'node';
  $handler->display->display_options['sorts'][$property]['field'] = $property;
  $handler->display->display_options['sorts'][$property]['order'] = $order;
}

function _portales7_listado_add_sort_by_field(&$handler, $field, $order = 'DESC') {
  $handler->display->display_options['sorts'][$field . '_value'] = array(
    'id' => $field . '_value',
    'table' => 'field_data_' . $field,
    'field' => $field . '_value',
    'order' => $order,
  );
}

function _portales7_listado_add_argument(&$handler, $name) {
  /* Contextual filter: Type: mandatory */
  $handler->display->display_options['arguments'][$name]['id'] = $name;
  $handler->display->display_options['arguments'][$name]['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments'][$name]['field'] = 'tid';
  $handler->display->display_options['arguments'][$name]['ui_name'] = 'Type: mandatory';
  $handler->display->display_options['arguments'][$name]['default_action'] = 'not found';
  $handler->display->display_options['arguments'][$name]['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments'][$name]['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments'][$name]['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments'][$name]['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments'][$name]['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments'][$name]['specify_validation'] = 1;
  $handler->display->display_options['arguments'][$name]['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments'][$name]['validate_options']['vocabularies'] = array();
  $handler->display->display_options['arguments'][$name]['validate_options']['type'] = 'synonym_tid';
  $handler->display->display_options['arguments'][$name]['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments'][$name]['break_phrase'] = 1;
  $handler->display->display_options['arguments'][$name]['add_table'] = 1;
  $handler->display->display_options['arguments'][$name]['require_value'] = 0;
  $handler->display->display_options['arguments'][$name]['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments'][$name]['set_breadcrumb'] = 0;
}

function _portales7_listado_set_num_items(&$handler, $count, $offset = 0) {
	$handler->display->display_options['pager']['options']['items_per_page'] = $count;
  $handler->display->display_options['pager']['options']['offset'] = $offset;
}

function _portales7_listado_add_title(&$handler, $options = NULL) {
  if(is_string($options)) {
    $options = (object) array('link' => ($options == 'nolink') ? 0 : 1);
  }
  else if (!is_object($options)) $options = (object) $options;
  if (!isset($options->link)) {
    $options->link = FALSE;
  }
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title'] = _portales7_listado_default_settings();
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = $options->link;
}

function _portales7_listado_add_weblink(&$handler){
  /* Campo: Contenido: Link */
  $handler->display->display_options['fields']['portales7_weblink']['id'] = 'portales7_weblink';
  $handler->display->display_options['fields']['portales7_weblink']['table'] = 'field_data_portales7_weblink';
  $handler->display->display_options['fields']['portales7_weblink']['field'] = 'portales7_weblink';
  $handler->display->display_options['fields']['portales7_weblink']['label'] = '';
  $handler->display->display_options['fields']['portales7_weblink']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['portales7_weblink']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['portales7_weblink']['delta_offset'] = '0';
  $handler->display->display_options['fields']['portales7_weblink']['multi_type'] = 'ul';
}

function _portales7_listado_add_path(&$handler, $options = array()) {
  _portales7_listado_generic_field_add($handler, 'path', $options);
}


function _portales7_listado_add_created(&$handler, $options = array()) {
  if (!is_array($options)) {
    list($o['date_format'], $o['custom_date_format']) = explode(':', $options, 2);
    $options = $o;
  }
  if (empty($options['date_format'])) {
    $options['date_format'] = array('date_format' => 'sin_hora');
  }
  _portales7_listado_generic_field_add($handler, 'created', $options);
}

function _portales7_listado_add_changed(&$handler, $options = array()) {
  if (!is_array($options)) {
    list($o['date_format'], $o['custom_date_format']) = explode(':', $options, 2);
    $options = $o;
  }
  if (empty($options['date_format'])) {
    $options['date_format'] = array('date_format' => 'sin_hora');
  }
  _portales7_listado_generic_field_add($handler, 'changed', $options);
}

function _portales7_listado_add_banner_group(&$handler) {
  _portales7_listado_generic_taxonomy_field_add('portales7_banner_group', $handler);
}

function _portales7_listado_add_type(&$handler, $link = 1) {
  _portales7_listado_generic_taxonomy_field_add('portales7_type', $handler);
  $handler->display->display_options['fields']['portales7_type']['alter']['make_link'] = $link;
  $handler->display->display_options['fields']['portales7_type']['alter']['path'] = 'listado/[portales7_type]';
}

function _portales7_listado_add_event_type(&$handler, $link = 1) {
  _portales7_listado_generic_taxonomy_field_add('portales7_event_type', $handler);
  $handler->display->display_options['fields']['portales7_event_type']['alter']['make_link'] = $link;
  $handler->display->display_options['fields']['portales7_event_type']['alter']['path'] = 'listado-evento/[portales7_event_type]';
}

function _portales7_listado_add_category(&$handler) {
  _portales7_listado_generic_taxonomy_field_add('portales7_category', $handler);
  //$handler->display->display_options['fields']['portales7_category']['alter']['make_link'] = 1;
  //$handler->display->display_options['fields']['portales7_category']['alter']['path'] = 'listado/[portales7_type]';
}

function _portales7_listado_add_families(&$handler) {
  _portales7_listado_generic_taxonomy_field_add('portales7_families', $handler);
}

function _portales7_listado_add_section(&$handler) {
  _portales7_listado_generic_taxonomy_field_add('portales7_section', $handler);
}

function _portales7_listado_add_main_image(&$handler, $formatter = 'thumbnail') {
  _portales7_listado_generic_filefield_add('portales7_main_image', $handler, $formatter);
}

function _portales7_listado_add_banner_image(&$handler, $formatter = 'thumbnail') {
  _portales7_listado_generic_filefield_add('portales7_banner_image', $handler, $formatter);
}

function _portales7_listado_add_banner_weight(&$handler, $formatter = 'default') {
  _portales7_listado_generic_text_add('portales7_banner_weight', $handler);
}

function _portales7_listado_add_images(&$handler, $formatter = 'thumbnail') {
  _portales7_listado_generic_filefield_add('portales7_images', $handler, $formatter);
}

function _portales7_listado_add_files(&$handler, $formatter = 'thumbnail') {
  _portales7_listado_generic_filefield_add('portales7_files', $handler, $formatter);
}

function _portales7_listado_add_videos(&$handler, $formatter = '640x480') {
  _portales7_listado_generic_filefield_add('portales7_videos', $handler, $formatter);
}

function _portales7_listado_add_concept(&$handler, $trim = 600) {
  _portales7_listado_generic_text_add('portales7_concept', $handler, $trim);
}
function _portales7_listado_add_pretitle(&$handler, $trim = 600) {
  _portales7_listado_generic_text_add('portales7_pretitle', $handler, $trim);
}
function _portales7_listado_add_subtitle(&$handler, $trim = 600) {
  _portales7_listado_generic_text_add('portales7_subtilte', $handler, $trim);
}

function _portales7_listado_add_source(&$handler, $trim = 600) {
  _portales7_listado_generic_text_add('portales7_source', $handler, $trim);
}

function _portales7_listado_add_link(&$handler, $trim = 600) {
  _portales7_listado_generic_text_add('portales7_link', $handler, $trim);
}

function _portales7_listado_add_newsdate(&$handler, $formatter = 'fecha_texto'){
  _portales7_listado_generic_date_add('portales7_newsdate', $handler, $formatter);
}

function _portales7_listado_add_eventdate(&$handler, $formatter = 'short'){
  _portales7_listado_generic_date_add('portales7_eventdate', $handler, $formatter);
}

function _portales7_listado_add_teaser(&$handler, $trim = 600) {
  if (is_object($trim)){
    $trim = !empty($trim->trim) ? $trim->trim : 600;
  }
  _portales7_listado_generic_text_add('portales7_teaser', $handler, $trim);
}

function _portales7_listado_add_event_note(&$handler, $trim = 600) {
  _portales7_listado_generic_text_add('portales7_event_note', $handler, $trim);
}

function _portales7_listado_add_media(&$handler, $formatter = 'fc_media') {
  return _portales7_listado_add_field_collection($handler, 'portales7_media', $formatter);
}
function _portales7_listado_add_main_media(&$handler, $options) {
  return _portales7_listado_add_field_collection($handler, 'portales7_main_media', $options);
}
function _portales7_listado_add_related_article(&$handler, $formatter = 'fc_relations') {
  return _portales7_listado_add_field_collection($handler, 'portales7_related_article', $formatter);
}
function _portales7_listado_add_related_entity(&$handler, $formatter = 'fc_relations') {
  return _portales7_listado_add_field_collection($handler, 'portales7_related_entity', $formatter);
}

function _portales7_listado_add_field_collection(&$handler, $field, $options = NULL) {
  /* Field: Content: Attachments */
$handler->display->display_options['fields'][$field] = _portales7_listado_default_settings();
$handler->display->display_options['fields'][$field]['id'] = $field;
$handler->display->display_options['fields'][$field]['table'] = 'field_data_' . $field;
$handler->display->display_options['fields'][$field]['field'] = $field;
$handler->display->display_options['fields'][$field]['hide_empty'] = TRUE;
$settings = array();
if (empty($options)) {
  $formatter = 'fc_default';
}
else {
  $formatter = isset($options->formatter) ? $options->formatter : 'fc_default';
  $settings = isset($options->settings) ? (array) $options->settings : array();
}
$handler->display->display_options['fields'][$field]['type'] = $formatter;
$handler->display->display_options['fields'][$field]['settings'] = $settings;
$handler->display->display_options['fields'][$field]['delta_offset'] = '0';
}

function _portales7_listado_add_eventcalendar(&$handler) {
  _portales7_listado_generic_taxonomy_field_add('portales7_eventcalendar', $handler);
  $handler->display->display_options['fields']['portales7_eventcalendar']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['portales7_eventcalendar']['alter']['path'] = 'listado-calendario/[portales7_eventcalendar]';
}

function _portales7_listado_add_eventcalendar_filter(&$handler, $calendar = 'any') {
  if ($calendar != 'any') {
    if (!is_numeric($calendar) && ($c = dvtoolbox_get_taxonomy_term_by_name($calendar, 'calendar'))) { $calendar = $c->tid; }
    if (!empty($calendar)) {
      /* Filter criterion: Content: Calendar (portales7_eventcalendar) */
      $handler->display->display_options['filters']['portales7_eventcalendar_tid']['id'] = 'portales7_eventcalendar_tid';
      $handler->display->display_options['filters']['portales7_eventcalendar_tid']['table'] = 'field_data_portales7_eventcalendar';
      $handler->display->display_options['filters']['portales7_eventcalendar_tid']['field'] = 'portales7_eventcalendar_tid';
      $handler->display->display_options['filters']['portales7_eventcalendar_tid']['value'] = array(
        $calendar => $calendar,
      );
      $handler->display->display_options['filters']['portales7_eventcalendar_tid']['type'] = 'select';
      $handler->display->display_options['filters']['portales7_eventcalendar_tid']['vocabulary'] = 'calendar';
    } 
  }
}

function _portales7_listado_add_event_type_filter(&$handler, $et = 'any') {
  if ($et != 'any') {
    if (!is_numeric($et) && ($t = dvtoolbox_get_taxonomy_term_by_name($et, 'event_types'))) { $et = $t->tid; }
    if (!empty($et)) {
      $handler->display->display_options['filters']['portales7_event_type_tid']['id'] = 'portales7_event_type_tid';
      $handler->display->display_options['filters']['portales7_event_type_tid']['table'] = 'field_data_portales7_event_type';
      $handler->display->display_options['filters']['portales7_event_type_tid']['field'] = 'portales7_event_type_tid';
      $handler->display->display_options['filters']['portales7_event_type_tid']['value'] = array(
        $et => $et,
      );
      $handler->display->display_options['filters']['portales7_event_type_tid']['reduce_duplicates'] = TRUE;
      $handler->display->display_options['filters']['portales7_event_type_tid']['vocabulary'] = 'event_types';
    }
  }
}

function _portales7_listado_default_settings() {
  $settings = array();
  $settings['alter']['absolute'] = 0;
  $settings['alter']['alter_text'] = 0;
  $settings['alter']['ellipsis'] = 1;
  $settings['alter']['external'] = 0;
  $settings['alter']['html'] = 0;
  $settings['alter']['make_link'] = 0;
  $settings['alter']['more_link'] = 0;
  $settings['alter']['nl2br'] = 0;
  $settings['alter']['replace_spaces'] = 0;
  $settings['alter']['strip_tags'] = 0;
  $settings['alter']['trim'] = 0;
  $settings['alter']['trim_whitespace'] = 0;
  $settings['alter']['word_boundary'] = 1;
  $settings['element_default_classes'] = 1;
  $settings['element_label_colon'] = FALSE;
  $settings['field_api_classes'] = 0;
  $settings['hide_alter_empty'] = 1;
  $settings['hide_empty'] = 1;
  $settings['label'] = '';
  $settings['empty_zero'] = 0;
  
  return $settings;
}

function _portales7_listado_add_body(&$handler, $formatter = '') {
  if (empty($formatter)) $formatter = 'text_default';
  /* Campo: Contenido: Cuerpo */
  $handler->display->display_options['fields']['body'] = _portales7_listado_default_settings();
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = $formatter;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'teaser_class' => 'embedded-teaser',
  );
}

function _portales7_listado_add_related(&$handler, $options = '') {
  /* Campo: Contenido: Related */
  $handler->display->display_options['fields']['portales7_related']['id'] = 'portales7_related';
  $handler->display->display_options['fields']['portales7_related']['table'] = 'field_data_portales7_related';
  $handler->display->display_options['fields']['portales7_related']['field'] = 'portales7_related';
  $handler->display->display_options['fields']['portales7_related']['settings'] = array();
  $handler->display->display_options['fields']['portales7_related']['delta_offset'] = '0';
  $handler->display->display_options['fields']['portales7_related']['multi_type'] = 'ul';
}

function _portales7_listado_add_telephone(&$handler, $options = '') {
  if (empty($handler->display->display_options['relationships']['portales7_place_target_id'])){
    /* Relación: Referencia a entidades: Entidad referenciada */
    $handler->display->display_options['relationships']['portales7_place_target_id']['id'] = 'portales7_place_target_id';
    $handler->display->display_options['relationships']['portales7_place_target_id']['table'] = 'field_data_portales7_place';
    $handler->display->display_options['relationships']['portales7_place_target_id']['field'] = 'portales7_place_target_id';
  }
  
  /* Campo: Contenido: Telephone */
  $handler->display->display_options['fields']['portales7_entity_telephone']['id'] = 'portales7_entity_telephone';
  $handler->display->display_options['fields']['portales7_entity_telephone']['table'] = 'field_data_portales7_entity_telephone';
  $handler->display->display_options['fields']['portales7_entity_telephone']['field'] = 'portales7_entity_telephone';
  $handler->display->display_options['fields']['portales7_entity_telephone']['relationship'] = 'portales7_place_target_id';
  $handler->display->display_options['fields']['portales7_entity_telephone']['label'] = '';
  $handler->display->display_options['fields']['portales7_entity_telephone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['portales7_entity_telephone']['delta_offset'] = '0';
  $handler->display->display_options['fields']['portales7_entity_telephone']['multi_type'] = 'ul';
}

function _portales7_listado_add_address(&$handler, $options = '') {
  if (empty($handler->display->display_options['relationships']['portales7_place_target_id'])){
    /* Relación: Referencia a entidades: Entidad referenciada */
    $handler->display->display_options['relationships']['portales7_place_target_id']['id'] = 'portales7_place_target_id';
    $handler->display->display_options['relationships']['portales7_place_target_id']['table'] = 'field_data_portales7_place';
    $handler->display->display_options['relationships']['portales7_place_target_id']['field'] = 'portales7_place_target_id';
  }
  /* Campo: Contenido: Postal address */
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['id'] = 'portales7_entity_postaladdress';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['table'] = 'field_data_portales7_entity_postaladdress';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['field'] = 'portales7_entity_postaladdress';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['relationship'] = 'portales7_place_target_id';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['label'] = '';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['delta_offset'] = '0';
  $handler->display->display_options['fields']['portales7_entity_postaladdress']['multi_type'] = 'ul';
}
function _portales7_listado_add_opendiv(&$handler, $options = NULL) {
  /* Campo: Global: Texto personalizado */
  $id = 'opendiv_' . count($handler->display->display_options['fields']);
  $attrs = '';
  if (is_object($options)) {
    $attrs = drupal_attributes((array)$options);
  }
  $handler->display->display_options['fields'][$id]['id'] = $id;
  $handler->display->display_options['fields'][$id]['table'] = 'views';
  $handler->display->display_options['fields'][$id]['field'] = 'nothing';
  $handler->display->display_options['fields'][$id]['label'] = '';
  $handler->display->display_options['fields'][$id]['alter']['text'] = "<div$attrs>";
  $handler->display->display_options['fields'][$id]['element_type'] = '0';
  $handler->display->display_options['fields'][$id]['element_label_colon'] = FALSE;
  $handler->display->display_options['fields'][$id]['element_wrapper_type'] = '0';
  $handler->display->display_options['fields'][$id]['element_default_classes'] = FALSE;
}
function _portales7_listado_add_closediv(&$handler, $options = NULL) {
  /* Campo: Global: Texto personalizado */
  $id = 'closediv_' . count($handler->display->display_options['fields']);
  $attrs = '';
  if (is_object($options)) {
    $attrs = drupal_attributes((array)$options);
  }
  $handler->display->display_options['fields'][$id]['id'] = $id;
  $handler->display->display_options['fields'][$id]['table'] = 'views';
  $handler->display->display_options['fields'][$id]['field'] = 'nothing';
  $handler->display->display_options['fields'][$id]['label'] = '';
  $handler->display->display_options['fields'][$id]['alter']['text'] = "</div$attrs>";
  $handler->display->display_options['fields'][$id]['element_type'] = '0';
  $handler->display->display_options['fields'][$id]['element_label_colon'] = FALSE;
  $handler->display->display_options['fields'][$id]['element_wrapper_type'] = '0';
  $handler->display->display_options['fields'][$id]['element_default_classes'] = FALSE;
}
/*
function _portales7_listado_add_related_entity(&$handler, $view_mode = 'full') {
  $handler->display->display_options['fields']['portales7_related_entity']['id'] = 'portales7_related_entity';
  $handler->display->display_options['fields']['portales7_related_entity']['table'] = 'field_data_portales7_related_entity';
  $handler->display->display_options['fields']['portales7_related_entity']['field'] = 'portales7_related_entity';
  $handler->display->display_options['fields']['portales7_related_entity']['label'] = '';
  $handler->display->display_options['fields']['portales7_related_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['portales7_related_entity']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => $view_mode,
  );
  $handler->display->display_options['fields']['portales7_related_entity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['portales7_related_entity']['multi_type'] = 'ul';
}
*/

function _portales7_listado_add_video_url(&$handler, $video_style = 'normal') {
  /* Campo: Contenido: Video URL */
  $handler->display->display_options['fields']['portales7_video_url']['id'] = 'portales7_video_url';
  $handler->display->display_options['fields']['portales7_video_url']['table'] = 'field_data_portales7_video_url';
  $handler->display->display_options['fields']['portales7_video_url']['field'] = 'portales7_video_url';
  $handler->display->display_options['fields']['portales7_video_url']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['portales7_video_url']['settings'] = array(
    'video_style' => $video_style,
  );
  $handler->display->display_options['fields']['portales7_video_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['portales7_video_url']['multi_type'] = 'ul';
}

function _portales7_listado_add_event_place(&$handler, $image_style = 'imagen-custom-100') {
  /* Campo: Contenido: Place */
  $handler->display->display_options['fields']['portales7_event_place']['id'] = 'portales7_event_place';
  $handler->display->display_options['fields']['portales7_event_place']['table'] = 'field_data_portales7_event_place';
  $handler->display->display_options['fields']['portales7_event_place']['field'] = 'portales7_event_place';
  $handler->display->display_options['fields']['portales7_event_place']['type'] = 'show_logos';
  $handler->display->display_options['fields']['portales7_event_place']['settings'] = array(
    'image_style' => $image_style,
    'image_link' => '',
    'clase' => '',
    'show_title' => 0,
  );
}
