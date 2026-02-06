
//import java.awt.print.Book;

abstract class Books
{
    int pages;
    static int rate;

    Books(int p)
    {
        pages = p;
    }

    public static void show()
    {
        System.out.println("Pages ");
    }

    void show(int ks)
    {
        System.out.println("Pages " + pages);
    }



    //abstract void page();
}

class Dictionary extends Books
{
    public int def;
    static int pages;

    Dictionary(int d, int d2) 
    {
        super(d);
        super.pages = d;
        this.pages = d2;
    }

    public static void show() // public+static must match
    {
        System.out.println(pages);
    }    

    void page()
    {
        System.out.println(pages);
    }

    void show(int ks)
    {

    }
}

class Trial
{
    final int x; //either in constructor or here //must ensure this is initialized

    Trial() {
        this.x = 10;
    }

    Trial(int y)
    {
        this.x = y;
    }

    // {
    //     x = 10; //instance initializer block, whenever this class is called, it will initialize this block
    // }

    final void meth()
    {
        System.out.println(x);
    }
}

public class inheritance {
    public static void main(String ohin[])
    {
        Dictionary d = new Dictionary(10, 20);

        d.show();

        Books b;
        Books bb = new Dictionary(0, 0); // allowed

        Books.rate = 1000; //accesses static

        Books[] arr = new Books[10]; //allowed

        //System.out.println(bb.def); //cant access sub class property

        b = d;

        b.show(1);

        System.out.println(b.pages);

        Trial t = new Trial();
        //t.x = 10;
        
    }
}
