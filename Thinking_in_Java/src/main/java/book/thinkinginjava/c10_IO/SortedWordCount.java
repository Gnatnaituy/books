package main.java.book.thinkinginjava.chapter10;

import main.java.book.thinkinginjava.chapter08.StrSortVector2;
import java.io.*;
import java.util.*;

public class SortedWordCount {
    private FileInputStream file;
    private StreamTokenizer st;
    private Hashtable counts = new Hashtable();

    SortedWordCount(String filename) throws FileNotFoundException {
        try {
            file = new FileInputStream(filename);
            st = new StreamTokenizer(file);
            st.ordinaryChar('.');
            st.ordinaryChar('-');
        } catch (FileNotFoundException e) {
            System.out.println("Couldn't open " + filename);
            throw e;
        }
    }

    void cleanup() {
        try {
            file.close();
        } catch (IOException e) {
            System.out.println("file.close() unsuccessful");
        }
    }

    void countWords() {
        try {
            while (st.nextToken() != StreamTokenizer.TT_EOF) {
                String s;
                switch (st.ttype) {
                    case StreamTokenizer.TT_EOF:
                        s = "EOL";
                        break;
                    case StreamTokenizer.TT_NUMBER:
                        s = Double.toString(st.nval);
                        break;
                    case StreamTokenizer.TT_WORD:
                        s = st.sval; //already a string
                        break;
                    default:    //single character in ttype
                        s = String.valueOf((char)st.ttype);
                }
                if (counts.containsKey(s))
                    ((Counter)counts.get(s)).increment();
                else
                    counts.put(s, new Counter());
            }
        } catch (IOException e) {
            System.out.println("st.nextToken() unsuccessful");
        }
    }

    Enumeration values() {
        return counts.elements();
    }

    Enumeration keys() {
        return counts.keys();
    }

    Enumeration sortedKeys() {
        Enumeration e = counts.keys();
        StrSortVector2 sv = new StrSortVector2();
        while (e.hasMoreElements())
            sv.addElement((String)e.nextElement());
        return sv.elements();
    }

    Counter getCounter(String s) {
        return (Counter)counts.get(s);
    }

    public static void main(String[] args) {
        try {
            SortedWordCount wc = new SortedWordCount(args[0]);
            wc.countWords();
            Enumeration keys = wc.sortedKeys();
            while (keys.hasMoreElements()) {
                String key = (String)keys.nextElement();
                System.out.println(key + ": " + wc.getCounter(key).read());
            }
            wc.cleanup();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


class Counter {
    private int i = 1;
    int read() { return i; }
    void increment() { i++; }
}

