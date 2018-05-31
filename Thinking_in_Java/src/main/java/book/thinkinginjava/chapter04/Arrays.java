package main.java.book.thinkinginjava.chapter04;

import java.util.*;


class ArrayNew{
    private static Random rand = new Random();
    static int pRand(int mod) {
        return Math.abs(rand.nextInt()) % mod + 1;
    }
}


public class Arrays {
    public static void main(String[] args) {
        int[] a1 = {1,2,3,4,5};
        int[] a2;
        a2 = a1;
        for(int i = 0; i < a2.length; i++)
            a2[i]++;
        for(int i = 0; i < a1.length; i++)
            System.out.println("a1[" + i +"] = " + a1[i]);

        int[] a3 = new int[ArrayNew.pRand(20)];
        System.out.println("Length of a = " + a3.length);
        for(int i = 0; i < a3.length; i++) {
            System.out.println("a3[" + i + "] = " + a3[i]);
        }
    }
}


