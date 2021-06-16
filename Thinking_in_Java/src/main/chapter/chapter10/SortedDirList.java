package main.chapter.chapter10;

import java.io.*;
import main.chapter.chapter08.StrSortVector2;

public class SortedDirList {
    private String[] list;

    public SortedDirList(final String afn) {
        File path = new File(".");
        if(afn == null)
            list = path.list();
        else
            list = path.list( (dir, name) -> {
                        String f = new File(name).getName();
                        return f.contains(afn);
                    });
        sort();
    }

    private void print() {
        for (String aList : list) System.out.println(aList);
    }

    private void sort() {
        StrSortVector2 sv = new StrSortVector2();
        for (String aList : list) sv.addElement(aList);
        // The first time an element is pulled from the StrSortVector the list is sorted
        for (int i = 0; i < list.length; i++)
            list[i] = sv.elementAt(i);
    }

    public static void main(String[] args) {
        SortedDirList sd;
        if(args.length ==0)
            sd = new SortedDirList(null);
        else
            sd = new SortedDirList(args[0]);
        sd.print();
    }
}
