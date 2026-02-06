abstract class Unknown
{
    abstract void hello();
}

interface Trial
{
    
}

public class anynomous_class {
    public static void main (String args[])
    {
        Unknown un = new Unknown() {
            static int x = 10;
            void hello()
            {
                System.out.println("HI " + x);
            }
        };

        un.hello();
    }
}
