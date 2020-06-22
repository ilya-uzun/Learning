
public class Main{
    public static void main(String[] args){
        int a = 5;
        int b = 2;

        a += +b;
        System.out.println(a);
        a += -b;
        System.out.println(a);
        a = a*b;
        System.out.println(a);
        a %= 3; // остаток от деления
        double result = a/b;
        System.out.println(result);
    }
}