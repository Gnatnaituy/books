package main.java.book.thinkinginjava.chapter08;

import java.util.*;

public class StrSortVector extends Vector {

    public void sort() {
        quickSort(0, size() - 1);
    }

    private void quickSort(int left, int right) {
        if(right > left) {
            String s1 = (String)elementAt(right);
            int i = left - 1;
            int j = right;
            while (true) {
                while (((String)elementAt(++i)).toLowerCase().compareTo(s1.toLowerCase()) < 0)
                    ;
                while (j > 0)
                    if(((String)elementAt(--j)).toLowerCase().compareTo(s1.toLowerCase()) <= 0)
                        break;
                if(i >= j) break;
                swap(i, j);
            }
            swap(i, right);
            quickSort(left, i - 1);
            quickSort(i + 1, right);
        }
    }

    private void swap(int loc1, int loc2) {
        Object tmp = elementAt(loc1);
        setElementAt(elementAt(loc2), loc1);
        setElementAt(tmp, loc2);
    }

    public static void main(String args[]) {
        StrSortVector sv = new StrSortVector();
        sv.addElement("d");
        sv.addElement("A");
        sv.addElement("C");
        sv.addElement("c");
        sv.addElement("b");
        sv.addElement("B");
        sv.addElement("D");
        sv.addElement("a");
        sv.sort();

        Enumeration e = sv.elements();
        while (e.hasMoreElements())
            System.out.println((String)e.nextElement());
    }
}


