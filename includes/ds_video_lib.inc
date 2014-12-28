<?php



/**
 * retrieves and construct video output from node with particular field as parameter
 * @return
 *      video output in html
 */
function construct_video($node, $format_name, $field_name = 'field_video_file')
{
    $video_output = array();
    $video_intance = $node->$field_name;
    if (!empty($video_intance['und'][0])) {
        $video_settings = _videojs_settings($format_name);
        //video file
        $video_render_array = field_view_field(
            'node',
            $node,
            'field_video_file',
            array(
                'type' => 'videojs',
                'label' => 'hidden',
                'settings' => $video_settings,
            )
        );

        if ($video_settings['width'] == 1) {
            $video_render_array[0]['#attributes']['width'] = '100%';
        }

        $video_output = $video_render_array;
    }
    return $video_output;
}

function construct_vimeo($node, $format_name, $field_name = 'field_video_id')
{
    $vimeo_output = array();
    $vimeo_instance = $node->$field_name;
    if (!empty($vimeo_instance[LANGUAGE_NONE][0]['value'])) {
        //vimeo video
        $vimeo_frame_size = _vimeo_settings($format_name);
        if ($vimeo_frame_size['width'] == 1 || $vimeo_frame_size['height'] == 1) {
            $vimeo_output = '<iframe src="http://player.vimeo.com/video/' . $node->field_video_id[LANGUAGE_NONE][0]['value'] . '?badge=0" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        } else {
            $vimeo_output = '<iframe src="http://player.vimeo.com/video/' . $node->field_video_id[LANGUAGE_NONE][0]['value'] . '?badge=0" width="' . $vimeo_frame_size['width'] . 'px" height="' . $vimeo_frame_size['height'] . 'px" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        }
    }

    return $vimeo_output;
}

/*****SETTINGS********/
function _videojs_settings($post_format)
{
    switch ($post_format) {
        case 'slider':
            $video_style = image_style_load('ds_blog_video_post_slider');
            if(empty($video_style)){
                $width = '570';
                $height = '330';
            }else{
                $thumb_effect = array_shift($video_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Big':
            $video_style = image_style_load('ds_blog_video_post_big');
            if(empty($video_style)){
                $width = '780';
                $height = '468';
            }else{
                $thumb_effect = array_shift($video_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Small':
            $video_style = image_style_load('ds_blog_video_post_small');
            if(empty($video_style)){
                $width = '370';
                $height = '222';
            }else{
                $thumb_effect = array_shift($video_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        default:
            $width = '200';
            $height = '200';
    }

    return array(
        'width' => $width,
        'height' => $height,
        'posterimage_field' => NULL,
        'posterimage_style' => NULL,
    );
}

function _vimeo_settings($post_format)
{
    switch ($post_format) {
        case 'slider':
            $vimeo_style = image_style_load('ds_blog_vimeo_post_slider');
            if(empty($vimeo_style)){
                $width = '320';
                $height = '240';
            }else{
                $thumb_effect = array_shift($vimeo_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Big':
            $vimeo_style = image_style_load('ds_blog_vimeo_post_big');
            if(empty($vimeo_style)){
                $width = '624';
                $height = '468';
            }else{
                $thumb_effect = array_shift($vimeo_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Small':
            $vimeo_style = image_style_load('ds_blog_vimeo_post_small');
            if(empty($vimeo_style)){
                $width = '200';
                $height = '150';
            }else{
                $thumb_effect = array_shift($vimeo_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        default:
            $width = '100%';
            $height = '200';
    }

    return array(
        'width' => $width,
        'height' => $height,
    );
}