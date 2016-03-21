//var base_url = 'http://desarrollo.portalesmunicipales.es/';
  var base_url = 'http://alcantir.portalesmunicipales.es/';
  var Count = 0;
  var Sortable1H=0;
  var Sortable2H=0;
  var Sortable3H=0;
  var Sortable4H=0;
  var Modo = "DC";
  function processNodes(data) {
    var items = [];
    $.each(data.nodes, function (key, val) {
      node = val.node;
      if (node.json_path) {
        path = base_url + node.json_path;
      }
      else {
        path = base_url + 'node/' + node.json_nid;
      }
      output = '<li class="draggable ui-state-default noticia-listado"><div class="node" id="node-'+node.json_nid+'" ><div class="node-title"><a href="' + path+ '">'+ node.json_title + '</a></div><div class="node-content">';
      if (node.json_images_thumbnail && node.json_images_thumbnail.length > 0) {
        if (node.json_images_thumbnail instanceof Array) {
          output += '<div class="node-thumbnail"><img src="'+base_url+node.json_images_thumbnail["1"]+'"/></div>';
        } else {
          output += '<div class="node-thumbnail"><img src="'+base_url+node.json_images_thumbnail+'"/></div>';
        } 
      }
      output += '<div class="node-body">' + node.json_teaser + '</div></div></div></li>';
      items.push(output);
    });
    $('#continguts').html(items.join(''));
    $( ".draggable" ).draggable({
      connectToSortable: '.sortable',
      helper: "clone",
      revert: false,
      tolerance: "pointer",
      appendTo: "body",
      scroll:"false",
    }).uniqueId();
  }
  function processSearch(data) {
	  	var filtro = $('#filtro').val().toLowerCase();
	    var items = [];
	    $.each(data.nodes, function (key, val) {
	      node = val.node;
	      if (node.json_path) {
	        path = base_url + node.json_path;
	      }
	      else {
	        path = base_url + 'node/' + node.json_nid;
	      }
	      output = '<li class="draggable ui-state-default noticia-listado"><div class="node" id="node-'+node.json_nid+'" ><div class="node-title"><a href="' + path+ '">'+ node.json_title + '</a></div><div class="node-content">';
	      if (node.json_images_thumbnail && node.json_images_thumbnail.length > 0) {
	        if (node.json_images_thumbnail instanceof Array) {
	          output += '<div class="node-thumbnail"><img src="'+base_url+node.json_images_thumbnail["1"]+'"/></div>';
	        } else {
	          output += '<div class="node-thumbnail"><img src="'+base_url+node.json_images_thumbnail+'"/></div>';
	        } 
	      }
	      output += '<div class="node-body">' + node.json_teaser + '</div></div></div></li>';
	      if(node.json_title.toString().toLowerCase().indexOf(filtro) >= 0 || node.json_teaser.toString().toLowerCase().indexOf(filtro) >= 0)
	      {
	    	  items.push(output);
	      }
	    });
	    $('#continguts').html(items.join(''));
	    $( ".draggable" ).draggable({
	      connectToSortable: '.sortable',
	      helper: "clone",
	      revert: false,
	      tolerance: "pointer",
	      appendTo: "body",
	      scroll:"false",
	    }).uniqueId();
	    if(items.length <= 0)
	    {	
	    	$('body').append($('<div id="dialog" title="Busqueda"><p>No se encontraron resultados..</p></div>'))
	    	$(function() {
	    		$( "#dialog" ).dialog({
	    		      autoOpen: true,
	    		      show: {
	    		        effect: "blind",
	    		        duration: 1000
	    		      },
	    		      hide: {
	    		        effect: "explode",
	    		        duration: 1000
	    		      }
	    		    });
	    	});
	    }
	  }
  /* Metodo onload */
  $(function() {
    //noticias = jQuery.getJSON(base_url + 'json/noticia', function (data) {
    refreshCustomElements();
    $( "#sortable1" ).sortable({
      update: addXbuttons
    });
    $( "#sortable2" ).sortable({
      update: addXbuttons
    });
    $( "#temp-custom" ).sortable({
        update: addXbuttons,
        appendTo: "body"
      });

    $( "ul, li" ).disableSelection();
    $("#boto-afegir").click(addCustomText);
    $('.boton-borrar').click(function(){$(this).parent().remove();});
    /*
    $("#datasources").change(function(event){
      base_url = document.getElementById('datasources').value;
      console.log("datasources change %o", event);
      noticias=jQuery.getJSON(base_url + 'json/noticia', processNodes);
    });
    */
    $('#buscar').click(function(){
    	base_url = document.getElementById('datasources').value;
        noticias=jQuery.getJSON(base_url + 'json/noticia', processSearch);
    });
    $("#boto-conectar").click(function(){
    	base_url = document.getElementById('datasources').value;
        noticias=jQuery.getJSON(base_url + 'json/noticia', processNodes);
    });
    $("#boto-guardar").click(function(event){
      data = {'custom': CKEDITOR.instances.texto_personalizado.getData()};
      jQuery.post('/portales7/newsletter/custom/save', data, saveCustomContent); // /portales7/newsletter/custom/save
    });
    $('#boto-refrescar').click(function(event) { refreshCustomElements(); });
    $('#tabs').tabs();
    document.getElementById('newsletter-generator').insertBefore(document.getElementById('newsletter-container'),document.getElementById('newsletter-generator').firstChild);

    if($('#modo').attr('modo') == 'DC' || $('#modo').attr('modo') == '')
    {
    	$('#DosColumnas').attr('checked','checked');
    	Modo = 'DC';
    	Enlong();
    }
    else if($('#modo').attr('modo') == 'TC')
    {
    	$('#TresColumnas').attr('checked','checked');
    	$( "#sortable3" ).sortable({
			revert: true,
			update: addXbuttons
		});
		$( "#sortable3" ).sortable({
			connectWith: ".sortable"
		}).disableSelection();
    	Modo = 'TC';
    	Enlong();
    }
    else if($('#modo').attr('modo') == 'V')
    {
    	$('#Vertical').attr('checked','checked');
    	Modo = 'V';
    	Enlong();
    }
    else if($('#modo').attr('modo') == 'CC')
    {
    	$('#CapiCua').attr('checked','checked');
    	$( "#sortable3" ).sortable({
			revert: true,
			update: addXbuttons
		});
		$( "#sortable3" ).sortable({
			connectWith: ".sortable"
		}).disableSelection();
		$( "#sortable4" ).sortable({
			revert: true,
			update: addXbuttons
		});
		$( "#sortable4" ).sortable({
			connectWith: ".sortable"
		}).disableSelection();
    	Modo = 'CC';
    	Enlong();
    }
    
    $("input[name=group1]").change(function () {//////////////deteción de radiobuttons
    	
    	if($('#TresColumnas').attr('checked'))
    	{
    		if(Modo != 'TC')
    		{
    			Limpiar();
    			$('#sortable4').remove();
    			if($('#sortable2').length == 0)
    			{
    				$('#newsletter').append($('<ul id="sortable2" style="width: 332.9px; background-color:#CcCcCc" class="content-pane horizontal sortable"></ul>'));
    				$( "#sortable2" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable2" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    				
    			}	
    			if($('#sortable3').length == 0)
    			{
    				$('#sortable1').attr('class','content-pane horizontal sortable');
    				$('#sortable2').attr('class','content-pane horizontal sortable');
    				$('#sortable1').width(332.9);
    				$('#sortable2').width(332.9);
    				$('#newsletter').append($('<ul id="sortable3" style="width: 332.9px; background-color:#C0C0C0" class="content-pane horizontal sortable"></ul>'));
    				$( "#sortable3" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable3" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    			}
    			else{
    				$('#sortable1').width(332.9);
    				$('#sortable2').width(332.9);
    				$('#sortable3').width(332.9);
    				$('#sortable1').attr('class','content-pane horizontal sortable');
    				$('#sortable1').css('background-color','#C0C0C0');
    				$('#sortable2').attr('class','content-pane horizontal sortable');
    				$('#sortable2').css('background-color','#CcCcCc');
    				$('#sortable3').attr('class','content-pane horizontal sortable');
    				$('#sortable3').css('background-color','#C0C0C0');
    			}
    			Enlong();
				Modo = 'TC';
				Limpiar();
    		}	
    	}	
    	else if($('#DosColumnas').attr('checked'))
    	{
    		if(Modo != 'DC')
    		{
    			Limpiar();
    			if($('#sortable2').length == 0)
    			{
    				$('#newsletter').append($('<ul id="sortable2" style="width: 500px; background-color: #CcCcCc" class="content-pane horizontal sortable"></ul>'));
    				$( "#sortable2" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable2" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    			}
    			$('#sortable4').remove();
				$('#sortable1').attr('class','content-pane horizontal sortable');
				$('#sortable1').css('background-color','#C0C0C0');
				$('#sortable2').attr('class','content-pane horizontal sortable');
				$('#sortable2').css('background-color','#CcCcCc');
    			$('#sortable3').remove();
    			$('#sortable1').width(500);
    			$('#sortable2').width(500);
    			Enlong();
    			Modo = 'DC';
    			Limpiar();
    		}	
    		
    	}
    	else if($('#Vertical').attr('checked'))
    	{
    		if(Modo != 'V')
    		{
    			Limpiar();
    			$('#sortable2').remove();
    			$('#sortable3').remove();
    			$('#sortable4').remove();
    			$('#sortable1').width(1000);
    			$('#sortable1').attr('class','content-pane vertical-full sortable');
    			Enlong();
    			Modo = 'V';
    		}	
    	}
    	else if($('#CapiCua').attr('checked'))
    	{
    		if(Modo != 'CC')
    		{
    			Limpiar();
    			$('#sortable1').css('background-color','#B8B8B8');
    			if($('#sortable2').length == 0)
    			{
    				$('#sortable1').width(1000);
    				$('#sortable1').attr('class','content-pane-vertical vertical sortable');
    				$('#newsletter').append($('<ul id="sortable2" style="width: 500px; background-color:#C0C0C0" class="content-pane centro-cc sortable"></ul>'));
    				$( "#sortable2" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable2" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    				$('#newsletter').append($('<ul id="sortable3" style="width: 500px; background-color:#CcCcCc" class="content-pane centro-cc sortable"></ul>'));
    				$( "#sortable3" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable3" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    				$('#newsletter').append($('<ul id="sortable4" style="width: 1000px; background-color:#B8B8B8" class="content-pane-vertical vertical-down sortable"></ul>'));
    				$( "#sortable4" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable4" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    			}
    			else if($('#sortable3').length == 0)
    			{
    				$('#sortable1').width(1000);
    				$('#sortable1').attr('class','content-pane-vertical vertical sortable');
    				$('#sortable2').width(500);
    				$('#sortable2').attr('class','content-pane centro-cc sortable');
    				$('#newsletter').append($('<ul id="sortable3" style="width: 500px; background-color:#C0C0C0" class="content-pane centro-cc sortable"></ul>'));
    				$( "#sortable3" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable3" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    				$('#newsletter').append($('<ul id="sortable4" style="width: 1000px; background-color:#B8B8B8" class="content-pane-vertical vertical-down sortable"></ul>'));
    				$( "#sortable4" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable4" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    			}	
    			else{
    				$('#sortable1').width(1000);
    				$('#sortable1').attr('class','content-pane-vertical vertical sortable');
    				$('#sortable1').css('background-color','#B8B8B8');
    				$('#sortable2').width(500);
    				$('#sortable2').attr('class','content-pane centro-cc sortable');
    				$('#sortable2').css('background-color','#CcCcCc');
    				$('#sortable3').width(500);
    				$('#sortable3').attr('class','content-pane centro-cc sortable');
    				$('#sortable3').css('background-color','#C0C0C0');
    				$('#newsletter').append($('<ul id="sortable4" style="width: 1000px; background-color:#B8B8B8" class="content-pane-vertical vertical-down sortable"></ul>'));
    				$( "#sortable4" ).sortable({
    					revert: true,
    					update: addXbuttons
    				});
    				$( "#sortable4" ).sortable({
    					connectWith: ".sortable"
    				}).disableSelection();
    			}
    			Enlong();
    			Modo = 'CC';
    			Limpiar();
    		}	
    	}
    });
    
  });
  function guardarNewsletter(enviado) {
    newsletter = $('#newsletter').clone();
    if(Modo == 'CC')
    {
    	var styles = '<style>#newsletter{margin-bottom:100px;display:inline-block;margin-left:20%;marin-right:20%;border: 1px solid black;background-color:#E8E8E8;box-shadow: 20px 10px 0px 0px rgba(0, 0, 0, 1);}#sortable4{margin-top:0px!important;clear:both;position:relative;}#sortable1>li,#sortable4>li{margin-left:30px;}#sortable1,#sortable4{padding:1px;width:1078px !important;}#sortable3,#sortable2{float:left;}img{margin-top:5px;}#sortable1>li>div>p>a>img,#sortable4>li>div>p>a>img{width:100%;}body{background-color:#999;font-family: Arial, Helvetica, sans-serif;}.sortable{background-color:#E8E8E8 !important;margin-right:0px;} ul{display:block;margin:0px;}li:hover{box-shadow: 0 0 5px 5px #888;} li{-webkit-transition: all 1s ease-in-out;margin-bottom:25px;padding:10px;background-color:#E8E8E8;display:block;margin-top:25px;margin-right:35px;}.node-title a,h1{text-decoration:none;color:#555555;font-weight:bold;font-size:20px;}a:visited{color:#555555;} .node-body,p{margin-top:10px;color:#555555;font-size:13px;} vertical{width:1084px;}</style>';
    }
    else
    {
    	var styles = '<style>#newsletter{margin-bottom:100px;display:inline-block;margin-left:20%;marin-right:20%;border: 1px solid black;background-color:#E8E8E8;box-shadow: 20px 10px 0px 0px rgba(0, 0, 0, 1);}img{margin-top:5px;}body{background-color:#999;font-family: Arial, Helvetica, sans-serif;}.sortable{background-color:#E8E8E8 !important;margin-right:0px;} ul{display:block;float:left;}li:hover{box-shadow: 0 0 5px 5px #888;} li{-webkit-transition: all 1s ease-in-out;padding:10px;background-color:#E8E8E8;display:block;margin-top:25px;margin-right:auto;margin-right:35px;}.node-title a,h1{text-decoration:none;color:#555555;font-weight:bold;font-size:20px;}a:visited{color:#555555;} .node-body,p{margin-top:10px;color:#555555;font-size:13px;} vertical{width:1000px;}p{font-size:13px;}</style>';
    }
    var html = $(newsletter).html();
    var plantilla = '<div id="modo" modo='+Modo+' style="visible:none"></div>';
    data = {
      id: document.getElementById('id').value, 
      subject: document.getElementById('subject').value,
      from: 'newsletter@portalesmunicipales.es',
      content: styles+html+plantilla,
      recipients: document.getElementById('destinatario').value,
    }
	  console.log("data %o",data);
    if(!enviado)
    jQuery.post('/portales7/newsletter/save', data, saveNewsletterCallback);///portales7/newsletter/save
    else if(enviado)
    jQuery.post('/portales7/newsletter/save/true', data, saveNewsletterCallback);
  }
  function saveNewsletterCallback(data, textStatus, jqXHR) {
	  console.log("data %o",data);
    if (data.status == 1) {
      text = 'El boletín se ha guardado correctamente.<br>ID: ' + data.id;
    }
    else if (data.status == 2) {
      text = 'El boletín se ha actualizado correctamente.<br>ID: ' + data.id;
    }
    else {
      text = 'Se ha producido un error al guardar el boletín.<br>Code: ' + data.status;
    }
    jQuery('<div>', {
        html: text
      }).dialog({modal: true});
    document.getElementById('id').value = data.id;
  }
  function VistaPrevia(){
	    var newsletter = $('#newsletter-container').clone();
	    newsletter.find('.boton-borrar').remove();
	    var w = window.open();
	    var html = $(newsletter).html();
	    if(Modo == 'CC')
	    {
	    	var styles = '<style>#newsletter{margin-bottom:100px;display:inline-block;margin-left:20%;marin-right:20%;border: 1px solid black;background-color:#E8E8E8;box-shadow: 20px 10px 0px 0px rgba(0, 0, 0, 1);}#sortable4{margin-top:0px!important;clear:both;position:relative;}#sortable1>li,#sortable4>li{margin-left:30px;}#sortable1,#sortable4{padding:1px;width:1078px !important;}#sortable3,#sortable2{float:left;}img{margin-top:5px;}#sortable1>li>div>p>a>img,#sortable4>li>div>p>a>img{width:100%;}body{background-color:#999;font-family: Arial, Helvetica, sans-serif;}.sortable{background-color:#E8E8E8 !important;margin-right:0px;} ul{display:block;margin:0px;}li:hover{box-shadow: 0 0 5px 5px #888;} li{-webkit-transition: all 1s ease-in-out;margin-bottom:25px;padding:10px;background-color:#E8E8E8;display:block;margin-top:25px;margin-right:35px;}.node-title a,h1{text-decoration:none;color:#555555;font-weight:bold;font-size:20px;}a:visited{color:#555555;} .node-body,p{margin-top:10px;color:#555555;font-size:13px;} vertical{width:1084px;}</style>';
	    }
	    else
	    {
	    	var styles = '<style>#newsletter{margin-bottom:100px;display:inline-block;margin-left:20%;marin-right:20%;border: 1px solid black;background-color:#E8E8E8;box-shadow: 20px 10px 0px 0px rgba(0, 0, 0, 1);}img{margin-top:5px;}body{background-color:#999;font-family: Arial, Helvetica, sans-serif;}.sortable{background-color:#E8E8E8 !important;margin-right:0px;} ul{display:block;float:left;}li:hover{box-shadow: 0 0 5px 5px #888;} li{-webkit-transition: all 1s ease-in-out;padding:10px;background-color:#E8E8E8;display:block;margin-top:25px;margin-right:auto;margin-right:35px;}.node-title a,h1{text-decoration:none;color:#555555;font-weight:bold;font-size:20px;}a:visited{color:#555555;} .node-body,p{margin-top:10px;color:#555555;font-size:13px;} vertical{width:1000px;}p{font-size:13px;}</style>';
	    }
	    w.document.writeln(styles+html);
  }
  function Enviar(){
	    newsletter = $('#newsletter-container').clone();
	    newsletter.find('.boton-borrar').remove();
	    if(Modo == 'CC')
	    {
	    	var styles = '<style>#newsletter{margin-bottom:100px;display:inline-block;margin-left:20%;marin-right:20%;border: 1px solid black;background-color:#E8E8E8;box-shadow: 20px 10px 0px 0px rgba(0, 0, 0, 1);}#sortable4{margin-top:0px!important;clear:both;position:relative;}#sortable1>li,#sortable4>li{margin-left:30px;}#sortable1,#sortable4{padding:1px;width:1078px !important;}#sortable3,#sortable2{float:left;}img{margin-top:5px;}#sortable1>li>div>p>a>img,#sortable4>li>div>p>a>img{width:100%;}body{background-color:#999;font-family: Arial, Helvetica, sans-serif;}.sortable{background-color:#E8E8E8 !important;margin-right:0px;} ul{display:block;margin:0px;}li:hover{box-shadow: 0 0 5px 5px #888;} li{-webkit-transition: all 1s ease-in-out;margin-bottom:25px;padding:10px;background-color:#E8E8E8;display:block;margin-top:25px;margin-right:35px;}.node-title a,h1{text-decoration:none;color:#555555;font-weight:bold;font-size:20px;}a:visited{color:#555555;} .node-body,p{margin-top:10px;color:#555555;font-size:13px;} vertical{width:1084px;}</style>';
	    }
	    else
	    {
	    	var styles = '<style>#newsletter{margin-bottom:100px;display:inline-block;margin-left:20%;marin-right:20%;border: 1px solid black;background-color:#E8E8E8;box-shadow: 20px 10px 0px 0px rgba(0, 0, 0, 1);}img{margin-top:5px;}body{background-color:#999;font-family: Arial, Helvetica, sans-serif;}.sortable{background-color:#E8E8E8 !important;margin-right:0px;} ul{display:block;float:left;}li:hover{box-shadow: 0 0 5px 5px #888;} li{-webkit-transition: all 1s ease-in-out;padding:10px;background-color:#E8E8E8;display:block;margin-top:25px;margin-right:auto;margin-right:35px;}.node-title a,h1{text-decoration:none;color:#555555;font-weight:bold;font-size:20px;}a:visited{color:#555555;} .node-body,p{margin-top:10px;color:#555555;font-size:13px;} vertical{width:1000px;}p{font-size:13px;}</style>';
	    }
	    var html = $(newsletter).html();
	    //var compost = styles+html;
	    data = {
	      subject: document.getElementById('subject').value,
	      from: 'newsletter@portalesmunicipales.es',
	      body: '<html><head>'+styles+'</head><body>' +html+ '</body></html>',
	      email: document.getElementById('destinatario').value,
	    }
	    $.post('http://desarrollo.digitalvalue.es/1000webs/cgi-bin/email-content.cgi', data, function (data, textStatus){
	      $('#result').html(data);
	    });
	    guardarNewsletter(true);
  }
  
  function refreshCustomElements(){
    customElements = jQuery.getJSON('/portales7/newsletter/custom/get', refreshCustomElementsProcess);//http://desarrollo.digitalvalue.es/portales7/newsletter/custom/get
  }

  function refreshCustomElementsProcess(data) {
    var items = [];
    $.each(data, function (key, customElement) {
      console.log("%s", customElement.content);
      output = '<li class="draggable ui-state-default noticia-listado"><div id='+data[key].id+' class="custom-content"><button id="x-custom" onclick="removeCustoms(this)">X</button>' + customElement.content + '</div></li>';
      items.push(output);
    });
    $('#custom-contents').html(items.join(''));
    $( '#custom-contents .draggable' ).draggable({//conflicto con boletines ya guardados
      connectToSortable: '.sortable',
      helper: "clone",
      revert: false,
      tolerance: "pointer",
      appendTo: "body",
    }).uniqueId();
  }
  function removeCustoms(data)
  {
	  $('body').append($('<div id="dialog-remove" title="Confirmar Borrado"><p>Realmente desea borrar este contenido?</p></div>'))
	  $( "#dialog-remove" ).dialog({
	      resizable: false,
	      height:150,
	      modal: true,
	      buttons: {
	        "Borrar": function() {
	          $(data).parent().parent().remove();
	          jQuery.getJSON('/portales7/newsletter/custom/get',removeCustomJSON);
	          function removeCustomJSON(dato)
	          {
	        	  $.each(dato, function(key){
	        		  if($(data).parent().attr('id') == dato[key].id)
	        		  {
	        			  jQuery.post('/portales7/newsletter/custom/delete/'+dato[key].id+'');
	        			  refreshCustomElements();
	        		  }	  
	        	  }); 
	          }
	          $( this ).dialog( "close" );
	        },
	        Cancel: function() {
	          $( this ).dialog( "close" );
	        }
	      }
	    });
  }
  function removeTempCustoms(data)
  {
	  $(data).parent().remove();
  }
  function saveCustomContent(data, textStatus, jqXHR) {
    if (data.status == 1) {
      jQuery('<div>', {
        html: 'El contenido personalizado se ha guardado correctamente.'
      }).dialog({modal: true});
    }
    addCustomText(event);
  }

function addXbuttons(event, ui) {
	ui.item.find('#x-custom').remove();
  if (ui.item.hasClass('noticia-listado')) {
    ui.item.uniqueId();
    ui.item.removeClass('noticia-listado');
    boton = jQuery('<button>', {
        text: 'X',
        class: 'boton-borrar',
        click: function(event) {
          jQuery(event.currentTarget.parentElement).remove();
          Enlong();
        }
    });
    boton2 = jQuery('<button>', {
        text: 'X',
        class: 'boton-borrar',
        click: function(event) {
          jQuery(event.currentTarget.parentElement).remove();
          Enlong();
        }
    });
    ui.item.prepend(boton2);
    ui.item.find('.node-content').find('div').prepend(boton);
  }
  Enlong();
}
function addCustomText(){
	$('#temp-custom').append($('<li class="draggable ui-state-default noticia-listado"><button id="x-custom" onclick="removeTempCustoms(this)">X</button>'+CKEDITOR.instances.texto_personalizado.getData()+'</li>'));
    $( ".draggable" ).draggable({
      connectToSortable: '.sortable',
      helper: "clone",
      revert: false,
      tolerance: "pointer",
      appendTo: "body",
      scroll:"false",
    }).uniqueId();
}
function Limpiar()
{
	$('#sortable1').empty();
	$('#sortable2').empty();
	$('#sortable3').empty();
	$('#sortable4').empty();
	if(Modo == 'TC'||Modo == 'DC')
	{
		$('#sortable1').height(810);
		$('#sortable2').height(810);
		$('#sortable3').height(810);
	}
	else if(Modo == 'CC')
	{
		$('#sortable1').height(270);
		$('#sortable2').height(270);
		$('#sortable3').height(270);
		$('#sortable4').height(270);
	}	
	else if(Modo == 'V')
	{
		$('#sortable1').height(810);
	}
	}
$(function() {//conecta los sortables para que puedan compartir draggables
    $( "#sortable1, #sortable2, #temp-custom" ).sortable({
      connectWith: ".sortable"
    }).disableSelection();
  });
function Enlong()//mantiene los tamaños de las sortables
{
	$("#sortable1 .draggable").each(function(){Sortable1H = Sortable1H+20 + $(this).innerHeight();});
	$("#sortable2 .draggable").each(function(){Sortable2H = Sortable2H+20 + $(this).innerHeight();});
	$("#sortable3 .draggable").each(function(){Sortable3H = Sortable3H+20 + $(this).innerHeight();});
	$("#sortable4 .draggable").each(function(){Sortable4H = Sortable4H+20 + $(this).innerHeight();});
	if(Modo == 'V')
	{
		$("#sortable1").height(Sortable1H + 60);
	}	
	else if(Modo != 'CC' && Modo != 'V')
	{	
		if(Sortable1H > Sortable2H && Sortable1H > Sortable3H)
		{
			$("#sortable1").height(Sortable1H + 60);
			$("#sortable2").height(Sortable1H + 60);
			$("#sortable3").height(Sortable1H + 60);
		}
		else if(Sortable2H > Sortable1H && Sortable2H > Sortable3H)
		{
			$("#sortable1").height(Sortable2H + 60);
			$("#sortable2").height(Sortable2H + 60);
			$("#sortable3").height(Sortable2H + 60);
		}
		else if(Sortable3H > Sortable1H && Sortable3H > Sortable2H)
		{
			$("#sortable1").height(Sortable3H + 60);
			$("#sortable2").height(Sortable3H + 60);
			$("#sortable3").height(Sortable3H + 60);
		}
	}
	else if(Modo = 'CC'){
			$('#sortable1').height(Sortable1H + 60);
			$('#sortable4').height(Sortable4H + 60);
			if(Sortable2H > Sortable3H)
			{
				$("#sortable2").height(Sortable2H + 60);
				$("#sortable3").height(Sortable2H + 60);
			}
			else if(Sortable3H > Sortable2H)
			{
				$("#sortable2").height(Sortable3H + 60);
				$("#sortable3").height(Sortable3H + 60);
			}
		}
		Sortable1H = 0;
		Sortable2H = 0;
		Sortable3H = 0;
		Sortable4H = 0;
}
