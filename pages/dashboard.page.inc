<?php
$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'dashboard';
$page->task = 'page';
$page->admin_title = 'Total Control administrative dashboard';
$page->admin_description = '';
$page->path = 'admin/dashboard';
$page->access = array(
  'plugins' => array(
    0 => array(
      'name' => 'perm',
      'settings' => array(
        'perm' => 'have total control',
      ),
      'context' => 'logged-in-user',
      'not' => FALSE,
    ),
  ),
  'logic' => 'and',
);
$page->menu = array(
  'type' => 'normal',
  'title' => 'Dashboard',
  'name' => 'management',
  'weight' => '-100',
  'parent' => array(
    'type' => 'normal',
    'title' => 'Dashboard',
    'name' => 'management',
    'weight' => '0',
  ),
);
$page->arguments = array();
$page->conf = array(
  'admin_paths' => TRUE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_dashboard_panel_context';
$handler->task = 'page';
$handler->subtask = 'dashboard';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Admin Dashboard',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
);
$display = new panels_display();
$display->layout = 'flexible';
$display->layout_settings = array(
  'items' => array(
    'canvas' => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 'main',
      ),
      'parent' => NULL,
    ),
    'main' => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'children' => array(
        0 => 3,
        1 => 1,
        2 => 'main-row',
        3 => 2,
      ),
      'parent' => 'canvas',
    ),
    'main-row' => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'left_side',
        1 => 'center',
      ),
      'parent' => 'main',
    ),
    'center' => array(
      'type' => 'region',
      'title' => 'Centrado',
      'width' => 100,
      'width_type' => '%',
      'parent' => 'main-row',
    ),
    'left_side' => array(
      'type' => 'region',
      'title' => 'Left Side',
      'width' => '305',
      'width_type' => 'px',
      'parent' => 'main-row',
      'class' => 'total-control-left',
      'hide_empty' => 1,
    ),
    1 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'header',
      ),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 1,
    ),
    'header' => array(
      'type' => 'region',
      'title' => 'Header',
      'width' => 100,
      'width_type' => '%',
      'parent' => '1',
      'class' => 'total-control-header',
      'hide_empty' => 1,
    ),
    2 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 0,
    ),
    3 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(),
      'parent' => 'main',
      'class' => '',
      'hide_empty' => 0,
    ),
  ),
);
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
    'top' => NULL,
    'left' => NULL,
    'right' => NULL,
    'bottom' => NULL,
    'center' => NULL,
    'left_side' => NULL,
    'header' => NULL,
  ),
);
$display->cache = array();
$display->title = 'Dashboard';
$display->uuid = '2958a630-9798-4a8d-b502-851eabda7059';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-db4b1674-43d1-444a-b4bd-945c0744ccff';
  $pane->panel = 'center';
  $pane->type = 'localizable';
  $pane->subtype = 'localizable';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'en' => array(
      'text' => array(
        'value' => '<ul>
  <li>
    <a class="btnPanel addArticle" href="/node/add/portales7-node">Add article</a></li>
  <li>
    <a class="btnPanel addEntity" href="/node/add/portales7-entity">Add entity</a></li>
  <li>
    <a class="btnPanel findContent" href="/admin/dashboard/content">Find content</a></li>
  <li>
    <a class="btnPanel mobileSim" href="/mobile_simulator">Mobile simulator</a></li>
  <li>
    <a class="btnPanel docExplo" href="/admin/dashboard/imce">Document explorer</a></li>
  <li>
    <a class="btnPanel closeSes" href="/user/logout">Logout</a></li>
</ul>
',
        'format' => 'full_html',
      ),
    ),
    'es' => array(
      'text' => array(
        'value' => '<ul>
  <li>
    <a class="btnPanel addArticle" href="/node/add/portales7-node">A&ntilde;adir art&iacute;culo</a></li>
  <li>
    <a class="btnPanel addEntity" href="/node/add/portales7-entity">A&ntilde;adir entidad</a></li>
  <li>
    <a class="btnPanel findContent" href="/admin/dashboard/content">Administrar contenido</a></li>
  <li>
    <a class="btnPanel mobileSim" href="/mobile_simulator">Simulador App m&oacute;vil</a></li>
  <li>
    <a class="btnPanel docExplo" href="/admin/dashboard/imce">Explorador de documentos</a></li>
  <li>
    <a class="btnPanel closeSes" href="/user/logout">Cerrar sesi&oacute;n</a></li>
</ul>
',
        'format' => 'full_html',
      ),
    ),
    'ca' => array(
      'text' => array(
        'value' => '<ul>
  <li>
    <a class="btnPanel addArticle" href="/node/add/portales7-node">Afegir art&iacute;cul</a></li>
  <li>
    <a class="btnPanel addEntity" href="/node/add/portales7-entity">Afegir entitat</a></li>
  <li>
    <a class="btnPanel findContent" href="/admin/dashboard/content">Administrar contingut</a></li>
  <li>
    <a class="btnPanel mobileSim" href="/mobile_simulator">Simulador App m&ograve;bil</a></li>
  <li>
    <a class="btnPanel docExplo" href="/admin/dashboard/imce">Explorador de documents</a></li>
  <li>
    <a class="btnPanel closeSes" href="/user/logout">Tancar sessi&oacute;</a></li>
</ul>
',
        'format' => 'full_html',
      ),
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'btnsSup',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'db4b1674-43d1-444a-b4bd-945c0744ccff';
  $display->content['new-db4b1674-43d1-444a-b4bd-945c0744ccff'] = $pane;
  $display->panels['center'][0] = 'new-db4b1674-43d1-444a-b4bd-945c0744ccff';
  $pane = new stdClass();
  $pane->pid = 'new-8f61ea3e-0ed1-422b-b14e-0f0d26a8b6fa';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'control_content_panes-pane_tc_new';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = '';
  $pane->uuid = '8f61ea3e-0ed1-422b-b14e-0f0d26a8b6fa';
  $display->content['new-8f61ea3e-0ed1-422b-b14e-0f0d26a8b6fa'] = $pane;
  $display->panels['center'][1] = 'new-8f61ea3e-0ed1-422b-b14e-0f0d26a8b6fa';
  $pane = new stdClass();
  $pane->pid = 'new-1ac7c547-9303-48cf-80fa-4629e4df07fb';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => '',
          'php' => '$sites = variable_get(\'piwik_reports_allowed_sites\');
if($sites==""){
return false;
}else{
return true;
}
',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Estadísticas Web',
    'body' => '<?php 
$url = variable_get(\'piwik_url_http\');
$sites = variable_get(\'piwik_reports_allowed_sites\');
$fechaAyer = date("y-m-d", strtotime( \'-1 days\' ));
$token = variable_get(\'piwik_reports_token_auth\');
$url_iframe= $url."?idSite=".str_replace(\'"\', "", $sites)."&date=".$fechaAyer."&period=day&disableLink=1&module=Widgetize&action=iframe&widget=1&token_auth=".$token."&columns%5B%5D=nb_visits&moduleToWidgetize=VisitsSummary&actionToWidgetize=getEvolutionGraph";
echo \'<a href="/admin/reports/piwik_reports">Ver más estadísticas</a>\';
echo \'<iframe width="100%" height="328" src="\'.$url_iframe.\'" scrolling="no" frameborder="0" marginheight="0" marginwidth="0"></iframe>\';
?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1ac7c547-9303-48cf-80fa-4629e4df07fb';
  $display->content['new-1ac7c547-9303-48cf-80fa-4629e4df07fb'] = $pane;
  $display->panels['center'][2] = 'new-1ac7c547-9303-48cf-80fa-4629e4df07fb';
  $pane = new stdClass();
  $pane->pid = 'new-20ad3023-2391-421e-b1a8-362e78c0d8ea';
  $pane->panel = 'center';
  $pane->type = 'dashboard';
  $pane->subtype = 'dashboard';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'sets' => array(
      'portales7' => 'portales7',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '20ad3023-2391-421e-b1a8-362e78c0d8ea';
  $display->content['new-20ad3023-2391-421e-b1a8-362e78c0d8ea'] = $pane;
  $display->panels['center'][3] = 'new-20ad3023-2391-421e-b1a8-362e78c0d8ea';
  $pane = new stdClass();
  $pane->pid = 'new-f0faf30a-017a-4107-a464-dbbe1ab1a3fe';
  $pane->panel = 'center';
  $pane->type = 'menus';
  $pane->subtype = 'menus';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'item1' => NULL,
    'item2' => NULL,
    'override_title' => 0,
    'override_title_text' => '',
    'menus' => array(
      'main-menu' => 'main-menu',
      'navigation' => 'navigation',
      'devel' => 0,
      'management' => 0,
      'user-menu' => 0,
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = '';
  $pane->uuid = 'f0faf30a-017a-4107-a464-dbbe1ab1a3fe';
  $display->content['new-f0faf30a-017a-4107-a464-dbbe1ab1a3fe'] = $pane;
  $display->panels['center'][4] = 'new-f0faf30a-017a-4107-a464-dbbe1ab1a3fe';
  $pane = new stdClass();
  $pane->pid = 'new-e4903777-b0e0-443c-98a2-979e455c4ca7';
  $pane->panel = 'center';
  $pane->type = 'node_types';
  $pane->subtype = 'node_types';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
            1 => 6,
            2 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'types' => array(
      'article' => 'article',
      'page' => 'page',
      'project' => 'project',
      'video' => 'video',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = '';
  $pane->uuid = 'e4903777-b0e0-443c-98a2-979e455c4ca7';
  $display->content['new-e4903777-b0e0-443c-98a2-979e455c4ca7'] = $pane;
  $display->panels['center'][5] = 'new-e4903777-b0e0-443c-98a2-979e455c4ca7';
  $pane = new stdClass();
  $pane->pid = 'new-5b9fba84-5f1d-4782-bdda-a1bf7620c35a';
  $pane->panel = 'center';
  $pane->type = 'taxonomy';
  $pane->subtype = 'taxonomy';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
            1 => 6,
            2 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'vids' => array(
      0 => '2',
      1 => '1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = '';
  $pane->uuid = '5b9fba84-5f1d-4782-bdda-a1bf7620c35a';
  $display->content['new-5b9fba84-5f1d-4782-bdda-a1bf7620c35a'] = $pane;
  $display->panels['center'][6] = 'new-5b9fba84-5f1d-4782-bdda-a1bf7620c35a';
  $pane = new stdClass();
  $pane->pid = 'new-16fb6779-6a59-435d-823f-14753f36b207';
  $pane->panel = 'center';
  $pane->type = 'panel_pages';
  $pane->subtype = 'panel_pages';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
            1 => 6,
            2 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'item1' => NULL,
    'item2' => NULL,
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = '';
  $pane->uuid = '16fb6779-6a59-435d-823f-14753f36b207';
  $display->content['new-16fb6779-6a59-435d-823f-14753f36b207'] = $pane;
  $display->panels['center'][7] = 'new-16fb6779-6a59-435d-823f-14753f36b207';
  $pane = new stdClass();
  $pane->pid = 'new-a78d4e24-653e-41f8-9634-83dcfa15c82a';
  $pane->panel = 'header';
  $pane->type = 'welcome';
  $pane->subtype = 'welcome';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a78d4e24-653e-41f8-9634-83dcfa15c82a';
  $display->content['new-a78d4e24-653e-41f8-9634-83dcfa15c82a'] = $pane;
  $display->panels['header'][0] = 'new-a78d4e24-653e-41f8-9634-83dcfa15c82a';
  $pane = new stdClass();
  $pane->pid = 'new-bb4ca03b-fb13-47dd-bc91-9447682c8c28';
  $pane->panel = 'left_side';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-panel-de-control';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bb4ca03b-fb13-47dd-bc91-9447682c8c28';
  $display->content['new-bb4ca03b-fb13-47dd-bc91-9447682c8c28'] = $pane;
  $display->panels['left_side'][0] = 'new-bb4ca03b-fb13-47dd-bc91-9447682c8c28';
  $pane = new stdClass();
  $pane->pid = 'new-5b83d0ef-d50d-4771-94f4-060cfc3cfb6d';
  $pane->panel = 'left_side';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Listados',
    'title' => 'Listados',
    'body' => '<ul>
  <li>
    <a href="/listado/banner">Banners</a></li>
  <li>
    <a href="/listado/bim">Bim</a></li>
  <li>
    <a href="/listado/evento">Evento</a></li>
  <li>
    <a href="/listado/galeria">Galer&iacute;a</a></li>
  <li>
    <a href="/listado/noticia">Noticia</a></li>
</ul>
',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5b83d0ef-d50d-4771-94f4-060cfc3cfb6d';
  $display->content['new-5b83d0ef-d50d-4771-94f4-060cfc3cfb6d'] = $pane;
  $display->panels['left_side'][1] = 'new-5b83d0ef-d50d-4771-94f4-060cfc3cfb6d';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
