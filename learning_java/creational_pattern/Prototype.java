import java.util.ArrayList;
import java.util.List;

interface Character
{
    Character shallowClone();
    Character deepClone();
}

class Zombie implements Character
{
    int health = 10;
    int x = 20;
    int y = 30;
    List<String> skills = new ArrayList<>();
    

    public Character shallowClone()
    {
        Zombie copy = new Zombie();
        copy.health = health;
        copy.skills = this.skills;

        return copy;
    }

    public Character deepClone()
    {
        Zombie copy = new Zombie();
        copy.health = health;
        copy.skills = new ArrayList<>(this.skills);

        return copy;
    }
}

public class Prototype {
    public static void main(String[] args) {
        Zombie z1 = new Zombie();
        z1.skills.add("Eat");

        System.out.println(z1.skills);

        Zombie z2 = (Zombie) z1.shallowClone();
        Zombie z3 = (Zombie) z1.deepClone();

        z2.skills.add("Bite");

        System.out.println(z1.skills);
        System.out.println(z2.skills);
        System.out.println(z3.skills);
    }
    
}
