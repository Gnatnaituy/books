package main.chapter.chapter09;

public class Rethrowing {

    private static void f() throws Exception {
        throw new Exception("Thrown from f()");
    }

    private static void g() throws Throwable {
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
