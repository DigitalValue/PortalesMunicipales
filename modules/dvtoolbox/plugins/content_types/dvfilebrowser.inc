<?php
/**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Filebrowser'),
  'description' => t('Shows a file browser.'),
  
// 'single' => TRUE means has no subtypes.
  'single' => TRUE,
// Constructor.
  'content_types' => array('dvtoolbox_filebrowser_content_type'),
// Name of a function which will render the block.
  'render callback' => 'dvtoolbox_filebrowser_content_type_render',
// The default context.
  'defaults' =>array('path' => 'public://'),

// This explicitly declares the config form. Without this line, the func would be
// ctools_plugin_example_no_context_content_type_edit_form.
  'edit form' => 'dvtoolbox_filebrowser_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_dvtoolbox.png',
  'category' => t('DV toolbox'),
  
  'admin title' => 'dvtoolbox_filebrowser_content_type_admin_title',

);

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvtoolbox_filebrowser_content_type_render($subtype, $conf, $panel_args, $context) {
  //return _dvtoolbox_filebrowser_by_fs($subtype, $conf, $panel_args, $context);
  $path = $conf['path'] . (empty($panel_args) ? '' : join('/', $panel_args) . '/');
  $cid = dvtoolbox_cid_generate(array('dvfilebrowser', $path));
  if (($cached = cache_get($cid)) && empty($_GET['reset'])) {return $cached->data;}
  $lp = strlen($path);
  if (!preg_match('@/$@', $path)) $path .= '/';
  $query = db_select('file_managed', 'f')->fields('f', array())->condition('uri', $path . '%', 'LIKE')->orderBy('uri')->execute();
  $dirs = array();
  if (!empty($panel_args)) {
    $dirs['..'] = array('<img class="file-icon" src="' .base_path() . drupal_get_path('module', 'dvtoolbox') . '/images/folder.png' . '">',
    l('..', join('/', array_slice(split('/', $_GET['q']), 0, -1)), array('attributes' => array('class' => array('folder')))),
    '&nbsp');
  }
  $files = array();
  foreach($query->fetchAll() as $file) {
    $np = substr($file->uri, $lp);
    if ((basename($file->uri) == $np) && is_file($file->uri)) {
      $files[$file->filename] = array(
        theme('file_icon', array('file' => file_load($file->fid))),
        l($file->filename, file_create_url($file->uri), array('attributes' => array('target' => '_blank', 'class' => array('file')))),
        format_size(filesize($file->uri)));
    }
    else {
      list($dirname, $rest) = split('/', $np, 2);
      if (isset($dirs[$dirname])) {
        $dirs[$dirname][2]++;
      }
      else {
        $dirs[$dirname] = array('<img class="file-icon" src="' .base_path() . drupal_get_path('module', 'dvtoolbox') . '/images/folder.png' . '">', 
          l($dirname, $_GET['q'] . '/' . $dirname, array('attributes' => array('class' => array('folder')))),
          1,
        );
      }
      
    }
  }
  $pane = new stdClass();
  $pane->title = $path;
  ksort($dirs);
  ksort($files);
  $all = array_merge($dirs, $files);
  $headers = array('&nbsp;', t('Name'), t('Size') . '/' . t('Elements'));
  $pane->content = theme('table', array('header' => $headers, 'rows' =>$all));
  cache_set($cid, $pane, 'cache', $_SERVER['REQUEST_TIME'] + 1200);
  return $pane;
}

function _dvtoolbox_filebrowser_by_fs($subtype, $conf, $panel_args, $context) {
  $path = $conf['path'] . join('/', $panel_args) . '/';
  $pane = new stdClass();
  $pane->title = '';
  $pane->content = '';
  $dirs = array();
  if (!empty($panel_args)) {
    $dirs['..'] = l('..', join('/', array_slice(split('/', $_GET['q']), 0, -1)), array('attributes' => array('class' => array('folder'))));
  }
  $files = array();
  foreach (scandir($path) as $filename) {
    if (preg_match('/^\./', $filename)) continue;
    if (is_dir($path . $filename)) $dirs[$filename] = l($filename, $_GET['q'] . '/' . $filename, array('attributes' => array('class' => array('folder'))));
    elseif (is_file($path . $filename)) $files[$filename] = l($filename, file_create_url($path .  '/' .$filename, array('attributes' => array('class' => array('file')))));
    elseif (is_link($path . $filename)) $links[$filename] = l($filename, file_create_url($path .  '/' .$filename, array('attributes' => array('class' => array('link')))));
  }
  ksort($dirs);
  ksort($files);
  ksort($links);
  $all = array_merge($dirs, $files);
  $pane->content = theme('item_list', array('items' => $all));
  return $pane;
}

/**
* Returns an edit form for the custom type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function dvtoolbox_filebrowser_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#description' => t('Top level path (with schema)'),
    '#default_value' => $conf['path'],
  );
  return $form;
}

function dvtoolbox_filebrowser_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = array();
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key]))
      $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function dvtoolbox_filebrowser_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('Filebrowser');
}

function dvtoolbox_filebrowser_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = dvtoolbox_filebrowser_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}
