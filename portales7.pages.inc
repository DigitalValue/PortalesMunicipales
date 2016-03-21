<?php
function portales7_cookie_disclaimer() {
  global $language;
  $languages = language_list();
  $languages =  array_merge(array($language->language => $language) ,$languages);
  foreach ($languages as $langcode => $lang) {
    $path = 'sites/all/cookie-info/' . $langcode . '.html';
    if (file_exists($path)) {
      return file_get_contents($path);
    }
  }
  drupal_not_found();
}
