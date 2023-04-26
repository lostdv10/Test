var openText = (function(path){

  var FSO = new ActiveXObject("Scripting.FileSystemObject");
  !!! FSO.FileExists(path) && alert("文件不存在");
  var forAppending = 1;
  var Txt = FSO.OpenTextFile(path);
  var str = Txt.ReadAll();
  Txt.close();
  FSO = null;
  document.getElementById('txt1').value = str;
  str = str.replace(/(".*")/g,"$1,").replace(/=/g,":").replace(/[^\]]+(?=\[|$)/g, function(o){return o.replace(/$/g,"}")}).
  replace(/\[(.*?)\]/g, ",\"$1\" : {").replace(/,[\s|\n|\r]*\}/g,"}").replace(/^,/g,"var Json = {")+"}";
  document.getElementById('txt2').value = str;
  eval(str);
  return function(argX,argY){
         return JSON[argX][argY]
  }
})('E:\\Paper.ini')