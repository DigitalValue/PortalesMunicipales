<?php
/**
 * Implements hook_default_panels_mini
 */
function portales7_default_panels_mini() {
  $minis = array();
  $files = glob(dirname(__FILE__) . '/minipanels/*.minipanel.inc');
  foreach($files as $file) {
    $mini = NULL;
    include($file);
    $minis[$mini->name] = $mini;
  }
  return $minis;
}
