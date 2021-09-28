package ru.uzun;


class Person {
    void walk(){
         System.out.println("Running Fast...");
    }
}

//класс-наследник Employee переопределяет поведение метода walk() класса Person.
class Employee extends Person {
    void walk(){
        System.out.println("Running Fast...");
    }

    public static void main(Srting[] arg){
        Person p = new Employee();
        p.walk();
    }
}