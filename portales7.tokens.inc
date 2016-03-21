<?php
function portales7_token_info() {
  $types['portales7'] = array(
    'name' => t("Portales 7"),
    'description' => t("Tokens for Portales 7 values."),
  );
  module_load_include('variable.inc', 'portales7');
  $tokens = array();
  foreach (variable_get_info() as $name => $info) {
    if (preg_match('/^portales7/', $name) && !empty($info['token'])) {
      $name = substr($name,10);
      $tokens[$name] = array(
        'name' => $info['title'],
        'description' => !empty($info['description']) ? $info['description'] : t('Value of variable !name', array('!name' => $info['title'])),
      );
    }
  }
  $tokens['favicon'] = array(
    'name' => t('Favicon image'),
    'description' => t('Image tag for favicon image'),
  );
  $tokens['contact_link'] = array(
    'name' => t('Contact link'),
    'description' => t('Link to contact page using mail address as link text'),
  );
  return array(
    'types' => $types,
    'tokens' => array(
      'portales7' => $tokens,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function portales7_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'portales7') {
    foreach ($tokens as $name => $original) {
      switch($name) {
        case 'favicon':
          $replacements[$original] = '<img src="' . file_create_url(theme_get_setting('favicon_path')) . '" alt="image" />';
          break;
        case 'contact_link':
          $replacements[$original] = l(variable_get_value("portales7_EL_mail"), "contact");
          break;
        default:
          $name = 'portales7_' . $name;
          $variable = variable_get_info($name, $options);
          if ($variable && !empty($variable['token'])) {
            $replacements[$original] = variable_format_value($variable, $options); 
          }
      }
      
    }
  }

  return $replacements;
}