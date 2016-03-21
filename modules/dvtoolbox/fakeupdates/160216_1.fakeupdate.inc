<?php
/**
 * Actualización de los campos newsdate y eventdate
 */
function _dvtoolbox_fakeupdate_160216_1() {
  $code = substr(__FUNCTION__, 22);
  if (!variable_get('fakeupdate-' . $code, FALSE)) {
    module_load_include('node.inc', 'portales7_node');
    module_load_include('field.inc', 'dvtoolbox');
    $fields = _portales7_node_installed_fields();
    $update = array('portales7_eventdate' => $fields['portales7_eventdate'], 'portales7_noticedate' => $fields['portales7_noticedate']);
    foreach (dvtoolbox_field_create_fields($update) as $message) {
      drupal_set_message($message, 'status');
    }
    variable_set('fakeupdate-' . $code, TRUE);
    return "fakeupdate-" . $code;
  }
  else {
    drupal_set_message(t('Code @code already executed', array('@code' => __FUNCTION__)), 'status');
  }
}
