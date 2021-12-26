

// Задача  fizzbuzz
function fizzbuzz(n)
{
    let a = new Array();
    for(let i = 1; i < n+1; i++){
        if (i % 15 == 0) {
            a.push("FizzBuzz");
        } else if (i % 5 == 0){
            a.push("Buzz");
        } else if (i % 3 == 0){
            a.push("Fizz");
        }else {
           a.push(i);
        }
    }
return a;
}

