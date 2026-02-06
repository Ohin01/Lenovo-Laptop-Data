class objects_string
{
    void print()
    {
        String s = "OHIN";
        String s1 = "OHIN";
        String s2 = new String("OHIN");

        System.out.println(s == s1); //true
        System.out.println(s == s2); //false

        s += 'S'; //creates a new string

        //s.charAt(0) = 'L'; //not allowed

        char chars[] = {'a', 'b', 'c'};
        byte[] ascii = {65,66, 67}; //"int" not allowed

        String ch = new String(chars);
        String ch2 = new String(chars, 1, 2);
        String ch3= new String(ascii);
    }

}

class Valueof_and_tostring
{
    void print()
    {
        int ab = 10;
        String aaa = String.valueOf(ab);

        int ab2 = 20;
        //String aaa2 = ab.toString(); // not allowed

        Integer ac = 20;
        String aac = ac.toString(); //allowed (as Integer is a class)

        Object o = null;
        String ooo = String.valueOf(o); //contains "null"
        String ooo2 = o.toString(); // gives error of NullPointerException
    }
}

class extraction_and_comp
{
    void print()
    {
        String s = "abcdef";

        char[] alp = {'a', '\0', 'b'};

        char[] ch = new char[10]; //all elements are \0
        ch[5] = 'a'; //rest are \0, and doesnt hinder printing

        s.getChars(1, 3, ch, 2);

        System.out.println(alp); //print ab
    }
}

public class strings {
    public static void main(String[] args) {
       extraction_and_comp e = new extraction_and_comp();

       e.print();

    }
}
