package main.java.book.thinkinginjava.chapter03;

import java.util.*;


class Number {
    int i;
}

class Letter {
    char c;
}

public class Property {
    public static void main(String[] args) {
        System.out.println(new Date());
        Properties p = System.getProperties();
        p.list(System.out);
        System.out.println("--- Memory Usage:");
        Runtime rt = Runtime.getRuntime();
        System.out.println("Total Memory = "
                            + rt.totalMemory()
                            + " Free Memory = "
                            + rt.freeMemory());
        try {
            Thread.currentThread().sleep(5000);
        } catch(InterruptedException e) {}

        Property.assignment();
        Property.passObject();
    }

    private static void assignment() {
        Number n1 = new Number();
        Number n2 = new Number();
        n1.i = 100;
        n2.i = 500;
        System.out.println("1: n1.i:" + n1.i + " n2.i=" + n2.i);
        n1 = n2;
        System.out.println("2: n1.i:" + n1.i + " n2.i=" + n2.i);
        n1.i = 900;
        System.out.println("3: n1.i:" + n1.i + " n2.i=" + n2.i);
    }

    private static void f(Letter x) {
        x.c = 'z';
    }

    private static void passObject() {
        Letter x = new Letter();
        x.c = 'a';
        System.out.println("1: x.c=" + x.c);
        f(x);
        System.out.println("2: x.c=" + x.c);
    }
}

