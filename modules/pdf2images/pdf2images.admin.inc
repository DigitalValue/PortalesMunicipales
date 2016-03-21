<?php
function pdf2images_admin($form, $form_state) {
  $form['pdfs'] = array(
    '#type' => 'markup',
    '#markup' => _pdf2images_get_pdfs(),
  );
  return $form;
}

function _pdf2images_get_pdfs() {
  $headers = array(
    array('data' => t('FID'), 'field' => 'fid'),
    array('data' => t('URI'), 'field' => 'uri', 'sort' => 'asc'),
    array('data' => t('Filename'), 'field' => 'filesize'),
    array('data' => t('Size'), 'field' => 'filesize'),
    array('data' => t('Link'))
  );
  $query = db_select('file_managed', 'fm')
    ->fields('fm', array())
    ->extend('TableSort')
    ->extend('PagerDefault')
    ->orderByHeader($headers)
    ->condition('filemime', 'application/pdf')
    ->limit(25);
  $res = $query->execute();
  $rows = array();
  $path = 'pdf2images/' . variable_get('file_public_path', conf_path() . '/files');
  while ($file = $res->fetch()) {
    $rows[] = array(
      $file->fid,
      $file->uri,
      $file->filename,
      format_size($file->filesize),
      file_create_url($path . '/' . file_uri_target($file->uri))
    );
  }
  
  return theme('table', array('header' => $headers, 'rows' => $rows, 'attributes' => array('id' => 'sort-table'))) . theme('pager');
}
