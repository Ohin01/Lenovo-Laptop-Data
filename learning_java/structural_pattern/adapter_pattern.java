interface DisplayScreen{
    void display(int a);
}

class NewDisplay{
    void displayString(String s)
    {
        System.out.println("This is a string");
    }
}

class NewDisplayAdapter implements DisplayScreen{
    NewDisplay nd = new NewDisplay();
    
    public void display(int a)
    {
        String s = String.valueOf(a);
        nd.displayString(s);
    }
}

class OldDisplay implements  DisplayScreen{
    public void display(int a)
    {
        System.out.println("This a integer");
    }
}

class Shop{
    DisplayScreen ds;

    Shop(DisplayScreen ds) 
    {
        this.ds = ds;
    }

    void show(int a)
    {
        ds.display(a);
    }
}

public class adapter_pattern {
    public static void main(String ohin[])
    {
        DisplayScreen ds = new NewDisplayAdapter();
        Shop shop = new Shop(ds);

        shop.show(10);

        DisplayScreen old = new OldDisplay();
        shop.ds = old;

        shop.show(10);
    }
    
}
