package main.java.book.thinkinginjava.chapter09;

public class OnOffSwitch {
    static Switch sw = new Switch();
    public static void main(String[] args) {
        try {
            sw.on();
            sw.off();
        } catch (NullPointerException e) {
            System.out.println("NullPointException");
        } catch (IllegalArgumentException e) {
            System.out.println("IOException");
        } finally {
            sw.off();
        }
    }
}

class Switch {
    boolean state = false;
    boolean read() { return state; }
    void on() { state = true; }
    void off() { state = false; }
}
