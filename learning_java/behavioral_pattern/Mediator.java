interface Mediatorr {
    void execute();
}

class Registration implements Mediatorr {
    Password pass;

    public void setPass(Password p)
    {
        pass = p;
    }

    public void execute() 
    {
        if (pass.isValid())
        {
            System.out.println("Button showing");
        }

        else
        {
            System.out.println("Button not showing");
        }
    }
}

abstract class Component 
{
    Mediatorr med;

    Component(Mediatorr med) {
        this.med = med;
    }

    abstract void notifyMed();
}

class Password extends Component 
{
    private String content = null;

    Password(Mediatorr med) {
        super(med);
    }

    public void setContent(String s)
    {
        content = s;
        notifyMed();
    }

    void notifyMed() 
    {
        med.execute();
    }

    public boolean isValid()
    {
        if (content == null) return false;
        else return true;
    }
}

public class Mediator {
    public static void main(String[] args) {
        Registration med = new Registration();
        Password comp = new Password(med);
        med.setPass(comp);

        med.execute();

        comp.setContent("Hi");
    }

}
