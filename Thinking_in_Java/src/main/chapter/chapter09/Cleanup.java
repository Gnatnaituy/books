package main.chapter.chapter09;

import java.io.*;


public class Cleanup {
    public static void main(String[] args) {
        try {
            InputFile in = new InputFile("thinking_in_java.iml");
            String s;
            int i = 1;
            while ((s = in.getLine()) != null)
                System.out.println("" + i++ + ": " + s);
            in.cleanup();
        } catch (Exception e) {
            System.out.println("Caught in main, e.printStackTrace():");
            e.printStackTrace();
        }
    }
}


class InputFile {
    private BufferedReader in;
    InputFile(String fname) throws Exception {
        try {
            in = new BufferedReader(new FileReader(fname));
        } catch (FileNotFoundException e) {
            System.out.println("Couldn't open " + fname);
            throw e;
        } catch (Exception e) {
            //All other exceptions must close it
            try {
                in.close();
            } catch (IOException e2) {
                System.out.println("in close unsuccessful");
            }
            throw e;
        } finally {
            // Don't close it here
        }
    }

    String getLine() {
        String s;
        try {
            s = in.readLine();
        } catch (IOException e) {
            System.out.println("readLine() unsuccessful");
            s = "failed";
        }
        return s;
    }

    void cleanup() {
        try {
            in.close();
        } catch (IOException e2) {
            System.out.println("in.close() unsuccessful");
        }
    }
}