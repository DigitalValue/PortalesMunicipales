<?php
$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'listado_titulares';
$page->task = 'page';
$page->admin_title = 'Listado-titulares';
$page->admin_description = '';
$page->path = 'listado-titulares';
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
$handler->name = 'page_listado_titulares_panel_context';
$handler->task = 'page';
$handler->subtask = 'listado_titulares';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
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
      'class' => 'pagina-listado pagina-listado-titulares',
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
$display->uuid = '3e261523-ee1c-4e60-8699-cd02c5b0c20d';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a7c3e67a-fb86-47ab-b61b-8c8b643b4aa7';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-2',
    'arguments' => '',
    'items' => '30',
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
    'pager_id' => '3',
    'id' => 'listado-titulares',
    'view_mode' => 'vinculo_noticia_titular',
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
    'css_class' => 'separado',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a7c3e67a-fb86-47ab-b61b-8c8b643b4aa7';
  $display->content['new-a7c3e67a-fb86-47ab-b61b-8c8b643b4aa7'] = $pane;
  $display->panels['center'][0] = 'new-a7c3e67a-fb86-47ab-b61b-8c8b643b4aa7';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
