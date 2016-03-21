<?php
$plugin = array(
  'title' => t('DV Menu'),
  'defaults' => array('mlid' => 0, 'menu_name'=>0, 'image_style' => 'none', 'depth' => 1, 'nolink_dest' => 'dvmenu'),
  'category' => t('DV toolbox'),
  'single' => TRUE,
  'disabled' => TRUE,
);

function dvtoolbox_dvmenu_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key]))
      $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
* Output function for the 'author pane' content type.
*/
// The function name is <code>MODULE_NAME_CT_NAME_content_type_render
function dvtoolbox_dvmenu_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;
  global $user;
  $pane=new stdClass();
  $pane->content = '';
  
  $item = NULL;
  $mlid = 0;
  $menu_name = '';
  $output = '';
  if ($conf['mlid'] != 'from-panel-arguments') {
    list($menu_name, $mlid) = explode(':', $conf['mlid'], 2);
  }
  else {
    $mlid = array_pop($panel_args);
    if (!is_numeric($mlid)) {
      $menu_name = $mlid;
      $mlid = 0;
    }
  }
  $cid = dvtoolbox_cid_generate(array($mlid, $menu_name, $conf['depth'], $conf['nolink_dest'], $language->language, $user->uid));
  if (!empty($_GET['reset']) || !$cached = cache_get($cid)) {
    if ($mlid == 0) {
      $tree = menu_build_tree($menu_name, array('max_depth' => $conf['depth']));
      $menu = menu_load($menu_name);
      $pane->title = $menu['title'];
    }
    else {
      $item = menu_link_load($mlid);
      $menu_name = $item['menu_name'];
      $parameters = array(
        'active_trail' => array($item['plid']),
        'only_active_trail' => FALSE,
        'min_depth' => $item['depth'] + 1,
        
      );
      if ($conf['depth'] > 0) {
        $parameters['max_depth'] = $item['depth'] + $conf['depth'];
        $tree = menu_build_tree($item['menu_name'], $parameters); 
      }
      else {
        $tree = menu_build_tree($item['menu_name'], $parameters);
        foreach ($tree as $k => $v) {
          if ($v['link']['plid'] != $item['mlid']) { unset($tree[$k]);}
        }
      }
      $pane->title = $item['title'];
      _dvtoolbox_purga_otras_ramas($tree, $mlid);
    }
    _dvtoolbox_purga_nolinks($tree, $conf['nolink_dest']);
    $output = drupal_render(menu_tree_output($tree));
    $pane->content = '<div class="dvmenu" id="dvmenu-' . join('-', array($menu_name, $mlid)) . '">' . $output . '</div>';
    cache_set($cid, $pane, 'cache', CACHE_TEMPORARY);
    return $pane;
  }
  return $cached->data;
}

function _dvtoolbox_purga_otras_ramas(&$tree, $parent) {
  foreach($tree as $k => $item) {
    if (!isset($item['link']['p0'])) continue;
    if (!in_array($parent, array($item['link']['p0'],$item['link']['p1'],$item['link']['p2'],$item['link']['p3'],$item['link']['p4'],$item['link']['p5'],$item['link']['p6'],$item['link']['p7'],$item['link']['p8'],$item['link']['p9']))) {
      unset($tree[$k]);
    }
  }
}

function _dvtoolbox_purga_nolinks(&$tree, $dest) {
  foreach ($tree as $k => &$v) {
    if (empty($v['below']) && $v['link']['link_path'] == '<nolink>') {
      //drupal_set_message($v['link']['link_title'], 'status');
      $v['link']['link_path'] =  $dest . '/' . $v['link']['mlid'];
      $v['link']['href'] = $dest . '/' . $v['link']['mlid'];
      $v['link']['router_path'] = $dest;
    }
    elseif (count($v['below'])) {
      _dvtoolbox_purga_nolinks($v['below'], $dest);
    }
  }
}

function dvtoolbox_dvmenu_content_type_edit_form($form, &$form_state) {
  // The current configuration
  $conf = $form_state['conf'];
  
 $options = menu_parent_options(menu_get_menus(),'');
 $options = array_merge(array('from-panel-arguments' => t('From panel arguments')), $options);
  $form['mlid'] = array(
  '#type' => 'select',
  '#title' => t('Menu item'),
  '#description' => t('Menu item to show'),
  '#options' => $options,
  '#default_value' => $conf['mlid'],
  );
  
  $image_styles = image_style_options(FALSE);
  $image_styles['original'] = t('Left blank for original size');
  $image_styles['hide'] = t('Hide');
  
  $form['depth'] = array(
    '#type' => 'textfield',
    '#title' => t('Depth'),
    '#description' => t('Max depth. Enter 0 to no limit.'),
    '#default_value' => $conf['depth'],
  );
  
  $form['nolink_dest'] = array(
    '#type' => 'textfield',
    '#title' => t('<nolink> destination'),
    '#description' => t('Change <nolink> items to link based on this path'),
    '#default_value' => $conf['nolink_dest'],
  );
  
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#description' => t('Select image style for menu images when available'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
  );

  return $form;
}

function dvtoolbox_dvmenu_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = dvtoolbox_dvmenu_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

function dvtoolbox_dvmenu_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('dvmenu from @item', array('@item' => $conf['mlid']));
}
