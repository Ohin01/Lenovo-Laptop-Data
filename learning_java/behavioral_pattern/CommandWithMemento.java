import java.util.*;

/* =======================
   COMMAND INTERFACE
   ======================= */
interface DrawCommand {
    void execute();
}

/* =======================
   RECEIVER + ORIGINATOR
   ======================= */
class Canvas {
    private List<String> shapes = new ArrayList<>();

    void drawCircle() {
        shapes.add("Circle");
    }

    void drawSqr() {
        shapes.add("Square");
    }

    void show() {
        System.out.println(shapes);
    }

    /* ----- MEMENTO SUPPORT ----- */
    CanvasMemento save() {
        return new CanvasMemento(new ArrayList<>(shapes));
    }

    void restore(CanvasMemento memento) {
        this.shapes = new ArrayList<>(memento.getState());
    }
}

/* =======================
   MEMENTO
   ======================= */
class CanvasMemento {
    private final List<String> state;

    CanvasMemento(List<String> state) {
        this.state = state;
    }

    List<String> getState() {
        return state;
    }
}

/* =======================
   CONCRETE COMMANDS
   ======================= */
class CircleDrawer implements DrawCommand {
    private Canvas canvas;

    CircleDrawer(Canvas canvas) {
        this.canvas = canvas;
    }

    @Override
    public void execute() {
        canvas.drawCircle();
    }
}

class SqrDrawer implements DrawCommand {
    private Canvas canvas;

    SqrDrawer(Canvas canvas) {
        this.canvas = canvas;
    }

    @Override
    public void execute() {
        canvas.drawSqr();
    }
}

/* =======================
   INVOKER + CARETAKER
   ======================= */
class Invoker {
    private Deque<CanvasMemento> history = new ArrayDeque<>();
    private Canvas canvas;

    Invoker(Canvas canvas) {
        this.canvas = canvas;
    }

    void execute(DrawCommand cmd) {
        // Save state BEFORE execution
        history.push(canvas.save());
        cmd.execute();
    }

    void undo() {
        if (!history.isEmpty()) {
            canvas.restore(history.pop());
        }
    }
}

/* =======================
   CLIENT
   ======================= */
public class CommandWithMemento {
    public static void main(String[] args) {
        Canvas canvas = new Canvas();
        Invoker user = new Invoker(canvas);

        DrawCommand circle = new CircleDrawer(canvas);
        DrawCommand square = new SqrDrawer(canvas);

        user.execute(circle);
        canvas.show();   // [Circle]

        user.execute(square);
        canvas.show();   // [Circle, Square]

        user.undo();
        canvas.show();   // [Circle]

        user.undo();
        canvas.show();   // []
    }
}
