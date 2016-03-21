<?php
if (!$term = dvtoolbox_get_taxonomy_term_by_name('link', 'type')) {
  $term = (object) array('tid' => 11);
}
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_link';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -28;
$handler->conf = array(
  'title' => 'Enlace',
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
        'name' => 'entity_field_value:node:portales7_node:portales7_type',
        'settings' => array(
          'portales7_type' => array(
            'und' => array(
              0 => array(
                'tid' => $term->tid,
              ),
            ),
          ),
          'portales7_type_tid' => array(
            0 => $term->tid,
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  ),
);
$display = new panels_display();
$display->layout = 'onecol';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '37e21f94-7b54-4725-bf36-13e222766d3b';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c24efed2-9099-44dc-a97a-e0fa9aeb8d01';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 1,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c24efed2-9099-44dc-a97a-e0fa9aeb8d01';
  $display->content['new-c24efed2-9099-44dc-a97a-e0fa9aeb8d01'] = $pane;
  $display->panels['middle'][0] = 'new-c24efed2-9099-44dc-a97a-e0fa9aeb8d01';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-c24efed2-9099-44dc-a97a-e0fa9aeb8d01';
$handler->conf['display'] = $display;
