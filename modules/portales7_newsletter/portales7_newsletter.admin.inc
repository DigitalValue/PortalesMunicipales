<?php
function portales7_newsletter_list() {
  $res = db_select('portales7_newsletters', 'n')->fields('n', array('id','uid','status','timestamp','subject','recipients'))->execute()->fetchAllAssoc('id');
  $table = array(
    'rows' => array(),
    'header' => array(
      array('data' => t('Title')),
      array('data' => t('Send date'), 'style' => "width: 150px"),
      array('data' => t('Recipients'), 'style' => "width: 250px"),
      array('data' => t('Status'), 'style' => "width: 40px"),
      array('data' => t('Actions'), 'style' => "width: 67px"),
     ),
    'attributes' => array('width' => '100%'),
    );
    $images = array(
    'view' => theme('image', array('path' => drupal_get_path('module', 'portales7_newsletter') .'/images/ic-preview.png')),
    'forward' => theme('image', array('path' => drupal_get_path('module', 'portales7_newsletter') .'/images/ic-forward.png')),
    'lock' => theme('image', array('path' => drupal_get_path('module', 'portales7_newsletter') .'/images/ic-lock.png')),
    'unlock' => theme('image', array('path' => drupal_get_path('module', 'portales7_newsletter') .'/images/ic-unlock.png')),
    'delete' => theme('image', array('path' => drupal_get_path('module', 'portales7_newsletter') .'/images/ic-delete.png')),
    'deleteno' => theme('image', array('path' => drupal_get_path('module', 'portales7_newsletter') .'/images/ic-delete-no.png')),
    );
  foreach($res as $row) {
    $actions = array();
    $actions[] = l($images['view'],'portales7/newsletter/' . $row->id, array('attributes' => array('target' => '_blank', 'title' => t('View')), 'html' => TRUE));
    $actions[] = l($images['forward'], 'portales7/newsletter/' . $row->id . '/clone', array('attributes' => array('target' => '_blank', 'title' => t('Forward')), 'html' => TRUE));
    $actions[] = l($images['lock'], 'portales7/newsletter/' . $row->id . '/block', array('attributes' => array('target' => '_blank', 'title' => t('Lock')), 'html' => TRUE));
    if($row->status == 0)
    {	
    	$actions[] = l($images['delete'], 'portales7/newsletter/delete/' . $row->id , array('query' => array('destination' => 'admin/portales7/newsletter'), 'attributes' => array( 'title' => t('Delete')), 'html' => TRUE));
    }
    else{
    	$actions[] = l($images['deleteno'], 'portales7/newsletter/delete/' . $row->id , array('query' => array('destination' => 'admin/portales7/newsletter'), 'attributes' => array( 'title' => t('Delete')), 'html' => TRUE));
    }
    $table['rows'][] = array($row->subject, format_date($row->timestamp, 'short'), $row->recipients, $row->status ? t('Sent'):t('Not sent'), join(' ', $actions));
  }
  $output = theme('table',$table);
  $output .= theme('table', array(
    'header' => array( array('data' => t('Leyenda'), 'colspan' => 5)),
    'attributes' => array('style' => 'width: 300px; float: right;'),
    'rows' => array( array(
      $images['view'] . '&nbsp;' . t('View'),
      $images['forward']. '&nbsp;' . t('Forward') ,
      $images['lock'] . '&nbsp;' . t('Lock'),
      $images['unlock'] . '&nbsp;' . t('Unlock'),
      $images['delete'] . '&nbsp;' . t('Delete'),
    ))
  ));
  $output .= '<button onclick="window.open(\'/admin/portales7/newsletter/add\')" style="margin-top: 25px;">Nuevo boletín</button>';
  //dsm($table, __FUNCTION__);
  drupal_set_title(t('Newsletters list'));
  return $output;
}

function portales7_newsletter_custom_get() {
	$res = db_select('portales7_newsletter_custom','c')->fields('c', array('id', 'content'))->condition('status', 1)->execute()->fetchAllAssoc('id');
	drupal_add_http_header('Content-type', 'application/json');
	print json_encode($res);
}

function portales7_newsletter_save($sent) {
  global $user;
  $newsletter = new stdClass();
  $newsletter->id = $_REQUEST['id'];
  $newsletter->uid = $user->uid;
  if($sent){
  $newsletter->status = 1;//enviado
  }
  else{
  $newsletter->status = 0;//no enviado
  }
  $newsletter->content = $_REQUEST['content'];
  $newsletter->timestamp = $_SERVER['REQUEST_TIME'];
  $newsletter->subject = $_REQUEST['subject'];
  $newsletter->recipients = $_REQUEST['recipients'];
  drupal_add_http_header('Content-type', 'application/json');
  if ($newsletter->id != 0) {
    $res = drupal_write_record('portales7_newsletters', $newsletter, array('id'));
  }
  else {
    $res = drupal_write_record('portales7_newsletters', $newsletter);
  }
  switch ($res) {
    case 1: watchdog('newsletter', t('The newsletter @title has been created with id @id'), array('@title' => $newsletter->subject, '@id' => $newsletter->id), WATCHDOG_INFO);
    case 2: watchdog('newsletter', t('The newsletter @title with id @id has been updated'), array('@title' => $newsletter->subject, '@id' => $newsletter->id), WATCHDOG_INFO);
    default: watchdog('newsletter', t('Unable to save newsletter @title'), array('@title' => $newsletter->subject), WATCHDOG_ERROR);
  }
  print json_encode(array('status' => $res, 'id' => $newsletter->id));
}

function portales7_newsletter_custom_save(){
  global $user;
  $custom = new stdClass();
  $custom->id = 0;
  $custom->uid = $user->uid;
  $custom->content = $_REQUEST['custom'];
  $custom->status = 1;
  $custom->timestamp = $_SERVER['REQUEST_TIME'];
  drupal_add_http_header('Content-type', 'application/json');
  $res = drupal_write_record('portales7_newsletter_custom', $custom);
  print json_encode(array('status' => $res));
}

function portales7_newsletter_custom_delete($id){
	drupal_add_http_header('Content-type', 'application/json');
	if (db_update('portales7_newsletter_custom')->fields(array('status' => 0))->condition('id', $id)->execute()) {
		print json_encode(array('status' => 1));
	}
	else {
		print json_encode(array('status' => 0));
	}
}

function portales7_newsletter_delete($id){
	if(db_delete('portales7_newsletters')->condition('id', $id)->condition('status',0)->execute()){ //añadir ->condition('status',0) para prohibir borrado de enviados
		drupal_set_message(t('The newsletter has been deleted'),'status');
	}
	else{
		drupal_set_message(t('Can\'t delete already sent newsletters'), 'error');
	}
	drupal_goto($_REQUESTS['destination']);
}
