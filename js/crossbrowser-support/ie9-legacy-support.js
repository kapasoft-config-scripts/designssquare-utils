

if (!window.DS_LIB_LEGACY) {
    /**
     * @singleton
     */
    window.DS_LIB_LEGACY = (function ($) {

        //private variables come here...
        var $log_on = false;

        //private function to initiate your widget
        var _fix_images = function (target) {
            $(window.document).ready(function ($) {
                //add size the height
                if($log_on){console.log('DS_LIB_LEGACY.target : ' + target)}

                $(target).each(function () {
                    $(this).load(function() {
                        var $height = $(this).height();
                        if($log_on){console.log('DS_LIB_LEGACY.height : ' + $height)}
                        var $width = $(this).width();
                        if($log_on){console.log('DS_LIB_LEGACY.width : ' + $width)}
                        $(this).css('height', $height + 'px');
                        $(this).css('width', $width + 'px');
                    });
                });
            });
        }

        //public interface...the API for your widget
        return {
            init: function(target){//public function called to initialize widget
                _fix_images(target);
            },
            turnOnDebug: function () {//public function to turn on logging
                $log_on = true;
            }
        }
    })(jQuery);
}