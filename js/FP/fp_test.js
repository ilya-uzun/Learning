//функция первого порядка - это функция которая ведет себя как переменная
const main = function (a, b){
    return a + b;
}
// Функция высшего порядка
function mainVP(a){
    return function(b){
        return a*b;
    }
}

function half(x){
    return x+2;
}
let func = mainVP(2);
let res = func(3);

console.log(res);
console.log(main);
console.log(half(2));
