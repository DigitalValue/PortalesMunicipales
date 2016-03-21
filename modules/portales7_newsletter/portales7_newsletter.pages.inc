<?php
function portales7_newsletter_view($newsletter) {
  //////eliminamos las x de la vista previa////////
  $str = $newsletter->content;
  $str2 = str_replace("<button class=\"boton-borrar\">X</button>","",$str);
  $newsletter->content = "<div id=\"newsletter\">" . $str2 . "</div>";
  /////////////////////////////////////////////////
  return theme('newsletter', array('newsletter' => $newsletter));
}

function portales7_newsletter_generator($newsletter) {
   //////eliminamos el css del newsletter//////////
   $str = $newsletter->content;
   $str2 = str_replace("<style>","<!--",$str);
   $str3 = str_replace("</style>","-->",$str2);
   $newsletter->content = $str3;
   ////////////////////////////////////////////////
   return theme('newsletter-generator', array('newsletter' => $newsletter));
}