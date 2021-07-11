package main.chapter.chapter14;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Daemon extends Thread {

    private static final int SIZE = 10;
    private final Thread[] t = new Thread[SIZE];

    Daemon() {
        setDaemon(true);
        start();
    }

    public void run() {
        for (int i = 0; i < SIZE; i++)
            t[i] = new DaemonSpawn(i);
        for (int i = 0; i < SIZE; i++)
            System.out.println("t[" + i + "].isDaemon() = " + t[i].isDaemon());
//        while (true) {
//            yield();
//        }
    }

    static class DaemonSpawn extends Thread {
        DaemonSpawn(int i) {
            System.out.println("DaemonSpawn " + i + " started");
            start();
        }

        public void run() {
//            while (true) {
//                yield();
//            }
        }
    }
}


public class Daemons {

    public static void main(String[] args) {
        Thread daemon = new Daemon();
        System.out.println("daemon.isDaemon() = " + daemon.isDaemon());
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("waiting for CR");
        try {
            bufferedReader.readLine();
        } catch (IOException ignored) {
            ignored.printStackTrace();
        }
    }
}
