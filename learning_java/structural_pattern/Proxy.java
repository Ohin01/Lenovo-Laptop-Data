interface Website
{
    void use(String user);
}

class RealServer implements Website
{
    public void use(String user)
    {
        System.out.println("Real Server Loaded");
    }
}

class ProxyServer implements Website
{
    private RealServer server;

    public void use(String user)
    {
        if (user.equalsIgnoreCase("Ohin"))
        {
            server = new RealServer();
            server.use(user);
        }
    }
}

public class Proxy {
    public static void main(String[] args) {
        Website web = new ProxyServer();

        web.use("Ohin");
    }
    
}
