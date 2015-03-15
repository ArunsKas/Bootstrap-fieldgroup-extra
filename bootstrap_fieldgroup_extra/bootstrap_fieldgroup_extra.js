(function($) {
	
/**
 * Behaviors.
 */  
Drupal.behaviors.BootstrapFieldgroupExtra = {
  attach: function (context, settings) {
    /* Automagically jump on good tab based on anchor; for page reloads or links */
    if(location.hash) {
    $('a[href=' + location.hash + ']').tab('show');
    }
   
    /* Update hash based on tab, basically restores browser default behavior to
     fix bootstrap tabs */
    $(document.body).on("click", "a[data-toggle]", function(event) {
    location.hash = this.getAttribute("href");
    });
  
    $(window).on('popstate', function() {
      var anchor = location.hash || $("a[data-toggle=tab]").first().attr("href");
      $('a[href=' + anchor + ']').tab('show');
    });
  }
}
})(jQuery);