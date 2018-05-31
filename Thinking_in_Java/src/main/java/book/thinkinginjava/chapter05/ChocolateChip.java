package main.java.book.thinkinginjava.chapter05;


public class ChocolateChip extends IceCream {

    private ChocolateChip() {
        System.out.println("ChocolateChip Constructor");
    }

    public static void main(String[] args) {
        ChocolateChip x = new ChocolateChip();
        x.fun();
    }
}
