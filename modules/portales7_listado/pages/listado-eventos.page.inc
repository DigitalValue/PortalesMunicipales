<?php
$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'eventos';
$page->task = 'page';
$page->admin_title = 'Listado eventos';
$page->admin_description = '';
$page->path = 'listado-evento';
$page->access = array();
$page->menu = array();
$page->arguments = array();
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_eventos_panel_context';
$handler->task = 'page';
$handler->subtask = 'eventos';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => 'llistat-events',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'panels_everywhere_site_template' => '',
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
    ),
    'main' => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'children' => array(
        0 => 1,
        1 => 'main-row',
      ),
      'parent' => 'canvas',
    ),
    'main-row' => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'center',
      ),
      'parent' => 'main',
    ),
    'center' => array(
      'type' => 'region',
      'title' => 'Centrado',
      'width' => '100',
      'width_type' => '%',
      'parent' => 'main-row',
    ),
    1 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'cap_llistat',
      ),
      'parent' => 'main',
      'class' => '',
    ),
    'cap_llistat' => array(
      'type' => 'region',
      'title' => 'cap-llistat',
      'width' => 100,
      'width_type' => '%',
      'parent' => '1',
      'class' => 'cap-llistat',
      'hide_empty' => 1,
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
    'center' => NULL,
    'columna_esquerra' => NULL,
    'cap_llistat' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '699d2e5a-e921-4edc-8878-1edc0ab43a11';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-640eb7eb-240f-4e4a-b4cf-c4ce32b95ca8';
  $pane->panel = 'cap_llistat';
  $pane->type = 'imagenes-vocabularios';
  $pane->subtype = 'imagenes-vocabularios';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'event_types',
    'possible_image_styles' => 'imagen-50',
    'url' => 'listado-evento',
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
  $pane->uuid = '640eb7eb-240f-4e4a-b4cf-c4ce32b95ca8';
  $display->content['new-640eb7eb-240f-4e4a-b4cf-c4ce32b95ca8'] = $pane;
  $display->panels['cap_llistat'][0] = 'new-640eb7eb-240f-4e4a-b4cf-c4ce32b95ca8';
  $pane = new stdClass();
  $pane->pid = 'new-fbdb62cb-0b06-484f-9be1-bbf7a3370d8a';
  $pane->panel = 'cap_llistat';
  $pane->type = 'listado-vocabularios';
  $pane->subtype = 'listado-vocabularios';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'calendar',
    'url' => 'listado-calendario',
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
  $pane->uuid = 'fbdb62cb-0b06-484f-9be1-bbf7a3370d8a';
  $display->content['new-fbdb62cb-0b06-484f-9be1-bbf7a3370d8a'] = $pane;
  $display->panels['cap_llistat'][1] = 'new-fbdb62cb-0b06-484f-9be1-bbf7a3370d8a';
  $pane = new stdClass();
  $pane->pid = 'new-33282a66-9fff-4428-82ac-3e480dd8151d';
  $pane->panel = 'cap_llistat';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'site_language',
        'settings' => array(
          'language' => array(
            'es' => 'es',
            'default' => 0,
          ),
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Seleccione un icono o un t&eacute;rmino para filtrar por una nueva categor&iacute;a</p>
',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '33282a66-9fff-4428-82ac-3e480dd8151d';
  $display->content['new-33282a66-9fff-4428-82ac-3e480dd8151d'] = $pane;
  $display->panels['cap_llistat'][2] = 'new-33282a66-9fff-4428-82ac-3e480dd8151d';
  $pane = new stdClass();
  $pane->pid = 'new-cfa28c8a-e9d1-4cbf-8fc8-46aab6fe3a97';
  $pane->panel = 'center';
  $pane->type = 'eventos';
  $pane->subtype = 'eventos';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => NULL,
    'arguments' => '',
    'items' => '10',
    'classes' => array(),
    'include_path' => 1,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_eventdate:ASC',
    'sort_by_url' => 1,
    'pager' => 'mini',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'field_event_type' => '-2',
    'fields' => '{
    "main_media":{
      "formatter": "fc_main_media",
      "settings" : {
        "video_style": "main_media",
        "image_style": "imagen-200",
        "description":0
      }
    },
    "title" : {
      "link" : 1
    },
    "teaser" : {
      "trim" : 300
    },
    "eventcalendar" : {},
    "eventdate" : {
      "format_type" : "sin_hora"
    }
  }',
    'possible_image_styles' => 'imagen-100',
    'override_title' => 0,
    'override_title_text' => '',
    'vocabulario' => 'event_types',
    'section' => 'any',
    'hide_description' => 0,
    'future_events' => 1,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cfa28c8a-e9d1-4cbf-8fc8-46aab6fe3a97';
  $display->content['new-cfa28c8a-e9d1-4cbf-8fc8-46aab6fe3a97'] = $pane;
  $display->panels['center'][0] = 'new-cfa28c8a-e9d1-4cbf-8fc8-46aab6fe3a97';
  $pane = new stdClass();
  $pane->pid = 'new-64365919-a007-4dcb-bef4-6d7fdb6663e7';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'event',
    'arguments' => '',
    'items' => '20',
    'classes' => NULL,
    'include_path' => 1,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_eventdate:ASC',
    'pager' => 'full',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginados-listado-eventos',
    'id' => 'pagina-listado-eventos',
    'view_mode' => 'vinculo_agenda_resumen',
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
    'css_class' => 'tres-columnas agenda5',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '64365919-a007-4dcb-bef4-6d7fdb6663e7';
  $display->content['new-64365919-a007-4dcb-bef4-6d7fdb6663e7'] = $pane;
  $display->panels['center'][1] = 'new-64365919-a007-4dcb-bef4-6d7fdb6663e7';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
