class Outer
{
    int x;
    private int y;
    static int z;

    Outer(int val)
    {
        x = val;
    }

    class nonInner
    {
        int nx;

        void print()
        {
            System.out.println(y);
        }
    }

    void hello()
    {
        nonInner hi = new nonInner();

        hi.print();
    }

    void inc()
    {
        System.out.println(x);
    }

    static class Inner
    {
        int inX; //non static can be used here

        Inner(int val)
        {
            inX = val;
            z = 30;
            //x = 30; //cant access non static
        }

        void print()
        {
            System.out.print(inX);
            System.out.println(z);
        }

        static void print2()
        {
            System.out.print(z);
        }
    }

    void print()
    {
        System.out.println(x);

        Inner in = new Inner(100);
        Inner.print2(); //must be static method inside static inner class
        in.print();  //object needs to be created
        System.out.println(x);
    }
}


public class nested_class {
    public static void main(String ohin[])
    {
        Outer o = new Outer(10);
        o.print();

        Outer.Inner in = new Outer.Inner(300); //if static

        Outer.Inner.print2();  //can be directly called

        Outer ot = new Outer(100);
        Outer.nonInner inn = ot.new nonInner();
        //Outer.Inner inn2 = ot.new Inner(100); //not allowed

        //inn.inc();    // wrong

        System.out.println(o.z);
    }
}
