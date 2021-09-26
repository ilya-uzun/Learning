
var saveLine;

function toLocal() {
  saveLine = list.innerHTML;
  localStorage.setItem('saveLine', saveLine);
}
var list = document.querySelector('ul');
list.addEventListener('click', function (ev){
  if(ev.target.tagName === "SPAN"){
      ev.target.classList.toggle('checked');
      toLocal();
      }else if(ev.target.tagName === "SPAN2"){
      var div = ev.target.parentNode;
      div.remove();
      toLocal();
  }
}, false);

function checkKey(event){
  if(event.keyCode == "13"){
    newElement();
  }
}

function newElement() {
  var doc = document;
  var li = doc.createElement('li');
  var inputValue = doc.getElementById('newCase').value;
  var t = doc.createTextNode(inputValue);
  li.appendChild(t);

  if(inputValue == ""){
    alert("Введите ваше дело!")
  }else{
    doc.getElementById('list').appendChild(li);
  }
  doc.getElementById('newCase').value = "";

  var done = doc.createElement('SPAN');
  done.className = "done";
  li.prepend(done);

  var span = doc.createElement('SPAN2');
  var txt = doc.createTextNode("Удалить");
  span.className = "close";
  span.append(txt);//
  li.append(span);
  toLocal();
}

if(localStorage.getItem('saveLine')){
  list.innerHTML = localStorage.getItem('saveLine');
}
