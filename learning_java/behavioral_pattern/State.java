interface CurState
{
    void execute(Mobile m);
}

class TurnedOn implements CurState
{
    public void execute(Mobile m)
    {
        System.out.println("Turning off");
        m.setState(new TurnedOff());
    }
}

class TurnedOff implements CurState
{
    public void execute(Mobile m)
    {
        System.out.println("Turning on");
        m.setState(new TurnedOn());
    }
}

abstract class Mobile
{
    protected CurState state;

    public void setState(CurState state)
    {
        this.state = state;
    }

    abstract void click();
}

class Ipad extends Mobile
{
    Ipad(CurState state)
    {
        super.state = state;
    }

    void click()
    {
        state.execute(this);
    }
}



public class State {
    public static void main(String[] args) {
        CurState cur = new TurnedOn();
        Mobile ipad = new Ipad(cur);

        ipad.click();
        ipad.click();
        ipad.click();
    }
    
}
