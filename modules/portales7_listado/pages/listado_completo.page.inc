<?php
$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'listado_completo';
$page->task = 'page';
$page->admin_title = 'Listado completo';
$page->admin_description = '';
$page->path = 'listado-completo';
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
$handler->name = 'page_listado_completo_panel_context';
$handler->task = 'page';
$handler->subtask = 'listado_completo';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => 'pagina-listado',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
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
      'class' => 'pagina-listado pagina-listado-resumen',
      'column_class' => '',
      'row_class' => '',
      'region_class' => '',
      'no_scale' => TRUE,
      'fixed_width' => '',
      'column_separation' => '',
      'region_separation' => '',
      'row_separation' => '',
      'hide_empty' => 1,
    ),
    'main' => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'children' => array(
        0 => 'main-row',
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
      'width' => 100,
      'width_type' => '%',
      'parent' => 'main-row',
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
    'center' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '4f064d3c-fbf8-4547-a0c5-a6036f7e1090';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bccee153-24e4-4dde-bf44-7a6206a9af29';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-2',
    'arguments' => '',
    'items' => '20',
    'classes' => NULL,
    'include_path' => 1,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'sort_by_url' => 1,
    'pager' => 'mini',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '12',
    'calendar' => 'any',
    'id' => 'listado-completo2',
    'view_mode' => 'vinculo_noticia_completo',
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
    'css_class' => 'foto-izquierda separado',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bccee153-24e4-4dde-bf44-7a6206a9af29';
  $display->content['new-bccee153-24e4-4dde-bf44-7a6206a9af29'] = $pane;
  $display->panels['center'][0] = 'new-bccee153-24e4-4dde-bf44-7a6206a9af29';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;


