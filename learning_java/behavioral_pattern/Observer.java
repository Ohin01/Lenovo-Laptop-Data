import java.util.ArrayList;
import java.util.List;

interface WObserver
{
    void update(int state);
}

class Mobile implements WObserver
{
    public void update(int state)
    {
        System.out.println("Price is now(Mobile) " + state);
    }
}

class PC implements WObserver
{
    public void update(int state)
    {
        System.out.println("Price is now(PC) " + state);
    }
}

interface Subject
{
    void add(WObserver wo);
    void remove(WObserver wo);
    void notifyOb();
}

class Weather implements Subject
{
    private List<WObserver> all = new ArrayList<>();
    private int state = 10;

    public void add(WObserver wo)
    {
        all.add(wo);
    }

    public void remove(WObserver wo)
    {
        all.remove(wo);
    }

    public void setState(int data)
    {
        state = data;
        notifyOb();
    }

    public void notifyOb()
    {
        for (WObserver wo: all)
        {
            wo.update(state);
        }
    }
}

public class Observer
{
    public static void main(String[] args) {
        WObserver mobile = new Mobile();
        WObserver pc = new PC();

        Weather sub = new Weather();

        sub.add(mobile);

        sub.setState(100);

        sub.add(pc);

        sub.setState(200);
    }
}