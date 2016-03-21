(function ($) {
  Drupal.behaviors.portales7_cclb_map = {
    attach: function (context) {
      //$(".portales7-map-container").each(function(index,item){$(this).hide();});
      $(".google_map_field_display").each(function(index,item){
        $(this).css('height', Drupal.settings.portales7_map.height).css('width', Drupal.settings.portales7_map.width);
      });
      $(".portales7-map-switch").each(function(index, item) {
        $(this).addClass('clickable');
        $(this).click(function() {
          $(".portales7-map-container").each(function(index,item){
            if ($(this).css('width') == '0px') {
              $(".portales7-map-switch").html("Ocultar mapa");
              $(this).show().animate({width: Drupal.settings.portales7_map.width, height: Drupal.settings.portales7_map.height});
            }
            else {
              $(".portales7-map-switch").html("Mostrar mapa");
              $(this).animate({width: '0px', height: '0px'});
            }
          });
        });
      });
    }
  };
})(jQuery);
