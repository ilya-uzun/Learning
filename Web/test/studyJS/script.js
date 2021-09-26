//Переменные в консоле
var num = 23.45;
var num1 = 12;
var num2 = "string";
var num3 = true;
//alert(num);
console.log(num);
console.log(num1);
console.log(num2);
console.log(num3);
//var name = prompt ("Вопрос");
console.log("Ответ в консоле -"+ name);
//переменные на странице 
var first = 12;
var second = 24;
document.write("Результат ", first + second + "<br>");
document.write("Результат ", first + second + "<br>");
document.write("Результат ", first - second + "<br>");
document.write("Результат ", first / second + "<br>"); //деление без остатка %
document.write(Math.PI + "<br>"); // вывод числа пи 

// массивы
var colors = ["Red", "Blue", "Green"];
document.write(colors[0]+ "<br>");

// массивы способ 2
//
// добовление нового элемента в массив
var colors2 = ["Red", "Blue", "Green"];
colors2[3]= 123;
colors2.push(456);// добавление нового элемента, нельзы использовась сcolors2[3]= 123;  
document.write(colors2[1] + colors2[3], "<br>");

//циклы
// for (var i  = 0; i < 10; i++) {
//   console.log(i);
//   document.write(i + "<br>");
// }
// var t = 0;
// while (t < 10) {
//   console.log(t);
//   t++;
// }

// var i= 20;
// do{
//   console.log(i);
// } while (i<10);

// цикл с массивом
var colors3 = new Array ("Red", "Blue", "Green");
for (var i  = 0; i < colors3.length; i++) {
    console.log(colors3[i]);
  }

  // условный оператор
  if (1 != 1) {
    console.log("1 равно 1");
  } else if (2==2){
    console.log("2 равно 1");
  } else {
    console.log("else chf,jnfkj");
  }

  // switch
  // var res = 3;
  // switch (res) {
  //   case 1:
  //     alert ("Вариант 1");
  //     break;
  //   case 2:
  //     alert ("Вариант 2");
  //     break;  
  //   case 3:
  //     alert ("Вариант 3");
  //     break;
  //   default:// срабатывает если другие на сработали       
  // }

  // создание объктов
  var person = {
    firstName: 'Илья',
    age: 32,
    children: ['Диана', 'Рита'],
    arress:{//новый объект в объекте
      street:'22',
      city: 'Perm'
    },
    NameAge: function () {
      return this.firstName + ", age is - " + this.age;
    }
  }
  document.write(person.arress.city, "<br>");//вывод адреса
  document.write(person.children[1], "<br>");//вывод массива
  document.write(person.NameAge(), "<br>");//вывод массива

  // Использование констрктора при создание объекта
  // var apple = new Object();
  // apple.color = 'green';
  // apple.shape = 'round';
  // //добавление функции
  // apple.descride = function () {
  //   return 'An apple is ' + this.color;
  // }
  // console.log(apple.descride());

  // консруктор иницилизация сразу после создания
  // создаём конструктор
  function Fruit(color, shape) {
    this.color = color;
    this.shape = shape;
  }
  // создаём новую функцию и передаёт туда значения из конструктор
 var  melon = new Fruit ('yellow', 'round');
 var  apple = new Fruit ('red', 'round');

 apple.descride = function () {
     return 'An apple is ' + this.color;
   }
   console.log(apple.descride());

   melon.descride = function () {
    return 'An apple is ' + this.color;
  }
   console.log(melon.descride());


   // события связь с html

   function changeColor(newColor) {
     var element = document.getElementById("text");
     element.style.color = newColor;
   }

   // функция для формы
   function validataForm() {
     var element = document.forms["myForm"]["fname"].value;
     var tel = document.forms["myForm"]["ftel"].value;
     if(element == "") {//Если елемент(поле формы) не чему не равно
      alert("Имя должно быть заполнено");
      return false;// если не вернём folse Submit  обновит строницу
    } else if (tel == ""){
      alert("Введите телефон");
      return false;
    }
   }