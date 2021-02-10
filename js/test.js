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

let s = 2, a = 3;
console.log(s+a); 
let xw = 2+2-4;
console.log(xw); 


// логические оператор
console.log(2>1);// true
console.log(2<1);// false
console.log(2==1);// false
console.log('a'== 'b');// false
console.log(null === undefined);// false При строгом равенстве ===, значения различны, так как различны их типы.
console.log(null == undefined);// true

console.log('---------');// false

console.log('dddddddd');

console.log(null > 0 );// false
console.log(null == 0 );// false
console.log(null >= 0 );// true

let dd = 'd';
let ss = 34;

console.log( dd + (ss - 4));

// простая функция
function showS(){
    let m = "Тестовая переменная";
    console.log('showS', m);
}
// вызов функции
showS();
// возврат значения
function sum(a, b){
    return a+b;
}
console.log(sum(1,2), " - функция sum");

// объекты
var person = {
    firstName: "Щипунов",
    lastName : "Андрей",
    age: 50,
    eysColor: "Зелёный",
    // метод класса
    fullName : function() {
        return this.firstName + " " + this.firstName;
    }
    
};
// доступ усвойствам объекта
console.log(person.age);
console.log(person.eysColor);
name = person.fullName;

// оператор if 
let year = 2016;


if (year == 2015) {
    console.log('Вы правы');
} else if (year > 2015){
    console.log('> 2015');
}else {
    console.log('< 2015');
}

// более короткая запись с помощью оператора ?
let age2 = 18;
let varible = ( age2 > 18) ? true : false;