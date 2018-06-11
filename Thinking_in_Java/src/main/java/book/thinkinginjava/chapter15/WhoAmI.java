package main.java.book.thinkinginjava.chapter15;

import java.net.Inet4Address;

public class WhoAmI {
    public static void main(String[] args) throws Exception {
            if (args.length != 1) {
                System.err.println("Usage: WhoAmI MachineName");
                System.exit(1);
            }
            Inet4Address a = (Inet4Address) Inet4Address.getByName(args[0]);
            System.out.println(a);
    }
}
