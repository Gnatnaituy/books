package main.java.book.thinkinginjava.chapter11;


interface HasBatteries {}
interface WaterProof {}
interface ShootThings {}

class Toy {
    Toy() {}
    Toy(int i) {}
}

class FancyToy extends Toy implements HasBatteries, WaterProof, ShootThings {
    FancyToy() {super(1);}
}

public class ToyTest {
    public static void main(String[] args) {
        Class c = null;
        try {
            c = Class.forName("FancyToy");
        } catch (ClassNotFoundException ignored) {}
        printInfo(c);

        Class[] faces = c.getInterfaces();
        for (Class face : faces) printInfo(face);
        Class cy = c.getSuperclass();
        Object o = null;
        try {
            o = cy.newInstance();
        } catch (InstantiationException | IllegalAccessException ignored) {}
        printInfo(o.getClass());
    }

    static void printInfo(Class cc) {
        System.out.println(
                "Class name: " + cc.getName() + " is interface? [" + cc.isInterface() + "]");
    }
}
