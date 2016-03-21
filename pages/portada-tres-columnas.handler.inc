<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_portada_tres_columnas';
$handler->task = 'page';
$handler->subtask = 'portada';
$handler->handler = 'panel_context';
$handler->weight = -30;
$handler->conf = array(
  'title' => 'portada tres columnas',
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
        0 => 11,
        1 => 6,
        2 => 3,
        3 => 5,
        4 => 21,
      ),
      'parent' => 'canvas',
      'class' => '',
      'hide_empty' => 1,
    ),
    3 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 17,
        1 => 18,
      ),
      'parent' => 'main',
      'class' => 'escaparate-inferior',
      'hide_empty' => 1,
    ),
    5 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 22,
        1 => 23,
      ),
      'parent' => 'main',
      'class' => 'carrusel-ediciones',
      'hide_empty' => 1,
    ),
    6 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 7,
        1 => 8,
      ),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 1,
    ),
    7 => array(
      'type' => 'column',
      'width' => '66.65259405197486',
      'width_type' => '%',
      'parent' => '6',
      'children' => array(
        0 => 9,
        1 => 12,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    8 => array(
      'type' => 'column',
      'width' => '33.34740594802514',
      'width_type' => '%',
      'parent' => '6',
      'children' => array(
        0 => 10,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    9 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'columna_izquierda_',
      ),
      'parent' => '7',
      'class' => '',
      'hide_empty' => 1,
    ),
    10 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'columna_derecha_',
      ),
      'parent' => '8',
      'class' => '',
      'hide_empty' => 1,
    ),
    'columna_izquierda_' => array(
      'type' => 'region',
      'title' => 'superior-izquierda',
      'width' => 100,
      'width_type' => '%',
      'parent' => '9',
      'class' => '',
      'hide_empty' => 1,
    ),
    'columna_derecha_' => array(
      'type' => 'region',
      'title' => 'superior-derecha',
      'width' => 100,
      'width_type' => '%',
      'parent' => '10',
      'class' => '',
      'hide_empty' => 1,
    ),
    11 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'columna_unica',
      ),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 1,
    ),
    'columna_unica' => array(
      'type' => 'region',
      'title' => 'superior',
      'width' => 100,
      'width_type' => '%',
      'parent' => '11',
      'class' => '',
      'hide_empty' => 1,
    ),
    12 => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 13,
        1 => 14,
      ),
      'parent' => '7',
      'class' => '',
      'hide_empty' => 1,
    ),
    13 => array(
      'type' => 'column',
      'width' => 50,
      'width_type' => '%',
      'parent' => '12',
      'children' => array(
        0 => 15,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    14 => array(
      'type' => 'column',
      'width' => 50,
      'width_type' => '%',
      'parent' => '12',
      'children' => array(
        0 => 16,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    15 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'columna_izquierda__',
      ),
      'parent' => '13',
      'class' => '',
      'hide_empty' => 1,
    ),
    16 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'columna_centro',
      ),
      'parent' => '14',
      'class' => '',
      'hide_empty' => 1,
    ),
    'columna_izquierda__' => array(
      'type' => 'region',
      'title' => 'superior-izquierda',
      'width' => 100,
      'width_type' => '%',
      'parent' => '15',
      'class' => '',
      'hide_empty' => 1,
    ),
    'columna_centro' => array(
      'type' => 'region',
      'title' => 'superior-centro',
      'width' => 100,
      'width_type' => '%',
      'parent' => '16',
      'class' => '',
      'hide_empty' => 1,
    ),
    17 => array(
      'type' => 'column',
      'width' => '66.67934296732183',
      'width_type' => '%',
      'parent' => '3',
      'children' => array(
        0 => 19,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    18 => array(
      'type' => 'column',
      'width' => '33.32065703267817',
      'width_type' => '%',
      'parent' => '3',
      'children' => array(
        0 => 20,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    19 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'inferior_izquierda',
      ),
      'parent' => '17',
      'class' => '',
      'hide_empty' => 1,
    ),
    20 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'inferior_derecha',
      ),
      'parent' => '18',
      'class' => '',
      'hide_empty' => 1,
    ),
    'inferior_izquierda' => array(
      'type' => 'region',
      'title' => 'inferior-izquierda',
      'width' => 100,
      'width_type' => '%',
      'parent' => '19',
      'class' => '',
      'hide_empty' => 1,
    ),
    'inferior_derecha' => array(
      'type' => 'region',
      'title' => 'inferior-derecha',
      'width' => 100,
      'width_type' => '%',
      'parent' => '20',
      'class' => '',
      'hide_empty' => 1,
    ),
    21 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'pie',
      ),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 1,
    ),
    'pie' => array(
      'type' => 'region',
      'title' => 'pie',
      'width' => 100,
      'width_type' => '%',
      'parent' => '21',
      'class' => '',
      'hide_empty' => 1,
    ),
    22 => array(
      'type' => 'column',
      'width' => '33.32065703267817',
      'width_type' => '%',
      'parent' => '5',
      'children' => array(
        0 => 24,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    23 => array(
      'type' => 'column',
      'width' => '66.67934296732183',
      'width_type' => '%',
      'parent' => '5',
      'children' => array(
        0 => 25,
      ),
      'class' => '',
      'hide_empty' => 1,
    ),
    24 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'inferior_izquierda_',
      ),
      'parent' => '22',
      'class' => '',
      'hide_empty' => 1,
    ),
    25 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'inferior_derecha_',
      ),
      'parent' => '23',
      'class' => '',
      'hide_empty' => 1,
    ),
    'inferior_izquierda_' => array(
      'type' => 'region',
      'title' => 'inferior-izquierda',
      'width' => 100,
      'width_type' => '%',
      'parent' => '24',
      'class' => '',
      'hide_empty' => 1,
    ),
    'inferior_derecha_' => array(
      'type' => 'region',
      'title' => 'inferior-derecha',
      'width' => 100,
      'width_type' => '%',
      'parent' => '25',
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
    'columna_izquierda' => NULL,
    'columna_derecha' => NULL,
    'columna_izquierda_' => NULL,
    'columna_derecha_' => NULL,
    'columna_unica' => NULL,
    'columna_izquierda__' => NULL,
    'columna_centro' => NULL,
    'inferior_izquierda' => NULL,
    'inferior_derecha' => NULL,
    'pie' => NULL,
    'inferior_izquierda_' => NULL,
    'inferior_derecha_' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = 'aa48ee40-5768-4c12-bc33-0071f7dfc9e0';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-308ce705-072c-4e67-93df-4d7ab8a7ecf9';
  $pane->panel = 'columna_centro';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'escaparate-portada',
    'items' => '',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-escaparate1',
    'id' => 'escaparate1',
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
    'css_class' => 'escaparate3',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '308ce705-072c-4e67-93df-4d7ab8a7ecf9';
  $display->content['new-308ce705-072c-4e67-93df-4d7ab8a7ecf9'] = $pane;
  $display->panels['columna_centro'][0] = 'new-308ce705-072c-4e67-93df-4d7ab8a7ecf9';
  $pane = new stdClass();
  $pane->pid = 'new-d5c1dc45-4ca4-492a-addd-b384b389adc0';
  $pane->panel = 'columna_centro';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'escaparate-portada',
    'items' => '1',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '1',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-escaparate2',
    'id' => 'escaparate2',
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
    'css_class' => 'escaparate3',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd5c1dc45-4ca4-492a-addd-b384b389adc0';
  $display->content['new-d5c1dc45-4ca4-492a-addd-b384b389adc0'] = $pane;
  $display->panels['columna_centro'][1] = 'new-d5c1dc45-4ca4-492a-addd-b384b389adc0';
  $pane = new stdClass();
  $pane->pid = 'new-23dd9ee2-6e1a-48f0-951d-da078be2394d';
  $pane->panel = 'columna_centro';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'escaparate-portada',
    'items' => '1',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '3',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-escaparate4',
    'id' => 'escaparate4',
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
    'css_class' => 'escaparate2',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '23dd9ee2-6e1a-48f0-951d-da078be2394d';
  $display->content['new-23dd9ee2-6e1a-48f0-951d-da078be2394d'] = $pane;
  $display->panels['columna_centro'][2] = 'new-23dd9ee2-6e1a-48f0-951d-da078be2394d';
  $pane = new stdClass();
  $pane->pid = 'new-71ab10a7-f67e-4099-a243-294a68e10f02';
  $pane->panel = 'columna_centro';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'event',
    'arguments' => '',
    'items' => '4',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_eventdate:ASC',
    'pager' => '',
    'more_link' => 'listado-calendario',
    'admin_title' => 'Agenda resumen',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '9',
    'calendar' => 'any',
    'id' => 'Agenda resumen',
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
    'css_class' => 'agenda5',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '71ab10a7-f67e-4099-a243-294a68e10f02';
  $display->content['new-71ab10a7-f67e-4099-a243-294a68e10f02'] = $pane;
  $display->panels['columna_centro'][3] = 'new-71ab10a7-f67e-4099-a243-294a68e10f02';
  $pane = new stdClass();
  $pane->pid = 'new-29f19554-0979-4d07-b821-fc9e6fb1ba8a';
  $pane->panel = 'columna_centro';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '7',
    'arguments' => '',
    'items' => '3',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '2',
    'sort' => 'portales7_eventdate:ASC',
    'pager' => '',
    'more_link' => '',
    'admin_title' => 'Agenda titular',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '1',
    'id' => 'Agenda titular',
    'view_mode' => 'vinculo_agenda_titular',
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
  $pane->uuid = '29f19554-0979-4d07-b821-fc9e6fb1ba8a';
  $display->content['new-29f19554-0979-4d07-b821-fc9e6fb1ba8a'] = $pane;
  $display->panels['columna_centro'][4] = 'new-29f19554-0979-4d07-b821-fc9e6fb1ba8a';
  $pane = new stdClass();
  $pane->pid = 'new-e38388b7-d0ec-4903-bbf4-92d777a68561';
  $pane->panel = 'columna_derecha_';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'notification',
    'arguments' => '',
    'items' => '10',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => 'listado-titulares/avisos',
    'admin_title' => 'Avisos',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '2',
    'id' => 'avisos',
    'view_mode' => 'link',
    'override_title' => 1,
    'override_title_text' => 'Avisos',
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
  $pane->uuid = 'e38388b7-d0ec-4903-bbf4-92d777a68561';
  $display->content['new-e38388b7-d0ec-4903-bbf4-92d777a68561'] = $pane;
  $display->panels['columna_derecha_'][0] = 'new-e38388b7-d0ec-4903-bbf4-92d777a68561';
  $pane = new stdClass();
  $pane->pid = 'new-cac7c770-9954-4bc9-a296-e7e734e914a8';
  $pane->panel = 'columna_derecha_';
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
    'group' => 'Redes sociales',
    'image_style' => 'imagen-200',
    'sort' => 'portales7_banners_weight:ASC',
    'override_title' => 1,
    'override_title_text' => 'Redes sociales',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'cac7c770-9954-4bc9-a296-e7e734e914a8';
  $display->content['new-cac7c770-9954-4bc9-a296-e7e734e914a8'] = $pane;
  $display->panels['columna_derecha_'][1] = 'new-cac7c770-9954-4bc9-a296-e7e734e914a8';
  $pane = new stdClass();
  $pane->pid = 'new-7a4e540a-d70b-49e3-82d0-5e1a584665f6';
  $pane->panel = 'columna_derecha_';
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
    'group' => 'Escaparate',
    'image_style' => 'imagen-300',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7a4e540a-d70b-49e3-82d0-5e1a584665f6';
  $display->content['new-7a4e540a-d70b-49e3-82d0-5e1a584665f6'] = $pane;
  $display->panels['columna_derecha_'][2] = 'new-7a4e540a-d70b-49e3-82d0-5e1a584665f6';
  $pane = new stdClass();
  $pane->pid = 'new-d39864cb-3bca-4736-a429-f4abd7731e46';
  $pane->panel = 'columna_derecha_';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'Escaparate-portada',
    'items' => '10',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
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
    'css_class' => 'una-columna escaparate',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd39864cb-3bca-4736-a429-f4abd7731e46';
  $display->content['new-d39864cb-3bca-4736-a429-f4abd7731e46'] = $pane;
  $display->panels['columna_derecha_'][3] = 'new-d39864cb-3bca-4736-a429-f4abd7731e46';
  $pane = new stdClass();
  $pane->pid = 'new-9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8';
  $pane->panel = 'columna_derecha_';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'anuncios',
    'items' => '5',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 1,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => '/listado-titulares/tablon de anuncios',
    'admin_title' => 'anuncios',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-anuncios',
    'id' => 'grupo-anuncios',
    'view_mode' => 'link',
    'override_title' => 1,
    'override_title_text' => 'Anuncios',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'una-columna postit',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8';
  $display->content['new-9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8'] = $pane;
  $display->panels['columna_derecha_'][4] = 'new-9f0d69e6-fedf-48fe-8bee-d4bbfb55afa8';
  $pane = new stdClass();
  $pane->pid = 'new-2d7a0524-954a-40ce-9d61-10987585b902';
  $pane->panel = 'columna_derecha_';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '-1',
    'arguments' => 'servicios municipales',
    'items' => '10',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => '',
    'more_link' => 'listado-titulares/servicios municipales',
    'admin_title' => 'Servicios Municipales',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => '9',
    'id' => 'servicios-municiapales',
    'view_mode' => 'link',
    'override_title' => 1,
    'override_title_text' => 'Servicios Municipales',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '2d7a0524-954a-40ce-9d61-10987585b902';
  $display->content['new-2d7a0524-954a-40ce-9d61-10987585b902'] = $pane;
  $display->panels['columna_derecha_'][5] = 'new-2d7a0524-954a-40ce-9d61-10987585b902';
  $pane = new stdClass();
  $pane->pid = 'new-d8e4d0fa-da10-48c0-b490-1aa98aadd76c';
  $pane->panel = 'columna_izquierda__';
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
    'css_class' => 'destacado una-columna',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd8e4d0fa-da10-48c0-b490-1aa98aadd76c';
  $display->content['new-d8e4d0fa-da10-48c0-b490-1aa98aadd76c'] = $pane;
  $display->panels['columna_izquierda__'][0] = 'new-d8e4d0fa-da10-48c0-b490-1aa98aadd76c';
  $pane = new stdClass();
  $pane->pid = 'new-1da1d9d2-7c9a-45ee-a278-154edd066afd';
  $pane->panel = 'columna_izquierda__';
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
    'more_link' => 'listado-completo/report',
    'admin_title' => 'grupo de noticias 2',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => 0,
    'pager_id' => 'paginador-grupo-noticias-2',
    'calendar' => 'any',
    'id' => 'grupo-noticias2',
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1da1d9d2-7c9a-45ee-a278-154edd066afd';
  $display->content['new-1da1d9d2-7c9a-45ee-a278-154edd066afd'] = $pane;
  $display->panels['columna_izquierda__'][1] = 'new-1da1d9d2-7c9a-45ee-a278-154edd066afd';
  $pane = new stdClass();
  $pane->pid = 'new-222c01c3-ee30-4bc9-a37c-1b4202f765a7';
  $pane->panel = 'columna_izquierda__';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'report',
    'arguments' => '',
    'items' => '5',
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
    'css_class' => 'una-columna extracto ',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '222c01c3-ee30-4bc9-a37c-1b4202f765a7';
  $display->content['new-222c01c3-ee30-4bc9-a37c-1b4202f765a7'] = $pane;
  $display->panels['columna_izquierda__'][2] = 'new-222c01c3-ee30-4bc9-a37c-1b4202f765a7';
  $pane = new stdClass();
  $pane->pid = 'new-ad938bb1-dfa4-4087-8417-17b654d49e28';
  $pane->panel = 'columna_izquierda__';
  $pane->type = 'definitivepane';
  $pane->subtype = 'definitivepane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'report',
    'arguments' => '',
    'items' => '3',
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
    'css_class' => 'una-columna extracto',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ad938bb1-dfa4-4087-8417-17b654d49e28';
  $display->content['new-ad938bb1-dfa4-4087-8417-17b654d49e28'] = $pane;
  $display->panels['columna_izquierda__'][3] = 'new-ad938bb1-dfa4-4087-8417-17b654d49e28';
  $pane = new stdClass();
  $pane->pid = 'new-4c911440-bc91-4cc2-b810-000507ef6a5b';
  $pane->panel = 'columna_izquierda__';
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
  $display->panels['columna_izquierda__'][4] = 'new-4c911440-bc91-4cc2-b810-000507ef6a5b';
  $pane = new stdClass();
  $pane->pid = 'new-a34c7920-5055-4404-bce6-67389dc47624';
  $pane->panel = 'columna_unica';
  $pane->type = 'advkenburns';
  $pane->subtype = 'advkenburns';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => '19',
    'arguments' => '',
    'items' => '10',
    'classes' => NULL,
    'include_path' => 0,
    'promoted' => 0,
    'offset' => '0',
    'sort' => 'portales7_newsdate:DESC',
    'pager' => NULL,
    'more_link' => NULL,
    'admin_title' => '',
    'og_group' => NULL,
    'section' => 'any',
    'hide_description' => NULL,
    'pager_id' => '4',
    'calendar' => 'any',
    'id' => 'principal',
    'image_style' => '',
    'duration' => '50000',
    'ease3d' => 'ease-out',
    'fadeSpeed' => '5000',
    'scale' => '1',
    'height' => '360',
    'width' => '925',
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
  $pane->uuid = 'a34c7920-5055-4404-bce6-67389dc47624';
  $display->content['new-a34c7920-5055-4404-bce6-67389dc47624'] = $pane;
  $display->panels['columna_unica'][0] = 'new-a34c7920-5055-4404-bce6-67389dc47624';
  $pane = new stdClass();
  $pane->pid = 'new-043a6d3e-2677-4b0f-9e77-9c887d3da2f9';
  $pane->panel = 'pie';
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
  $display->panels['pie'][0] = 'new-043a6d3e-2677-4b0f-9e77-9c887d3da2f9';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$handler->conf['display'] = $display;