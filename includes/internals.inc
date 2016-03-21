<?php
function portales7_internals_page($form_state) {
  if (!empty($_REQUEST['set_allowed_protocols'])) variable_set('filter_allowed_protocols', array('ftp', 'http', 'https', 'irc', 'mailto', 'news', 'nntp', 'rtsp', 'sftp', 'ssh', 'tel', 'telnet', 'webcal'));
  $form = array();
  $form['portales7_frontpage_images'] = array(
    '#type' => 'textfield',
    '#title' => 'Frontpage display',
    '#description' => t('Folder inside public files to store custom frontpage display images'),
    '#default_value' => variable_get('portales7_frontpage_images', 'portadas'),
    '#field_prefix' => 'public://',
  );
  
  $form['portales7_demo_max_snapshots'] = array(
    '#type' => 'select',
    '#title' => 'Number of snapshots',
    '#description' => t('The maximum number of snapshots allowed on this site'),
    '#default_value' => variable_get('portales7_demo_max_snapshots', 2),
    '#options' => drupal_map_assoc(range(1,5,1)),
  );
  
  $form['filter_allowed_protocols'] = array(
    '#type' => 'textfield',
    '#title' => 'Allowed protocols',
    '#description' => t('Allowed protocols on urls. You can force rebuild of <em>filter_allowed_protocols</em> variable calling this page with <em>set_allowed_protocols=1</em> parameter.'),
    '#default_value' => join(' ', variable_get('filter_allowed_protocols', array('ftp', 'http', 'https', 'irc', 'mailto', 'news', 'nntp', 'rtsp', 'sftp', 'ssh', 'tel', 'telnet', 'webcal'))),
  );
  
  $form['portales7_searchable_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Searchable content types'),
    '#default_value' => array_keys(variable_get('portales7_searchable_types', array('portales7_node' => 'portales7_node'))),
    '#options' => node_type_get_names(),
    '#multiple' => TRUE,
  );  
  
  $form['clear_login_attempts'] = array(
    '#type' => 'submit',
    '#value' => t('Clear login attempts'),
  );
  
  $form['#validate'][] = 'portales7_admin_page_validate';
  
  $form['scan_for_files'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scan for files'),
    '#description' => t('Scan for files not added to the database in selected folders recursively, and files in public root not recursively.'),
    '#tree' => FALSE, 
  );
  
  $dirs = drupal_map_assoc(array_map('basename', glob(drupal_realpath('public://').'/*', GLOB_ONLYDIR)));
  foreach(array('color', 'css', 'css_injector', 'ctools', 'dvexport', 'file_attach', 'imagefield_thumbs', 'js', 'languages', 'pdfpreview', 'styles') as $key) {
    if (isset($dirs[$key])) unset($dirs[$key]);
  }
  $form['scan_for_files']['dirs'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Folders to scan'),
    '#options' => $dirs,
    '#default_value' => array('images', 'documents', 'videos', 'entidades', 'misdocumentos', 'users', 'documentos', 'imagenes', 'portales7-recursos', 'archivos'),
  );
  
  $form['scan_for_files']['scan'] = array(
    '#type' => 'submit',
    '#value' => t('Scan'),
    '#options' => $dirs,
  );
  if (preg_match('@(cheste|chiva|leliana).p7.portalesmunicipales.es@', $_SERVER['HTTP_HOST'])) {
    $form['update03'] = array(
      '#type' => 'submit',
      '#value' => t('Update nodes'),
      '#description' => t('Update nodes from 7.5.0 to 7.5.2+'),
    );
  }
  $form['#submit'][] = 'portales7_internals_scan_submit';
  return system_settings_form($form);
}

/**
 * Form validation handler for demo_admin_settings().
 */
function portales7_admin_page_validate($form, &$form_state) {
  $path = $form['portales7_frontpage_images']['#field_prefix'] . $form_state['values']['portales7_frontpage_images'];
  if (!file_prepare_directory($path, FILE_CREATE_DIRECTORY)) {
    form_set_error('portales7_frontpage_images', t('The snapshot directory %directory could not be created.', array('%directory' => $path)));
  }
  $form_state['values']['filter_allowed_protocols'] = preg_split('/(,|\ )+/', $form_state['values']['filter_allowed_protocols']);
}

function portales7_internals_scan_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#parents'][0] == 'clear_login_attempts') {
    db_query('truncate table {flood}');
    drupal_set_message(t('Login attempts were cleaned'), 'status');
    return FALSE;
  }
  elseif ($form_state['triggering_element']['#parents'][0] == 'update03') {
    if (!empty($_SESSION['DEBUG'])) dpm($form_state, __FUNCTION__ . ' form_state');
    if (!empty($_SESSION['DEBUG'])) dpm($form, __FUNCTION__ . ' form');
    module_load_include('inc', 'portales7', 'includes/update03');
    if ($batch = portales7_update03_batch_prepare()) {
      batch_set($batch);
      batch_process('admin/dashboard/portales7/internals');  
    }
    else {
      drupal_set_message(t('No batch'), 'error');
    }
    
    return FALSE;
  }
  elseif ($form_state['triggering_element']['#parents'][0] == 'scan') {
    $dirs = array_filter($form_state['values']['dirs']);
    module_load_include('inc', 'portales7', 'includes/scan_files');
    $batch = portales7_internals_files_add_batch_prepare($dirs);
    batch_set($batch);
    batch_process('admin/dashboard/portales7/internals');
  }
}
