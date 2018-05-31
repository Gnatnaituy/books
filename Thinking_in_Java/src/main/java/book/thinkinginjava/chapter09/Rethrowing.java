package main.java.book.thinkinginjava.chapter09;

public class Rethrowing {

    public static void f() throws Exception {
        throw new Exception("Thrown from f()");
    }

    public static void g() throws Throwable {
        try {
            f();
        } catch (Exception e) {
            e.printStackTrace();
            throw e.fillInStackTrace();
        }
    }

    public static void main(String[] args) throws Throwable {
        try {
            g();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
