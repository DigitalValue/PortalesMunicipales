<?php
$plugin = array(
  'title' => t('DV Taxonomy'),
  'defaults' => array('parent' => 0, 'vocabulary'=>0, 'include_vocabulary' => 1, 'include_hierarchy' => 1, 'depth' => 1, 'base_url' => 'dvtaxonomy', 'accordion' => 1),
  'category' => t('DV toolbox'),
  'single' => TRUE,
  'disabled' => TRUE,
);

function dvtoolbox_dvtaxonomy_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf'] = array();
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key]))
      $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvtoolbox_dvtaxonomy_content_type_render($subtype, $conf, $panel_args, $context) {
  $cid = dvtoolbox_cid_generate(array_merge(array('dvtaxonomy', $parent, $vocabulary, $conf['accordion'], $conf['depth'], $conf['include_vocabulary'], $conf['include_path']), $panel_args));
  if ($conf['accordion']) {
    drupal_add_library('system', 'ui.accordion');
    drupal_add_js(drupal_get_path('module', 'dvtoolbox') . '/js/dvtaxonomy-accordion.js', 'file');
  }
  drupal_add_css(drupal_get_path('module', 'dvtoolbox') . '/css/dvtaxonomy.css');
  if (TRUE || !empty($_SESSION['DEBUG']) || !empty($_GET['reset']) || !$cached = cache_get($cid)) {
    $pane = new stdClass();
    $pane->content = '';
    
    $parent = 0;
    $output = '';
    $vocabulary = NULL;
    if ($conf['vocabulary'] == 'from-panel-arguments') {
      if (empty($panel_args)) return;
      $voc_name = array_shift($panel_args);
    }
    else {
     $voc_name = $conf['vocabulary']; 
    }
    if (!$vocabulary = taxonomy_vocabulary_machine_name_load($voc_name)) {
      drupal_set_message(t('Unknown vocabulary @voc_name', array('@voc_name' => $voc_name)), 'error');
      return;
    }
    $pane->title = $vocabulary->name;
    if ($conf['parent'] == 'from-panel-arguments') {
      $parent_name = array_pop($panel_args);
      if (!empty($parent_name)) {
        if ($t = dvtoolbox_get_taxonomy_term_by_name($parent_name, $voc_name, 0, FALSE)) {
          $parent = $t->tid;
          $pane->title = $parent_name;
        }
        else {
          drupal_set_message(t('Parent term @term not found', array('@term' => $parent_name)), 'error');
        }
      }
    }
    elseif ($conf['parent'] != 'any') {
      $parent = $conf['parent'];
    }
    
    $trail = array();
    if (($parent_name = end($panel_args)) && is_string($parent_name) 
        && ($t = dvtoolbox_get_taxonomy_term_by_name($parent_name, $voc_name, 0, FALSE))) {
      foreach(taxonomy_get_parents_all($t->tid) as $p) $trail[] = $p->tid;
    }
    //$items = i18n_taxonomy_localize_terms(taxonomy_get_tree($vocabulary->vid, $parent, $conf['depth'] ? $conf['depth'] : NULL));
    $items = taxonomy_get_tree($vocabulary->vid, $parent, $conf['depth'] ? $conf['depth'] : NULL);
    $base = $conf['base_url'];
    if (!empty($conf['include_vocabulary'])) $base .= '/' . $voc_name;
    $output = '';
    if (!empty($conf['accordion'])) {
      $items2 = $items;
      $index = 0;
      $output = _dvtoolbox_print_tree($items2, $base, $index);
      $pane->content .= '<div class="dvtaxonomy dvtaxonomy-accordion" id="dvtaxonomy-' . join('-', array($voc_name, $parent)) . '">' . $output . '</div>';
    }
    else {
      $tree = dvtoolbox_taxonomy_tree_data($items, $trail, 0, $base, $conf['include_hierarchy']);
      $output .= drupal_render(menu_tree_output($tree));
      $pane->content .= '<div class="dvtaxonomy" id="dvtaxonomy-' . join('-', array($voc_name, $parent)) . '">' . $output . '</div>';
    }
    //
    
    cache_set($cid, $pane, 'cache', CACHE_TEMPORARY);
    return $pane;
  }
  return $cached->data;
}

function _dvtoolbox_print_tree(&$tree, $base = 'taxonomy/term', &$index = 0){
  $output = '';
  static $printed = FALSE;
  while ($current = array_shift($tree)) {
    $t = i18n_taxonomy_localize_terms($current);
    $output .= '<div class="dvtaxonomy-depth-' . $current->depth . '" >' . l($t->name, $base . '/' . $current->name, array('attributes' => array('data-activepanel' => $index))) . '</div>';
    if ($next = current($tree)) {
      if ($next->depth > $current->depth) {
        $output .= '<div class="dvtaxonomy-childrens-' . $next->depth . '">';
        $output .= _dvtoolbox_print_tree($tree, $base . '/' . $current->name, $index);
        $output .= '</div>';
      }
      elseif ($current->depth > $next->depth) {
        $index++;
        return $output;
      }
      elseif ($current->depth == 0) {
      	$index++;
      }
    }
  }
  return $output;
}

function dvtoolbox_dvtaxonomy_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
 
  $options = array('from-panel-arguments' => t('From panel arguments')); 
  foreach (taxonomy_vocabulary_get_names() as $voc) {
    $options[$voc->machine_name] = $voc->name;
  }

  $form['vocabulary'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary'),
    '#description' => t('Vocabulary'),
    '#options' => $options,
    '#default_value' => $conf['vocabulary'],
  );
  
  $form['include_vocabulary'] = array(
    '#type' => 'checkbox',
    '#title' => t('Vocabulary on path'),
    '#description' => t("Include vocabulary's machine name on urls"),
    '#default_value' => $conf['include_vocabulary'],
  );
  
  $form['parent'] = array(
    '#type' => 'select',
    '#title' => t('Parent term'),
    '#description' => t('Select parent term'),
    '#options' => empty($conf['vocabulary']) ? array() : dvtoolbox_get_taxonomy_options($conf['vocabulary'], 0, TRUE),
    '#empty_value' => 'from-panel-arguments',
    '#empty_option' => t('From panel arguments'),
    '#default_value' => $conf['parent'],
  );
  
  $form['include_hierarchy'] = array(
    '#type' => 'select',
    '#title' => t('Hierarchy on path'),
    '#description' => t("Select how many levels of hierarchy will be included on path"),
    '#default_value' => $conf['include_hierarchy'],
    '#empty_value' => 0,
    '#empty_option' => t('None'),
    '#options' => range(1, 10, 1),
  );
  
  $form['depth'] = array(
    '#type' => 'textfield',
    '#title' => t('Depth'),
    '#description' => t('Max depth. Enter 0 to no limit.'),
    '#default_value' => $conf['depth'],
  );
  
  $form['base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Link base'),
    '#description' => t('The base url to create links like base/vocabulary/term'),
    '#default_value' => $conf['base_url'],
  );
  
  $form['accordion'] = array(
    '#type' => 'checkbox',
    '#title' => t('Accordion'),
    '#description' => t("Collapse like an accordion"),
    '#default_value' => $conf['accordion'],
  );
  return $form;
}

function dvtoolbox_dvtaxonomy_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = dvtoolbox_dvtaxonomy_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function dvtoolbox_dvtaxonomy_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('dvtaxonomy from @item', array('@item' => $conf['mlid']));
}



function _dvtoolbox_dvtaxonomy_rebase_links(&$tree, $base = '') {
  if (empty($tree)) return;
  foreach ($tree as &$item) {
    $item['link']['href'] = $base . '/' . $item['link']['title'];
    _dvtoolbox_dvtaxonomy_rebase_links($item['below'], $item['link']['href']);
  }
}



function dvtoolbox_taxonomy_tree_data( array $links, array $parents = array(), $depth = 1, $base = '', $limit_components = 1) {
  $links = array_reverse($links);
  return _dvtoolbox_taxonomy_tree_data($links, $parents, $depth, $base, $limit_components);
}

function _dvtoolbox_taxonomy_tree_data(&$links, $parents, $depth, $base, $limit_components) {
  $tree = array();
  while ($item = array_pop($links)) {
    $tree[$item->tid] = array(
      'link' => array(
        'in_active_trail' => in_array($item->tid, $parents),
        'menu_name' => $voc_name,
        'mlid' => $item->tid,
        'href' => $base . '/' . $item->name,
        'title' => $item->name,
        'has_children' => !empty($tree['tid-' . $item->parents[0]]['below']),
        'access' => TRUE,
        'hidden' => 0,
        'localized_options' => array('attributes' => array('class' => array('dvtaxonomy-depth-' . $item->depth))),
      ),
      'below' => array(),
    );
    $next = end($links);
    if ($next && $next->depth > $depth) {
      $tree[$item->tid]['below'] = _dvtoolbox_taxonomy_tree_data($links, $parents, $next->depth, $base . ($item->depth < $limit_components ?  '/' . $item->name : ''), $limit_components);
    }
    $next = end($links);
    if (!$next || $next->depth < $depth) {
      break;
    }
  }
  return $tree;
}
