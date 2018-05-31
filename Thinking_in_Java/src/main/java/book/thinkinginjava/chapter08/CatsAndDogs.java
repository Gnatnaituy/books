package main.java.book.thinkinginjava.chapter08;

import java.util.*;
import main.java.com.hasaker.tools.P;


public class CatsAndDogs {
    public static void main(String[] args) {
        Vector cats = new Vector();
        for (int i = 0; i < 7; i++)
            cats.addElement(new Cat(i));
        cats.addElement(new Dog(7));
        for (int i = 0; i < cats.size(); i++)
            ((Cat)cats.elementAt(i)).print();
    }
}


class Cat {
    private int catNumber;
    Cat(int i) {
        catNumber = i;
    }
    void print() {
        P.rintln("Cat #" + catNumber);
    }
}


class Dog {
    private int dogNumber;
    Dog(int i) {
        dogNumber = i;
    }
    void print() {
        P.rintln("Dog #" + dogNumber);
    }
}

