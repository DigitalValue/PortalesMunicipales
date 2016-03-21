<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -19;
$handler->conf = array(
  'title' => 'Webform',
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
            'webform' => 'webform',
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
$display->uuid = '4f706087-7bb9-43fd-a723-105fc2405b84';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d9bb339b-b570-45c5-aa4b-3eb6d8b320ae';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
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
  $pane->uuid = 'd9bb339b-b570-45c5-aa4b-3eb6d8b320ae';
  $display->content['new-d9bb339b-b570-45c5-aa4b-3eb6d8b320ae'] = $pane;
  $display->panels['middle'][0] = 'new-d9bb339b-b570-45c5-aa4b-3eb6d8b320ae';
  $pane = new stdClass();
  $pane->pid = 'new-546dcb63-985b-4011-8423-3e69c8305576';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'submenutree-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '546dcb63-985b-4011-8423-3e69c8305576';
  $display->content['new-546dcb63-985b-4011-8423-3e69c8305576'] = $pane;
  $display->panels['middle'][1] = 'new-546dcb63-985b-4011-8423-3e69c8305576';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = 'new-d9bb339b-b570-45c5-aa4b-3eb6d8b320ae';
$handler->conf['display'] = $display;
