let cars = ["Honda", "Toyota", "Opel", "BMV", "Lada"];
let nums = [1,2,1,2,3,3,3,4,1,1,1,1,3,4];

// сумма в массиве
// let sum = nums.reduce((x, y) => x + y);

// удалить ложное значение из массива
// let arr = [false, "red", 0, 2, "", null, true, NaN, undefined];
// let new_arr = arr.filter(Boolean);

// конвертация массива в объект
// let obj = {...cars};
// console.log(cars);
// console.log(obj);

// удаление повторяющихся иградиентов ихз массива
// способ 1
// let uni_mams = [...new Set(nums)];
// console.log(uni_mams);
// способ 2
// let uni_mams = Array.from(new Set(nums));
// console.log(uni_mams);

// замена определённог элемента в массиве 
// cars.splice(0, 2, "Opel")
// console.log(cars);

// перебор массива без метода med
let new_cars = [
    {car : "Lada", color : "Red"},
    {car : "Toyota", color : "Gren"},
    {car : "Opel", color : "Black"},
    {car : "Honda", color : "Orange"},
];

let car_name = Array.from(new_cars, ({car}) => car);
console.log(car_name);
