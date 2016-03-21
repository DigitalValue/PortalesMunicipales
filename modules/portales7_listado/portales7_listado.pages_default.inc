<?php
function portales7_listado_default_page_manager_pages() {
  $pages = array();
  $files = glob(dirname(__FILE__) . '/pages/*.page.inc');
  foreach($files as $file) {
    $page = NULL;
    include($file);
    $pages[$page->name] = $page;
  }
  return $pages;
}
