var list = document.querySelector('ul');
//Добавление локального хранилища
var todos;
function toLocal() {
  todos = list.innerHTML;
  localStorage.setItem('todos', todos);
}

list.addEventListener('click', function (ev){
  if(ev.target.tagName === "LI"){
      ev.target.classList.toggle('checked');
      toLocal();
  } else if(ev.target.tagName === "SPAN"){
      var div = ev.target.parentNode;
      div.remove();
      toLocal();
  }
}, false);

// Добавление в список дел
function newElement() {
  var li = document.createElement('li');
  var inputValue = document.getElementById('toDoEl').value;
  var t = document.createTextNode(inputValue);
  li.appendChild(t);
  if(inputValue == ""){
    alert("Введите ваше дело!")
  }else{
    document.getElementById('list').appendChild(li);
  }
  document.getElementById('toDoEl').value = "";
  var span = document.createElement('SPAN');
  var txt = document.createTextNode("X");
  span.className = "close";
  span.appendChild(txt);
  li.appendChild(span);
  toLocal();
}

// вывод содержимого храниляща при обновлении вкладки
// если есть значение ключа todos, то записываем в (localStorage) список это содержимое 
if(localStorage.getItem('todos')){
  list.innerHTML = localStorage.getItem('todos');
}