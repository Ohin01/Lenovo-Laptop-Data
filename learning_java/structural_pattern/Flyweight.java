import java.util.HashMap;
import java.util.Map;

class BulletType
{
    int speed;
    String shape;

    public BulletType(int sp, String sh) {
        speed = sp;
        shape = sh;
    }

    void draw(int x, int y)
    {
        System.out.println("I am at" + x + " " + y + "and I am " + shape + " " + speed);
    }
}

class Bullet
{
    int x;
    int y;

    BulletType bulletType;

    public Bullet(int x, int y, BulletType bt) {
        this.x = x;
        this.y = y;
        bulletType = bt;
    }

    void draw()
    {
        bulletType.draw(x, y);
    }
}

class BulletFactory
{
    public Map<String, BulletType> mp = new HashMap<>();

    public BulletType getBulletType(String name, int sp)
    {
        String key = name + sp;

        if (!mp.containsKey(key))
        {
            BulletType bt = new BulletType(sp, name);
            mp.put(name, bt);
        }
        return mp.get(name);
    }

}

public class Flyweight {
    public static void main(String[] args) {
        BulletType bt = new BulletFactory().getBulletType(".45mm", 100);

        Bullet b = new Bullet(0, 0, bt);

        b.draw();

    }
    
}
