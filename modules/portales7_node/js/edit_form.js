(function ($) {
  Drupal.behaviors.portales7_node_edit_form = {
    attach: function (context) {
      if (Drupal.settings.portales7_node_edit_form == undefined) {
        Drupal.settings.portales7_node_edit_form = 1;
        $('#edit-actions').clone().prependTo($('#portales7-node-node-form:first-child'));
      }
    }
  };
})(jQuery);
