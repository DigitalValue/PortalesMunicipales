<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'site_template_admin';
$handler->task = 'site_template';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -4;
$handler->conf = array(
  'title' => 'Administracio',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => 'pm-template-administracio',
  'body_classes_to_add' => 'pm-template-administracio',
  'css_id' => 'pm-pagina-administracio',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => '*/edit
*/edit/*
*/admin
*/admin/*
*/add
*/add/*',
        ),
        'context' => 'argument_string_1',
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
        0 => 'main',
      ),
      'parent' => NULL,
      'class' => 'pm-canvas',
      'column_class' => 'pm-column',
      'row_class' => 'pm-row',
      'region_class' => 'pm-region',
      'no_scale' => TRUE,
      'fixed_width' => '',
      'column_separation' => '',
      'region_separation' => '',
      'row_separation' => '',
    ),
    'main' => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'children' => array(
        0 => 9,
        1 => 'main-row',
        2 => 1,
        3 => 5,
        4 => 10,
      ),
      'parent' => 'canvas',
      'class' => 'pm-cap',
    ),
    'main-row' => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'center',
      ),
      'parent' => 'main',
      'class' => 'pm-cap2',
    ),
    'center' => array(
      'type' => 'region',
      'title' => 'regio-cap-2',
      'width' => 100,
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => 'regio-cap-2',
    ),
    1 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 2,
      ),
      'parent' => 'main',
      'class' => 'pm-cos',
    ),
    2 => array(
      'type' => 'column',
      'width' => '100',
      'width_type' => '%',
      'parent' => '1',
      'children' => array(
        0 => 12,
        1 => 7,
        2 => 11,
      ),
      'class' => 'pm-cos-resultat',
    ),
    5 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu',
      ),
      'parent' => 'main',
      'class' => 'pm-peu pm-peu2',
      'hide_empty' => 0,
    ),
    7 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_cos',
      ),
      'parent' => '2',
      'class' => '',
    ),
    'regio_cos' => array(
      'type' => 'region',
      'title' => 'regio-cos-resultat',
      'width' => 100,
      'width_type' => '%',
      'parent' => '7',
      'class' => 'regio-cos-resultat',
    ),
    'regio_peu' => array(
      'type' => 'region',
      'title' => 'regio-peu2',
      'width' => 100,
      'width_type' => '%',
      'parent' => '5',
      'class' => 'regio-peu2',
      'hide_empty' => 1,
    ),
    9 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_cap',
      ),
      'parent' => 'main',
      'class' => 'pm-cap',
    ),
    'regio_cap' => array(
      'type' => 'region',
      'title' => 'regio-cap',
      'width' => 100,
      'width_type' => '%',
      'parent' => '9',
      'class' => 'regio-cap',
    ),
    10 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu_',
      ),
      'parent' => 'main',
      'class' => 'pm-peu pm-peu3',
      'hide_empty' => 0,
    ),
    'regio_peu_' => array(
      'type' => 'region',
      'title' => 'regio-peu3',
      'width' => 100,
      'width_type' => '%',
      'parent' => '10',
      'class' => 'regio-peu3',
      'hide_empty' => 1,
    ),
    11 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu2',
      ),
      'parent' => '2',
      'class' => '',
      'hide_empty' => 0,
    ),
    'regio_peu2' => array(
      'type' => 'region',
      'title' => 'regio-cos',
      'width' => 100,
      'width_type' => '%',
      'parent' => '11',
      'class' => 'regio-cos',
      'hide_empty' => 0,
    ),
    12 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(),
      'parent' => '2',
      'class' => '',
      'hide_empty' => 0,
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'center' => NULL,
    'regio_esquerra_1' => NULL,
    'regio_cos' => NULL,
    'regio_dreta' => NULL,
    'regio_peu' => NULL,
    'regio_cap' => NULL,
    'regio_peu_' => NULL,
    'regio_peu2' => NULL,
  ),
);
$display->cache = array();
$display->title = 'General a 3 columnas';
$display->uuid = '4768427a-7af5-41e7-9a95-d65d4ac15bd1';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c81a3115-eb1d-498f-9849-e4c7ff28b1f9';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'superfish-1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'c81a3115-eb1d-498f-9849-e4c7ff28b1f9';
  $display->content['new-c81a3115-eb1d-498f-9849-e4c7ff28b1f9'] = $pane;
  $display->panels['center'][0] = 'new-c81a3115-eb1d-498f-9849-e4c7ff28b1f9';
  $pane = new stdClass();
  $pane->pid = 'new-db445cc6-be1d-40ef-9a0c-9a37b8d92f49';
  $pane->panel = 'regio_cap';
  $pane->type = 'block';
  $pane->subtype = 'locale-language';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = 'db445cc6-be1d-40ef-9a0c-9a37b8d92f49';
  $display->content['new-db445cc6-be1d-40ef-9a0c-9a37b8d92f49'] = $pane;
  $display->panels['regio_cap'][0] = 'new-db445cc6-be1d-40ef-9a0c-9a37b8d92f49';
  $pane = new stdClass();
  $pane->pid = 'new-711a07ee-20ab-4d2c-8efc-9ece195bc6fe';
  $pane->panel = 'regio_cap';
  $pane->type = 'page_logo';
  $pane->subtype = 'page_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '711a07ee-20ab-4d2c-8efc-9ece195bc6fe';
  $display->content['new-711a07ee-20ab-4d2c-8efc-9ece195bc6fe'] = $pane;
  $display->panels['regio_cap'][1] = 'new-711a07ee-20ab-4d2c-8efc-9ece195bc6fe';
  $pane = new stdClass();
  $pane->pid = 'new-9b02b3cc-980d-4869-a3cd-a5a40316ec4e';
  $pane->panel = 'regio_cos';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-panel-de-control';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '9b02b3cc-980d-4869-a3cd-a5a40316ec4e';
  $display->content['new-9b02b3cc-980d-4869-a3cd-a5a40316ec4e'] = $pane;
  $display->panels['regio_cos'][0] = 'new-9b02b3cc-980d-4869-a3cd-a5a40316ec4e';
  $pane = new stdClass();
  $pane->pid = 'new-8a720014-3009-42f7-a056-e47d94b2e03e';
  $pane->panel = 'regio_cos';
  $pane->type = 'pane_messages';
  $pane->subtype = 'pane_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8a720014-3009-42f7-a056-e47d94b2e03e';
  $display->content['new-8a720014-3009-42f7-a056-e47d94b2e03e'] = $pane;
  $display->panels['regio_cos'][1] = 'new-8a720014-3009-42f7-a056-e47d94b2e03e';
  $pane = new stdClass();
  $pane->pid = 'new-d84fd890-822e-415b-9d1b-2d06420f8658';
  $pane->panel = 'regio_cos';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
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
  $pane->uuid = 'd84fd890-822e-415b-9d1b-2d06420f8658';
  $display->content['new-d84fd890-822e-415b-9d1b-2d06420f8658'] = $pane;
  $display->panels['regio_cos'][2] = 'new-d84fd890-822e-415b-9d1b-2d06420f8658';
  $pane = new stdClass();
  $pane->pid = 'new-5047215c-2744-45fe-a7a9-10d839cab1ca';
  $pane->panel = 'regio_peu';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'ayuntamiento',
    'items' => '10',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'MenÃº pie: Ayuntamiento',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '7',
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Ayuntamiento',
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
  $pane->uuid = '5047215c-2744-45fe-a7a9-10d839cab1ca';
  $display->content['new-5047215c-2744-45fe-a7a9-10d839cab1ca'] = $pane;
  $display->panels['regio_peu'][0] = 'new-5047215c-2744-45fe-a7a9-10d839cab1ca';
  $pane = new stdClass();
  $pane->pid = 'new-d62cdeeb-fe1e-4670-97c9-de4a6cd36fa9';
  $pane->panel = 'regio_peu';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'pueblo ',
    'items' => '10',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'Menu pie: Pueblo',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '2',
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Pueblo',
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
  $pane->uuid = 'd62cdeeb-fe1e-4670-97c9-de4a6cd36fa9';
  $display->content['new-d62cdeeb-fe1e-4670-97c9-de4a6cd36fa9'] = $pane;
  $display->panels['regio_peu'][1] = 'new-d62cdeeb-fe1e-4670-97c9-de4a6cd36fa9';
  $pane = new stdClass();
  $pane->pid = 'new-8dea590f-2a64-4d81-a769-c6a300d5eeaf';
  $pane->panel = 'regio_peu';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'directorio',
    'items' => '10',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'Menu pie: Directorio',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '1',
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Directorio',
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
  $pane->uuid = '8dea590f-2a64-4d81-a769-c6a300d5eeaf';
  $display->content['new-8dea590f-2a64-4d81-a769-c6a300d5eeaf'] = $pane;
  $display->panels['regio_peu'][2] = 'new-8dea590f-2a64-4d81-a769-c6a300d5eeaf';
  $pane = new stdClass();
  $pane->pid = 'new-dcf64a7b-dcdd-4261-b77e-75de61863279';
  $pane->panel = 'regio_peu';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'turismo',
    'items' => '10',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'Menu pie: Turismo',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '3',
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Turismo',
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
  $pane->uuid = 'dcf64a7b-dcdd-4261-b77e-75de61863279';
  $display->content['new-dcf64a7b-dcdd-4261-b77e-75de61863279'] = $pane;
  $display->panels['regio_peu'][3] = 'new-dcf64a7b-dcdd-4261-b77e-75de61863279';
  $pane = new stdClass();
  $pane->pid = 'new-936227a7-bc2a-4864-a6c0-8a70e9c77027';
  $pane->panel = 'regio_peu_';
  $pane->type = 'signature';
  $pane->subtype = 'signature';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '936227a7-bc2a-4864-a6c0-8a70e9c77027';
  $display->content['new-936227a7-bc2a-4864-a6c0-8a70e9c77027'] = $pane;
  $display->panels['regio_peu_'][0] = 'new-936227a7-bc2a-4864-a6c0-8a70e9c77027';
  $pane = new stdClass();
  $pane->pid = 'new-4f404eb5-300d-4c2b-b5d9-989d1f147970';
  $pane->panel = 'regio_peu_';
  $pane->type = 'footerlinks';
  $pane->subtype = 'footerlinks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'active' => array(
      'contact' => 'contact',
      'legal_advice' => 'legal_advice',
      'site_map' => 'site_map',
      'privacy_policy' => 'privacy_policy',
      'rss' => 'rss',
    ),
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
  $pane->uuid = '4f404eb5-300d-4c2b-b5d9-989d1f147970';
  $display->content['new-4f404eb5-300d-4c2b-b5d9-989d1f147970'] = $pane;
  $display->panels['regio_peu_'][1] = 'new-4f404eb5-300d-4c2b-b5d9-989d1f147970';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = 'new-d84fd890-822e-415b-9d1b-2d06420f8658';
$handler->conf['display'] = $display;
