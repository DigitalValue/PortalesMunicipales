(function ($) {
  Drupal.behaviors.dvtoolbox_multiple_filter = {
    attach: function (context) {
      list = jQuery('<div />', {id: "multiple-filter-list"});
      //$(".portales7-map-container").each(function(index,item){$(this).hide();});
      $("#edit-field-transp-category-tid").find('option').each(function(index,item){       
       option = jQuery('<div/>', {"text" : item.text, "value" : item.value, 'data-value' : item.value});
       close = '';
       if (item) {
         if (item.selected) {
           option.addClass('item-selected');
           close = jQuery('<div/>', {"text" : "X", "class" : "deselect-button", 'data-value' : item.value});
           close.click(function(event){
             $("#edit-field-transp-category-tid option[value='" +  jQuery(this).attr('data-value') + "']").each(function (index, item) { jQuery(this).attr('selected', '');});
             //$('#views-exposed-form-transparencia-contenido-panel-pane-1').submit();
           });
           //console.log("%s selected", item.text);
         }
         else {
           option.click(function(event){
             console.log("%o", jQuery(this));
             console.log("clicked %s", jQuery(this).attr('data-value'));
             $("#edit-field-transp-category-tid option[value='" +  jQuery(this).attr('data-value') + "']").each(function (index, item) { jQuery(this).attr('selected', 'selected');});
             $('#views-exposed-form-transparencia-contenido-panel-pane-1').submit();
           });
           //console.log("%s not selected", item.text);
         }
       }
       else {
          //console.log("%s not jquery", item.text);
       }
       wrapper = jQuery('<div/>', {"class" : "option-wraper"}).append(option).append(close);
       list.append(wrapper);
      });
      list.appendTo($("#edit-field-transp-category-tid").parent());
      console.log("list %o", list);
    }
  };
})(jQuery);
