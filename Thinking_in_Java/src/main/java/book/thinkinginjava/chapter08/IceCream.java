package main.java.book.thinkinginjava.chapter08;

public class IceCream {
    private static String flav[] = {
            "A", "B", "C", "D", "E", "F", "G", "H"
    };

    private static String[] flavorSet(int n) {
        n = Math.abs(n) % (flav.length + 1);
        String results[] = new String[n];
        int picks[] = new int[n];
        for(int i = 0; i < picks.length; i++)
            picks[i] = -1;
        for(int i = 0; i < picks.length; i++) {
            retry:
            while(true) {
                // Randomly choose flavors from flav and place them into results
                int t = (int)(Math.random() * flav.length);
                // Math.random() returns a double value with a positive sign,
                // greater than or equal to 0.0 and less than 1.0.
                for(int j = 0; j < i; j++)
                    if(picks[j] == t) continue retry;
                picks[i] = t;
                results[i] = flav[t];
                break ;
            }

        }
        return results;
    }

    public static void main(String[] args) {
        for(int i = 0; i < 20; i++) {
            System.out.println("flavorSet(" + i + ") = ");
            String fl[] = flavorSet(flav.length);
            for (String aFl : fl) System.out.println("\t" + aFl);
        }
    }
}

