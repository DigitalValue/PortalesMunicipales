function callView(url) {

var results = $("#results");
results.html('');

$.ajax({
url: url,
dataType:'json',
success: function(data) {
$.each(data.nodes, function(i,node){
results.append("...");
})
pager(data,url);
},
error: function () {
results.html("Error");
}
});

}

function pager(data,url) {

	url = url.split('?', 1)[0];
	var current = parseInt(data.pager.current);
	var total = parseInt(data.pager.total);

	if (total > 1) {
		if(current == 0) {				
			var pagination = 
				"<li class='pager-current first'>"+(current+1)+"</li>"+	
				"<li class='pager-item'><a class='active' title='Go to page "+(current+2)+"' href='"+url+"?page="+(current+1)+"'>"+(current+2)+"</a></li>"+
				"<li class='pager-item'><a class='active' title='Go to page "+(current+3)+"' href='"+url+"?page="+(current+2)+"'>"+(current+3)+"</a></li>"+							
				"<li class='pager-next'><a class='active' title='Go to next page' href='"+url+"?page="+(current+1)+"'>next &#187;</a></li>"+
				"<li class='pager-last last'><a class='active' title='Go to last page' href='"+url+"?page="+(total-1)+"'>last &#187;</a></li>";

		} else if (current == total - 1) {			
			var pagination = 
				"<li class='pager-first first'><a class='active' title='Go to first page' href='"+url+"'>&#171; first</a></li>"+
				"<li class='pager-previous'><a class='active' title='Go to previous page' href='"+url+"?page="+(current-1)+"'>&#171; previous</a></li>"+
				"<li class='pager-item'><a class='active' title='Go to page "+(current-1)+"' href='"+url+"?page="+(current-2)+"'>"+(current-1)+"</a></li>"+
				"<li class='pager-item'><a class='active' title='Go to page "+(current)+"' href='"+url+"?page="+(current-1)+"'>"+(current)+"</a></li>"+	
				"<li class='pager-current first'>"+(current+1)+"</li>";

		} else {				
			var pagination = 
				"<li class='pager-first first'><a class='active' title='Go to first page' href='"+url+"'>&#171; first</a></li>"+																				
				"<li class='pager-item'><a class='active' title='Go to page "+(current)+"' href='/zeemp/"+url+"?page="+(current-1)+"'>"+(current)+"</a></li>"+										
				"<li class='pager-current first'>"+(current+1)+"</li>"+
				"<li class='pager-item'><a class='active' title='Go to page "+(current+2)+"' href='"+url+"?page="+(current+1)+"'>"+(current+2)+"</a></li>"+										
				"<li class='pager-last last'><a class='active' title='Go to last page' href='"+url+"?page="+(total-1)+"'>last &#187;</a></li>";

		}
                $('#content-inner .item-list').remove();
		$("#content-inner").append("<div class='item-list'><ul class='pager'>"+pagination+"</ul></div>");

		$(".pager li a").click(function(e) {			
			e.preventDefault();
			var url = $(this).attr("href");
			callView(url, '');								
		})
	} 		
}	
