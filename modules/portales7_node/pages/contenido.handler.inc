<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view__panel_context_b6d68ec2-b02b-4d7d-8822-e6703e82513d';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -18;
$handler->conf = array(
  'title' => 'Contenido',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => 'pm-pagina-nodo-contenido',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(),
    'logic' => 'and',
  ),
);
$display = new panels_display();
$display->layout = 'flexible';
$display->layout_settings = array(
  'items' => array(
    'canvas' => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 1,
      ),
      'parent' => NULL,
      'class' => 'estructura-columna-izquierda',
      'column_class' => '',
      'row_class' => '',
      'region_class' => '',
      'no_scale' => TRUE,
      'fixed_width' => '',
      'column_separation' => '',
      'region_separation' => '',
      'row_separation' => '',
      'hide_empty' => 0,
    ),
    1 => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'parent' => 'canvas',
      'children' => array(
        0 => 26,
        1 => 18,
        2 => 3,
        3 => 4,
        4 => 14,
        5 => 15,
        6 => 27,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    3 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'contenido',
      ),
      'parent' => '1',
      'class' => 'contiene-flotante',
      'hide_empty' => 1,
    ),
    4 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'pie',
      ),
      'parent' => '1',
      'class' => '',
      'hide_empty' => 1,
    ),
    'pie' => array(
      'type' => 'region',
      'title' => 'adjuntos',
      'width' => 100,
      'width_type' => '%',
      'parent' => '4',
      'class' => 'adjuntos',
      'hide_empty' => 1,
    ),
    14 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'mes_info',
      ),
      'parent' => '1',
      'class' => '',
      'hide_empty' => 1,
    ),
    'mes_info' => array(
      'type' => 'region',
      'title' => 'Relacionados',
      'width' => 100,
      'width_type' => '%',
      'parent' => '14',
      'class' => 'grupo-nodo-relacionados',
      'hide_empty' => 1,
    ),
    15 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'otros_',
      ),
      'parent' => '1',
      'class' => '',
      'hide_empty' => 1,
    ),
    'otros_' => array(
      'type' => 'region',
      'title' => 'Entidades',
      'width' => 100,
      'width_type' => '%',
      'parent' => '15',
      'class' => 'grupo-nodo-entidades',
      'hide_empty' => 1,
    ),
    18 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'cabecera',
      ),
      'parent' => '1',
      'class' => 'fila-flotante-izquierda',
      'hide_empty' => 1,
    ),
    'cabecera' => array(
      'type' => 'region',
      'title' => 'columna-izquierda',
      'width' => 100,
      'width_type' => '%',
      'parent' => '18',
      'class' => 'columna-nodo',
      'hide_empty' => 1,
    ),
    'contenido' => array(
      'type' => 'region',
      'title' => 'basico',
      'width' => 100,
      'width_type' => '%',
      'parent' => '3',
      'class' => 'cuerpo-nodo',
      'hide_empty' => 1,
    ),
    26 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'cabecera_',
      ),
      'parent' => '1',
      'class' => '',
      'hide_empty' => 1,
    ),
    'cabecera_' => array(
      'type' => 'region',
      'title' => 'cabecera',
      'width' => 100,
      'width_type' => '%',
      'parent' => '26',
      'class' => '',
      'hide_empty' => 1,
    ),
    27 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'otros',
      ),
      'parent' => '1',
      'class' => 'Otros',
      'hide_empty' => 1,
    ),
    'otros' => array(
      'type' => 'region',
      'title' => 'Otros',
      'width' => 100,
      'width_type' => '%',
      'parent' => '27',
      'class' => 'grupo-nodo-otros',
      'hide_empty' => 1,
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'center' => NULL,
    'columna_nodo' => NULL,
    'cabecera_pagina' => NULL,
    'cabecera' => NULL,
    'basico' => NULL,
    'adjuntos' => NULL,
    'relaciones' => NULL,
    'otros' => NULL,
    'info' => NULL,
    'pie' => NULL,
    'mes_info' => NULL,
    'otros_' => NULL,
    'columna_izquierda' => NULL,
    'columna_nodo_' => NULL,
    'columna_izquierda_' => NULL,
    'contenido' => NULL,
    'contenido_' => NULL,
    'cabecera_' => NULL,
  ),
  'mes_info' => array(
    'style' => '-1',
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '47457c9d-1e58-415b-bd5e-d802c8684752';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-83451c99-454f-4cf3-bf0c-95996ee15c04';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_eventdate';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'custom_date',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'class_title' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'agenda5 solo-primer-dia',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '83451c99-454f-4cf3-bf0c-95996ee15c04';
  $display->content['new-83451c99-454f-4cf3-bf0c-95996ee15c04'] = $pane;
  $display->panels['cabecera'][0] = 'new-83451c99-454f-4cf3-bf0c-95996ee15c04';
  $pane = new stdClass();
  $pane->pid = 'new-b9e48dfb-0fa0-4222-8087-e0ef5d1eadb8';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_main_media';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'fc_main_media',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'imagen-300',
      'video_width' => '400',
      'video_style' => 'video_300',
      'widthxheight' => '320x180',
      'portales7_mm_video_url' => array(
        'video_style' => 'video_300',
        'description' => 1,
        'description_position' => 'bottom',
      ),
      'portales7_mm_video' => array(
        'widthxheight' => '300x225',
        'poster_image_style' => 'imagen-300',
      ),
      'portales7_mm_image' => array(
        'image_style' => 'imagen-300',
        'image_link' => '',
      ),
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b9e48dfb-0fa0-4222-8087-e0ef5d1eadb8';
  $display->content['new-b9e48dfb-0fa0-4222-8087-e0ef5d1eadb8'] = $pane;
  $display->panels['cabecera'][1] = 'new-b9e48dfb-0fa0-4222-8087-e0ef5d1eadb8';
  $pane = new stdClass();
  $pane->pid = 'new-79cd2e57-152e-40ac-81a1-223a9e72eb64';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_families';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'url_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'url_link' => 'listado-titulares',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '79cd2e57-152e-40ac-81a1-223a9e72eb64';
  $display->content['new-79cd2e57-152e-40ac-81a1-223a9e72eb64'] = $pane;
  $display->panels['cabecera'][2] = 'new-79cd2e57-152e-40ac-81a1-223a9e72eb64';
  $pane = new stdClass();
  $pane->pid = 'new-adf335b3-a191-47e0-8649-cca51786d079';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_weblink';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'link_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'adf335b3-a191-47e0-8649-cca51786d079';
  $display->content['new-adf335b3-a191-47e0-8649-cca51786d079'] = $pane;
  $display->panels['cabecera'][3] = 'new-adf335b3-a191-47e0-8649-cca51786d079';
  $pane = new stdClass();
  $pane->pid = 'new-9edb3e51-5b4e-4166-80a9-732bf8b55603';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_place';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'field_p7_place',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'completa',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9edb3e51-5b4e-4166-80a9-732bf8b55603';
  $display->content['new-9edb3e51-5b4e-4166-80a9-732bf8b55603'] = $pane;
  $display->panels['cabecera'][4] = 'new-9edb3e51-5b4e-4166-80a9-732bf8b55603';
  $pane = new stdClass();
  $pane->pid = 'new-1227d799-c009-40cb-867f-fbb4bf884da3';
  $pane->panel = 'contenido';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_pretitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1227d799-c009-40cb-867f-fbb4bf884da3';
  $display->content['new-1227d799-c009-40cb-867f-fbb4bf884da3'] = $pane;
  $display->panels['contenido'][0] = 'new-1227d799-c009-40cb-867f-fbb4bf884da3';
  $pane = new stdClass();
  $pane->pid = 'new-dcc8cdf8-8969-447f-9b83-0c58d0ae45d9';
  $pane->panel = 'contenido';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dcc8cdf8-8969-447f-9b83-0c58d0ae45d9';
  $display->content['new-dcc8cdf8-8969-447f-9b83-0c58d0ae45d9'] = $pane;
  $display->panels['contenido'][1] = 'new-dcc8cdf8-8969-447f-9b83-0c58d0ae45d9';
  $pane = new stdClass();
  $pane->pid = 'new-0567b685-7a9a-4079-ab4d-f83417f93dd8';
  $pane->panel = 'contenido';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_subtitle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0567b685-7a9a-4079-ab4d-f83417f93dd8';
  $display->content['new-0567b685-7a9a-4079-ab4d-f83417f93dd8'] = $pane;
  $display->panels['contenido'][2] = 'new-0567b685-7a9a-4079-ab4d-f83417f93dd8';
  $pane = new stdClass();
  $pane->pid = 'new-97878359-5e27-464f-ad68-eb0e43a275df';
  $pane->panel = 'contenido';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_teaser';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '97878359-5e27-464f-ad68-eb0e43a275df';
  $display->content['new-97878359-5e27-464f-ad68-eb0e43a275df'] = $pane;
  $display->panels['contenido'][3] = 'new-97878359-5e27-464f-ad68-eb0e43a275df';
  $pane = new stdClass();
  $pane->pid = 'new-0963a627-2d94-46b6-b88b-8977ceda3b70';
  $pane->panel = 'contenido';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_newsdate';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'sin_hora',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '0963a627-2d94-46b6-b88b-8977ceda3b70';
  $display->content['new-0963a627-2d94-46b6-b88b-8977ceda3b70'] = $pane;
  $display->panels['contenido'][4] = 'new-0963a627-2d94-46b6-b88b-8977ceda3b70';
  $pane = new stdClass();
  $pane->pid = 'new-78a0ca30-f661-474a-a3e7-5df0299417a3';
  $pane->panel = 'contenido';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '78a0ca30-f661-474a-a3e7-5df0299417a3';
  $display->content['new-78a0ca30-f661-474a-a3e7-5df0299417a3'] = $pane;
  $display->panels['contenido'][5] = 'new-78a0ca30-f661-474a-a3e7-5df0299417a3';
  $pane = new stdClass();
  $pane->pid = 'new-867e2b88-36d0-44dd-8c78-d5a00859f8ad';
  $pane->panel = 'contenido';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_source';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'link_itself',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '867e2b88-36d0-44dd-8c78-d5a00859f8ad';
  $display->content['new-867e2b88-36d0-44dd-8c78-d5a00859f8ad'] = $pane;
  $display->panels['contenido'][6] = 'new-867e2b88-36d0-44dd-8c78-d5a00859f8ad';
  $pane = new stdClass();
  $pane->pid = 'new-bacb64e6-ad73-46e4-b0e3-49e73b99ca54';
  $pane->panel = 'mes_info';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_weblink';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'link_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bacb64e6-ad73-46e4-b0e3-49e73b99ca54';
  $display->content['new-bacb64e6-ad73-46e4-b0e3-49e73b99ca54'] = $pane;
  $display->panels['mes_info'][0] = 'new-bacb64e6-ad73-46e4-b0e3-49e73b99ca54';
  $pane = new stdClass();
  $pane->pid = 'new-0052e6bd-8cad-4154-b266-876ce5e3e0f7';
  $pane->panel = 'mes_info';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_related_article';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'fc_relations',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'fc_default' => '',
      'image_style' => 'original',
      'video_width' => 'default',
      'edit' => 'Editar',
      'delete' => 'Eliminar',
      'add' => 'Agregar',
      'description' => 1,
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0052e6bd-8cad-4154-b266-876ce5e3e0f7';
  $display->content['new-0052e6bd-8cad-4154-b266-876ce5e3e0f7'] = $pane;
  $display->panels['mes_info'][1] = 'new-0052e6bd-8cad-4154-b266-876ce5e3e0f7';
  $pane = new stdClass();
  $pane->pid = 'new-d91ad43a-b778-4e6d-afe8-22b21fc6e021';
  $pane->panel = 'otros';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_social';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'addthis_basic_toolbox',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'share_services' => 'facebook,twitter,email,compact',
      'buttons_size' => 'addthis_16x16_style',
      'counter_orientation' => 'horizontal',
      'extra_css' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'flota-derecha',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd91ad43a-b778-4e6d-afe8-22b21fc6e021';
  $display->content['new-d91ad43a-b778-4e6d-afe8-22b21fc6e021'] = $pane;
  $display->panels['otros'][0] = 'new-d91ad43a-b778-4e6d-afe8-22b21fc6e021';
  $pane = new stdClass();
  $pane->pid = 'new-61f2db06-8703-4309-83aa-998e22a328a8';
  $pane->panel = 'otros';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'share fb custom',
    'title' => '',
    'body' => '<?php
$node = node_load(arg(1));

$node    = node_load(arg(1));
$tokenes = portales7_node_tokens(\'node\', array(
    \'portales7_opengraph_image\' => \'portales7_opengraph_image\'
), array(
    \'node\' => $node
));
$path    = isset($_GET[\'q\']) ? $_GET[\'q\'] : \'<front>\';
$link    = url($path, array(
    \'absolute\' => TRUE
));
drupal_add_js("document.addEventListener(\'DOMContentLoaded\', function(event) {


function fbShare(url, title, descr, image, winWidth, winHeight) {
        var winTop = (screen.height / 2) - (winHeight / 2);
        var winLeft = (screen.width / 2) - (winWidth / 2);
        window.open(\'https://www.facebook.com/sharer/sharer.php?title=\'+title+\'&description=\'+descr+\'&u=\'+url+\'&picture=\'+image, \'sharer\', \'top=\' + winTop + \',left=\' + winLeft + \',toolbar=0,status=0,width=\'+winWidth+\',height=\'+winHeight);
 }
jQuery(\'.shareFBp\').click(function(){
fbShare(\'" . $link . "\', \'" . $node -> title . "\', \'" . $node -> portales7_teaser[\'und\'][0][\'safe_value\'] . "\', \'" . $tokenes[\'portales7_opengraph_image\'] . "\', 520, 350)
})});", "inline");
echo "<a href=\\"javascript:void(0)\\" class=\\"shareFBp\\"> </a>";
?>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '61f2db06-8703-4309-83aa-998e22a328a8';
  $display->content['new-61f2db06-8703-4309-83aa-998e22a328a8'] = $pane;
  $display->panels['otros'][1] = 'new-61f2db06-8703-4309-83aa-998e22a328a8';
  $pane = new stdClass();
  $pane->pid = 'new-1329ab48-15d9-4023-b165-e1e20dbc10de';
  $pane->panel = 'otros_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_related_entity';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'fc_relations',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => 'original',
      'video_width' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'foto-izquierda',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1329ab48-15d9-4023-b165-e1e20dbc10de';
  $display->content['new-1329ab48-15d9-4023-b165-e1e20dbc10de'] = $pane;
  $display->panels['otros_'][0] = 'new-1329ab48-15d9-4023-b165-e1e20dbc10de';
  $pane = new stdClass();
  $pane->pid = 'new-f35500ef-efdc-4d2b-ab43-2c8d6da72ffb';
  $pane->panel = 'pie';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_media';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'fc_media',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 1,
      'image_style' => 'thumbnail',
      'video_width' => 'default',
      'portales7_video_url' => array(
        'video_style' => 'video_43_500',
        'image_style' => 'imagen-200',
        'description' => 0,
        'description_position' => 'top',
      ),
      'portales7_videos' => array(
        'widthxheight' => '400x300',
        'poster_image_style' => 'imagen-200',
      ),
      'portales7_images' => array(
        'colorbox_node_style' => 'imagen-200',
        'colorbox_node_style_first' => '',
        'colorbox_image_style' => '',
        'colorbox_gallery' => 'post',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'auto',
        'colorbox_caption_custom' => '',
        'class_title' => 'nombre-imagen',
      ),
      'portales7_files' => array(
        'image_style' => 'imagen-200',
        'image_link' => 'file',
        'show_description' => 1,
        'tag' => 'span',
        'fallback_formatter' => 'file_table',
      ),
      'display_fields' => array(
        'portales7_video_url' => 'portales7_video_url',
        'portales7_videos' => 'portales7_videos',
        'portales7_images' => 'portales7_images',
        'portales7_files' => 'portales7_files',
      ),
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'cuatro-columnas',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f35500ef-efdc-4d2b-ab43-2c8d6da72ffb';
  $display->content['new-f35500ef-efdc-4d2b-ab43-2c8d6da72ffb'] = $pane;
  $display->panels['pie'][0] = 'new-f35500ef-efdc-4d2b-ab43-2c8d6da72ffb';
  $pane = new stdClass();
  $pane->pid = 'new-b56f1363-d9f0-473b-9809-c1ae8106f1f8';
  $pane->panel = 'pie';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_category';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b56f1363-d9f0-473b-9809-c1ae8106f1f8';
  $display->content['new-b56f1363-d9f0-473b-9809-c1ae8106f1f8'] = $pane;
  $display->panels['pie'][1] = 'new-b56f1363-d9f0-473b-9809-c1ae8106f1f8';
$display->hide_title = PANELS_TITLE_PANE;
$display->title_pane = 'new-0052e6bd-8cad-4154-b266-876ce5e3e0f7';
$handler->conf['display'] = $display;
