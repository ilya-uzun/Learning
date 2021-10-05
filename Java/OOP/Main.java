

public abstract class Person {
    private String name = "Петя";
    private int age = 30;
    
     public void ageM(){
       System.out.println(age);
   }
   
   public abstract void walk();
}

//класс-наследник Men переопределяет поведение метода walk() класса Person.
public class Men extends Person {
    @Override
    void walk(){
        System.out.println("Сообщение класса Men..");
    }
}

 public class Women extends Person {
     @Override
     void walk(){
         System.out.println("Сообщение класса Women..");
     }
 }

public class Main {   
    public static void main(String[] arg){
        Men p = new Men();
        Women p2 = new Women();
        p.walk();
        p2.walk();
    }

}
//https://javarush.ru/groups/posts/1973-abstraktnihe-klassih-v-java-na-konkretnihkh-primerakh
