package main.java.book.thinkinginjava.chapter05;


class SunDae {
    private SunDae() {}
    static SunDae makeSunDae() {
        return new SunDae();
    }
}


public class IceCream {
    public static void main(String[] args) {
        SunDae x = SunDae.makeSunDae();
    }

    protected void fun() {
        System.out.println("A test function.");
    }
}
