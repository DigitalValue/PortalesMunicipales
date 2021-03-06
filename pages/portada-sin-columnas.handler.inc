<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_portada_sin_columnas';
$handler->task = 'page';
$handler->subtask = 'portada';
$handler->handler = 'panel_context';
$handler->weight = -28;
$handler->conf = array(
  'title' => 'portada sin columnas',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => 'pm-pagina-portada',
  'body_classes_to_add' => 'pm-pagina-portada',
  'css_id' => 'pm-pagina-portada',
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
      'class' => '',
      'column_class' => '',
      'row_class' => '',
      'region_class' => '',
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
        0 => 4,
        1 => 3,
        2 => 1,
        3 => 'main-row',
        4 => 2,
        5 => 5,
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
      'class' => '',
      'hide_empty' => 1,
    ),
    'center' => array(
      'type' => 'region',
      'title' => 'Centrado',
      'width' => 100,
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => '',
      'hide_empty' => 1,
    ),
    1 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'centrado_superior',
      ),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 1,
    ),
    'centrado_superior' => array(
      'type' => 'region',
      'title' => 'centrado-superior',
      'width' => 100,
      'width_type' => '%',
      'parent' => '1',
      'class' => '',
      'hide_empty' => 1,
    ),
    2 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'centrado_inferior',
      ),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 1,
    ),
    'centrado_inferior' => array(
      'type' => 'region',
      'title' => 'centrado inferior',
      'width' => 100,
      'width_type' => '%',
      'parent' => '2',
      'class' => '',
      'hide_empty' => 1,
    ),
    3 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'escaparate_superior',
      ),
      'parent' => 'main',
      'class' => 'escaparate-superior',
      'hide_empty' => 1,
    ),
    4 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'capitel_superior',
      ),
      'parent' => 'main',
      'class' => 'capitel',
      'hide_empty' => 1,
    ),
    'capitel_superior' => array(
      'type' => 'region',
      'title' => 'capitel-superior',
      'width' => 100,
      'width_type' => '%',
      'parent' => '4',
      'class' => 'capitel-superior',
      'hide_empty' => 1,
    ),
    'escaparate_superior' => array(
      'type' => 'region',
      'title' => 'escaparate-superior',
      'width' => 100,
      'width_type' => '%',
      'parent' => '3',
      'class' => 'escaparate-superior',
      'hide_empty' => 1,
    ),
    5 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'carrusel_ediciones',
      ),
      'parent' => 'main',
      'class' => 'carrusel-ediciones',
      'hide_empty' => 0,
    ),
    'carrusel_ediciones' => array(
      'type' => 'region',
      'title' => 'pie',
      'width' => 100,
      'width_type' => '%',
      'parent' => '5',
      'class' => '',
      'hide_empty' => 1,
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'center' => NULL,
    'centrado_superior' => NULL,
    'centrado_inferior' => NULL,
    'capitel_superior' => NULL,
    'escaparate_superior' => NULL,
    'carrusel_ediciones' => NULL,
    'carrusel_ediciones1' => NULL,
    'carrusel_ediciones2' => NULL,
    'carrusel_ediciones3' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = 'aa48ee40-5768-4c12-bc33-0071f7dfc9e0';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ad85638b-37c0-43d0-b703-b5aca4bf73d5';
  $pane->panel = 'capitel_superior';
  $pane->type = 'banners74';
  $pane->subtype = 'banners74';
  $pane->shown = FALSE;
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
    'group' => '5',
    'image_style' => 'imagen-200',
    'sort' => 'portales7_banners_weight:ASC',
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
    'css_class' => 'tres-columnas',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ad85638b-37c0-43d0-b703-b5aca4bf73d5';
  $display->content['new-ad85638b-37c0-43d0-b703-b5aca4bf73d5'] = $pane;
  $display->panels['capitel_superior'][0] = 'new-ad85638b-37c0-43d0-b703-b5aca4bf73d5';
  $pane = new stdClass();
  $pane->pid = 'new-043a6d3e-2677-4b0f-9e77-9c887d3da2f9';
  $pane->panel = 'carrusel_ediciones';
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
    'group' => '4',
    'image_style' => 'imagen-300',
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
    'css_class' => 'cinco-columnas',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '043a6d3e-2677-4b0f-9e77-9c887d3da2f9';
  $display->content['new-043a6d3e-2677-4b0f-9e77-9c887d3da2f9'] = $pane;
  $display->panels['carrusel_ediciones'][0] = 'new-043a6d3e-2677-4b0f-9e77-9c887d3da2f9';
  $pane = new stdClass();
  $pane->pid = 'new-d8e4d0fa-da10-48c0-b490-1aa98aadd76c';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'report',
    'arguments' => '',
    'items' => '1',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'grupo de noticias 1',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-noticias-1',
    'id' => 'grupo-noticias-1',
    'view_mode' => 'vinculo_noticia_resumen',
    'override_title' => 1,
    'override_title_text' => 'Noticias',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'destacado foto-izquierda',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd8e4d0fa-da10-48c0-b490-1aa98aadd76c';
  $display->content['new-d8e4d0fa-da10-48c0-b490-1aa98aadd76c'] = $pane;
  $display->panels['center'][0] = 'new-d8e4d0fa-da10-48c0-b490-1aa98aadd76c';
  $pane = new stdClass();
  $pane->pid = 'new-1da1d9d2-7c9a-45ee-a278-154edd066afd';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'report',
    'arguments' => '',
    'items' => '2',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '1',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'grupo de noticias 2',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-noticias-2',
    'id' => 'grupo-noticias2',
    'view_mode' => 'vinculo_noticia_resumen',
    'override_title' => 1,
    'override_title_text' => 'noticias 2',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1da1d9d2-7c9a-45ee-a278-154edd066afd';
  $display->content['new-1da1d9d2-7c9a-45ee-a278-154edd066afd'] = $pane;
  $display->panels['center'][1] = 'new-1da1d9d2-7c9a-45ee-a278-154edd066afd';
  $pane = new stdClass();
  $pane->pid = 'new-222c01c3-ee30-4bc9-a37c-1b4202f765a7';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'report',
    'arguments' => '',
    'items' => '6',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '3',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'grupo de noticias 3',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-noticias3',
    'id' => 'grupo-noticias3',
    'view_mode' => 'vinculo_noticia_resumen',
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
    'css_class' => 'tres-filas extracto foto-izquierda',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '222c01c3-ee30-4bc9-a37c-1b4202f765a7';
  $display->content['new-222c01c3-ee30-4bc9-a37c-1b4202f765a7'] = $pane;
  $display->panels['center'][2] = 'new-222c01c3-ee30-4bc9-a37c-1b4202f765a7';
  $pane = new stdClass();
  $pane->pid = 'new-ad938bb1-dfa4-4087-8417-17b654d49e28';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '6',
    'arguments' => '',
    'items' => '6',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '9',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => 'listado-titulares/report',
    'admin_title' => 'grupo de noticias 4',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-noticias4',
    'id' => 'grupo-noticias-4',
    'view_mode' => 'vinculo_noticia_titular',
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
    'css_class' => 'tres-filas extracto',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ad938bb1-dfa4-4087-8417-17b654d49e28';
  $display->content['new-ad938bb1-dfa4-4087-8417-17b654d49e28'] = $pane;
  $display->panels['center'][3] = 'new-ad938bb1-dfa4-4087-8417-17b654d49e28';
  $pane = new stdClass();
  $pane->pid = 'new-4c911440-bc91-4cc2-b810-000507ef6a5b';
  $pane->panel = 'center';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'report',
    'arguments' => '',
    'items' => '6',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '9',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '/listado-titulares/report',
    'admin_title' => 'grupo de noticias de titulares',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'grupo-noticias-4',
    'id' => 'grupo-noticias-4',
    'view_mode' => 'vinculo_noticia_titular',
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
    'css_class' => 'tres-columnas',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '4c911440-bc91-4cc2-b810-000507ef6a5b';
  $display->content['new-4c911440-bc91-4cc2-b810-000507ef6a5b'] = $pane;
  $display->panels['center'][4] = 'new-4c911440-bc91-4cc2-b810-000507ef6a5b';
  $pane = new stdClass();
  $pane->pid = 'new-20803022-fb8f-438e-bd7b-6aa510b1729f';
  $pane->panel = 'centrado_inferior';
  $pane->type = 'agenda';
  $pane->subtype = 'agenda';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => NULL,
    'arguments' => '',
    'items' => '6',
    'classes' => array(),
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_eventdate:DESC',
    'pager' => '',
    'more_link' => '/listado-titulares/event',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-events',
    'calendar' => '18',
    'date_style' => 'Y-m-d H:i',
    'hide_end_date' => 1,
    'image_style' => 'imagen-43-150',
    'override_title' => 1,
    'override_title_text' => 'Agenda',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '20803022-fb8f-438e-bd7b-6aa510b1729f';
  $display->content['new-20803022-fb8f-438e-bd7b-6aa510b1729f'] = $pane;
  $display->panels['centrado_inferior'][0] = 'new-20803022-fb8f-438e-bd7b-6aa510b1729f';
  $pane = new stdClass();
  $pane->pid = 'new-3bf48570-df3f-4b2a-9511-c47531127c70';
  $pane->panel = 'centrado_inferior';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'event',
    'arguments' => '',
    'items' => '10',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '/listado-titulares/agenda',
    'admin_title' => 'Agenda',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-agenda1',
    'id' => 'grupo-agenda1',
    'view_mode' => 'vinculo_agenda_resumen',
    'override_title' => 1,
    'override_title_text' => 'Agenda',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'tres-columnas agenda3',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3bf48570-df3f-4b2a-9511-c47531127c70';
  $display->content['new-3bf48570-df3f-4b2a-9511-c47531127c70'] = $pane;
  $display->panels['centrado_inferior'][1] = 'new-3bf48570-df3f-4b2a-9511-c47531127c70';
  $pane = new stdClass();
  $pane->pid = 'new-9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8';
  $pane->panel = 'centrado_superior';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'notification',
    'arguments' => '',
    'items' => '3',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '/listado-titulares/notification',
    'admin_title' => 'anuncios',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-anuncios',
    'id' => 'grupo-anuncios',
    'view_mode' => 'default',
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
    'css_class' => 'tres-columnas',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8';
  $display->content['new-9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8'] = $pane;
  $display->panels['centrado_superior'][0] = 'new-9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8';
  $pane = new stdClass();
  $pane->pid = 'new-d39864cb-3bca-4736-a429-f4abd7731e46';
  $pane->panel = 'escaparate_superior';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'Escaparate-portada',
    'items' => '10',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'Escaparate',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '9',
    'id' => 'escaparate-superior',
    'view_mode' => 'vinculo_escaparate_libre',
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
    'css_class' => 'tres-columnas escaparate',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd39864cb-3bca-4736-a429-f4abd7731e46';
  $display->content['new-d39864cb-3bca-4736-a429-f4abd7731e46'] = $pane;
  $display->panels['escaparate_superior'][0] = 'new-d39864cb-3bca-4736-a429-f4abd7731e46';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$handler->conf['display'] = $display;
