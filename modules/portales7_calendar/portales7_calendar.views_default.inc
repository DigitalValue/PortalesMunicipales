<?php
/**
 * @file
 * Views API hooks
 */
/**
 * Implements hook_views_default_views().
 */
function portales7_calendar_views_default_views() {
  
$term = dvtoolbox_get_taxonomy_term_by_name('event', 'type');
  $views = array();
$view = new view();
$view->name = 'calendario';
$view->description = '';
$view->tag = 'Calendar';
$view->base_table = 'node';
$view->human_name = 'Calendario';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'más';
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'month';
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['name_size'] = '3';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['row_plugin'] = 'calendar_entity';
/* Campo: Contenido: Título */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
/* Campo: Contenido: Event date */
$handler->display->display_options['fields']['portales7_eventdate']['id'] = 'portales7_eventdate';
$handler->display->display_options['fields']['portales7_eventdate']['table'] = 'field_data_portales7_eventdate';
$handler->display->display_options['fields']['portales7_eventdate']['field'] = 'portales7_eventdate';
$handler->display->display_options['fields']['portales7_eventdate']['label'] = '';
$handler->display->display_options['fields']['portales7_eventdate']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['portales7_eventdate']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['portales7_eventdate']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => '',
);
$handler->display->display_options['fields']['portales7_eventdate']['group_rows'] = FALSE;
$handler->display->display_options['fields']['portales7_eventdate']['delta_offset'] = '0';
/* Campo: Contenido: Calendar */
$handler->display->display_options['fields']['portales7_eventcalendar']['id'] = 'portales7_eventcalendar';
$handler->display->display_options['fields']['portales7_eventcalendar']['table'] = 'field_data_portales7_eventcalendar';
$handler->display->display_options['fields']['portales7_eventcalendar']['field'] = 'portales7_eventcalendar';
$handler->display->display_options['fields']['portales7_eventcalendar']['label'] = '';
$handler->display->display_options['fields']['portales7_eventcalendar']['element_label_colon'] = FALSE;
/* Criterio de ordenación: Contenido: Event date - fecha de inicio (portales7_eventdate) */
$handler->display->display_options['sorts']['portales7_eventdate_value']['id'] = 'portales7_eventdate_value';
$handler->display->display_options['sorts']['portales7_eventdate_value']['table'] = 'field_data_portales7_eventdate';
$handler->display->display_options['sorts']['portales7_eventdate_value']['field'] = 'portales7_eventdate_value';
/* Criterios de filtrado: Contenido: Publicado */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Criterios de filtrado: Contenido: Calendar (portales7_eventcalendar) */
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['id'] = 'portales7_eventcalendar_tid';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['table'] = 'field_data_portales7_eventcalendar';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['field'] = 'portales7_eventcalendar_tid';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['expose']['operator_id'] = 'portales7_eventcalendar_tid_op';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['expose']['label'] = 'Calendario (portales7_eventcalendar)';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['expose']['operator'] = 'portales7_eventcalendar_tid_op';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['expose']['identifier'] = 'portales7_eventcalendar_tid';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  4 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_eventcalendar_tid']['vocabulary'] = 'calendar';
/* Criterios de filtrado: Contenido: Content type (portales7_type) */
$handler->display->display_options['filters']['portales7_type_tid']['id'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['table'] = 'field_data_portales7_type';
$handler->display->display_options['filters']['portales7_type_tid']['field'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['value'] = array(
  $term->tid => $term->tid,
);
$handler->display->display_options['filters']['portales7_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_type_tid']['vocabulary'] = 'type';
/* Criterios de filtrado: Contenido: Idioma */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  'und' => 'und',
);

/* Display: Month */
$handler = $view->new_display('page', 'Month', 'page_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'month';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['name_size'] = '2';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['row_options']['colors']['legend'] = 'type';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Filtro contextual: Fecha: Fecha (node) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'node';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Todo(s)';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'field_data_portales7_eventdate.portales7_eventdate_value' => 'field_data_portales7_eventdate.portales7_eventdate_value',
);
$handler->display->display_options['path'] = 'calendar/month';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Month';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Calendar';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Week */
$handler = $view->new_display('page', 'Week', 'page_2');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'week';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['calendar_type'] = 'week';
$handler->display->display_options['style_options']['name_size'] = '2';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Filtro contextual: Fecha: Fecha (node) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'node';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Todo(s)';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'field_data_portales7_eventdate.portales7_eventdate_value' => 'field_data_portales7_eventdate.portales7_eventdate_value',
);
$handler->display->display_options['path'] = 'calendar/week';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Week';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Day */
$handler = $view->new_display('page', 'Day', 'page_3');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'day';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['calendar_type'] = 'day';
$handler->display->display_options['style_options']['name_size'] = '3';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Filtro contextual: Fecha: Fecha (node) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'node';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Todo(s)';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'field_data_portales7_eventdate.portales7_eventdate_value' => 'field_data_portales7_eventdate.portales7_eventdate_value',
);
$handler->display->display_options['path'] = 'calendar/day';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Day';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Year */
$handler = $view->new_display('page', 'Year', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'year';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['calendar_type'] = 'year';
$handler->display->display_options['style_options']['name_size'] = '2';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenido: Título */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
/* Campo: Contenido: Event date */
$handler->display->display_options['fields']['portales7_eventdate']['id'] = 'portales7_eventdate';
$handler->display->display_options['fields']['portales7_eventdate']['table'] = 'field_data_portales7_eventdate';
$handler->display->display_options['fields']['portales7_eventdate']['field'] = 'portales7_eventdate';
$handler->display->display_options['fields']['portales7_eventdate']['label'] = '';
$handler->display->display_options['fields']['portales7_eventdate']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['portales7_eventdate']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['portales7_eventdate']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => '',
);
$handler->display->display_options['fields']['portales7_eventdate']['group_rows'] = FALSE;
$handler->display->display_options['fields']['portales7_eventdate']['delta_offset'] = '0';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Filtro contextual: Fecha: Fecha (node) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'node';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Todo(s)';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'field_data_portales7_eventdate.portales7_eventdate_value' => 'field_data_portales7_eventdate.portales7_eventdate_value',
);
$handler->display->display_options['path'] = 'calendar/year';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Year';
$handler->display->display_options['menu']['weight'] = '4';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'mini';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['name_size'] = '2';
$handler->display->display_options['style_options']['mini'] = '1';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Filtro contextual: Fecha: Fecha (node) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'node';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Todo(s)';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'field_data_portales7_eventdate.portales7_eventdate_value' => 'field_data_portales7_eventdate.portales7_eventdate_value',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Criterios de filtrado: Contenido: Publicado */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Criterios de filtrado: Contenido: Content type (portales7_type) */
$handler->display->display_options['filters']['portales7_type_tid']['id'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['table'] = 'field_data_portales7_type';
$handler->display->display_options['filters']['portales7_type_tid']['field'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['value'] = array(
  $term->tid => $term->tid,
);
$handler->display->display_options['filters']['portales7_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_type_tid']['vocabulary'] = 'type';
/* Criterios de filtrado: Contenido: Idioma */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  'und' => 'und',
);$handler->display->display_options['filters']['portales7_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_type_tid']['vocabulary'] = 'type';
$handler->display->display_options['block_description'] = 'Calendario';

/* Display: Upcoming */
$handler = $view->new_display('block', 'Upcoming', 'block_2');
$handler->display->display_options['display_description'] = 'Upcoming events block';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Criterios de filtrado: Contenido: Publicado */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Criterios de filtrado: Fecha: Fecha (node) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'node';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = '>=';
$handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'field_data_portales7_eventdate.portales7_eventdate_value' => 'field_data_portales7_eventdate.portales7_eventdate_value',
);
/* Criterios de filtrado: Contenido: Content type (portales7_type) */
$handler->display->display_options['filters']['portales7_type_tid']['id'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['table'] = 'field_data_portales7_type';
$handler->display->display_options['filters']['portales7_type_tid']['field'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['value'] = array(
  $term->tid => $term->tid,
);
$handler->display->display_options['filters']['portales7_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_type_tid']['vocabulary'] = 'type';
/* Criterios de filtrado: Contenido: Idioma */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  'und' => 'und',
);
$translatables['calendario'] = array(
  t('Master'),
  t('más'),
  t('Aplicar'),
  t('Reiniciar'),
  t('Ordenar por'),
  t('Ascendente'),
  t('Desc'),
  t('Calendario (portales7_eventcalendar)'),
  t('Month'),
  t('Todo(s)'),
  t('Week'),
  t('Day'),
  t('Year'),
  t('Block'),
  t('Calendario'),
  t('Upcoming'),
  t('Upcoming events block'),
);

$views[$view->name] = $view;
return $views;
}

