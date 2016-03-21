(function ($) {
  Drupal.behaviors.dvtaxonomy_accordion = {
    attach: function (context) {
      if (context == '#cboxLoadedContent') return;
      var activePane;
      $( ".dvtaxonomy-accordion" ).find('a.active').first().each(function (index, element) {
        activePane = jQuery(this).data('activepanel');
      });
      $( ".dvtaxonomy-accordion" ).accordion({
        header: "div.dvtaxonomy-depth-0",
        active: activePane,
        beforeActivate: function( event, ui) {
          if (ui.newHeader != 'undefined') {
            ui.newHeader.find('a').first().each(function (index, element) {
              if (element.href != 'undefined') {
                document.location = element.href;
                $('.transparencia-dreta').html('<img src="/sites/all/modules/dvtoolbox/images/spinner.gif" style="widht:100%">');
              }
            });
          }
        }
      });
    }
  };
})(jQuery);
