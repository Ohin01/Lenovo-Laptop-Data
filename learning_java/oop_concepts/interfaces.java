import java.util.ArrayList;
import java.util.List;

interface Animal
{
    static void eat() //must write default
    {
        System.out.println("Animal is eating");
    }

    default void run()
    {
        System.out.println("Animal is running");
    }

    void bark();

    int ohin = 10; //final
    List<Integer> numList = new ArrayList<>();
}

class Dog implements Animal
{
    public void eat() //must be public
    {
        numList.add(10); //allowed to touch even if final
        
        System.out.println("Dog is eating " + ohin); // ohin accessed directly but cant be changeds
    }

    public void run()
    {
        System.out.println("Dog is running");
        Animal.super.run();
    }

    public void bark()
    {
        System.out.println("Dog is barking ");
    }

    void scream()
    {
        System.out.println("SCREAM");
    }
}

abstract class Cat implements Mammal
{
    public void eat()
    {
        System.out.println("Cat is eating ");
    }

    public void hi()
    {
        System.out.println(num);
    }
}

interface Mammal extends Animal
{
    int num = 12;

    default void bark()
    {
        System.out.println("bark bark mammal");
    }
}

class Cozy extends Cat
{
    public void bark()
    {
        run(); //has access to inetrface
        System.out.println("Cozy is barking " + num);   
    }
}



public class interfaces {
    public static void main(String[] ohin)
    {
        Dog d = new Dog();
        d.eat();
        d.run();
        Animal.eat();
        //Animal.run(); //not allowed as non static
        System.out.println(Animal.ohin); //allowed

        Animal morph = new Dog(); //same as inheritaance- dynamic dispatch
        //morph.scream();// no access

        morph = new Cozy();

        morph.bark();
    }
    
}
