interface Pizza
{
    void make();
}

class BeefPizza implements Pizza
{
    public void make()
    {
        System.out.println("its a beef pizza");
    }
}


class ChickenPizza implements Pizza
{
    public void make()
    {
        System.out.println("its a chicken pizza");
    }
}

abstract class PizzaFactory
{
    abstract Pizza create();
}

class ItalianPizzaFactory extends PizzaFactory
{
    Pizza create()
    {
        return new ChickenPizza();
    }
}

public class Abstract_Factory {
    public static void main(String[] args) {
        PizzaFactory pf = new ItalianPizzaFactory();
        Pizza p = pf.create();

        p.make();
    }
    
}
