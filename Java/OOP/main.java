package ru.uzun;


class  abstract Person {
    private String name = "Петя";
    private int age = 30;
    
     public void ageM() {
       System.out.println(age);
   }
}

//класс-наследник Men переопределяет поведение метода walk() класса Person.
class Men extends Person {
    void walk(){
        System.out.println("Сообщение класса Men..");
    }

class Women extends Person {
    void walk(){
        System.out.println("Сообщение класса Women..");
    }
    
    public static void main(String[] arg){
        Person p = new Men();
        Person p2 = new Women();
        p.walk();
        p2.walk();
    }
}
//https://javarush.ru/groups/posts/1973-abstraktnihe-klassih-v-java-na-konkretnihkh-primerakh
