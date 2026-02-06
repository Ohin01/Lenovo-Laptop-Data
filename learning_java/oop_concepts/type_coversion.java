class Wrap
{
    int x;

    Wrap(int val)
    {
        x = val;
    }
}

class Inc
{
    void plus(Integer x)
    {
        x++;
    }

    
    void plus(Wrap x)
    {
        x.x++;
    }
}

public class type_coversion {
    public static void main(String ohin[])
    {
        byte b = 100;

        int ii = 130;
        byte con = (byte) ii;

        System.out.println(con);

        //int xx = (int) (2 * 2.0f); //possible
        //int xx = 2 * 2.0d; // not possible 

        b *= 3;

        //System.out.println(b);

        Integer x = 10;

        Wrap y = new Wrap(20); //create a wrapper to increment and pssing reference

        Inc i = new Inc();

        int hi = 128;
        char hii = (char)hi; //must typecast 
 

        i.plus(x);
        i.plus(y);
        
        //x++;

        System.out.println(x);
        System.out.println(y.x);
    }
}
