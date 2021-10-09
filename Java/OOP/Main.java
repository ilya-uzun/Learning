 abstract class Person {
    private String name = "Петя";
    private int age = 30;


   public abstract void walk();
}

 //класс-наследник Men переопределяет поведение метода walk() класса Person.
 class Men extends Person {
    @Override
    public void walk(){
        System.out.println("Сообщение класса Men..");
    }
}

  class Women extends Person {

     @Override
     public void walk(){
         System.out.println("Сообщение класса Women..");
     }
 }



public class Main {   
    public static void main(String[] arg){
         Men p = new Men();
         Women p2 = new Women();
         p.walk();
         p2.walk();
        p2.ageM();
    }

}
