
//Добавление локального хранилища
var saveLine;

function toLocal() {
  saveLine = list.innerHTML;
  localStorage.setItem('saveLine', saveLine);
}
var list = document.querySelector('ul');
list.addEventListener('click', function (ev){
  if(ev.target.tagName === "SPAN"){
      ev.target.classList.toggle('checked');//Устаноавливаем класс 'checked'элементу списка
      toLocal();
      }else if(ev.target.tagName === "SPAN2"){//
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
  var doc = document;//улучшение произодительности 
  var li = doc.createElement('li');
  var inputValue = doc.getElementById('newCase').value;// получаем значения поля ввода
  var t = doc.createTextNode(inputValue);
  li.appendChild(t);// сформирован элемент списка

  if(inputValue == ""){
    alert("Введите ваше дело!")
  }else{
    doc.getElementById('list').appendChild(li);// добавляем в список дел
  }
  // очистка значения списка
  doc.getElementById('newCase').value = "";

  var done = doc.createElement('SPAN');//создать новый элемент
  done.className = "done";
  li.prepend(done);

  var span = doc.createElement('SPAN2');//создать новый элемент
  var txt = doc.createTextNode("Удалить");
  span.className = "close";
  span.append(txt);//
  li.append(span);
  toLocal();
}

// вывод содержимого храниляща при обновлении вкладки
// если есть значение ключа todos, то записываем в (localStorage) список это содержимое 
if(localStorage.getItem('saveLine')){
  list.innerHTML = localStorage.getItem('saveLine');
}
