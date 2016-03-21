<?php
/**
 * Implements hook_default_page_manager_pages().
 */
function dvtoolbox_default_page_manager_pages(){
  $pages = array();
  $files = glob(dirname(__FILE__) . '/pages/*.page.inc');
  foreach($files as $file) {
    $page = NULL;
    include($file);
    $pages[$page->name] = $page;
  }
  return $pages;
}

/**
 * Implements hook_default_page_manager_handlers().
 */
function dvtoolbox_default_page_manager_handlers() {
  $handlers = array();
  $files = glob(dirname(__FILE__) . '/pages/*.handler.inc');
  foreach($files as $file) {
    $handler = NULL;
    include($file);
    if (!empty($handler))
      $handlers[$handler->name] = $handler;
  }
  return $handlers;
}

  