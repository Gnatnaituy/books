package main.java.book.thinkinginjava.chapter07;

public class WIndError {
    public static void tune(InstrumentX i) {
        i.play(NoteX.MIDDLE_C);
    }
    public static void main(String[] args) {
        WindX flute = new WindX();
        tune(flute);
    }
}

class NoteX {
    public static final int
        MIDDLE_C = 0, C_SHARP = 1, C_FLAT = 2;
}

class InstrumentX {
    public void play (int NoteX) {
        System.out.println("InstrumentX.play()");
    }
}

class WindX extends InstrumentX {
    public void play(NoteX n) {
        System.out.println(("WindX.play(NoteX n)"));
    }
}
