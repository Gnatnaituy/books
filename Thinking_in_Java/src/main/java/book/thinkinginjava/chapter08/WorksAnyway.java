package main.java.book.thinkinginjava.chapter08;

import java.util.*;
import main.java.com.hasaker.tools.P;


public class WorksAnyway {
    public static void main(String[] args) {
        Vector mice = new Vector();
        for (int i = 0; i < 3; i++)
            mice.addElement(new Mouse(i));
        for (int i = 0; i < mice.size(); i++) {
            P.rintln("Free mouse : " + mice.elementAt(i));
            MouseTrap.caughtYa(mice.elementAt(i));
        }
    }
}


class Mouse {
    private int mouseNumber;

    Mouse(int i) {
        mouseNumber = i;
    }

    public String toString() {
        return "This is mouse #" + mouseNumber;
    }

    void print(String msg) {
        if(msg != null)
            P.rintln(msg);
        P.rintln("Mouse number " + mouseNumber);
    }
}


class MouseTrap {
    static void caughtYa(Object m) {
        Mouse mouse = (Mouse)m;
        mouse.print("caught one!");
    }
}