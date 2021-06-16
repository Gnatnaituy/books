package main.chapter.chapter07;
import main.tools.*;

public class Music {
    public static void tune(Instrument i) {
        i.play(Note.middleC);
    }
    public static void main(String[] args) {
        Wind flute = new Wind();
        tune(flute);
    }
}

class Note {
    private int value;
    private Note(int val) {val = value;}
    public static final Note
        middleC = new Note(0),
        cSharp = new Note(1),
        cFlat = new Note(2);
}

class Instrument {
    public void play(Note n) {
        StdOut.rintln("Instrument.play()");
    }
}

class Wind extends Instrument {
    public void play(Note n) {
        StdOut.rintln("Wind.play()");
    }
}

