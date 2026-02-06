interface Printer {
    void print();                 // abstract
    static void info() {          // static
        System.out.println("Printer interface");
    }
    default void scan()
    {
        System.out.println("Prining document");
    }

    void hi();
    void bye();
    int val = 10;
    
}

interface Scanner {
    int val = 20;
    void bye();
    default void scan() {         // default
        System.out.println("Scanning document");
    }
}

class SmartDevice implements Printer, Scanner {
    public void scan()
    {
        Scanner.super.scan();
    }
    
    public void hi()
    {

    }

    public void bye()
    {
        System.out.println("Bye");
    }
    public void print() { //must resolve issues
        System.out.println("Printing document");
        System.out.println(Printer.val);//must specify
    }
}

public class multiples_interface {
    public static void main(String[] args) {
        SmartDevice device = new SmartDevice();
        device.print(); 
        device.scan();
        Printer.info();  

        Scanner sc = new SmartDevice();
        sc.scan();
        sc.bye();
    }
}
