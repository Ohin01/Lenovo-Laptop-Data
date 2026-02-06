class OhinException extends Exception
{
    final int val;

    // OhinException(String s) 
    // {
    //     super(s);
    // }

    OhinException(int v) 
    {
        this.val = v;
    }

    public String toString()
    {
        return String.valueOf(val);
    }
}

public class exception{
    public static void main(String[] args) throws Exception{
        int arr[] = new int[10];
        int arr2[] = {1, 2, 3};

        try {
            int x = 10 / 0;
        } finally {
            System.out.println("I WILL EXECUTE NO MATTER WHAT");
        }

        System.out.println(arr.length);
        System.out.println(arr2.length);
    }
    
}
