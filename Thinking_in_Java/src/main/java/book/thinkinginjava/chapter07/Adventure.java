package main.java.book.thinkinginjava.chapter07;

public class Adventure {
    static void t(CanFight x) {x.fight();}
    static void u(CanSwim x) {x.swim();}
    static void v(CanFly x) {x.fly();}
    static void w(ActionCharacter x) {x.fight();}

    public static void main(String[] args) {
        Hero i = new Hero();
        t(i);
        u(i);
        v(i);
        w(i);
    }
}

interface CanFight {
    void fight();
}

interface CanFly {
    void fly();
}

interface CanSwim {
    void swim();
}

class ActionCharacter {
    public void fight() {}
}

class Hero extends ActionCharacter implements CanFight, CanFly, CanSwim {
    public void swim() {}
    public void fly() {}
}