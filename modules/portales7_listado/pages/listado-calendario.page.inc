<?php
$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'listado_calendario';
$page->task = 'page';
$page->admin_title = 'Listado calendario';
$page->admin_description = '';
$page->path = 'listado-calendario';
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
$handler->name = 'page_listado_calendario_panel_context';
$handler->task = 'page';
$handler->subtask = 'listado_calendario';
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
      'width' => 100,
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
    'cap_llistat' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '72ab0ec6-095e-4d19-9ce5-fc8fde905be1';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-53d09d37-140b-447a-aa0c-3b37e6967d97';
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
  $pane->uuid = '53d09d37-140b-447a-aa0c-3b37e6967d97';
  $display->content['new-53d09d37-140b-447a-aa0c-3b37e6967d97'] = $pane;
  $display->panels['cap_llistat'][0] = 'new-53d09d37-140b-447a-aa0c-3b37e6967d97';
  $pane = new stdClass();
  $pane->pid = 'new-ea3ce763-2c5d-488a-9206-dceae3b02e0c';
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
  $pane->uuid = 'ea3ce763-2c5d-488a-9206-dceae3b02e0c';
  $display->content['new-ea3ce763-2c5d-488a-9206-dceae3b02e0c'] = $pane;
  $display->panels['cap_llistat'][1] = 'new-ea3ce763-2c5d-488a-9206-dceae3b02e0c';
  $pane = new stdClass();
  $pane->pid = 'new-6344af8e-518f-471a-aebd-486a57fd9432';
  $pane->panel = 'cap_llistat';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
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
  $pane->uuid = '6344af8e-518f-471a-aebd-486a57fd9432';
  $display->content['new-6344af8e-518f-471a-aebd-486a57fd9432'] = $pane;
  $display->panels['cap_llistat'][2] = 'new-6344af8e-518f-471a-aebd-486a57fd9432';
  $pane = new stdClass();
  $pane->pid = 'new-d9d439f2-3629-47ef-b1b5-b820a7559a5d';
  $pane->panel = 'center';
  $pane->type = 'agenda';
  $pane->subtype = 'agenda';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => NULL,
    'arguments' => '',
    'items' => '0',
    'classes' => array(),
    'include_path' => 1,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_eventdate:ASC',
    'sort_by_url' => 1,
    'pager' => 'mini',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => 'any',
    'calendar' => '-1',
    'date_style' => 'Y-m-d H:i',
    'hide_end_date' => 0,
    'image_style' => 'imagen-100',
    'override_title' => 0,
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
  $pane->uuid = 'd9d439f2-3629-47ef-b1b5-b820a7559a5d';
  $display->content['new-d9d439f2-3629-47ef-b1b5-b820a7559a5d'] = $pane;
  $display->panels['center'][0] = 'new-d9d439f2-3629-47ef-b1b5-b820a7559a5d';
  $pane = new stdClass();
  $pane->pid = 'new-e87ba594-ee6d-4253-9791-fc4ddeb9f57e';
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
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-listado-calendarios',
    'id' => 'pagina-listado-calendarios',
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
  $pane->uuid = 'e87ba594-ee6d-4253-9791-fc4ddeb9f57e';
  $display->content['new-e87ba594-ee6d-4253-9791-fc4ddeb9f57e'] = $pane;
  $display->panels['center'][1] = 'new-e87ba594-ee6d-4253-9791-fc4ddeb9f57e';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = 'new-53d09d37-140b-447a-aa0c-3b37e6967d97';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
