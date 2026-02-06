class exam {
    static int compute()
    {
        try
        {
            return 10;
        } finally 
        {
            return 20;
        }
    }
    public static void main(String arg[])
    {
        System.out.println(compute());
        
    }
}
