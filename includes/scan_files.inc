<?php
function portales7_internals_files_add_batch_prepare($dirs = array('images', 'documents', 'videos', 'entidades', 'misdocumentos', 'users', 'documentos', 'imagenes')) {
  $operations = array();
  $files = array();
  foreach ($dirs as $path) {
    $files += file_scan_directory('public://' . $path, '/.*/');
  }
  $files += file_scan_directory('public://', '/.*/', array('recurse' => FALSE));
 
  foreach (array_chunk($files, 5, TRUE) as $part) {
    $operations[] = array('portales7_internals_files_add_batch_do', array($part, count($files)));
  }
  $batch = array(
    'title' => $output,
    'operations' => $operations,
    'finished' => 'portales7_internals_files_add_batch_finished',
    'file' => drupal_get_path('module', 'portales7') . '/includes/scan_files.inc',
  );
  return $batch;
}

function portales7_internals_files_add_batch_do($files, $total, &$context) {
  if (empty($context['results']['added'])) $context['results']['added'] = 0;
  $added = 0;
  $errors = 0;
  foreach($files as $uri => $file) {
    try {
      if (!db_select('file_managed', 'f')->fields('f', array('fid'))->condition('uri', $uri)->execute()->fetch()) {
        $file->filename = utf8_encode($file->filename);
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        file_usage_add($file, 'imce', 'file', $file->fid);
        $added++;
      }
    }
    catch (Exception $e){
      $errors++;
      $uri = utf8_encode($uri);
      drupal_set_message("error on $uri => " . $e->getMessage(), 'error');
      $context['results']['errors'][] = $uri . ' => ' . $e->getMessage();
    }
  }
  $context['results']['added'] += $added; 
  $context['message'] = format_plural($added, 'Added one file', 'Added @num files', array('@num' => $added)) . ' ' . format_plural(count($errors, 'One error found', '@count errors found'));
  $context['finished'] = 1;
}


function portales7_internals_files_add_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(format_plural($results['added'], 'Added one file', 'Added @num files', array('@num' => $results['added'])), 'status');
  }
  else {
    drupal_set_message(t('There was a problem adding files, please, try again'), 'error');
  }
  if (!empty($results['errors'])) {
    foreach($results['errors'] as $uri) {
      drupal_set_message(t("Can't import file @uri", array('@uri' => htmlentities($uri))), 'error');
    }
  }
}

