interface Console
{
    void playJoy();
    void playKey();
}

class XBox implements Console 
{
    public void playJoy()
    {
        System.out.println("Using xbox joystick");
    }

    public void playKey()
    {
        System.out.println("Using xbox keyboard");
    }
}

class PlayStation  implements Console
{
    public void playJoy()
    {
        System.out.println("Using playstation joystick");
    }

    public void playKey()
    {
        System.out.println("Using playstation keyboard");
    }
}

abstract class Controller
{
    protected Console console;

    Controller(Console console) 
    {
        this.console = console;
    }
    
    abstract void play();
}

class JoyStick extends Controller
{
    JoyStick(Console con)
    {
        super(con);
    }
    
    void play()
    {
        console.playJoy();
    }
} 

public class Bridge {
    public static void main(String[] args) {
        Console xbox = new XBox();
        Controller c = new JoyStick(xbox);
        c.play();
    }
    
}
