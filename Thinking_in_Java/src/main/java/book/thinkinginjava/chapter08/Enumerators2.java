package main.java.book.thinkinginjava.chapter08;

import java.util.*;
import java.io.*;
import java.net.*;

public class Enumerators2 {

    public static void main(String args[]) {
        Vector<Object> v = new Vector<>();
        v.addElement(new File("."));
        v.addElement(new Vector<>());
        v.addElement(new PrintData());
        v.addElement(new Enumerators2());
        v.addElement(new Date());

        Hashtable<Integer, Object> h = new Hashtable<>();
        h.put(1, new Thread());
        h.put(2, ProtocolException.class.getSuperclass());
        h.put(3, v.clone());

        PrintData.print("Vector", v.elements());
        PrintData.print("Hashtable", h.elements());
    }
}


class PrintData {

    static void print(String s, Enumeration<Object> e) {
        System.out.println(s);
        while (e.hasMoreElements()) {
            Object o = e.nextElement();
            System.out.println(o.getClass().getName() + ": " + o.toString());
        }
    }
}
