package main.java.book.thinkinginjava.chapter08;

import java.util.Vector;

class GopherVector {

    private Vector v = new Vector();

    private void addElement(Gopher m) {
        v.addElement(m);
    }

    private Gopher elementAt(int index) {
        return (Gopher)v.elementAt(index);
    }

    private int size() {
        return v.size();
    }

    public static void main(String args[]) {
        GopherVector gophers = new GopherVector();
        for(int i = 0; i < 3; i++)
            gophers.addElement(new Gopher(i));
        for(int i = 0; i < 3; i++)
            GopherTrap.caughtYa(gophers.elementAt(i));
        System.out.println(gophers.size());
    }

}


class Gopher {

    private int gopherNumber;

    Gopher(int i) {
        gopherNumber = i;
    }

    void print(String msg) {
        if(msg != null) System.out.println(msg);
        System.out.println("Gopher Number " + gopherNumber);
    }
}


class GopherTrap {

    static void caughtYa(Gopher m) {
        m.print("Caught one !");
    }
}