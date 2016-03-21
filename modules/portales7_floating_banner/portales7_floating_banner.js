function findPos(obj) {
  var curleft = curtop = 0;
  if (obj.offsetParent) {
    do {
      curleft += obj.offsetLeft;
      curtop += obj.offsetTop;
    } while (obj = obj.offsetParent);
  }
  return [curleft,curtop];
} 

(function ($) {
Drupal.behaviors.portales7_floating_banner = { attach: function(context, settings) {
  start = 174;
  main = findPos(document.getElementById('cuerpo'));
  sk_l_width = $('#skycraper-left').width();
  if (sk_l_width == 0) sk_l_width = 160;
  //content = findPos(document.getElementById('content'));
  current = $(document).scrollTop();
  //$('#skycraper-left').css('top',content[1] - current);
  $('#skycraper-left').css('top', start - current);
  //$('#skycraper-left').css('left',main[0] - 160);
  $('#skycraper-left').css('left',main[0] - sk_l_width);
  //$('#skycraper-right').css('top',content[1] - current);
  $('#skycraper-right').css('top', start - current);
  $('#skycraper-right').css('left',main[0] + $('#cuerpo').width());
  /*$('#main').append('<div id="debuginfo"></div>');
  $('#debuginfo').css('position', 'fixed').css('top',105).css('left',0).css('background-color','white');
  $('#debuginfo').html('skycraper-left.width: '+sk_l_width);
  $('#debuginfo').append('<br/>left: '+ main[0]);
  $('#debuginfo').append('<br/> top: ' + (start-current));
  $('#debuginfo').append('<br/> current: ' + current );
  $('#debuginfo').append('<br /> width: '+$('#skycraper-left').width());*/
  
  $(document).scroll(function (){
    current = $(document).scrollTop();
    if (current > start) {
      $('#skycraper-left').css('top', 0);
      $('#skycraper-right').css('top', 0);
    }
    else {
      //$('#skycraper-left').css('top', coord[1]-current);
      //$('#skycraper-right').css('top', coord[1]-current);
      $('#skycraper-left').css('top', start -current);
      $('#skycraper-right').css('top', start-current);
      main = findPos(document.getElementById('main'));
      /*$('#debuginfo').html('skycraper-left.width: '+sk_l_width);
      $('#debuginfo').append('<br/>left: '+ main[0]);
      $('#debuginfo').append('<br/> top: ' + (start-current));
      $('#debuginfo').append('<br/> current: ' + current );
      $('#debuginfo').append('<br /> width: '+$('#skycraper-left').width());*/
    }
  });
  
}
};
})(jQuery);
