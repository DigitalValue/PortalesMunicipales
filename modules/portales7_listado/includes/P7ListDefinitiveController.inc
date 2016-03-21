<?php
module_load_include('inc', 'portales7_listado', 'includes/P7ListController');
class P7ListDefinitiveController extends P7ListController{
  public function prepare() {
    module_load_include('util.inc', 'portales7_listado');
    if (($this->conf['type'] != -1 ) && count($this->type) == 0 && count($this->arguments) == 0) {return NULL; }
    $view = portales7_listado_get_view();
    $this->view = &$view;
    
    if (!empty($this->type)) {
      _portales7_listado_add_tid_filter($view->display['default']->handler, 'portales7_type', 'type', $this->type);
    }
    for ($i = 0; $i < count($this->arguments); $i++){
      _portales7_listado_add_argument($view->display['default']->handler, 'tid_' . $i);
    }
  
    _portales7_listado_set_num_items($view->display['default']->handler, $this->conf['items'], $this->conf['offset']);
    
    _portales7_listado_add_generic_sort($view->display['default']->handler, 'sticky', 'DESC');
    if (!empty($this->conf['sort'])) {
      list($field, $order) = explode(':', $this->conf['sort']);
      if (preg_match('/^portales7_/', $field)) {
        _portales7_listado_add_sort_by_field($view->display['default']->handler, $field, $order);
      }
      else {
        _portales7_listado_add_generic_sort($view->display['default']->handler, $field, $order);
      }
    }
    
    if ($this->conf['promoted']) {
      _portales7_listado_add_generic_filter($view->display['default']->handler, 'promote', 1);
    }
    if (isset($this->conf['calendar'])) {
      _portales7_listado_add_eventcalendar_filter($view->display['default']->handler, $this->conf['calendar']);
    }
    if ($this->conf['pager']) {
      _portales7_listado_add_pager($view->display['default']->handler, array('items_per_page' => $this->conf['items'], 'id' => $this->conf['pager_id'], 'offset' => $this->conf['offset'], 'type' => $this->conf['pager']));
    }
    if (function_exists('portales7_og_add_og_filter')) {
      portales7_og_add_og_filter($view->display['default']->handler, $this->conf['og_group']);
    }
    if (!empty($this->conf['section']) && is_numeric($this->conf['section'])) {
      $this->add_tid_filter('portales7_section', 'sections', array($this->conf['section']));
    }
    
    $view->name .= '_' . $this->listtype;
    if (!method_exists($this->view, 'execute_display') && function_exists('dpm')) { dpm($view, __FUNCTION__);}
    return $this;
  }

  public function getPane($title, $args, $rpl) {
    $pane = new stdClass();
    $pane->title = $this->getTitle($title, $args, $rpl);
    $pane->content = (empty($this->conf['hide_description']) ? $this->getDescription() : '') . $this->render();
    return $pane;
  }
  
  public function render() {
    $elements['items'] = array();
    $elements['conf'] = $this->conf;
    foreach($this->getResult() as $r) {
      $node = node_load($r->nid);
      $render = node_view($node, $this->conf['view_mode']);
      $elements['items'][] = drupal_render($render);
    }
    $elements['attributes']['class'] = array('portales7-definitivepane');
    $elements['attributes']['id'] = $this->conf['id'];
    
    $output = theme('item_list', $elements);
    if (!empty($this->conf['pager']) && $this->getView()->use_pager()) {
      $output .= $this->getView()->query->pager->render();
    }
    if (!empty($this->conf['more_link'])) {
      $output .= '<div class="more-link">' . l(t('More'), $this->conf['more_link']) . '</div>';
    }
    return $output;
  }
}


