interface WorkBehavior
{
    void work();
}

class Labor implements WorkBehavior
{
    public void work()
    {
        System.out.println("I do physical work for Humans");
    }
}

class Assist implements WorkBehavior
{
    public void work()
    {
        System.out.println("I assist people by chatting");
    }
}

interface Movement
{
    void move();
}

class HumanLike implements Movement
{
    public void move()
    {
        System.out.println("I move like a human with legs");
    }
}

class CantMove implements Movement
{
    public void move()
    {
        System.out.println("I cannot move");
    }
}


abstract class Robot
{
    WorkBehavior workBehavior;
    Movement movement;
    abstract void appearance();
    abstract void sound();

    void performWork()
    {
        workBehavior.work();
    }

    void doMovement()
    {
        movement.move();
    }

    void setWorkBehavior(WorkBehavior wb)
    {
        workBehavior = wb;
    }

    void setMovement(Movement mv)
    {
        movement = mv;
    }
}

class Humanoid extends Robot
{
    Humanoid()
    {
        WorkBehavior wb = new Labor();
        Movement mv = new HumanLike();

        setWorkBehavior(wb);
        setMovement(mv); 
    }

    void appearance()
    {
        System.out.println("I look like you");
    }

    void sound()
    {
        System.out.println("Beep beep");
    }
}

class ChatGPT extends Robot
{
    ChatGPT()
    {
        WorkBehavior wb = new Assist();
        Movement mv = new CantMove();

        setWorkBehavior(wb);
        setMovement(mv); 
    }

    void appearance()
    {
        System.out.println("I am only a software");
    }

    void sound()
    {
        System.out.println("Hi I am ChatGPT");
    }
}

public class strategy_pattern {
    public static void main(String args[])
    {
        Robot ariba = new Humanoid();
        ariba.appearance();
        ariba.doMovement();

        Robot ohin = new ChatGPT();
        ohin.performWork();
        ohin.sound();
    }
    
}
