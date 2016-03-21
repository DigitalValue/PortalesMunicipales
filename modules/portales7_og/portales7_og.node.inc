<?php
/* 
 *//**
 * Returns a structured array defining the fields created by this content type.
 *
 * This is factored into this function so it can be used in both
 * portales7_node_install() and portales7_node_uninstall().
 *
 * @return
 *  An associative array specifying the fields we wish to add to our
 *  new node type.
 *
 * @ingroup portales7_node
 */
function _portales7_og_installed_fields() {
  return array(
    'portales7_og_header' => array(
      'field_name' => 'portales7_og_header',
      'type' => 'image',
      'cardinality' => 1,
    ),
  );
}

/**
 * Returns a structured array defining the instances for this content type.
 *
 * The instance lets Drupal know which widget to use to allow the user to enter
 * data and how to react in different view modes.  We are going to display a
 * page that uses a custom "portales7_node_list" view mode.  We will set a
 * cardinality of three allowing our content type to give the user three color
 * fields.
 *
 * This is factored into this function so it can be used in both
 * portales7_node_install() and portales7_node_uninstall().
 *
 * @return
 *  An associative array specifying the instances we wish to add to our new
 *  node type.
 *
 * @ingroup portales7_node
 */
function _portales7_og_installed_instances() {
  return array(
    'portales7_node' => array(
       'og_group_ref' => array(
        'label' => "Grups d'audiència",
        'widget' => array(
          'type' => 'og_complex',
          'module' => 'og',
          'settings' => array(),
          'weight' => 45,
        ),
        'settings' => array(
          'behaviors' => array(
            'og_widget' => array(
              'status' => TRUE,
              'default' => array(
                'widget_type' => 'options_select',
              ),
              'admin' => array(
                'widget_type' => 'entityreference_autocomplete',
              ),
            ),
          ),
        ),
        'view modes' => array(
          'full' => array(
            'label' => 'Complet',
            'type' => 'og_list_default',
            'custom settings' => FALSE,
          ),
          'teaser' => array(
            'label' => 'Resum',
            'type' => 'og_list_default',
            'custom settings' => FALSE,
          ),
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 9,
            'settings' => array(),
          ),
          'link' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 1,
            'settings' => array(),
          ),
          'listado' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 20,
            'settings' => array(),
          ),
          'bim' => array(
            'label' => 'above',
            'type' => 'og_list_default',
            'weight' => 31,
            'settings' => array(),
            'module' => 'og_ui',
          ),
          'vinculo_articulo_completo' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 7,
            'settings' => array(),
          ),
          'vinculo_articulo_resumen' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 4,
            'settings' => array(),
          ),
          'vinculo_articulo_simple' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 3,
            'settings' => array(),
          ),
          'vinculo_articulo_titular' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 2,
            'settings' => array(),
          ),
          'vinculo_elemento_completo' => array(
            'label' => 'above',
            'type' => 'og_list_default',
            'weight' => 31,
            'settings' => array(),
            'module' => 'og_ui',
          ),
          'vinculo_elemento_resumen' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 2,
            'settings' => array(),
          ),
          'vinculo_elemento_titular' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 1,
            'settings' => array(),
          ),
          'vinculo_escaparate_completo' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 4,
            'settings' => array(),
          ),
          'vinculo_escaparate_libre' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 1,
            'settings' => array(),
          ),
          'vinculo_escaparate_resumen' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 3,
            'settings' => array(),
          ),
          'vinculo_escaparate_simple' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 2,
            'settings' => array(),
          ),
          'vinculo_noticia_completo' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 6,
            'settings' => array(),
          ),
          'vinculo_noticia_resumen' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 5,
            'settings' => array(),
          ),
          'vinculo_noticia_simple' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 4,
            'settings' => array(),
          ),
          'vinculo_noticia_titular' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 3,
            'settings' => array(),
          ),
          'galeria' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 21,
            'settings' => array(),
          ),
        ),
      ),
    ),
    'portales7_group' => array(
      'group_group' => array(
        'entity_type' => 'node',
        'bundle' => 'portales7_group',
        'field_name' => 'group_group',
        
        'label'       => 'Grupo',
        'required'  => TRUE,
        'default_value' => 1,
        'widget'      => array(
          'module' => 'options',
          'settings' => array ('og_hide' => TRUE, 'display_label' => 0),
          'type'    => 'options_onoff',
          'weight' => 0,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => 15,
            'settings' => array(),
          ),
        ),
      ),
      'portales7_og_header' => array(
        'entity_type' => 'node',
        'bundle' => 'portales7_group',
        'field_name'  => 'portales7_og_header',
        'label'       => 'Imagen de cabecera',
        'description' => 'Esta imagen se utilizará como cabecera en los contenidos del miniportal.',
        'required'    => FALSE,
        'widget' => array(
          'type'    => 'image_image',
          'weight'  => 1,
          'settings' => array (
            'filefield_sources' => array (
              'filefield_sources' => array (
                'plupload' => 'plupload',
                'imce' => 'imce',
              ),
              'source_imce' => array (
                'imce_mode' => 1,
              ),
              'source_reference' => array (
                'autocomplete' => 0,
              ),
            ),
            'imce_filefield_on' => 0,
          ),
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'image',
            'weight' => 0,
            'settings' => array (
                    'image_style' => '',
                    'image_link' => '',
                ),
            'module' => 'image',
          ),
        ),
        'settings' => array(
          'file_directory' => 'imagenes/cabeceras/[current-date:custom:Ym]',
          'file_extensions' => 'png jpg jpeg gif tiff',
          'max_filesize' => '1MB',
          'alt_field' => 1,
          'title_field' => 1,
        ),
      ),
    ),
  );
}
