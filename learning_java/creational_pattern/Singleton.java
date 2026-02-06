class Log
{
    private static Log instance;

    private Log()
    {

    }

    public static Log getInstance()
    {
        if (instance == null)
        {
            instance = new Log();
        }

        return instance;
    }

    public void show(String msg)
    {
        System.out.println("You put: " + msg);
    }
}

public class Singleton {
    public static void main(String[] args) {
        Log.getInstance().show("HI");
    }
    
}
