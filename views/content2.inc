<?php
$view = new view();
$view->name = 'admin_content';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Admin content';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Admin content';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'más';
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  3 => '3',
  4 => '4',
  6 => '6',
  5 => '5',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
$handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'timestamp' => 'timestamp',
  'title' => 'title',
  'type' => 'type',
  'created' => 'created',
  'status' => 'status',
  'promote' => 'promote',
  'name' => 'name',
  'edit_node' => 'edit_node',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'timestamp' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'promote' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Contenido';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::pathauto_node_update_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_revision' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_assign_owner_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::clone_action_clone' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::portales7_json_json_raw_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_export_json_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_save_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_make_unsticky_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_make_sticky_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_promote_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
        'portales7_node::portales7_eventcalendar' => 'portales7_node::portales7_eventcalendar',
        'portales7_node::portales7_category' => 'portales7_node::portales7_category',
        'portales7_node::portales7_families' => 'portales7_node::portales7_families',
        'portales7_node::portales7_event_type' => 'portales7_node::portales7_event_type',
      ),
    ),
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::node_publish_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpromote_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpublish_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpublish_by_keyword_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
/* Field: Content: Has new content */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '[title][timestamp]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Fecha creación';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'sin_hora';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Content: Promoted to front page */
$handler->display->display_options['fields']['promote']['id'] = 'promote';
$handler->display->display_options['fields']['promote']['table'] = 'node';
$handler->display->display_options['fields']['promote']['field'] = 'promote';
$handler->display->display_options['fields']['promote']['label'] = 'Promocionado';
$handler->display->display_options['fields']['promote']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['promote']['not'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Author';
$handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Acciones';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Tipo';
$handler->display->display_options['filters']['type']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  5 => 0,
  4 => 0,
  6 => 0,
  3 => 0,
);
/* Filter criterion: Content: Content type (portales7_type) */
$handler->display->display_options['filters']['portales7_type_tid']['id'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['table'] = 'field_data_portales7_type';
$handler->display->display_options['filters']['portales7_type_tid']['field'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['group'] = 1;
$handler->display->display_options['filters']['portales7_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['portales7_type_tid']['expose']['operator_id'] = 'portales7_type_tid_op';
$handler->display->display_options['filters']['portales7_type_tid']['expose']['label'] = 'Tipo de Artículo';
$handler->display->display_options['filters']['portales7_type_tid']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['portales7_type_tid']['expose']['operator'] = 'portales7_type_tid_op';
$handler->display->display_options['filters']['portales7_type_tid']['expose']['identifier'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  5 => 0,
  4 => 0,
  6 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['portales7_type_tid']['group_info']['label'] = 'Tipo';
$handler->display->display_options['filters']['portales7_type_tid']['group_info']['identifier'] = 'portales7_type_tid';
$handler->display->display_options['filters']['portales7_type_tid']['group_info']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_type_tid']['group_info']['group_items'] = array(
  1 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
  2 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
);
$handler->display->display_options['filters']['portales7_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_type_tid']['vocabulary'] = 'type';
/* Filter criterion: Content: Category (portales7_category) */
$handler->display->display_options['filters']['portales7_category_tid']['id'] = 'portales7_category_tid';
$handler->display->display_options['filters']['portales7_category_tid']['table'] = 'field_data_portales7_category';
$handler->display->display_options['filters']['portales7_category_tid']['field'] = 'portales7_category_tid';
$handler->display->display_options['filters']['portales7_category_tid']['group'] = 1;
$handler->display->display_options['filters']['portales7_category_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['portales7_category_tid']['expose']['operator_id'] = 'portales7_category_tid_op';
$handler->display->display_options['filters']['portales7_category_tid']['expose']['label'] = 'Categoría';
$handler->display->display_options['filters']['portales7_category_tid']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['portales7_category_tid']['expose']['operator'] = 'portales7_category_tid_op';
$handler->display->display_options['filters']['portales7_category_tid']['expose']['identifier'] = 'portales7_category_tid';
$handler->display->display_options['filters']['portales7_category_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_category_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['portales7_category_tid']['group_info']['label'] = 'Category (portales7_category)';
$handler->display->display_options['filters']['portales7_category_tid']['group_info']['identifier'] = 'portales7_category_tid';
$handler->display->display_options['filters']['portales7_category_tid']['group_info']['group_items'] = array(
  1 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
  2 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
);
$handler->display->display_options['filters']['portales7_category_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_category_tid']['vocabulary'] = 'category';
$handler->display->display_options['filters']['portales7_category_tid']['hierarchy'] = 1;
/* Filter criterion: Content: Event type (portales7_event_type) */
$handler->display->display_options['filters']['portales7_event_type_tid']['id'] = 'portales7_event_type_tid';
$handler->display->display_options['filters']['portales7_event_type_tid']['table'] = 'field_data_portales7_event_type';
$handler->display->display_options['filters']['portales7_event_type_tid']['field'] = 'portales7_event_type_tid';
$handler->display->display_options['filters']['portales7_event_type_tid']['group'] = 1;
$handler->display->display_options['filters']['portales7_event_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['operator_id'] = 'portales7_event_type_tid_op';
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['label'] = 'Tipo de evento';
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['operator'] = 'portales7_event_type_tid_op';
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['identifier'] = 'portales7_event_type_tid';
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_event_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['portales7_event_type_tid']['group_info']['label'] = 'Event type (portales7_event_type)';
$handler->display->display_options['filters']['portales7_event_type_tid']['group_info']['identifier'] = 'portales7_event_type_tid';
$handler->display->display_options['filters']['portales7_event_type_tid']['group_info']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_event_type_tid']['group_info']['group_items'] = array(
  1 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
  2 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
);
$handler->display->display_options['filters']['portales7_event_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_event_type_tid']['vocabulary'] = 'event_types';
/* Filter criterion: Content: Section (portales7_section) */
$handler->display->display_options['filters']['portales7_section_tid']['id'] = 'portales7_section_tid';
$handler->display->display_options['filters']['portales7_section_tid']['table'] = 'field_data_portales7_section';
$handler->display->display_options['filters']['portales7_section_tid']['field'] = 'portales7_section_tid';
$handler->display->display_options['filters']['portales7_section_tid']['group'] = 1;
$handler->display->display_options['filters']['portales7_section_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['portales7_section_tid']['expose']['operator_id'] = 'portales7_section_tid_op';
$handler->display->display_options['filters']['portales7_section_tid']['expose']['label'] = 'Sección';
$handler->display->display_options['filters']['portales7_section_tid']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['portales7_section_tid']['expose']['operator'] = 'portales7_section_tid_op';
$handler->display->display_options['filters']['portales7_section_tid']['expose']['identifier'] = 'portales7_section_tid';
$handler->display->display_options['filters']['portales7_section_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_section_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['portales7_section_tid']['group_info']['label'] = 'Section (portales7_section)';
$handler->display->display_options['filters']['portales7_section_tid']['group_info']['identifier'] = 'portales7_section_tid';
$handler->display->display_options['filters']['portales7_section_tid']['group_info']['multiple'] = TRUE;
$handler->display->display_options['filters']['portales7_section_tid']['group_info']['group_items'] = array(
  1 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
  2 => array(
    'title' => '',
    'operator' => 'or',
    'value' => array(),
  ),
);
$handler->display->display_options['filters']['portales7_section_tid']['type'] = 'select';
$handler->display->display_options['filters']['portales7_section_tid']['vocabulary'] = 'sections';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['group'] = 1;
$handler->display->display_options['filters']['language']['exposed'] = TRUE;
$handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
$handler->display->display_options['filters']['language']['expose']['label'] = 'Idioma';
$handler->display->display_options['filters']['language']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
$handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
$handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status_1']['id'] = 'status_1';
$handler->display->display_options['filters']['status_1']['table'] = 'node';
$handler->display->display_options['filters']['status_1']['field'] = 'status';
$handler->display->display_options['filters']['status_1']['value'] = 'All';
$handler->display->display_options['filters']['status_1']['group'] = 1;
$handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status_1']['expose']['label'] = 'Publicado';
$handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
$handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
$handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  6 => 0,
  4 => 0,
  14 => 0,
  15 => 0,
);
/* Filter criterion: Content: Promoted to front page */
$handler->display->display_options['filters']['promote']['id'] = 'promote';
$handler->display->display_options['filters']['promote']['table'] = 'node';
$handler->display->display_options['filters']['promote']['field'] = 'promote';
$handler->display->display_options['filters']['promote']['value'] = 'All';
$handler->display->display_options['filters']['promote']['group'] = 1;
$handler->display->display_options['filters']['promote']['exposed'] = TRUE;
$handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['promote']['expose']['label'] = 'Página principal';
$handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
$handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
$handler->display->display_options['filters']['promote']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  6 => 0,
  4 => 0,
  14 => 0,
  15 => 0,
);
/* Filter criterion: Content: Sticky */
$handler->display->display_options['filters']['sticky']['id'] = 'sticky';
$handler->display->display_options['filters']['sticky']['table'] = 'node';
$handler->display->display_options['filters']['sticky']['field'] = 'sticky';
$handler->display->display_options['filters']['sticky']['value'] = 'All';
$handler->display->display_options['filters']['sticky']['group'] = 1;
$handler->display->display_options['filters']['sticky']['exposed'] = TRUE;
$handler->display->display_options['filters']['sticky']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['sticky']['expose']['label'] = 'Fijo en cabeza de las listas';
$handler->display->display_options['filters']['sticky']['expose']['operator'] = 'sticky_op';
$handler->display->display_options['filters']['sticky']['expose']['identifier'] = 'sticky';
$handler->display->display_options['filters']['sticky']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  6 => 0,
  4 => 0,
  14 => 0,
  15 => 0,
);
/* Filter criterion: Content: Author uid */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'node';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 1;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'Autor';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  5 => 0,
  4 => 0,
  6 => 0,
  3 => 0,
);
/* Filter criterion: Content: Post date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'node';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['group'] = 1;
$handler->display->display_options['filters']['created']['exposed'] = TRUE;
$handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['label'] = 'Fecha del envío';
$handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
$handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  5 => 0,
  4 => 0,
  6 => 0,
  3 => 0,
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Título';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  6 => 0,
  4 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/dashboard/content';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Contenido';
$handler->display->display_options['menu']['weight'] = '-19';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['admin_content'] = array(
  t('Master'),
  t('Admin content'),
  t('más'),
  t('Aplicar'),
  t('Reiniciar'),
  t('Ordenar por'),
  t('Ascendente'),
  t('Desc'),
  t('Elementos por página'),
  t('- Todos -'),
  t('Desplazamiento'),
  t('« primera'),
  t('‹ anterior'),
  t('siguiente ›'),
  t('última »'),
  t('author'),
  t('Contenido'),
  t('- Choose an operation -'),
  t('[title][timestamp]'),
  t('Type'),
  t('Fecha creación'),
  t('Published'),
  t('Promocionado'),
  t('Author'),
  t('Acciones'),
  t('Tipo'),
  t('Tipo de Artículo'),
  t('Categoría'),
  t('Category (portales7_category)'),
  t('Tipo de evento'),
  t('Event type (portales7_event_type)'),
  t('Sección'),
  t('Section (portales7_section)'),
  t('Idioma'),
  t('Publicado'),
  t('Página principal'),
  t('Fijo en cabeza de las listas'),
  t('Autor'),
  t('Fecha del envío'),
  t('Título'),
  t('Page'),
  t('more'),
);
