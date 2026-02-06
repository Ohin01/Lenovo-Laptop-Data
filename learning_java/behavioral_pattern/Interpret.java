interface Expression
{
    int eval();
}

class Number implements Expression
{
    int tot = 0;

    Number(int a) 
    {
        tot = a;
    }

    public int eval()
    {
        return tot;
    }
}

class Add implements Expression
{
    int tot = 0;
    Expression l, r;

    Add(Expression left, Expression right)
    {
        l = left;
        r = right;
    }

    public int eval()
    {
        return l.eval() + r.eval();
    }
}

public class Interpret {
    public static void main(String[] args) {
        Expression ans = new Add(new Number(10), new Number(20));
        
        System.out.println(ans.eval());
    }
}
