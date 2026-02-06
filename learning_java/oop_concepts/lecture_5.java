class Box
{
    static double w = 20;
    private double h;
    private double d;
    
    static //called when you make a object
    {
        w = 1000;
        //h = 10;// non static
    }

    Box()  //multiple constructors
    {

    }

    Box(double w, double h, double d)
    {
        setW(w);
        setH(h);
        setD(d);
    }


    static void inc()
    {
        Box tm = new Box();
        double hhh = tm.getH();

        // double hh = getH();
        //this.w++; //not allowed
        w++;
    }

    static void set(Box b)
    {
        b.d *= 2;
        b.h /= 2;
    }

    void setW(double w)
    {
        this.w = w;
    }

    void setH(double w)
    {
        this.h = w;
    }

    void setD(double w)
    {
        this.d = w;
    }

    double getH()
    {
        return h;
    }

    static double getW()
    {
        return w;
    }

    double getD()
    {
        return d;
    }

    void print(int a)
    {

    }

    String print()
    {
        String s = "Ohin";
        return s;
    }
}

public class lecture_5
{
    public static void main(String ohin[])
    {
        //System.out.println(Box.w); 

        Box a = new Box();

        System.out.println(Box.w);
        
        Box b = new Box(1, 2,3);

        a.setW(20);

        //int bb; //not initialized

        Box.inc();
        a.set(b);

        Box c = new Box();

        System.out.println(c.getW());
        System.out.println(Box.getW());

    }
}