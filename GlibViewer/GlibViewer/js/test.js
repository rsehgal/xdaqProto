 $(document).ready(function()
{
alert("doucment loaded");
$("#btn1").click(function(){
  $("#div1").text("Hello world!");
});
});

$(document).ready(function(){
$(".setBtn").click(function(){
var v=this.id;
var regId="#regname_"+v;
var valId="#value_"+v;
var maskId="#mask_"+v;
var addressId="#address_"+v;
var divId="#div_"+v;

alert(regId + " : " + valId );
var dataString="regname="+$(regId).val() +"&value="+ $(valId).val()+"&mask="+$(maskId).val()+"&address="+$(addressId).val(); 
//alert($(regId).val());
alert(dataString);

$.ajax({
type: 'POST',
url : '/urn:xdaq-application:lid=15/setParameter',
data : dataString,
processData: false,
success : function(result,stat){
$(divId).text("Value set").fadeOut(2000);
}
});
});

});

