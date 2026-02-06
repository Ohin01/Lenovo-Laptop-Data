interface AccVisitor
{
    void visitSavings(SavingsAcc a);
    void visitLoan(LoanAcc a);
}

class Interest implements AccVisitor
{
    public void visitSavings(SavingsAcc a)
    {
        System.out.println("Savings interest " + 100);
    }
    public void visitLoan(LoanAcc a)
    {
        System.out.println("Loan interest " + 99);
    }
}

interface Account
{
    void accept(AccVisitor v);
}

class SavingsAcc implements Account
{
    public void accept(AccVisitor v)
    {
        v.visitSavings(this);
    }
}

class LoanAcc implements Account
{
    public void accept(AccVisitor v)
    {
        v.visitLoan(this);
    }
}



public class Visitor {
    public static void main(String[] args) {
        AccVisitor intt = new Interest();
        Account acc = new SavingsAcc();

        acc.accept(intt);

    }
    
}
