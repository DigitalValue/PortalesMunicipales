<?php
if (empty($newsletter)) {
  $newsletter = (object) array(
    'subject' => t('Newsletter'),
    'recipients' => '',
    'content' => '',
    );
}?>
<html lang="en">
<head>
  <meta/>
  <title><?php print($newsletter->subject);?></title>
  <link rel="stylesheet" href="http://code.jquery.com/ui/1.10.0/themes/base/jquery-ui.css" />
  <script src="http://code.jquery.com/jquery-1.8.3.js"></script>
  <script src="http://code.jquery.com/ui/1.10.0/jquery-ui.js"></script>
  <link rel="stylesheet" type="text/css" href="/sites/all/modules/portales7/portales7_newsletter/portales7_newsletter.css" />
  <script type="text/javascript" src="/sites/all/modules/portales7/portales7_newsletter/portales7_newsletter.js"></script>
  <script type="text/javascript" src="/sites/all/libraries/ckeditor/ckeditor.js"></script>
  
</head>
<body>

<div style="clear:both;">
  <form id="enviar" method="post">
    <input type="hidden" id="id" value="0">
    <div style="display:block;">
    <table>	
    <tr><td><label for="subject">Título:</label></td><td><input type="text" id="subject" value="Newsletter cultura" style="width:500px;"></td></tr>
    <tr><td><label for="destinatario">Destinatario:</label></td><td><input type="text" id="destinatario" value="juanjo@digitalvalue.es" style="width:435px;">
    <input type="button" value="Enviar" onclick="Enviar();"></td></tr>
    </table>
    </div>	 
  </form>
</div>
<div id="result" style="clear:both;"></div>
<div id="newsletter-generator">
<div id="tabs">
  <ul class="tabs">
    <li><a href="#tab-sources">Origenes de datos</a></li>
    <li><a href="#tab-presets">Predefinidos</a></li>
    <li><a href="#tab-custom">Personalizados</a></li>
  </ul>
  <div id="tab-sources" class="tab" style="min-height: 689px;">
    <div id="fuentes" class="filter">
    <div  style="width:90%;height:10%;">
      <div id="form-fuentes">
        <label for="datasources" style="float:left;margin:0px;">Origenes de datos</label><br/><br/>
    <select id="datasources">
      <option value="http://alcantir.portalesmunicipales.es/" selected>Alcantir</option>
      <option value="http://desarrollo.portalesmunicipales.es/">Desarrollo</option>
    </select>
    <input type="button" id="boto-conectar" value="Conectar" />
    </div>
    <div id="form-filters" class="filter">
      <select id="filter-tipo" ><option value="" disabled="disabled">Tipo</option></select>
      <input type="button" value="Filtrar" style="clear:right;margin-bottom:7px;"><br/>
      <select id="filter-clasificacion"><option value="" disabled="disabled">Clasificacion</option></select>
      <input type="button" value="Reiniciar" style="clear:right;">
    </div>
    </div>
    <div  style="width:90%;height:10%;">
    <div id="filter-search" class="filter" style="float:left;margin:auto;">
      <input type="text" id="filtro" value="Cadena de búsqueda" style="width:300px;">
      <input type="button" id="buscar" value="Buscar">
    </div>
    </div>
    </div>
    <div>
    <ul id="continguts" style="clear: both; size: 100%;"></ul>
    </div>
</div>
<div id="tab-presets" class="tab">
  <div style="float: left"><h3>Aquí se muestran los contenidos predefinidos</h3></div><div style="float: left; clear:both"><button id="boto-refrescar">Refrescar</button></div>
  <div style="clear: both;"></div>
  <ul id="custom-contents" style="width:770px; height:600px; margin-top:20px;border: 1px solid black;overflow:scroll;"></ul>
</div>
<div id="tab-custom" class="tab">
  <div id="form-custom">
  <textarea id="texto_personalizado" class="ckeditor"></textarea>
  <button id="boto-afegir">Añadir</button>
  <button id="boto-guardar">Añadir y guardar</button>
  <ul id="temp-custom" class="sortable"></ul>
  </div>
</div>
</div>
<div id="newsletter-container">
<div id="newsletter">
  <?php if(empty($newsletter->content)) { ?>
        <ul id="sortable1" style="width: 500px; background-color: #C0C0C0" class="content-pane horizontal sortable"></ul>
    	<ul id="sortable2" style="width: 500px; background-color: #CcCcCc" class="content-pane horizontal sortable"></ul>
  <?php } else {
    print $newsletter->content;
  }?>
</div>
</div>
</div>

<div id="footer" style="margin-top:auto;border: 1px solid black;display:block;height:6.3%;">
    
    <div style="display:block;float:left;margin-left:5%;margin-top:2px;">
    	<form method="post">
    		<img class="minis" src="<?php print file_create_url(drupal_get_path('module','portales7_newsletter'). '/images/mini1.png');?>"></img><input style="margin-right:50px;position:relative;top:-20px;" type="radio" name="group1" value="DosColumnas" id="DosColumnas">
    		<img class="minis" src="<?php print file_create_url(drupal_get_path('module','portales7_newsletter'). '/images/mini2.png');?>"></img><input style="margin-right:50px;position:relative;top:-20px;" type="radio" name="group1" value="Vertical" id="Vertical">
    		<img class="minis" src="<?php print file_create_url(drupal_get_path('module','portales7_newsletter'). '/images/mini3.png');?>"></img><input style="margin-right:50px;position:relative;top:-20px;" type="radio" name="group1" value="CapiCua" id="CapiCua">
    		<img class="minis" src="<?php print file_create_url(drupal_get_path('module','portales7_newsletter'). '/images/mini4.png');?>"></img><input style="margin-right:50px;position:relative;top:-20px;" type="radio" name="group1" value="TresColumnas" id="TresColumnas">
    	</form>
    </div>
    <div style="display:block;clear:right;float:left;margin-left:26%;margin-top:13px;">	
    		<input style="padding:5px;margin-left:10px;" type="button" value="Vista previa" onclick="VistaPrevia();">
    		<input style="padding:5px;margin-left:10px;;" type="button" value="Guardar" onclick="guardarNewsletter(false);">
    		<input style="padding:5px;margin-left:10px;;" type="button" value="Limpiar" onclick="Limpiar();">
    </div>		
</div>

</body>
</html>
