(function ($) {
  Drupal.behaviors.dvtoolbox_multiple_filter = {
    attach: function (context) {
      list = jQuery('<div />', {id: "select-menu-list"});
      //$(".portales7-map-container").each(function(index,item){$(this).hide();});
      $("#edit-field-transp-category-tid").find('option').each(function(index,item){       
       option = jQuery('<div/>', {"text" : item.text, "value" : item.value, 'data-value' : item.value});
       if (item) {
         if (item.selected) {
           option.addClass('item-selected');
         }
         else {
           option.click(function(event){
             console.log("%o", jQuery(this));
             console.log("clicked %s", jQuery(this).attr('data-value'));
             $("#edit-field-transp-category-tid option").each(function (index, item) { jQuery(this).attr('selected', false);});
             $("#edit-field-transp-category-tid option[value='" +  jQuery(this).attr('data-value') + "']").each(function (index, item) { jQuery(this).attr('selected', 'selected');});
             $('#views-exposed-form-transparencia-contenido-panel-pane-1').submit();
           });
         }
       }
       list.append(option);
      });
      list.appendTo($("#edit-field-transp-category-tid").parent());
      //console.log("list %o", list);
      $("#edit-field-transp-category-tid").hide();
    }
  };
})(jQuery);
