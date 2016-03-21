<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'site_template__panel_context_069b2df5-b01e-4e8b-9dc4-eb3ab5d17614';
$handler->task = 'site_template';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -1;
$handler->conf = array(
  'title' => 'Interior 2',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => 'pm-template-general',
  'body_classes_to_add' => 'pm-template-general',
  'css_id' => 'pm-pagina-interior',
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
        5 => 11,
        6 => 12,
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
      'hide_empty' => 1,
    ),
    'center' => array(
      'type' => 'region',
      'title' => 'regio-cap-2',
      'width' => 100,
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => 'regio-cap-2',
      'hide_empty' => 1,
    ),
    1 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 2,
        1 => 4,
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
        0 => 13,
        1 => 7,
      ),
      'class' => 'pm-cos-resultat',
    ),
    4 => array(
      'type' => 'column',
      'width' => '180',
      'width_type' => 'px',
      'parent' => '1',
      'children' => array(
        0 => 8,
      ),
      'class' => 'pm-columna pm-columna-dreta',
      'hide_empty' => 1,
    ),
    5 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu',
      ),
      'parent' => 'main',
      'class' => 'pm-cos2',
      'hide_empty' => 1,
    ),
    7 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_cos',
      ),
      'parent' => '2',
      'class' => '',
      'hide_empty' => 1,
    ),
    8 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_dreta',
      ),
      'parent' => '4',
      'class' => '',
      'hide_empty' => 1,
    ),
    'regio_cos' => array(
      'type' => 'region',
      'title' => 'regio-cos-resultat',
      'width' => 100,
      'width_type' => '%',
      'parent' => '7',
      'class' => 'regio-cos-resultat',
      'hide_empty' => 1,
    ),
    'regio_dreta' => array(
      'type' => 'region',
      'title' => 'regio-dreta',
      'width' => 100,
      'width_type' => '%',
      'parent' => '8',
      'class' => 'regio-dreta',
      'hide_empty' => 1,
    ),
    'regio_peu' => array(
      'type' => 'region',
      'title' => 'regio-cos2',
      'width' => 100,
      'width_type' => '%',
      'parent' => '5',
      'class' => 'regio-cos2',
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
      'hide_empty' => 1,
    ),
    'regio_cap' => array(
      'type' => 'region',
      'title' => 'regio-cap',
      'width' => 100,
      'width_type' => '%',
      'parent' => '9',
      'class' => 'regio-cap',
      'hide_empty' => 1,
    ),
    10 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu_',
      ),
      'parent' => 'main',
      'class' => 'pm-peu pm-peu1',
      'hide_empty' => 1,
    ),
    'regio_peu_' => array(
      'type' => 'region',
      'title' => 'regio-peu',
      'width' => 100,
      'width_type' => '%',
      'parent' => '10',
      'class' => 'regio-peu',
      'hide_empty' => 1,
    ),
    11 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu2',
      ),
      'parent' => 'main',
      'class' => 'pm-peu pm-peu2',
      'hide_empty' => 1,
    ),
    'regio_peu2' => array(
      'type' => 'region',
      'title' => 'regio-peu2',
      'width' => 100,
      'width_type' => '%',
      'parent' => '11',
      'class' => 'regio-peu2',
      'hide_empty' => 1,
    ),
    12 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'regio_peu3',
      ),
      'parent' => 'main',
      'class' => 'pm-peu pm-peu3',
      'hide_empty' => 1,
    ),
    'regio_peu3' => array(
      'type' => 'region',
      'title' => 'regio-peu3',
      'width' => 100,
      'width_type' => '%',
      'parent' => '12',
      'class' => 'regio-peu3',
      'hide_empty' => 1,
    ),
    13 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'contenido',
      ),
      'parent' => '2',
      'class' => '',
      'hide_empty' => 1,
    ),
    'contenido' => array(
      'type' => 'region',
      'title' => 'Contenido',
      'width' => 100,
      'width_type' => '%',
      'parent' => '13',
      'class' => '',
      'hide_empty' => 1,
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => array(),
    'center' => array(),
    'regio_esquerra_1' => array(),
    'regio_cos' => array(),
    'regio_dreta' => array(),
    'regio_peu' => array(),
    'regio_cap' => array(),
    'regio_peu_' => array(),
    'regio_peu2' => array(),
    'regio_peu3' => array(),
    'contenido' => array(),
  ),
  'style' => 'stylizer',
  'center' => array(
    'style' => 'stylizer',
  ),
  'regio_esquerra_1' => array(
    'style' => 'stylizer',
  ),
  'regio_cos' => array(
    'style' => 'stylizer',
  ),
  'regio_dreta' => array(
    'style' => 'stylizer',
  ),
  'regio_peu' => array(
    'style' => 'stylizer',
  ),
  'regio_cap' => array(
    'style' => 'stylizer',
  ),
  'regio_peu_' => array(
    'style' => 'stylizer',
  ),
  'regio_peu2' => array(
    'style' => 'stylizer',
  ),
  'regio_peu3' => array(
    'style' => 'stylizer',
  ),
  'contenido' => array(
    'style' => 'stylizer',
  ),
);
$display->cache = array();
$display->title = 'General a 3 columnas';
$display->uuid = '06147fa1-126a-482f-a822-e9b953e3d760';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-149f7aa5-25bf-496f-a8fe-926b23c83f49';
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
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'mov-oculto',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '149f7aa5-25bf-496f-a8fe-926b23c83f49';
  $display->content['new-149f7aa5-25bf-496f-a8fe-926b23c83f49'] = $pane;
  $display->panels['center'][0] = 'new-149f7aa5-25bf-496f-a8fe-926b23c83f49';
  $pane = new stdClass();
  $pane->pid = 'new-8a5beeef-3720-49ed-bd4d-c22694fc23be';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'system-main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
    'css_class' => 'web-oculto menu-principal',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8a5beeef-3720-49ed-bd4d-c22694fc23be';
  $display->content['new-8a5beeef-3720-49ed-bd4d-c22694fc23be'] = $pane;
  $display->panels['center'][1] = 'new-8a5beeef-3720-49ed-bd4d-c22694fc23be';
  $pane = new stdClass();
  $pane->pid = 'new-cd7cc4a3-cc11-4ee5-b1ae-ba3229f80a11';
  $pane->panel = 'contenido';
  $pane->type = 'pane_messages';
  $pane->subtype = 'pane_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cd7cc4a3-cc11-4ee5-b1ae-ba3229f80a11';
  $display->content['new-cd7cc4a3-cc11-4ee5-b1ae-ba3229f80a11'] = $pane;
  $display->panels['contenido'][0] = 'new-cd7cc4a3-cc11-4ee5-b1ae-ba3229f80a11';
  $pane = new stdClass();
  $pane->pid = 'new-a085cb81-1225-4373-9c26-bb05f26630cc';
  $pane->panel = 'contenido';
  $pane->type = 'block';
  $pane->subtype = 'system-help';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a085cb81-1225-4373-9c26-bb05f26630cc';
  $display->content['new-a085cb81-1225-4373-9c26-bb05f26630cc'] = $pane;
  $display->panels['contenido'][1] = 'new-a085cb81-1225-4373-9c26-bb05f26630cc';
  $pane = new stdClass();
  $pane->pid = 'new-857137f9-e436-416b-819e-b0675e5be74d';
  $pane->panel = 'regio_cap';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'font',
    'title' => '',
    'body' => '<link href="http://fonts.googleapis.com/css?family=Roboto+Condensed:400,400italic,300,300italic,700,700italic" rel="stylesheet" type="text/css" />',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '857137f9-e436-416b-819e-b0675e5be74d';
  $display->content['new-857137f9-e436-416b-819e-b0675e5be74d'] = $pane;
  $display->panels['regio_cap'][0] = 'new-857137f9-e436-416b-819e-b0675e5be74d';
  $pane = new stdClass();
  $pane->pid = 'new-b245bf8f-5735-43ee-a520-62ba188b4422';
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
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b245bf8f-5735-43ee-a520-62ba188b4422';
  $display->content['new-b245bf8f-5735-43ee-a520-62ba188b4422'] = $pane;
  $display->panels['regio_cap'][1] = 'new-b245bf8f-5735-43ee-a520-62ba188b4422';
  $pane = new stdClass();
  $pane->pid = 'new-7662b63d-944b-4179-9225-4384d49f40e4';
  $pane->panel = 'regio_cap';
  $pane->type = 'page_logo';
  $pane->subtype = 'page_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7662b63d-944b-4179-9225-4384d49f40e4';
  $display->content['new-7662b63d-944b-4179-9225-4384d49f40e4'] = $pane;
  $display->panels['regio_cap'][2] = 'new-7662b63d-944b-4179-9225-4384d49f40e4';
  $pane = new stdClass();
  $pane->pid = 'new-f17390d0-776b-44e7-a38e-1def970145c9';
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
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f17390d0-776b-44e7-a38e-1def970145c9';
  $display->content['new-f17390d0-776b-44e7-a38e-1def970145c9'] = $pane;
  $display->panels['regio_cos'][0] = 'new-f17390d0-776b-44e7-a38e-1def970145c9';
  $pane = new stdClass();
  $pane->pid = 'new-256daddd-b29d-4685-ba10-943650fddf50';
  $pane->panel = 'regio_dreta';
  $pane->type = 'banners74';
  $pane->subtype = 'banners74';
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
    'type' => NULL,
    'arguments' => '',
    'items' => '0',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'pager' => 0,
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'group' => 'Administracion',
    'image_style' => 'banner-200',
    'sort' => 'portales7_banners_weight:ASC',
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
  $pane->uuid = '256daddd-b29d-4685-ba10-943650fddf50';
  $display->content['new-256daddd-b29d-4685-ba10-943650fddf50'] = $pane;
  $display->panels['regio_dreta'][0] = 'new-256daddd-b29d-4685-ba10-943650fddf50';
  $pane = new stdClass();
  $pane->pid = 'new-49e1319a-256f-49f2-81fc-f37c86bd7fcb';
  $pane->panel = 'regio_dreta';
  $pane->type = 'block';
  $pane->subtype = 'search-form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '49e1319a-256f-49f2-81fc-f37c86bd7fcb';
  $display->content['new-49e1319a-256f-49f2-81fc-f37c86bd7fcb'] = $pane;
  $display->panels['regio_dreta'][1] = 'new-49e1319a-256f-49f2-81fc-f37c86bd7fcb';
  $pane = new stdClass();
  $pane->pid = 'new-0d117348-559b-42a3-9214-e8fc77b6711b';
  $pane->panel = 'regio_dreta';
  $pane->type = 'block';
  $pane->subtype = 'submenutree-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '0d117348-559b-42a3-9214-e8fc77b6711b';
  $display->content['new-0d117348-559b-42a3-9214-e8fc77b6711b'] = $pane;
  $display->panels['regio_dreta'][2] = 'new-0d117348-559b-42a3-9214-e8fc77b6711b';
  $pane = new stdClass();
  $pane->pid = 'new-f73c1c11-7bc9-4e4a-bec5-d109c0dd8d13';
  $pane->panel = 'regio_dreta';
  $pane->type = 'banners74';
  $pane->subtype = 'banners74';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => NULL,
    'arguments' => '',
    'items' => '0',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'pager' => 0,
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'group' => 'right-col',
    'image_style' => '',
    'sort' => 'portales7_banners_weight:ASC',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array(
    'css_id' => 'banners-der',
    'css_class' => 'banners-der',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f73c1c11-7bc9-4e4a-bec5-d109c0dd8d13';
  $display->content['new-f73c1c11-7bc9-4e4a-bec5-d109c0dd8d13'] = $pane;
  $display->panels['regio_dreta'][3] = 'new-f73c1c11-7bc9-4e4a-bec5-d109c0dd8d13';
  $pane = new stdClass();
  $pane->pid = 'new-94325cd6-02bd-4417-8a57-cce0e8859131';
  $pane->panel = 'regio_dreta';
  $pane->type = 'banners74';
  $pane->subtype = 'banners74';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => NULL,
    'arguments' => '',
    'items' => '0',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'pager' => 0,
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'group' => 'minibanners',
    'image_style' => '',
    'sort' => 'portales7_banners_weight:ASC',
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
    'css_class' => 'dos-columnas',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '94325cd6-02bd-4417-8a57-cce0e8859131';
  $display->content['new-94325cd6-02bd-4417-8a57-cce0e8859131'] = $pane;
  $display->panels['regio_dreta'][4] = 'new-94325cd6-02bd-4417-8a57-cce0e8859131';
  $pane = new stdClass();
  $pane->pid = 'new-cb3a56ee-9c47-4305-b097-fdca3e38c011';
  $pane->panel = 'regio_dreta';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Banner app',
    'title' => '',
    'body' => '<div class="banner-app" style="background-color:#12416a; padding:0 0 5px 5px; margin-bottom:5px;">
  <img src="/sites/all/files/banner_provinciavlc.png" style="width:100%;" /><a href="https://itunes.apple.com/es/app/ayuntamientos-de-valencia/id922826907" target="blank"><img src="/sites/all/files/appstore.png" style="width:45%; float:left; padding:0 4px;" /></a><a href="https://play.google.com/store/apps/details?id=es.digitalvalue.valencia" target="blank"><img src="/sites/all/files/googleplay.png" style="width:45%; padding:0 4px;" /></a></div>
',
    'format' => 'full_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'cb3a56ee-9c47-4305-b097-fdca3e38c011';
  $display->content['new-cb3a56ee-9c47-4305-b097-fdca3e38c011'] = $pane;
  $display->panels['regio_dreta'][5] = 'new-cb3a56ee-9c47-4305-b097-fdca3e38c011';
  $pane = new stdClass();
  $pane->pid = 'new-0343402b-2f8a-4e32-b43e-b4f72d1afb9d';
  $pane->panel = 'regio_dreta';
  $pane->type = 'visorFarma';
  $pane->subtype = 'visorFarma';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'script' => 'sites/all/modules/jsapp/modules/visorfarma/index.js',
    'id' => '',
    'type' => 'file',
    'send' => TRUE,
    'endpoint' => '',
    'method' => 'JSON',
    'login_bar' => TRUE,
    'appkey' => '',
    'visorfarma_showRefuerzo' => 0,
    'visorfarma_showTomorrow' => 0,
    'visor_tipo' => 'banner',
    'visorfarma_texto_sup' => '',
    'visorfarma_node_enlace' => '',
    'visorfarma_poblacion' => '',
    'visorfarma_id' => 'panel-farmacias2',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '0343402b-2f8a-4e32-b43e-b4f72d1afb9d';
  $display->content['new-0343402b-2f8a-4e32-b43e-b4f72d1afb9d'] = $pane;
  $display->panels['regio_dreta'][6] = 'new-0343402b-2f8a-4e32-b43e-b4f72d1afb9d';
  $pane = new stdClass();
  $pane->pid = 'new-6b0d144d-c26b-478c-9cf5-75032bcb1809';
  $pane->panel = 'regio_dreta';
  $pane->type = 'views';
  $pane->subtype = 'calendario';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '@0',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'calendario1',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '6b0d144d-c26b-478c-9cf5-75032bcb1809';
  $display->content['new-6b0d144d-c26b-478c-9cf5-75032bcb1809'] = $pane;
  $display->panels['regio_dreta'][7] = 'new-6b0d144d-c26b-478c-9cf5-75032bcb1809';
  $pane = new stdClass();
  $pane->pid = 'new-fba674cc-b6b2-4614-877d-fd7ddcc02d90';
  $pane->panel = 'regio_peu2';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = TRUE;
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
    'admin_title' => 'Menú pie: Ayuntamiento ',
    'og_group' => NULL,
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Ayuntamiento',
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fba674cc-b6b2-4614-877d-fd7ddcc02d90';
  $display->content['new-fba674cc-b6b2-4614-877d-fd7ddcc02d90'] = $pane;
  $display->panels['regio_peu2'][0] = 'new-fba674cc-b6b2-4614-877d-fd7ddcc02d90';
  $pane = new stdClass();
  $pane->pid = 'new-6a2cf7d4-c547-410d-9898-ef4705be7262';
  $pane->panel = 'regio_peu2';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'pueblo',
    'items' => '10',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'Menú pie: Pueblo ',
    'og_group' => NULL,
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Pueblo',
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6a2cf7d4-c547-410d-9898-ef4705be7262';
  $display->content['new-6a2cf7d4-c547-410d-9898-ef4705be7262'] = $pane;
  $display->panels['regio_peu2'][1] = 'new-6a2cf7d4-c547-410d-9898-ef4705be7262';
  $pane = new stdClass();
  $pane->pid = 'new-28eb812a-297a-4662-9cf4-20df85b0e2ac';
  $pane->panel = 'regio_peu2';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = TRUE;
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
    'admin_title' => 'Menú pie: Directorio ',
    'og_group' => NULL,
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Directorio',
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '28eb812a-297a-4662-9cf4-20df85b0e2ac';
  $display->content['new-28eb812a-297a-4662-9cf4-20df85b0e2ac'] = $pane;
  $display->panels['regio_peu2'][2] = 'new-28eb812a-297a-4662-9cf4-20df85b0e2ac';
  $pane = new stdClass();
  $pane->pid = 'new-eb277ae9-4563-458a-8d17-138c6ef5ce1c';
  $pane->panel = 'regio_peu2';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = TRUE;
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
    'admin_title' => 'Menú pie: Turismo ',
    'og_group' => NULL,
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Turismo',
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'eb277ae9-4563-458a-8d17-138c6ef5ce1c';
  $display->content['new-eb277ae9-4563-458a-8d17-138c6ef5ce1c'] = $pane;
  $display->panels['regio_peu2'][3] = 'new-eb277ae9-4563-458a-8d17-138c6ef5ce1c';
  $pane = new stdClass();
  $pane->pid = 'new-43d4f381-eb8e-4ef9-aee3-41d1ec4c0047';
  $pane->panel = 'regio_peu2';
  $pane->type = 'pane';
  $pane->subtype = 'pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => '',
    'items' => '10',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '5',
    'fields' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Teleadministración ',
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
  $pane->uuid = '43d4f381-eb8e-4ef9-aee3-41d1ec4c0047';
  $display->content['new-43d4f381-eb8e-4ef9-aee3-41d1ec4c0047'] = $pane;
  $display->panels['regio_peu2'][4] = 'new-43d4f381-eb8e-4ef9-aee3-41d1ec4c0047';
  $pane = new stdClass();
  $pane->pid = 'new-01a973c1-bf22-4c1f-94f3-4bcd96141db9';
  $pane->panel = 'regio_peu3';
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
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '01a973c1-bf22-4c1f-94f3-4bcd96141db9';
  $display->content['new-01a973c1-bf22-4c1f-94f3-4bcd96141db9'] = $pane;
  $display->panels['regio_peu3'][0] = 'new-01a973c1-bf22-4c1f-94f3-4bcd96141db9';
  $pane = new stdClass();
  $pane->pid = 'new-4312c630-dbcf-470f-860c-ae0ab0776f05';
  $pane->panel = 'regio_peu3';
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
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'stylizer',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4312c630-dbcf-470f-860c-ae0ab0776f05';
  $display->content['new-4312c630-dbcf-470f-860c-ae0ab0776f05'] = $pane;
  $display->panels['regio_peu3'][1] = 'new-4312c630-dbcf-470f-860c-ae0ab0776f05';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$handler->conf['display'] = $display;
