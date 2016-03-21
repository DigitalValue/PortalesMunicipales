<?php
/**
 * Implements hook_views_default_views().
 */
function portales7_views_default_views() {
  $views = array();
  $files = glob(dirname(__FILE__) . '/views/*.inc');
  foreach($files as $file) {
    $view = NULL;
    include($file);
    $views[$view->name] = $view;
  }
  return $views;
}
