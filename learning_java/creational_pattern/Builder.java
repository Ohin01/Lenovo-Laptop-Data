class Burger
{
    String patty;
    String sauce;

    void setPatty(String s)
    {
        patty = s;
    }

    void setSauce(String s)
    {
        sauce = s;
    }
}

interface BurgerBuilder
{
    BurgerBuilder patty();
    BurgerBuilder sauce();
    Burger getResult();
}

class HamBurgerBuilder implements BurgerBuilder
{
    private Burger burger;

    public HamBurgerBuilder() {
        burger = new Burger();
    }

    public HamBurgerBuilder patty()
    {
        burger.setPatty("Pork");
        return this;
    }

    public HamBurgerBuilder sauce()
    {
        burger.setSauce("Mayo");
        return this;
    }

    public Burger getResult()
    {
        return burger;
    }
}

class Director
{
    void construct(BurgerBuilder builder)
    {
        builder.sauce();
        builder.patty();
    }
}

public class Builder {
    public static void main(String[] args) {
        BurgerBuilder builder = new HamBurgerBuilder();
        Director dir = new Director();
        dir.construct(builder);
        Burger b = builder.getResult();

        System.out.println(b.sauce);
    }
    
}
