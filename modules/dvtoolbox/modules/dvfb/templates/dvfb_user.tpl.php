<div class="dvfb">
<?php if ($userId) { ?>
<div class='dvfb-logged'>
<img class="dvfb_picture" src="https://graph.facebook.com/<?php print $userId;?>/picture" />
<span class="name"><?php print $name;?></span>
<span class="link">
<?php print l($icon_tag . '&nbsp;' . t('Logout'), 'dvfb/logout', array('html' => TRUE, 'query' => array('destination' => $_GET['q'])));?>
</span>
</div>
<?php
} else {
  print theme('dvfb_login_button', array('style_name' => $style_name));
}
?>
</div>