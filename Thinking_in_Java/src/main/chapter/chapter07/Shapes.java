package main.chapter.chapter07;
import main.tools.*;

public class Shapes {
    private static Shape randShape() {
        switch ((int) (Math.random() * 3)) {
            default:
            case 0: return new Circle();
            case 1: return new Triangle();
            case 2: return new Square();
        }
    }

    public static void main(String[] args) {
        Shape[] s = new Shape[9];
        for(int i = 0; i < s.length; i++)
            s[i] = randShape();
        for (Shape value : s) {
            value.draw();
            value.erase();
        }
    }
}

abstract class Shape {
    abstract void draw();
    abstract void erase();
}

class Circle extends Shape {
    @Override
    void draw() {
        StdOut.rintln("Circle.draw()");
    }

    @Override
    void erase() {
        StdOut.rintln("Circle.erase()");
    }
}

class Triangle extends Shape {
    @Override
    void draw() {
        StdOut.rintln("Triangle.draw()");
    }

    @Override
    void erase() {
        StdOut.rintln("Triangle.erase()");
    }
}

class Square extends Shape {
    @Override
    void draw() {
        StdOut.rintln("Square.draw()");
    }

    @Override
    void erase() {
        StdOut.rintln("Square.erase()");
    }
}