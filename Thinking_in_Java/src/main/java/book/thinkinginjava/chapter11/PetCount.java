package main.java.book.thinkinginjava.chapter11;

import java.util.*;

class                   Pet {}
class Dog       extends Pet {}
class Cat       extends Pet {}
class Pug       extends Pet {}
class Rodent    extends Pet {}
class Gerbil    extends Pet {}
class Hamster   extends Pet {}

class Counter { int i; }

public class PetCount {
    static String[] typenames = {
            "Pet", "Dog", "Cat", "Pug", "Rodent", "Gerbil", "Hamster"
    };

    public static void main(String[] args) {
        Vector pets = new Vector();
        try {
            Class[] petTypes = {
                    Class.forName("main.java.book.thinkinginjava.chapter11.Cat"),
                    Class.forName("main.java.book.thinkinginjava.chapter11.Dog"),
                    Class.forName("main.java.book.thinkinginjava.chapter11.Pug"),
                    Class.forName("main.java.book.thinkinginjava.chapter11.Rodent"),
                    Class.forName("main.java.book.thinkinginjava.chapter11.Gerbil"),
                    Class.forName("main.java.book.thinkinginjava.chapter11.Hamster"),
            };
            for (int i = 0; i < 15; i++)
                pets.addElement(petTypes[(int)(Math.random()*petTypes.length)].newInstance());
        } catch (InstantiationException | ClassNotFoundException | IllegalAccessException e) {}

        Hashtable h = new Hashtable();
        for (int i = 0; i < typenames.length; i++)
            h.put(typenames[i], new Counter());
        for (int i = 0; i < pets.size(); i++) {
            Object o = pets.elementAt(i);
            if(o instanceof Pet)
                ((Counter)h.get("Pet")).i++;
            if(o instanceof Dog)
                ((Counter)h.get("Dog")).i++;
            if(o instanceof Pug)
                ((Counter)h.get("Pug")).i++;
            if(o instanceof Cat)
                ((Counter)h.get("Cat")).i++;
            if(o instanceof Hamster)
                ((Counter)h.get("Hamster")).i++;
            if(o instanceof Rodent)
                ((Counter)h.get("Rodent")).i++;
            if(o instanceof Gerbil)
                ((Counter)h.get("Gerbil")).i++;
        }
        for (int i = 0; i < pets.size(); i++)
            System.out.println(pets.elementAt(i).getClass().toString());
        for (String typename : typenames)
            System.out.println("quantity " + typename + ": " + ((Counter) h.get(typename)).i);
    }
}
