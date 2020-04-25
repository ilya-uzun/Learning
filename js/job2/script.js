
//Добавление локального хранилища
var saveLine;
function toLocal() {
  saveLine = list.innerHTML;
  localStorage.setItem('saveLine', saveLine);
}
var list = document.querySelector('ul');
list.addEventListener('click', function (ev){
  if(ev.target.tagName === "LI"){// если кликнули по элементу списка
      ev.target.classList.toggle('checked');//Устаноавливаем класс 'checked'элементу списка 
      toLocal();
}else if(ev.target.tagName === "SPAN"){//
      var div = ev.target.parentNode;
      div.remove();
      toLocal();
  }
}, false);

// ввод по enter
function checkKey(event){
  if(event.keyCode == "13"){
    newElement();
  }
}
// Добавление в список дел
function newElement() {
  var li = document.createElement('li');
  var inputValue = document.getElementById('newCase').value;// получаем значения поля ввода
  var t = document.createTextNode(inputValue);
  li.appendChild(t);// сформирован элемент списка

  if(inputValue == ""){
    alert("Введите ваше дело!")
  }else{
    document.getElementById('list').appendChild(li);// добавляем в список дел
  }
  // очистка значения списка
  document.getElementById('newCase').value = "";
  var span = document.createElement('SPAN');//создать новый элемент
  var txt = document.createTextNode("Удалить");
  span.className = "close";
  span.appendChild(txt);//
  li.appendChild(span);

  var done = document.createElement('span');//создать новый элемент
  var txtDone = document.createTextNode("Не выполнено");
  done.className = "done";
  done.appendChild(txtDone);//
  li.appendChild(done);

  toLocal();
}

// вывод содержимого храниляща при обновлении вкладки
// если есть значение ключа todos, то записываем в (localStorage) список это содержимое 
if(localStorage.getItem('saveLine')){
  list.innerHTML = localStorage.getItem('saveLine');
}