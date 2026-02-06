import java.util.ArrayList;
import java.util.List;

interface Department
{
    void hello();
}

class Student implements Department
{
    public void hello()
    {
        System.out.println("Hi I am a student");
    }
}

class Teacher implements Department
{
    public void hello()
    {
        System.out.println("Hi I am a teacher");
    }
}

class DeptGroup implements Department
{
    private List<Department> child = new ArrayList<>();

    public void hello()
    {
        for (Department d: child)
        {
            d.hello();
        }
    }

    public void add(Department d)
    {
        child.add(d);
    }
}

public class Composite {
    public static void main(String ohin[])
    {
        DeptGroup cse = new DeptGroup();

        Department s = new Student();
        Department t = new Teacher();
        cse.add(s);
        cse.add(t);

        cse.hello();
    }
}
