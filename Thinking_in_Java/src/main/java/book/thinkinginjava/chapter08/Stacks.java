package main.java.book.thinkinginjava.chapter08;

import java.util.*;
import java.io.*;


public class Stacks {

    public static void main(String args[]) throws IOException {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            Stack<String> stk = new Stack<>();
            String s;
            while ((s = in.readLine()) != null)
                stk.push("\n" + s);
            System.out.println("stk = " + stk);
            // Treating a stack as a Vector
            System.out.println("element 5 = " + stk.elementAt(5));
            System.out.println("popping elements: ");
            while (!stk.empty())
                System.out.println(stk.pop());
    }
}
