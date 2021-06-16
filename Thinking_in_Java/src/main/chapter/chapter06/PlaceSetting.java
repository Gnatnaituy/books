// :PlaceSetting.java
// Combine Composition and Inheritance

package main.chapter.chapter06;

import main.tools.*;

class Plate {
    Plate(int i) {
        StdOut.rintln(i + " Plate Constructor.");
    }
}

class DinnerPlate extends Plate {
    DinnerPlate(int i) {
        super(i);
        StdOut.rintln(i + " DinnerPlate Constructor.\n");
    }
}

class Utensil {
    Utensil(int i) {
        StdOut.rintln(i + " Utensil Constructor.");
    }
}

class Spoon extends Utensil {
    Spoon(int i) {
        super(i);
        StdOut.rintln(i + " Spoon Constructor.\n");
    }
}

class Fork extends Utensil {
    Fork(int i) {
        super(i);
        StdOut.rintln(i + " Fork Constructor.\n");
    }
}

class Knife extends Utensil {
    Knife(int i) {
        super(i);
        StdOut.rintln(i + " Knife Constructor.\n");
    }
}

class Custom {
    Custom(int i) {
        StdOut.rintln(i + " Custom Constructor.");
    }
}


public class PlaceSetting extends Custom {
    Spoon sp;
    Fork frk;
    Knife kn;
    DinnerPlate pl;
    PlaceSetting(int i) {
        super(i+1);
        sp = new Spoon(i + 2);
        frk = new Fork(i + 3);
        kn = new Knife(i + 4);
        pl = new DinnerPlate(i + 5);
        StdOut.rintln(i + " PlaceSetting Constructor.\n");
    }

    public static void main(String[] args) {
        PlaceSetting x = new PlaceSetting(1);
    }
}