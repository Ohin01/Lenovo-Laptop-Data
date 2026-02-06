interface SayHello
{
    void hello();
}

public class functional_interface {
    public static void main(String[] args) {
        SayHello s = () -> System.out.println("Hi");

        s.hello();
    }
}
