<?php 

function _portales7_banners_get_view(){
$view = new view();
$view->name = 'portales7_banners';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'CCLB Listado';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'más';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['offset'] = 0;
$handler->display->display_options['pager']['options']['items_per_page'] = 5;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Campo: Contenido: Título */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Campo: Contenido: target */
$handler->display->display_options['fields']['portales7_banners_target']['id'] = 'portales7_banners_target';
$handler->display->display_options['fields']['portales7_banners_target']['table'] = 'field_data_portales7_banners_target';
$handler->display->display_options['fields']['portales7_banners_target']['field'] = 'portales7_banners_target';
$handler->display->display_options['fields']['portales7_banners_target']['label'] = '';
$handler->display->display_options['fields']['portales7_banners_target']['element_label_colon'] = FALSE;
/* Campo: Contenido: Url */
$handler->display->display_options['fields']['portales7_banners_url']['id'] = 'portales7_banners_url';
$handler->display->display_options['fields']['portales7_banners_url']['table'] = 'field_data_portales7_banners_url';
$handler->display->display_options['fields']['portales7_banners_url']['field'] = 'portales7_banners_url';
$handler->display->display_options['fields']['portales7_banners_url']['label'] = '';
$handler->display->display_options['fields']['portales7_banners_url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['portales7_banners_url']['type'] = 'text_plain';
/* Campo: Contenido: nodo */
$handler->display->display_options['fields']['portales7_banners_node']['id'] = 'portales7_banners_node';
$handler->display->display_options['fields']['portales7_banners_node']['table'] = 'field_data_portales7_banners_node';
$handler->display->display_options['fields']['portales7_banners_node']['field'] = 'portales7_banners_node';
$handler->display->display_options['fields']['portales7_banners_node']['label'] = '';
$handler->display->display_options['fields']['portales7_banners_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['portales7_banners_node']['type'] = 'node_reference_path';
$handler->display->display_options['fields']['portales7_banners_node']['settings'] = array(
  'alias' => 1,
  'absolute' => 1,
);
/* Campo: Contenido: sobreimpresion */
$handler->display->display_options['fields']['portales7_banners_overlay']['id'] = 'portales7_banners_overlay';
$handler->display->display_options['fields']['portales7_banners_overlay']['table'] = 'field_data_portales7_banners_overlay';
$handler->display->display_options['fields']['portales7_banners_overlay']['field'] = 'portales7_banners_overlay';
/* Criterio de ordenación: Contenido: Fijo en cabeza de las listas */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Criterio de ordenación: Contenido: Fijo en cabeza de las listas */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Criterio de ordenación: Contenido: peso (field_peso) */
$handler->display->display_options['sorts']['portales7_banners_weight_value']['id'] = 'portales7_banners_weight_value';
$handler->display->display_options['sorts']['portales7_banners_weight_value']['table'] = 'field_data_portales7_banners_weight';
$handler->display->display_options['sorts']['portales7_banners_weight_value']['field'] = 'portales7_banners_weight_value';
/* Criterios de filtrado: Contenido: Publicado */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Criterios de filtrado: Contenido: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'portales7_banner' => 'portales7_banner',
);
/* Criterios de filtrado: Contenido: Idioma */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  'und' => 'und',
);
$translatables['carteles'] = array(
  t('Master'),
  t('más'),
  t('Aplicar'),
  t('Reiniciar'),
  t('Ordenar por'),
  t('Asc'),
  t('Desc'),
  t('Elementos por página'),
  t('- Todos -'),
  t('Desplazamiento'),
  t('« primera'),
  t('‹ anterior'),
  t('siguiente ›'),
  t('última »'),
);
 return $view;
}

function _portales7_banners_add_pager(&$handler, $options) {
  $handler->display->display_options['pager']['type'] = 'mini';
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

function _portales7_banners_add_generic_filter(&$handler, $property, $value) {
  $handler->display->display_options['filters'][$property]['id'] = $property;
  $handler->display->display_options['filters'][$property]['table'] = 'node';
  $handler->display->display_options['filters'][$property]['field'] = $property;
  $handler->display->display_options['filters'][$property]['value'] = $value;
}

function _portales7_banners_add_tid_filter(&$handler, $field, $voc, $values) {
  /* Filter criterion: Contenido: Calendar (portales7_eventcalendar) */
  $handler->display->display_options['filters'][$field . '_tid']['id'] = $field . '_tid';
  $handler->display->display_options['filters'][$field . '_tid']['table'] = 'field_data_' . $field;
  $handler->display->display_options['filters'][$field . '_tid']['field'] = $field . '_tid';
  $handler->display->display_options['filters'][$field . '_tid']['value'] = $values;
  $handler->display->display_options['filters'][$field . '_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters'][$field . '_tid']['vocabulary'] = $voc;
  $handler->display->display_options['filters'][$field . '_tid']['type'] = 'select';
}

function _portales7_banners_add_generic_sort(&$handler, $property, $order = 'DESC') {
  $sort = array( 
  $property => array(
    'id' => $property,
    'table' => 'node',
    'field' => $property,
    'order' => $order,
    ),
  );
  $handler->display->display_options['sorts'] = array_merge($sort,(array) $handler->display->display_options['sorts']);
}

function _portales7_banners_add_sort_by_field(&$handler, $field, $order = 'DESC') {
  $sort = array( 
  $field . '_value' => array(
    'id' => $field . '_value',
    'table' => 'field_data_' . $field,
    'field' => $field . '_value',
    'order' => $order,
    ),
  );
  $handler->display->display_options['sorts'] = array_merge($sort, $handler->display->display_options['sorts']);
}

function _portales7_banners_add_argument(&$handler, $name, $voc_name) {
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
  $handler->display->display_options['arguments'][$name]['validate_options']['vocabularies'] = array(
    $voc_name => $voc_name,
  );
  $handler->display->display_options['arguments'][$name]['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments'][$name]['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments'][$name]['break_phrase'] = 1;
  $handler->display->display_options['arguments'][$name]['add_table'] = 1;
  $handler->display->display_options['arguments'][$name]['require_value'] = 0;
  $handler->display->display_options['arguments'][$name]['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments'][$name]['set_breadcrumb'] = 0;
}

function _portales7_banners_set_num_items(&$handler, $count, $offset = 0) {
	$handler->display->display_options['pager']['options']['items_per_page'] = $count;
  $handler->display->display_options['pager']['options']['offset'] = $offset;
}

function _portales7_banners_add_title(&$handler, $link = 'nolink') {
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title'] = _portales7_banners_default_settings();
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = ($link == 'nolink') ? 0 : 1;
}

function _portales7_banners_add_path(&$handler, $options = array()) {
  _portales7_banners_generic_field_add($handler, 'path', $options);
}


function _portales7_banners_add_created(&$handler, $options = array()) {
  if (!is_array($options)) {
    list($o['date_format'], $o['custom_date_format']) = explode(':', $options, 2);
    $options = $o;
  }
  _portales7_banners_generic_field_add($handler, 'created', $options);
}

function _portales7_banners_add_changed(&$handler, $options = array()) {
  if (!is_array($options)) {
    list($o['date_format'], $o['custom_date_format']) = explode(':', $options, 2);
    $options = $o;
  }
  _portales7_banners_generic_field_add($handler, 'changed', $options);
}

function _portales7_banners_add_type(&$handler, $link = 1) {
  _portales7_banners_generic_taxonomy_field_add('portales7_type', $handler);
  $handler->display->display_options['fields']['portales7_type']['alter']['make_link'] = $link;
  $handler->display->display_options['fields']['portales7_type']['alter']['path'] = 'listado/[portales7_type]';
}

function _portales7_banners_add_images(&$handler, $formatter = 'thumbnail') {
  _portales7_banners_generic_filefield_add('field_banner', $handler, $formatter);
}


function _portales7_banners_default_settings() {
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

function _portales7_banners_add_body(&$handler, $formatter = '') {
  if (empty($formatter)) $formatter = 'text_default';
  /* Campo: Contenido: Cuerpo */
  $handler->display->display_options['fields']['body'] = _portales7_banners_default_settings();
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = $formatter;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'teaser_class' => 'embedded-teaser',
  );
}


