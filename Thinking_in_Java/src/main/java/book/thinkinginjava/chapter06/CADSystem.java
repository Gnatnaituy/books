package main.java.book.thinkinginjava.chapter06;
import main.java.com.hasaker.tools.P;

public class CADSystem extends Shape {
    private Circle c;
    private Triangle t;
    private Line[] lines = new Line[10];

    CADSystem(int i) {
        super(i + 1);
        for(int j = 0; j < 10; j++)
            lines[j] = new Line(j, j*j);
        c = new Circle(1);
        t = new Triangle(1);
        P.rintln("Combined Constructor");
    }

    void cleanup() {
        P.rintln("CADSystem.cleanup()");
        t.cleanup();
        c.cleanup();
        for(int i=0; i < lines.length; i++)
            lines[i].cleanup();
        super.cleanup();
    }

    public static void main(String[] args) {
        CADSystem x = new CADSystem(47);
        try { } finally {
            x.cleanup();
        }
    }
}

class Shape {
    Shape(int i) {
        P.rintln("Shape Constructor");
    }
    void cleanup() {
        P.rintln("Shape Cleanup");
    }
}

class Circle extends Shape {
    Circle(int i) {
        super(i);
        P.rintln("Drawing a Circle");
    }
    void cleanup() {
        P.rintln("Erasing a Circle");
        super.cleanup();
    }
}

class Triangle extends Shape {
    Triangle(int i) {
        super(i);
        P.rintln("Drawing a Triangle");
    }
    void cleanup() {
        P.rintln("Erasing a Triangle");
        super.cleanup();
    }
}

class Line extends Shape {
    private int start, end;
    Line(int start, int end) {
        super(start);
        this.start = start;
        this.end = end;
        P.rintln("Drawing a Line: " + start + ", " + end);
    }
    void cleanup() {
        P.rintln("Erasing a Line: " + start + ", " + end);
        super.cleanup();
    }
}