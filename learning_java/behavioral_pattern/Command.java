
import java.util.ArrayDeque;
import java.util.Deque;

interface DrawCommand
{
    void execute();
}

class Canvas
{
    void drawCircle()
    {
        System.out.println("Circle");
    }

    
    void drawSqr()
    {
        System.out.println("Square");
    }
}

class CircleDrawer implements DrawCommand
{
    private Canvas canvas;

    public CircleDrawer(Canvas canvas) {
        this.canvas = canvas;
    }

    public void execute()
    {
        canvas.drawCircle();
    }
}

class SqrDrawer implements DrawCommand
{
    private Canvas canvas;

    public SqrDrawer(Canvas canvas) {
        this.canvas = canvas;
    }

    public void execute()
    {
        canvas.drawSqr();
    }
}

class Invoker
{
    private Deque<DrawCommand> dq = new ArrayDeque<>();

    void execute(DrawCommand cmd)
    {
        cmd.execute();
        dq.addLast(cmd);
    }

    void execute()
    {
        DrawCommand cmd = dq.peekLast();
        cmd.execute();
    }

    void undo()
    {
        dq.pollLast();
    }



}

public class Command {
    public static void main(String[] args) {
        Canvas canvas = new Canvas();
        DrawCommand circ = new CircleDrawer(canvas);
        DrawCommand sqr = new SqrDrawer(canvas);

        Invoker user = new Invoker();

        user.execute(circ);

        user.execute(sqr);

        user.undo();

        user.execute();
        
    }
}
