var list = document.querySelector('ul');
//Добавление локального хранилища
var saveLine;
function toLocal() {
  saveLine = list.innerHTML;
  localStorage.setItem('saveLine', saveLine);
}

list.addEventListener('click', function (ev){
  if(ev.target.tagName === "LI"){
      ev.target.classList.toggle('checked');
;
      toLocal();
  } else if(ev.target.tagName === "SPAN"){
      var div = ev.target.parentNode;
      div.remove();
      toLocal();
  }
}, false);

// Добавление в список дел
function checkKey(event){
  if(event.keyCode == "13"){
    newElement();
  }
}
function newElement() {
  var li = document.createElement('li');
  var inputValue = document.getElementById('newCase').value;
  var t = document.createTextNode(inputValue);
  li.appendChild(t);
  if(inputValue == ""){
    alert("Введите ваше дело!")
  }else{
    document.getElementById('list').appendChild(li);
  }
  document.getElementById('newCase').value = "";
  var done = document.createElement('DONE');//создать новый элемент
  var doneText = document.createTextNode("Выполнено");
  done.className = "done";
  done.insertBefore(doneText, );//
  li.insertBefore(done); 

  var span = document.createElement('SPAN');//создать новый элемент
  var txt = document.createTextNode("Удалить");
  span.className = "close";
  span.appendChild(txt);//
  li.appendChild(span);
  toLocal();
}

// вывод содержимого храниляща при обновлении вкладки
// если есть значение ключа todos, то записываем в (localStorage) список это содержимое 
if(localStorage.getItem('saveLine')){
  list.innerHTML = localStorage.getItem('saveLine');
}