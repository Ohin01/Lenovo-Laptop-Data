import java.util.ArrayList;

public class replaceCheck {
    public String replace(String text, String oldWord, String newWord){
        // TODO: implement a case-insensitive replace of all occurrences
       String newtext = "";
       String lowertext = text.toLowerCase();

       String lowerold = oldWord.toLowerCase();

       ArrayList<Integer> allInds = new ArrayList<>();

       int st = 0;

       while (true)
       {
            int ind = lowertext.indexOf(lowerold, st);

            if (ind == -1)
            break;

            allInds.add(ind);
            st = ind + 1;
       }

       for (int i = 0; i < text.length(); i++)
       {
            if (allInds.contains(i))
            {
                newtext = newtext + newWord;
                i += oldWord.length() - 1;
            }

            else
            {
                newtext = newtext + text.charAt(i);
            }
       }
       
        return newtext;
        //throw new UnsupportedOperationException("TODO");
    }
    public static void main(String[] args) {
        String text = "Java is bad java";

        replaceCheck rc = new replaceCheck();
        
        System.out.println(rc.replace(text, "java", "Old"));
    }
}
