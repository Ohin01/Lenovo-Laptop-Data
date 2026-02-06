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

class PizzaFactory
{
    Pizza create(String req)
    {
        if(req.equalsIgnoreCase("beef"))
        return new BeefPizza();

        else if (req.equalsIgnoreCase("chicken"))
        return new ChickenPizza();

        return null;
    }
}

public class Factory {
    public static void main(String[] args) {
        PizzaFactory pf = new PizzaFactory();
        Pizza p = pf.create("beef");

        p.make();
    }
    
}
