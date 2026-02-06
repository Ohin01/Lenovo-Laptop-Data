interface Pizza
{
    int cost();
}

class Dough implements Pizza
{
    public int cost()
    {
        return 1000;
    }
}

abstract class PizzaDecorator implements Pizza
{
    protected Pizza base;

    public PizzaDecorator(Pizza p) {
        base = p;
    }  
}

class Cheese extends PizzaDecorator
{
    Cheese(Pizza b)
    {
        super(b);
    }

    public int cost()
    {
        return base.cost() + 100;
    }
}

public class Decorator {
    public static void main(String[] args) {
        Pizza p = new Cheese(new Dough());

        System.out.println(p.cost());
    }
}
