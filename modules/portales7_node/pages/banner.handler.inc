<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view__panel_context_cd62acab-2cf7-48e8-a9de-f5eaa608441f';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -24;
$handler->conf = array(
  'title' => 'Banner',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => 'pm-pagina-banner',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'portales7_banner' => 'portales7_banner',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
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
      'class' => '',
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
      ),
      'class' => '',
    ),
    3 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 30,
      ),
      'parent' => '1',
      'class' => 'contiene-flotante',
      'hide_empty' => 1,
    ),
    4 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 27,
      ),
      'parent' => '1',
      'class' => 'contiene-flotante',
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
      'hide_empty' => 0,
    ),
    'mes_info' => array(
      'type' => 'region',
      'title' => 'mes-info',
      'width' => 100,
      'width_type' => '%',
      'parent' => '14',
      'class' => 'grupo-nodo-info',
      'hide_empty' => 0,
    ),
    15 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'otros_',
      ),
      'parent' => '1',
      'class' => '',
      'hide_empty' => 0,
    ),
    'otros_' => array(
      'type' => 'region',
      'title' => 'Otros',
      'width' => 100,
      'width_type' => '%',
      'parent' => '15',
      'class' => 'grupo-nodo-otros',
      'hide_empty' => 0,
    ),
    18 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'cabecera',
      ),
      'parent' => '1',
      'class' => 'fila-flotante-derecha',
      'hide_empty' => 0,
    ),
    'cabecera' => array(
      'type' => 'region',
      'title' => 'columna-izquierda',
      'width' => 100,
      'width_type' => '%',
      'parent' => '18',
      'class' => 'columna-nodo',
      'hide_empty' => 0,
    ),
    26 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'cabecera_',
      ),
      'parent' => '1',
      'class' => '',
      'hide_empty' => 0,
    ),
    'cabecera_' => array(
      'type' => 'region',
      'title' => 'cabecera',
      'width' => 100,
      'width_type' => '%',
      'parent' => '26',
      'class' => '',
      'hide_empty' => 0,
    ),
    27 => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'parent' => '4',
      'children' => array(
        0 => 28,
        1 => 29,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    28 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'simula_banner_300',
      ),
      'parent' => '27',
      'class' => '',
      'hide_empty' => 1,
    ),
    29 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'simula_banner_300_',
      ),
      'parent' => '27',
      'class' => 'simula-banner-300',
      'hide_empty' => 1,
    ),
    'simula_banner_300' => array(
      'type' => 'region',
      'title' => 'titul-simula-banner-300',
      'width' => 100,
      'width_type' => '%',
      'parent' => '28',
      'class' => 'titul-simula-banner-300',
      'hide_empty' => 1,
    ),
    'simula_banner_300_' => array(
      'type' => 'region',
      'title' => 'simula-banner-300',
      'width' => 100,
      'width_type' => '%',
      'parent' => '29',
      'class' => 'simula-banner-300',
      'hide_empty' => 1,
    ),
    30 => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'parent' => '3',
      'children' => array(
        0 => 31,
        1 => 32,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    31 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'titul_simula_banner_300',
      ),
      'parent' => '30',
      'class' => '',
      'hide_empty' => 1,
    ),
    32 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'simula_banner_200',
      ),
      'parent' => '30',
      'class' => 'simula-banner-200',
      'hide_empty' => 1,
    ),
    'simula_banner_200' => array(
      'type' => 'region',
      'title' => 'simula-banner-200',
      'width' => 100,
      'width_type' => '%',
      'parent' => '32',
      'class' => 'simula-banner-200',
      'hide_empty' => 1,
    ),
    'titul_simula_banner_300' => array(
      'type' => 'region',
      'title' => 'titul-simula-banner-200',
      'width' => 100,
      'width_type' => '%',
      'parent' => '31',
      'class' => 'titul-simula-banner-200',
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
    'simula_banner_300' => NULL,
    'simula_banner_300_' => NULL,
    'simula_banner_200' => NULL,
    'titul_simula_banner_300' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '47457c9d-1e58-415b-bd5e-d802c8684752';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-08a7ad74-dfb2-4c4e-8fb0-a83bdad7bdd3';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_group';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '08a7ad74-dfb2-4c4e-8fb0-a83bdad7bdd3';
  $display->content['new-08a7ad74-dfb2-4c4e-8fb0-a83bdad7bdd3'] = $pane;
  $display->panels['cabecera'][0] = 'new-08a7ad74-dfb2-4c4e-8fb0-a83bdad7bdd3';
  $pane = new stdClass();
  $pane->pid = 'new-a0509871-af0c-46d6-851a-eae49775163b';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'node_reference_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a0509871-af0c-46d6-851a-eae49775163b';
  $display->content['new-a0509871-af0c-46d6-851a-eae49775163b'] = $pane;
  $display->panels['cabecera'][1] = 'new-a0509871-af0c-46d6-851a-eae49775163b';
  $pane = new stdClass();
  $pane->pid = 'new-0dbb02e5-0fa2-4f6b-b1ec-da27f4a535f2';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_target';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'i18n_list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0dbb02e5-0fa2-4f6b-b1ec-da27f4a535f2';
  $display->content['new-0dbb02e5-0fa2-4f6b-b1ec-da27f4a535f2'] = $pane;
  $display->panels['cabecera'][2] = 'new-0dbb02e5-0fa2-4f6b-b1ec-da27f4a535f2';
  $pane = new stdClass();
  $pane->pid = 'new-0f7f7254-429e-462f-aaef-3073a579cabd';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_url';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '0f7f7254-429e-462f-aaef-3073a579cabd';
  $display->content['new-0f7f7254-429e-462f-aaef-3073a579cabd'] = $pane;
  $display->panels['cabecera'][3] = 'new-0f7f7254-429e-462f-aaef-3073a579cabd';
  $pane = new stdClass();
  $pane->pid = 'new-151462d0-b415-43e2-968b-fc7b8fe07d49';
  $pane->panel = 'cabecera';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:language';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '151462d0-b415-43e2-968b-fc7b8fe07d49';
  $display->content['new-151462d0-b415-43e2-968b-fc7b8fe07d49'] = $pane;
  $display->panels['cabecera'][4] = 'new-151462d0-b415-43e2-968b-fc7b8fe07d49';
  $pane = new stdClass();
  $pane->pid = 'new-dcc8cdf8-8969-447f-9b83-0c58d0ae45d9';
  $pane->panel = 'cabecera_';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'dcc8cdf8-8969-447f-9b83-0c58d0ae45d9';
  $display->content['new-dcc8cdf8-8969-447f-9b83-0c58d0ae45d9'] = $pane;
  $display->panels['cabecera_'][0] = 'new-dcc8cdf8-8969-447f-9b83-0c58d0ae45d9';
  $pane = new stdClass();
  $pane->pid = 'new-51fc9a4e-9f1a-457b-b588-4aeed966b848';
  $pane->panel = 'simula_banner_200';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'imagen-200',
      'image_link' => '',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '51fc9a4e-9f1a-457b-b588-4aeed966b848';
  $display->content['new-51fc9a4e-9f1a-457b-b588-4aeed966b848'] = $pane;
  $display->panels['simula_banner_200'][0] = 'new-51fc9a4e-9f1a-457b-b588-4aeed966b848';
  $pane = new stdClass();
  $pane->pid = 'new-4f875392-a48f-4a15-9a1d-25ea99fdaa8a';
  $pane->panel = 'simula_banner_200';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_overlay';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4f875392-a48f-4a15-9a1d-25ea99fdaa8a';
  $display->content['new-4f875392-a48f-4a15-9a1d-25ea99fdaa8a'] = $pane;
  $display->panels['simula_banner_200'][1] = 'new-4f875392-a48f-4a15-9a1d-25ea99fdaa8a';
  $pane = new stdClass();
  $pane->pid = 'new-bcd60500-c2ee-417c-9c4b-2a3f736725cf';
  $pane->panel = 'simula_banner_300';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Tamaño',
    'title' => '',
    'body' => '<p>BANNER 300PX</p>
',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'tamano-banner',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bcd60500-c2ee-417c-9c4b-2a3f736725cf';
  $display->content['new-bcd60500-c2ee-417c-9c4b-2a3f736725cf'] = $pane;
  $display->panels['simula_banner_300'][0] = 'new-bcd60500-c2ee-417c-9c4b-2a3f736725cf';
  $pane = new stdClass();
  $pane->pid = 'new-005db102-fe07-4b1a-9d63-ea2b0fb5b566';
  $pane->panel = 'simula_banner_300_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'imagen-300',
      'image_link' => '',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '005db102-fe07-4b1a-9d63-ea2b0fb5b566';
  $display->content['new-005db102-fe07-4b1a-9d63-ea2b0fb5b566'] = $pane;
  $display->panels['simula_banner_300_'][0] = 'new-005db102-fe07-4b1a-9d63-ea2b0fb5b566';
  $pane = new stdClass();
  $pane->pid = 'new-657bde02-4018-4391-b122-3f4e52da9cc2';
  $pane->panel = 'simula_banner_300_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_banners_overlay';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '657bde02-4018-4391-b122-3f4e52da9cc2';
  $display->content['new-657bde02-4018-4391-b122-3f4e52da9cc2'] = $pane;
  $display->panels['simula_banner_300_'][1] = 'new-657bde02-4018-4391-b122-3f4e52da9cc2';
  $pane = new stdClass();
  $pane->pid = 'new-30e817d2-6af5-49af-9247-d880ecde8d69';
  $pane->panel = 'titul_simula_banner_300';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Tamaño',
    'title' => '',
    'body' => '<p>BANNER 200PX</p>
',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'tamano-banner',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '30e817d2-6af5-49af-9247-d880ecde8d69';
  $display->content['new-30e817d2-6af5-49af-9247-d880ecde8d69'] = $pane;
  $display->panels['titul_simula_banner_300'][0] = 'new-30e817d2-6af5-49af-9247-d880ecde8d69';
$display->hide_title = PANELS_TITLE_PANE;
$display->title_pane = '0';
$handler->conf['display'] = $display;
