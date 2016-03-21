<?php
function portales7_variable_info($options = array()) {
  $variables['portales7_EL_name'] = array(
    'type' => 'string',
    'title' => t('Name', array(), $options),
    'description' => t('City council official name'),
    'default' => 'UNCONFIGURED',
    'required' => TRUE,
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_EL_INE'] = array(
    'type' => 'string',
    'title' => t('INE', array(), $options),
    'description' => t('INE code'),
    'default_value' => '',
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_EL_address'] = array(
    'type' => 'string',
    'title' => t('Address', array(), $options),
    'default' => '',
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_EL_telephone'] = array(
    'type' => 'string',
    'title' => t('Telephone', array(), $options),
    'default' => '',
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_EL_mail'] = array(
    'type' => 'string',
    'title' => t('Mail address', array(), $options),
    'default' => '',
    'group' => 'portales7',
    'token' => TRUE,
  );
  
  $variables['portales7_EL_city'] = array(
    'type' => 'string',
    'title' => t('City', array(), $options),
    'description' => t('City name'),
    'default' => '',
    'group' => 'portales7',
    'localize' => TRUE,
    'token' => TRUE,
  );
  $variables['portales7_EL_zip'] = array(
    'type' => 'string',
    'title' => t('ZIP', array(), $options),
    'description' => t('ZIP code'),
    'default_value' => '',
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_EL_cif'] = array(
    'type' => 'string',
    'title' => t('CIF', array(), $options),
    'description' => t('City council CIF'),
    'default' => '',
    'group' => 'portales7',
    'token' => TRUE,
  );
  
  $variables['portales7_EL_signature'] = array(
    'type' => 'text_format',
    'title' => t('Signature'),
    'description' => t('The former footer message'),
    'default' => array(
    'value' => '<div class="div-credits">
  <div class="conjunt-logo" valign="middle">
  <div class="logo-peu">[portales7:favicon]</div>
  <div class="credit-ajuntament">
    <p><b>[portales7:EL_name]</b><br>
  [portales7:EL_address] - CP: [portales7:EL_zip]<br>
  Tel: [portales7:EL_telephone]<br>
  email: [portales7:contact_link]</p>
  </div>
  </div>  
  </div>',
    'format' => 'full_html'),
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => FALSE,
  );
  $variables['portales7_legal_advice'] = array(
    'type' => 'number',
    'title' => t('Legal advice'),
    'description' => t('NID of legal advice node'),
    'default' => 1,
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_privacy_policy'] = array(
    'type' => 'number',
    'title' => t('Privacy policy'),
    'description' => t('NID of privacy policy node'),
    'default' => 3,
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => TRUE,
  );
  $variables['portales7_egov_url'] = array(
    'type' => 'string',
    'title' => t('eGoverment url'),
    'description' => t('URL of eGoverment site'),
    'default' =>  'https://sede.dival.es',
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => TRUE,
  );
    $body_backgrounds = array('body-background-white' => t('white'),
      'body-background-blue' => t('blue'),
      'body-background-blue-dark' => t('dark blue'),
      'body-background-brown-light' => t('light brown'),
      'body-background-brown' => t('brown'),
      'body-background-brown-dark' => t('dark brown'),
      'body-background-cream' => t('cream'),
      'body-background-green' => t('green'),
      'body-background-green-dark' => t('dark green'),
      'body-background-lilac' => t('lilac'),
      'body-background-magenta' => t('magenta'),
      'body-background-orange-light' => t('light orange'),
      'body-background-orange' => t('orange'),
      'body-background-orange-dark' => t('dark orange'),
      'body-background-purple-light' => t('light purple'),
      'body-background-purple' => t('purple'),
      'body-background-red' => t('red'),
      'body-background-yellow' => t('yellow'),
  );
  asort($body_backgrounds);
  
  $variables['portales7_body_class'] = array(
    'type' => 'select',
    'title' => t('Class'),
    'description' => t('Class name for the body tag'),
    'default' =>  '',
    'localize' => FALSE,
    'group' => 'portales7',
    //'options' => array_merge(array( 'body-background-none' => t('None')), $body_backgrounds),
    'options' => array( 'body-background-none' => t('None')),
    'token' => TRUE,
  );
  
  $variables['portales7_sponsor'] = array(
    'type' => 'text_format',
    'title' => t('Sponsor'),
    'description' => t('The sponsor of the site'),
    'default' => array(
    'value' => '<div class="grup-sponsor">
<div class="inside">
<<div class="element-sponsor sponsor-client" onclick="window.open(\'http://www.dival.es\',\'_blank\');" style="cursor:pointer;" title="Dival"></div>
<div class="element-sponsor logo-plataforma transparent2" onclick="window.open(\'http://comunidad.portalesmunicipales.es\',\'_blank\');" style="cursor:pointer;" title="Portales Municipales"></div>
</div></div>',
    'format' => 'php_code'),
    'localize' => TRUE,
    'group' => 'portales7',
    'token' => FALSE,
  );
  /*$variables['portales7_EL_site_logo'] = array(
    'type' => 'file',
    'title' => t('Site logo'),
    'description' => t('The site logo'),
    'default' => '',
    'group' => 'portales7',
  );*/
  
  
  
  return $variables;
}

function portales7_variable_type_info() {
  $types = array();
  $types['file'] = array(
    'element' => array('#type' => 'managed_file'),
  );
  return $types;
}

function portales7_variables($form, &$form_state) {
  global $language;
  module_load_include('form.inc', 'variable');
  $key = !empty($_GET['variable_realm_key_language']) ? $_GET['variable_realm_key_language'] : $language->language;
  $realm = variable_realm('language', $key);
  $options = array('realm' => $realm);
  $variables = portales7_variable_info($options);
  $form = array();
  foreach ($variables as $k => $v) {
    $value = variable_get_value($k, !empty($v['localize']) ? $options : array());
    $form[$k] = array(
      '#title' => $v['title'],
      '#description' => !empty($v['description']) ? $v['description'] : '',
      '#default_value' => $value,
    );
    if (!empty($v['element callback'])) {
      $form[$k] = $v['element callback']($v);
    }
    else {
      switch ($v['type']) {
        case 'number':
        case 'string': $form[$k]['#type'] = 'textfield'; break;
        case 'text_format':
          $form[$k]['#type'] = 'text_format'; 
          $form[$k]['#default_value'] = $value['value'];
          $form[$k]['#format'] = $value['format'];
          break;
        case 'textarea': $form[$k]['#type'] = 'textarea'; break;
        case 'select': $form[$k]['#type'] = 'select';
          $form[$k]['#options'] = $v['options'];
          break;
        default:
            $form[$k]['#type'] = $v['type'];
      }
      if (isset($v['element']) && is_array($v['element'])) $form[$k] += $v['element'];
    }
  }
  $form['replacement_tokens'] = array(
    '#type' => 'fieldset',
    '#title' => t('Replacement tokens'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['replacement_tokens']['tokens'] = array(
    '#type' => 'markup',
    '#markup' => theme('token_tree', array('token_types' => array('portales7'), 'global_types' => FALSE)),
  );
  return system_settings_form($form);
}

function portales7_variable_group_info() {
  $groups = array();
  $groups['portales7'] = array(
    'title' => 'Portales 7',
    'description' => t('Portales 7 site settings'),
    'access' => 'administer portales7',
    'path' => array('admin/portales7'),
  );
  return $groups;
}

