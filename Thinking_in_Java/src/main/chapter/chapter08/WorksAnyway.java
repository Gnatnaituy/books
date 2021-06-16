package main.chapter.chapter08;

import java.util.*;
import main.tools.*;


public class WorksAnyway {
    public static void main(String[] args) {
        Vector mice = new Vector();
        for (int i = 0; i < 3; i++)
            mice.addElement(new Mouse(i));
        for (int i = 0; i < mice.size(); i++) {
            StdOut.rintln("Free mouse : " + mice.elementAt(i));
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
            StdOut.rintln(msg);
        StdOut.rintln("Mouse number " + mouseNumber);
    }
}


class MouseTrap {
    static void caughtYa(Object m) {
        Mouse mouse = (Mouse)m;
        mouse.print("caught one!");
    }
}