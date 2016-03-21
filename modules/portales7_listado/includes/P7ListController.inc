<?php
class P7ListController {
  protected $view;
  protected $conf;
  protected $type;
  protected $classes;
  protected $arguments;
  protected $listtype;

  function getTypes() {
    return $this->type;
  }
  function __construct($subtype, $conf, $panel_args, $context) {
    $classes = $conf['classes'];
    if (is_array($conf['classes'])){
      $classes = join(' ', $conf['classes']);
    }
    $type = array();
    if (is_string($conf['type']) && ($t = dvtoolbox_get_taxonomy_term_by_name($conf['type'], 'type'))) {
      $conf['type'] = $t->tid;
    }
    if ($conf['type'] > 0) {
      if (is_array($conf['type'])) {
        foreach ($conf['type'] as $t){
          $type[$t] = $t;
        }
      }
      else {
        $type = array($conf['type'] => $conf['type']);
      }
    }
    elseif ($conf['type'] == -2) {
      //el type ve dels arguments del panell
      $type_name = array_shift($panel_args);
      if ($term = dvtoolbox_get_taxonomy_term_by_name($type_name,'type',FALSE)){
        $type = array($term->tid => $term->tid);
      }
      else {
        array_unshift($panel_args, $type_name);
      }
    }
    foreach ($type as $tid) {
      if ($term = taxonomy_term_load($tid)) {
        $classes .= ' portales7_listado-' . transliteration_clean_filename($term->name, '-');
      }
    }
    
    $arguments = array();
    if (!empty($conf['arguments'])) {
      $arguments = explode('/', $conf['arguments']);
    }
    if ($conf['include_path'] && !empty($panel_args)){
      $arguments = array_merge($arguments, $panel_args); 
    }
    if ($conf['pager'] == 1) {
      $conf['pager'] == 'mini';
    }
    if (empty($conf['pager_id'])) $conf['pager_id'] = rand(0,10);
    $this->listtype = $conf['subtype'];
    $this->arguments = $arguments;
    $this->type = $type;
    $this->classes = $classes;
    $this->conf = $conf;
    if (!empty($_GET['sort']) && !empty($conf['sort_by_url'])) $this->conf['sort'] = $_GET['sort'];
  }
  
  public function render() {
    if (!empty($this->view->result)) {
      $prefix = "<div class=\"portales7_listado {$this->view->name}\"><div class=\"{$this->classes}\">";
      $suffix = '</div></div>';
      $more_link = '';
      if (!empty($this->conf['more_link']) && count($this->view->result) >= $this->conf['items']) {
        $more_link = '<div class="more-link">' . l(t('More'), $this->conf['more_link']) . '</div>';
      }
      return $prefix . $this->output . $more_link . $suffix;
    }
  }

  public function prepare() {
    if (count($this->type) == 0 && count($this->arguments) == 0) {return NULL; }
    $view = _portales7_listado_prepare_view($this->type, $this->arguments, $this->conf['fields'], $this->conf['items'], $this->conf['offset']);
    $this->view = &$view;
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
  
  public function getNumResults() {
    return min($this->conf['items'], count($this->view->result));
  }
  
  public function execute() {
    if (empty($this->view)) $this->prepare();
    if (method_exists($this->view, 'execute_display')) {
      $this->output = $this->view->execute_display('default',$this->arguments);
    }
    return $this;
  }
  
  public function add_tid_filter($field, $vocabulary, $values) {
    if (is_scalar($values)) {
      $values = array($values);
    }
    $values = drupal_map_assoc($values);
    _portales7_listado_add_tid_filter($this->view->display['default']->handler, $field, $vocabulary, $values);
  }
  
  public function add_eventdate_argument() {
    if (empty($this->view)) throw new Exception('No view defined');
    array_pop($this->view->display['default']->handler->display->display_options['arguments']);
    _portales7_listado_add_eventdate_argument($this->view->display['default']->handler);
  }
  
  public function add_eventdate_end_filter() {
    if (empty($this->view)) throw new Exception('No view defined');
    _portales7_listado_add_eventdate_end_filter($this->view->display['default']->handler);
  }

  public function getTitle($title, $args, $rpl) {
    foreach ($this->getTypes() as $t) {
      if ($term = taxonomy_term_load($t)){
        $types[$term->tid] = $term;
      }
    }

    foreach($this->arguments as $name) {
      if ($term = dvtoolbox_get_taxonomy_term_by_name($name, 'category', FALSE, 0)) {
        $types[$term->tid] = $term;
      }
    }
    foreach (i18n_taxonomy_localize_terms($types) as $term) {
      $types[$term->tid] = $term->name;
    }
    
    if (!empty($types)) {
      if (empty($title)) return t('List of @types', array('@types' => join(', ', $types)));
      else {
        $args[$rpl] = join(', ', $types);
        return t($title, $args);
      }
    }
    return '';
  }

  public function getDescription($voc = 'category') {
    foreach($this->arguments as $name) {
      if ($term = dvtoolbox_get_taxonomy_term_by_name($name, $voc)) {
        if (!empty($term->description)) {
          return '<div class="term-description">' . check_markup($term->description, $term->format) . '</div>';
        }
      }
    }
  }
  public function getPane($title, $args, $rpl) {
    $pane = new stdClass();
    $this->prepare();
    $this->execute();
    $pane->content = (empty($this->conf['hide_description']) ? $this->getDescription() : '') . $this->render();
    $pane->title = $this->getTitle($title, $args, $rpl);
    return $pane;
  }
  public function getResult() {
    if (empty($this->view)) $this->prepare();
    if (empty($this->view->result)) $this->execute();
    return $this->view->result;
  }
  
  public function getView() {
    return $this->view;
  }
  
  public function getConf() {
    return $this->conf;
  }
  
  public function getArguments() {
    return $this->arguments;
  }
}


