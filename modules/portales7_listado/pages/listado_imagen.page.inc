<?php
$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'listado_imagen';
$page->task = 'page';
$page->admin_title = 'Listado imagen';
$page->admin_description = '';
$page->path = 'listado-imagen';
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
$handler->name = 'page_listado_imagen_panel_context';
$handler->task = 'page';
$handler->subtask = 'listado_imagen';
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
      'class' => 'pagina-listado pagina-listado-imagenes',
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
$display->uuid = 'da49d3ec-8a19-4e16-bb50-6c6e8742739c';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-01d16086-4a82-4457-b3ae-1fe0ca26f481';
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
    'pager_id' => '9',
    'id' => 'listado-imagenes',
    'view_mode' => 'vinculo_imagen_adjunta_43_150',
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
  $pane->uuid = '01d16086-4a82-4457-b3ae-1fe0ca26f481';
  $display->content['new-01d16086-4a82-4457-b3ae-1fe0ca26f481'] = $pane;
  $display->panels['center'][0] = 'new-01d16086-4a82-4457-b3ae-1fe0ca26f481';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
