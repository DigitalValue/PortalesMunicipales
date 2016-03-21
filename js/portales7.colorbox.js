(function ($) {
  Drupal.behaviors.portales7_colorbox_youtube = {
    attach: function (context) {
      $(".colorbox-iframe").each(function () { this.colorbox({iframe:true, innerWidth:640, innerHeight:390});});
      $(".colorbox-640x390").each(function () { this.colorbox({innerWidth:640, innerHeight:390});});
    }
  };
})(jQuery);
