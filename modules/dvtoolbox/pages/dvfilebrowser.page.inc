<?php
$page = new stdClass();
$page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'dvfilebrowser';
$page->task = 'page';
$page->admin_title = 'dvfilebrowser';
$page->admin_description = '';
$page->path = 'dvfilebrowser';
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
$handler->name = 'page_dvfilebrowser__panel_context_4c92ee9e-46f4-410c-ba6f-3542871efc13';
$handler->task = 'page';
$handler->subtask = 'dvfilebrowser';
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
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'center' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = 'b5215d8b-5361-452e-9707-5e2bf23ae998';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cb17ca77-eedb-4aff-9934-5fee4cc0159d';
  $pane->panel = 'center';
  $pane->type = 'dvfilebrowser';
  $pane->subtype = 'dvfilebrowser';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'path' => 'public://',
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
  $pane->uuid = 'cb17ca77-eedb-4aff-9934-5fee4cc0159d';
  $display->content['new-cb17ca77-eedb-4aff-9934-5fee4cc0159d'] = $pane;
  $display->panels['center'][0] = 'new-cb17ca77-eedb-4aff-9934-5fee4cc0159d';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
