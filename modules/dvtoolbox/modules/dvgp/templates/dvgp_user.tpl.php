<div class="dvgp">
<?php if ($userId) { ?>
<div class='dvgp-logged'>
<img class="dvgp_picture" src="<?php print $picture;?>" />
<span class="name"><?php print $name;?></span>
<span class="link">
<?php print l($icon_tag . '&nbsp;' . t('Logout'), 'dvgp/logout', array('html' => TRUE, 'query' => array('destination' => $_GET['q'])));?>
</span>
</div>
<?php
} else {
  print theme('dvgp_login_button', array('style_name' => $style_name)); 
}
?>
</div>