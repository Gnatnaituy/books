package main.java.book.thinkinginjava.chapter07;

public class Parcel3 {
    private class PContents extends Contents {
        private int i = 11;
        public int value() {return i;}
    }

    protected class PDestination implements Destination {
        private String label;
        private PDestination(String whereTo) {
            label = whereTo;
        }
        public String readLabel() {return label;}
    }

    public Destination dest(String s) {
        return new PDestination(s);
    }

    public Contents conts() {
        return new PContents();
    }
}


abstract class Contents {
    abstract public int value();
}


interface Destination {
    String readLabel();
}


class Test {
    public static void main(String[] args) {
        Parcel3 p = new Parcel3();
        Contents c = p.conts();
        Destination d = p.dest("Tanzania");
    }
}