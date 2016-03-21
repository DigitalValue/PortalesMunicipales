<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context_7';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -25;
$handler->conf = array(
  'title' => 'Nodo entidad',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
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
            'portales7_entity' => 'portales7_entity',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  ),
  'panels_everywhere_site_template' => 'site_template_panel_context_19',
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
        0 => 'main-row',
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
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
        0 => 'datos_entidad',
      ),
      'parent' => 'main',
      'class' => '',
    ),
    'datos_entidad' => array(
      'type' => 'region',
      'title' => 'Datos-entidad',
      'width' => 100,
      'width_type' => '%',
      'parent' => '1',
      'class' => '',
    ),
    2 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'datos_contacto',
      ),
      'parent' => 'main',
      'class' => '',
    ),
    'datos_contacto' => array(
      'type' => 'region',
      'title' => 'datos contacto',
      'width' => 100,
      'width_type' => '%',
      'parent' => '2',
      'class' => '',
    ),
    3 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'mas_informaci__n',
      ),
      'parent' => 'main',
      'class' => '',
    ),
    'mas_informaci__n' => array(
      'type' => 'region',
      'title' => 'mas información',
      'width' => 100,
      'width_type' => '%',
      'parent' => '3',
      'class' => '',
    ),
    4 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'archivos',
      ),
      'parent' => 'main',
      'class' => '',
    ),
    'archivos' => array(
      'type' => 'region',
      'title' => 'archivos',
      'width' => 100,
      'width_type' => '%',
      'parent' => '4',
      'class' => '',
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
    'center' => NULL,
    'datos_entidad' => NULL,
    'datos_contacto' => NULL,
    'mas_informaci__n' => NULL,
    'archivos' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '1cf839f8-205c-49f8-a68a-020c041950b8';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1588288d-1d9c-46ad-a2a2-4cd973db716c';
  $pane->panel = 'archivos';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_images';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'colorbox',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'colorbox_node_style' => 'imagen-200',
      'colorbox_image_style' => '',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'auto',
      'colorbox_caption_custom' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '1588288d-1d9c-46ad-a2a2-4cd973db716c';
  $display->content['new-1588288d-1d9c-46ad-a2a2-4cd973db716c'] = $pane;
  $display->panels['archivos'][0] = 'new-1588288d-1d9c-46ad-a2a2-4cd973db716c';
  $pane = new stdClass();
  $pane->pid = 'new-00ac822d-d535-4266-b4c1-52e25b280cee';
  $pane->panel = 'archivos';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_files';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'file_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
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
  $pane->uuid = '00ac822d-d535-4266-b4c1-52e25b280cee';
  $display->content['new-00ac822d-d535-4266-b4c1-52e25b280cee'] = $pane;
  $display->panels['archivos'][1] = 'new-00ac822d-d535-4266-b4c1-52e25b280cee';
  $pane = new stdClass();
  $pane->pid = 'new-5d89a1d7-2334-43c9-a9b2-681c6efe4bd9';
  $pane->panel = 'archivos';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_videos';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'video_formatter_player',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'widthxheight' => '640x360',
      'poster_image_style' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5d89a1d7-2334-43c9-a9b2-681c6efe4bd9';
  $display->content['new-5d89a1d7-2334-43c9-a9b2-681c6efe4bd9'] = $pane;
  $display->panels['archivos'][2] = 'new-5d89a1d7-2334-43c9-a9b2-681c6efe4bd9';
  $pane = new stdClass();
  $pane->pid = 'new-52c49f69-a326-4304-b353-573324f84a63';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
    ),
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
  $pane->uuid = '52c49f69-a326-4304-b353-573324f84a63';
  $display->content['new-52c49f69-a326-4304-b353-573324f84a63'] = $pane;
  $display->panels['center'][0] = 'new-52c49f69-a326-4304-b353-573324f84a63';
  $pane = new stdClass();
  $pane->pid = 'new-a72d99d1-1231-4956-9d07-dadc8e316f67';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_opening_hours';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'field_collection_fields',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
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
  $pane->uuid = 'a72d99d1-1231-4956-9d07-dadc8e316f67';
  $display->content['new-a72d99d1-1231-4956-9d07-dadc8e316f67'] = $pane;
  $display->panels['center'][1] = 'new-a72d99d1-1231-4956-9d07-dadc8e316f67';
  $pane = new stdClass();
  $pane->pid = 'new-5b308d43-6952-4e5d-9bd1-7e394980dddf';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_main_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image_title',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'colorbox_node_style' => 'imagen-300',
      'colorbox_image_style' => '',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'auto',
      'colorbox_caption_custom' => '',
      'class_title' => '',
    ),
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5b308d43-6952-4e5d-9bd1-7e394980dddf';
  $display->content['new-5b308d43-6952-4e5d-9bd1-7e394980dddf'] = $pane;
  $display->panels['center'][2] = 'new-5b308d43-6952-4e5d-9bd1-7e394980dddf';
  $pane = new stdClass();
  $pane->pid = 'new-0d808786-179a-48f0-8c39-d44358d84be9';
  $pane->panel = 'center';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '0d808786-179a-48f0-8c39-d44358d84be9';
  $display->content['new-0d808786-179a-48f0-8c39-d44358d84be9'] = $pane;
  $display->panels['center'][3] = 'new-0d808786-179a-48f0-8c39-d44358d84be9';
  $pane = new stdClass();
  $pane->pid = 'new-19e00cc8-e078-4b3c-874b-28090d3d82ba';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_teaser';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '19e00cc8-e078-4b3c-874b-28090d3d82ba';
  $display->content['new-19e00cc8-e078-4b3c-874b-28090d3d82ba'] = $pane;
  $display->panels['center'][4] = 'new-19e00cc8-e078-4b3c-874b-28090d3d82ba';
  $pane = new stdClass();
  $pane->pid = 'new-4516abf2-caa4-4ecc-ac25-dc8419dc7856';
  $pane->panel = 'datos_contacto';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '4516abf2-caa4-4ecc-ac25-dc8419dc7856';
  $display->content['new-4516abf2-caa4-4ecc-ac25-dc8419dc7856'] = $pane;
  $display->panels['datos_contacto'][0] = 'new-4516abf2-caa4-4ecc-ac25-dc8419dc7856';
  $pane = new stdClass();
  $pane->pid = 'new-dd4a6e32-034b-4f2c-a1eb-a4f403c00cae';
  $pane->panel = 'datos_contacto';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_geofield';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'map_from_adressess',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'include_map' => 1,
      'include_static_map' => 0,
      'include_link' => 0,
      'include_text' => 0,
      'iframe_height' => '200',
      'iframe_width' => '200',
      'zoom_level' => '18',
      'information_bubble' => 0,
      'link_text' => 'Ver más grande',
      'map_type' => 'm',
      'langcode' => 'es',
    ),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dd4a6e32-034b-4f2c-a1eb-a4f403c00cae';
  $display->content['new-dd4a6e32-034b-4f2c-a1eb-a4f403c00cae'] = $pane;
  $display->panels['datos_contacto'][1] = 'new-dd4a6e32-034b-4f2c-a1eb-a4f403c00cae';
  $pane = new stdClass();
  $pane->pid = 'new-dbb37453-3d0e-4693-9c6c-b202aa0aa862';
  $pane->panel = 'datos_contacto';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_people';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'field_collection_fields',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dbb37453-3d0e-4693-9c6c-b202aa0aa862';
  $display->content['new-dbb37453-3d0e-4693-9c6c-b202aa0aa862'] = $pane;
  $display->panels['datos_contacto'][2] = 'new-dbb37453-3d0e-4693-9c6c-b202aa0aa862';
  $pane = new stdClass();
  $pane->pid = 'new-8ebdafcf-0fc7-47b9-a756-5f3f2835ac22';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_postaladdress';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'addressfield_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'use_widget_handlers' => 1,
      'format_handlers' => array(
        'address' => 'address',
      ),
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '8ebdafcf-0fc7-47b9-a756-5f3f2835ac22';
  $display->content['new-8ebdafcf-0fc7-47b9-a756-5f3f2835ac22'] = $pane;
  $display->panels['datos_entidad'][0] = 'new-8ebdafcf-0fc7-47b9-a756-5f3f2835ac22';
  $pane = new stdClass();
  $pane->pid = 'new-c31abf58-9680-45e8-a959-935eeaad9770';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_telephone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
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
  $pane->uuid = 'c31abf58-9680-45e8-a959-935eeaad9770';
  $display->content['new-c31abf58-9680-45e8-a959-935eeaad9770'] = $pane;
  $display->panels['datos_entidad'][1] = 'new-c31abf58-9680-45e8-a959-935eeaad9770';
  $pane = new stdClass();
  $pane->pid = 'new-5803c6d6-803f-43c7-b190-e0ae17cb0374';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_fax';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_trimmed',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '600',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5803c6d6-803f-43c7-b190-e0ae17cb0374';
  $display->content['new-5803c6d6-803f-43c7-b190-e0ae17cb0374'] = $pane;
  $display->panels['datos_entidad'][2] = 'new-5803c6d6-803f-43c7-b190-e0ae17cb0374';
  $pane = new stdClass();
  $pane->pid = 'new-37eb33b8-f6fc-4fbc-81c3-444f03b9a9a0';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'link_email',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '37eb33b8-f6fc-4fbc-81c3-444f03b9a9a0';
  $display->content['new-37eb33b8-f6fc-4fbc-81c3-444f03b9a9a0'] = $pane;
  $display->panels['datos_entidad'][3] = 'new-37eb33b8-f6fc-4fbc-81c3-444f03b9a9a0';
  $pane = new stdClass();
  $pane->pid = 'new-95936e77-3269-45c6-98be-e7610d7c7ee2';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_web';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'link_itself',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '95936e77-3269-45c6-98be-e7610d7c7ee2';
  $display->content['new-95936e77-3269-45c6-98be-e7610d7c7ee2'] = $pane;
  $display->panels['datos_entidad'][4] = 'new-95936e77-3269-45c6-98be-e7610d7c7ee2';
  $pane = new stdClass();
  $pane->pid = 'new-59b5fa98-36ac-433b-8d69-0bab470fd98a';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_facebook';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '59b5fa98-36ac-433b-8d69-0bab470fd98a';
  $display->content['new-59b5fa98-36ac-433b-8d69-0bab470fd98a'] = $pane;
  $display->panels['datos_entidad'][5] = 'new-59b5fa98-36ac-433b-8d69-0bab470fd98a';
  $pane = new stdClass();
  $pane->pid = 'new-a1ae639d-7a7c-4d4c-b1e3-a7bffe340599';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_twitter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'a1ae639d-7a7c-4d4c-b1e3-a7bffe340599';
  $display->content['new-a1ae639d-7a7c-4d4c-b1e3-a7bffe340599'] = $pane;
  $display->panels['datos_entidad'][6] = 'new-a1ae639d-7a7c-4d4c-b1e3-a7bffe340599';
  $pane = new stdClass();
  $pane->pid = 'new-9010464e-5979-4ab3-aa7d-fb8fc29f2ee2';
  $pane->panel = 'datos_entidad';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_other';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '9010464e-5979-4ab3-aa7d-fb8fc29f2ee2';
  $display->content['new-9010464e-5979-4ab3-aa7d-fb8fc29f2ee2'] = $pane;
  $display->panels['datos_entidad'][7] = 'new-9010464e-5979-4ab3-aa7d-fb8fc29f2ee2';
  $pane = new stdClass();
  $pane->pid = 'new-95ea7489-12b9-48e0-a878-5cd99199a36c';
  $pane->panel = 'mas_informaci__n';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '95ea7489-12b9-48e0-a878-5cd99199a36c';
  $display->content['new-95ea7489-12b9-48e0-a878-5cd99199a36c'] = $pane;
  $display->panels['mas_informaci__n'][0] = 'new-95ea7489-12b9-48e0-a878-5cd99199a36c';
  $pane = new stdClass();
  $pane->pid = 'new-805e52cd-72da-477e-a880-dba4b4545f5a';
  $pane->panel = 'mas_informaci__n';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_families';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
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
  $pane->uuid = '805e52cd-72da-477e-a880-dba4b4545f5a';
  $display->content['new-805e52cd-72da-477e-a880-dba4b4545f5a'] = $pane;
  $display->panels['mas_informaci__n'][1] = 'new-805e52cd-72da-477e-a880-dba4b4545f5a';
  $pane = new stdClass();
  $pane->pid = 'new-6abe02da-376b-4659-bb94-88f72c4bd65e';
  $pane->panel = 'mas_informaci__n';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:portales7_entity_extra';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6abe02da-376b-4659-bb94-88f72c4bd65e';
  $display->content['new-6abe02da-376b-4659-bb94-88f72c4bd65e'] = $pane;
  $display->panels['mas_informaci__n'][2] = 'new-6abe02da-376b-4659-bb94-88f72c4bd65e';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
