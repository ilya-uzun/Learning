// стрелочная функция
const polindrom =str =>{ 
    //перевод строки в нижний регистр
    str = str.toLowerCase();
    return str == str.split('').reverse().join('');// сранение

    // неудачный способ
    // // перевод строки в массив
    // let str2 = str.split('');
    // // развернуть строку
    // str2 = str2.reverse(); // разварачивает массив
    // str2 = str2.join(''); // обратная опираия  split
    // if (str == str2) return true;
    // else return false;
    // return str2;
}
console.log(polindrom('AbbeA'));