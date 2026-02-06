import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class input_math {
    public static void main(String ohin[]) throws IOException
    {

        Random r = new Random();
        Scanner sc = new Scanner(System.in);

        FileReader fin = new FileReader("in.txt");
        FileWriter fout = new FileWriter("out.txt");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader normally = new BufferedReader(new FileReader("in.txt"));

        ObjectInputStream oin = new ObjectInputStream(new FileInputStream("in.dat"));
        Integer s = (Integer) oin.readObject();

        FileInputStream fin2 = new FileInputStream("in.dat");
        byte st = (byte)fin2.read();


        int a = br.read();
        Scanner re = new Scanner(fin);



        fout.write("Ohin hi hi Ariba");
        fout.close();

        //String s = sc.next(); //creates new string

        //System.out.println(s);

        System.out.println("\077" + "\u0077");

        // System.out.println("Absolute: " + Math.abs(a));
        // System.out.println("Square root: " + Math.sqrt(b));
        // System.out.println("Power: " + Math.pow(2, 3));
        // System.out.println("Max: " + Math.max(a, b));
        // System.out.println("Random: " + Math.random()); //returns from 0.0 to 1.0
        // System.out.println("Ceil: " + Math.ceil(a));
        // System.out.println("Floor: " + Math.floor(a));
        int a[][] = new int[3][];
        a[2] = new int[10];
        a[0] = new int[] {1, 2};
        int c[][] = {{1, 2, 3}, new int[4]};
        //a[0] = {1, 2} not allowed
        //nullpointer for a[1].length as not assigned

        int b[] = {1, 2, 3};
        System.out.println(c[0].length + " " +  c[1].length);

        
    }
    
}
