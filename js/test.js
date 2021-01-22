// переменные
let message, age = 32;
message = 'Илья';
console.log('Привет', message, age);

// таймер
setTimeout(() => {
    console.log('Прошло 5000 мс')
}, 5000);

setTimeout(() => {
    console.log('Прошло 1000 мс')
}, 1000);

// массивы одномерные
let some = new Array();
some[0] = '1'; // добавляем первый элемент
some[1] = 2; //второй элемент
console.log(some[0], some[1], some[2]);// some[2] вывденно намеренно 


let element = new Array(23,'s', true, "первый");
console.log(element.length); // количеств элементов
console.log(element);

// массивы многомерные

let x = Array(new Array(0,2,'sa'), new Array(5,'d')); // заране объяленны
x[1][2] = 'asdd'; //присвоить значение уже в созданный массив
console.log(x);
console.log(x[0][1]);// вывод одного элеента

let y = Array(new Array(), new Array()); // заране объяленныy
y[0][0] = 'asw'; //присвоить значение
y[0][1] = 'as'; //присвоить значение
y[1][0] = 'asw'; //присвоить значение
y[1][1] = 'as'; //присвоить значение
console.log(y);// вывод одного элеента

//result = prompt(title, [default]);

// преобразование типов

let value = true;
console.log(value);
value = String(value); // преобразование  string
console.log(value);