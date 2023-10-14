$(function(){
     $('section').each(function(){
              $(this).nextUntil(':header').wrapAll("<div class='collapse'></div>");
          });
     $( ".hg-article-body :header" ).wrap( "<div class='expand'></div>" );


    $('.expand').next('.collapse').addClass('collapse-indent');;
    $('.expand').find(':header').prepend('<i class="fa fa-plus-circle"></i>');
 
    $('.expand').on('click', function(){
      $(this).find('i').toggleClass('fa-minus-circle').toggleClass('fa-plus-circle');
      $(this).next('.collapse', ".open").slideUp();
      $(this).next('.collapse').not(".open").slideDown();
      $(this).next('.collapse').toggleClass('open');
    });
});

    $(function(){
        if(!window.collapseHasRun) {
            window.collapseHasRun = true;
            $('.hg-article-body h3').each(function(){
                $(this).nextUntil('h2, h3').wrapAll("<div class='collapse'></div>");
            });
            $( ".hg-article-body h3" ).wrap( "<div class='expand'></div>" );
            
            $('.expand').next('.collapse').addClass('collapse-indent');
            $('.expand').find(':header').prepend('<i class="fa fa-plus-circle"></i>');
            
            $('.expand').on('click', function(){
                $(this).find('i').toggleClass('fa-minus-circle').toggleClass('fa-plus-circle');
                $(this).next('.collapse', ".open").slideUp();
                $(this).next('.collapse').not(".open").slideDown();
                $(this).next('.collapse').toggleClass('open');
            });
        }
    });

    $(function(){
        if(!window.collapseHasRun) {
            window.collapseHasRun = true;
            $('.hg-article-body h5').each(function(){
                $(this).nextUntil('h2, h3, h4, h5').wrapAll("<div class='collapse'></div>");
            });
            $( ".hg-article-body h5" ).wrap( "<div class='expand'></div>" );
            
            $('.expand').next('.collapse').addClass('collapse-indent');
            $('.expand').find(':header').prepend('<i class="fa fa-plus-circle"></i>');
            
            $('.expand').on('click', function(){
                $(this).find('i').toggleClass('fa-minus-circle').toggleClass('fa-plus-circle');
                $(this).next('.collapse', ".open").slideUp();
                $(this).next('.collapse').not(".open").slideDown();
                $(this).next('.collapse').toggleClass('open');
            });
        }
    });















var sectionHeight = function() {
  var total    = $(window).height(),
      $section = $('section').css('height','auto');

  if ($section.outerHeight(true) < total) {
    var margin = $section.outerHeight(true) - $section.height();
    $section.height(total - margin - 20);
  } else {
    $section.css('height','auto');
  }
}

$(window).resize(sectionHeight);

$(function() {
  $("section h1, section h2, section h3").each(function(){
    $("nav ul").append("<li class='tag-" + this.nodeName.toLowerCase() + "'><a href='#" + $(this).text().toLowerCase().replace(/ /g, '-').replace(/[^\w-]+/g,'') + "'>" + $(this).text() + "</a></li>");
    $(this).attr("id",$(this).text().toLowerCase().replace(/ /g, '-').replace(/[^\w-]+/g,''));
    $("nav ul li:first-child a").parent().addClass("active");
  });

  $("nav ul li").on("click", "a", function(event) {
    var position = $($(this).attr("href")).offset().top - 190;
    $("html, body").animate({scrollTop: position}, 400);
    $("nav ul li a").parent().removeClass("active");
    $(this).parent().addClass("active");
    event.preventDefault();
  });

  sectionHeight();

  $('img').on('load', sectionHeight);
});
