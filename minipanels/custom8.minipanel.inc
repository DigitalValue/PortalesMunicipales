<?php
$mini = new stdClass();
$mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
$mini->api_version = 1;
$mini->name = 'panel_personalizable_8';
$mini->category = 'Portales 7';
$mini->admin_title = 'Panel personalizable 8';
$mini->admin_description = '';
$mini->requiredcontexts = array();
$mini->contexts = array();
$mini->relationships = array();
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
$display->uuid = 'd6f04b70-ea6f-49f8-8b6f-b9e553a7095b';
$display->content = array();
$display->panels = array();
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$mini->display = $display;
