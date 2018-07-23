package main.java.book.thinkinginjava.chapter09;

public class LostMessage {
    void f() throws VeryImportantException {
        throw new VeryImportantException();
    }

    void g() throws TrivialException {
        throw new TrivialException();
    }

    public static void main(String[] args) throws Exception {
        LostMessage m = new LostMessage();
        try {
            m.f();
        } finally {
            m.g();
        }
    }
}


class VeryImportantException extends Exception {
    public String toString() {
        return "A very important exception";
    }
}


class TrivialException extends Exception {
    public String toString() {
        return "A trivial exception";
    }
}