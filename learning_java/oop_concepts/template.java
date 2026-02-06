class tuple<A, B, C>
{
    private A a;
    private B b;
    private C c;

    tuple(A a, B b, C c) {
        this.a = a;
        this.b = b;
        this.c = c; 
    }

    void show()
    {
         System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}

public class template {
    public static void main(String ohin[])
    {
        tuple<Integer, Integer, Double> tu = new tuple<>(10, 20, 30.54);

        tu.show();

        //  Collections.sort(pairs, new Comparator<Pair<Integer, String>>() {
        //     @Override
        //     public int compare(Pair<Integer, String> p1, Pair<Integer, String> p2) {
        //         // Compare by key (first element)
        //         int keyComparison = p1.getKey().compareTo(p2.getKey());
        //         if (keyComparison != 0) {
        //             return keyComparison;
        //         }
        //         // If keys are equal, compare by value (second element)
        //         return p1.getValue().compareTo(p2.getValue());
        //     }
        // });

    }
    
}
