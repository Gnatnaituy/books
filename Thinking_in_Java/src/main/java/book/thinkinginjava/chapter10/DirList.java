package main.java.book.thinkinginjava.chapter10;

import java.io.*;

public class DirList{
    public static void main(String[] args) {
        try {
            File path = new File(".");
            String[] list;
            if(args.length == 0)
                list = path.list();
            else
                list = path.list(new DirFilter(args[0]));
            assert list != null;
            for (String aList : list) System.out.println(aList);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


class DirFilter implements FilenameFilter {

    private String afn;

    DirFilter(String afn) {this.afn = afn;}

    public boolean accept(File dir, String name) {
        // Strip path information
        String f = new File(name).getName();
        return f.contains(afn);
    }
}