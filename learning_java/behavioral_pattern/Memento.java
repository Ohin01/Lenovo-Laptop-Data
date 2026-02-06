import java.util.Stack;

class TextMemento
{
    private String state;

    public TextMemento(String state) {
        this.state = state;
    }

    public String getState()
    {
        return state;
    }
}

class Text
{
    private String state;

    void update(String newState)
    {
        state = newState;
    }

    TextMemento save()
    {
        return new TextMemento(state);
    }

    void restore(TextMemento m)
    {
        state = m.getState();
    }
}


class History
{
    private Stack<TextMemento> st = new Stack<>();

    void push(TextMemento m)
    {
        st.push(m);
    }

    TextMemento pop()
    {
        return st.pop();
    }
}

public class Memento {
    public static void main(String[] args) {
        
        
    }
}
