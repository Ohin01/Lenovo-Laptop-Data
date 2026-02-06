abstract class Recipe
{
    void stove()
    {
        System.out.println("stove is on");
    }

    abstract void brew();
}

class Coffee extends Recipe
{
    void brew()
    {
        System.out.println("Coffee is brewing");
    }
}

class Tea extends Recipe
{
    void brew()
    {
        System.out.println("Tea is brewing");
    }
}

public class Template {
    public static void main(String[] args) {
        Recipe recipe = new Coffee();
        recipe.stove();
        recipe.brew();
    }
    
}
