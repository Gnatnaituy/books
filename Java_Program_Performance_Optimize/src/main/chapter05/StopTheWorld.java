package main.chapter05;

import java.util.HashMap;

public class StopTheWorld {

    public static void main(String[] args) {
        MyThread t = new MyThread();
        PrintThread p = new PrintThread();
        t.start();
        p.start();
    }


    public static class MyThread extends Thread {
        HashMap<Long, byte[]> hashMap = new HashMap<>();

        @Override
        public void run() {
            try {
                while (true) {
                    if (hashMap.size() * 512 / 1024 / 1024 >= 400) {
                        hashMap.clear();
                        System.out.println("Clean hashMap");
                    }
                    byte[] b1;
                    for (int i = 0; i < 100; i++) {
                        b1 = new byte[512];
                        hashMap.put(System.nanoTime(), b1);
                    }
                    Thread.sleep(1);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }


    public static class PrintThread extends Thread {
        static final long startTime = System.currentTimeMillis();

        @Override
        public void run() {
            try {
                while (true) {
                    long t = System.currentTimeMillis() - startTime;
                    System.out.println(t / 1000 + "." + t % 1000);
                    Thread.sleep(100);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
