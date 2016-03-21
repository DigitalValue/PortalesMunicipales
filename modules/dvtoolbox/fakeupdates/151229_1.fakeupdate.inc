<?php
function _dvtoolbox_fakeupdate_151229_1() {
  $code = substr(__FUNCTION__, 22);
  if (variable_get('portales7_node_field_update_needed', FALSE)) {
    if (!variable_get('fakeupdate-' . $code, FALSE)) {
      module_load_include('update7520.inc', 'portales7_node');
      _portales7_node_field_update_needed();
      drupal_set_message(t('Code @code executed', array('@code' => __FUNCTION__)), 'status');
      variable_del('portales7_node_field_update_needed');
      variable_set('fakeupdate-' . $code, TRUE);
      return "fakeupdate-" . $code;
    }
    else {
      drupal_set_message(t('Code @code already executed', array('@code' => __FUNCTION__)), 'status');
    }
  }
}
