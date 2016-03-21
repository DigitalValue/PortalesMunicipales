<?php
$mini = new stdClass();
$mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
$mini->api_version = 1;
$mini->name = 'panel_personalizable_6';
$mini->category = 'Portales 7';
$mini->admin_title = 'Panel personalizable 6';
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
$display->uuid = '4b469a21-fce5-4a45-915e-0b881ea050f7';
$display->content = array();
$display->panels = array();
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = '0';
$mini->display = $display;
