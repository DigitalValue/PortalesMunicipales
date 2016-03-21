<?php
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'site_template_onlycontent';
$handler->task = 'site_template';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = -99;
$handler->conf = array(
  'title' => 'Solo contenido',
  'no_blocks' => 1,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => 'onlycontent',
  'css_id' => 'onlycontent',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'parametro',
          'php' => 'return !empty($_GET[\'onlycontent\']);',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  ),
);
$display = new panels_display();
$display->layout = 'flexible';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
    'center' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '11e4e812-a7fb-46b0-8f04-6e2e89cb401e';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0e3e947b-c10e-49f4-946c-a069bf3829f5';
  $pane->panel = 'center';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
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
  $pane->uuid = '0e3e947b-c10e-49f4-946c-a069bf3829f5';
  $display->content['new-0e3e947b-c10e-49f4-946c-a069bf3829f5'] = $pane;
  $display->panels['center'][0] = 'new-0e3e947b-c10e-49f4-946c-a069bf3829f5';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = 'new-0e3e947b-c10e-49f4-946c-a069bf3829f5';
$handler->conf['display'] = $display;
