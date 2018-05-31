package main.java.book.thinkinginjava.chapter08;

import java.util.*;

public class StrSortVector2 {

    private StrSortVector v = new StrSortVector();
    private boolean sorted = false;

    public void addElement(String s) {
        v.addElement(s);
        sorted = false;
    }

    public String elementAt(int index) {
        if(!sorted) {
            v.sort();
            sorted = true;
        }
        return (String)v.elementAt(index);
    }

    public Enumeration elements() {
        if(!sorted) {
            v.sort();
            sorted = true;
        }
        return v.elements();
    }

    public static void main(String args[]) {
        StrSortVector2 sv = new StrSortVector2();
        sv.addElement("d");
        sv.addElement("A");
        sv.addElement("C");
        sv.addElement("c");
        sv.addElement("b");
        sv.addElement("B");
        sv.addElement("D");
        sv.addElement("a");

        Enumeration e = sv.elements();
        while (e.hasMoreElements())
            System.out.println((String)e.nextElement());
    }
}
