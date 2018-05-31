package main.java.book.thinkinginjava.chapter04;


class Tag {
    Tag(int marker) {
        System.out.println("Tag(" + marker + ")");
    }
}


class Card {
    Tag t1 = new Tag(1); //Before Constructor

    Card() {
        // Indicate we're in the constructor
        System.out.println("Card()");
        t3 = new Tag(333);
    }
    Tag t2 = new Tag(2);

    void f() {
        System.out.println("f()");
    }
    Tag t3 = new Tag(3);
}


public class OrderOfInitialization {
    public static void main(String[] args) {
        Card t = new Card();
        t.f(); // Show that construction is done
    }
}
