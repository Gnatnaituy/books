// Rethrow a different object from the one that was caught

package main.java.book.thinkinginjava.c09_Exception;

public class RethrowNew {
    public static void f() throws Exception {
        System.out.println("Originating the exception in f()");
        throw new Exception("Thrown from f()");
    }

    public static void main(String[] args) {
        try {
            f();
        } catch (Exception e) {
            System.out.println("Caught in main(),e.printStackTrace()");
            e.printStackTrace();
            throw new NullPointerException("From main()");
        }
    }
}
