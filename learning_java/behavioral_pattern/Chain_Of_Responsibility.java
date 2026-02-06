abstract class LeaveRequest
{
    protected LeaveRequest next = null;

    public LeaveRequest setNext(LeaveRequest next)
    {
        this.next = next;
        return next;
    }

    public void handle (String req)
    {
        if (!check(req))
        {
            System.out.println("Not given Leave");
        }

        if (next != null)
        next.handle(req);

        System.out.println("Given Leave");
    }

    abstract boolean check(String req);
}

class StudentAdvisor extends LeaveRequest
{
    boolean check(String req)
    {
        if (req.equalsIgnoreCase("Sick"))
        return true;

        else
        return false;
    }
}

class Chairman extends LeaveRequest
{
    boolean check(String req)
    {
        if (req.equalsIgnoreCase("Sick"))
        return true;

        else
        return false;
    }
}


public class Chain_Of_Responsibility {
    public static void main(String[] args) {
        LeaveRequest lr = new StudentAdvisor().setNext(new Chairman());
        lr.handle("sick");
    }
    
}
