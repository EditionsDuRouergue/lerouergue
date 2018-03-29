(function ($) {
  // Sanity check because sometimes we might be included on a page with jQuery
  // < 1.7, in which case Magnific Popup's use of $().on/$().off will blow up.
  if (!("off" in $.fn)) {
    if (window.console) {
      console.log('Magnific Popup disabled: legacy jQuery detected (no "off" method).');
    }
    return;
  }
  Drupal.settings.magnific_popup = Drupal.settings.magnific_popup || {};
  Drupal.settings.magnific_popup_api = Drupal.settings.magnific_popup_api || {};
  Drupal.settings.magnific_popup.common_options = {
    disableOn: 300,
    mainClass: 'mfp-fade',
    removalDelay: 160,
    preloader: false,
    fixedContentPos: 'auto'
  };
  var youtube_id = function (url) {
    // Get video ID and extra params (if they exist). Sometimes the order of
    // parameters in "/watch?"-style URLs can change, so allow "v=" to appear
    // anywhere.
    // Example URLs:
    //  http://www.youtube.com/watch?v=VIDEOID&t=60&list=PLAYLISTID
    //  https://www.youtube.com/v/VIDEOID?t=60&list=PLAYLISTID
    //  https://www.youtube.com/embed/VIDEOID?t=60&list=PLAYLISTID
    //  https://youtu.be/VIDEOID?t=60&list=PLAYLISTID
    var video_ID = /(youtu\.be\/|youtube\.com\/(embed|v)\/|watch\?v=|watch\?.*&v=)([a-zA-Z0-9_-]+)/.exec(url);
    if (!video_ID || !video_ID.length || typeof video_ID[3] === 'undefined') {
      return false;
    }
    var video_params_test = /\?+(.+)/.exec(url), video_params = '';
    if (!!video_params_test && typeof video_params_test[1] !== 'undefined') {
      video_params = '&' + video_params_test[1];
      // Remove redundant video param, if it exists.
      video_params = video_params.replace(/&v=.*?(?=$|&)/gi, '');
      // Remove autoplay param, if it exists.
      video_params = video_params.replace(/&autoplay=.*?(?=$|&)/gi, '');
      // Convert "t"/"time_continue" to "start" param.
      video_params = video_params.replace(/&(t|time_continue)=/gi, '&start=');
      // Adjust "start" param; the YT share GUI generates URLs like ?t=1h2m3s
      // but the embed endpoint requires time in seconds with no units or text
      // chars of any kind.
      var start_times = /&start=((\d+h)?(\d+m)?(\d+s)?)/i.exec(video_params);
      if (start_times && start_times.length && start_times[1] !== '') {
        var time = 0;
        for (var i = 2; i < start_times.length; ++i) {
          if (typeof start_times[i] !== 'undefined') {
            time += parseInt(start_times[i]) * Math.pow(60, 4 - i);
          }
        }
        video_params = video_params.replace(/&start=.*?(?=$|&)/gi, '&start=' + time);
      }
    }
    return video_ID[3] + '?autoplay=1' + video_params;
  };
  Drupal.settings.magnific_popup.common_options_iframe = {
    type: 'iframe',
    iframe: {
      markup: '<div class="mfp-iframe-scaler"><div class="mfp-close"></div><iframe class="mfp-iframe" id="mfp-iframe" frameborder="0" seamless="seamless" allowfullscreen="allowfullscreen"></iframe></div>',
      patterns: {
        youtube_short: {
          index: 'youtu.be/',
          id: youtube_id,
          src: '//www.youtube.com/embed/%id%'
        },
        // To override the default "youtube" handler, we need to name ours the
        // same.
        youtube: {
          index: 'www.youtube.com/',
          id: youtube_id,
          src: '//www.youtube.com/embed/%id%'
        }
      }
    }
  };
  Drupal.behaviors.magnific_popup = {
    attach: function (context, settings) {
      settings.magnific_popup = settings.magnific_popup || {
          common_options: {},
          common_options_iframe: {}
        };
      var common_options = settings.magnific_popup.common_options || {};
      var common_options_iframe = settings.magnific_popup.common_options_iframe || {};
      // Allow modules to extend the set of patterns we support via iframe.
      if (settings.magnific_popup_api && settings.magnific_popup_api.iframe_patterns) {
        jQuery.extend(settings.magnific_popup.common_options_iframe.iframe.patterns, settings.magnific_popup_api.iframe_patterns);
        // There are some bugs around the delete operator, so make sure we never
        // double-up on iframe patterns.
        settings.magnific_popup_api.iframe_patterns = {};
        // Attempt to delete the iframe patterns from our settings object.
        delete settings.magnific_popup_api.iframe_patterns;
      }
      var common_options_image = {
        type: 'image',
        image: {
          titleSrc: function (item) {
            return $('img.mfp-thumbnail,span.mfp-title', item.el).attr('title') || '';
          }
        }
      };
      var common_options_gallery = {
        gallery: {enabled: true},
        delegate: 'a'
      };
      // Instantiate no-gallery, images.
      var options = {};
      $.extend(options, common_options, common_options_image);
      $('.mfp-nogallery-image .mfp-item', context).once('magnific_popup').magnificPopup(options);
      // Instantiate no-gallery, iframes.
      options = {};
      $.extend(options, common_options, common_options_iframe);
      $('.mfp-nogallery-iframe .mfp-item', context).once('magnific_popup').magnificPopup(options);
      // Instantiate galleries, images.
      options = {};
      $.extend(options, common_options, common_options_image, common_options_gallery);
      $('.mfp-gallery-image', context).once('magnific_popup').each(function (el, i) {
        $(this).magnificPopup(options);
      });
      // Instantiate galleries, iframes.
      options = {};
      $.extend(options, common_options, common_options_iframe, common_options_gallery);
      $('.mfp-gallery-iframe', context).once('magnific_popup').each(function (el, i) {
        $(this).magnificPopup(options);
      });
    }
  }
})(jQuery);
