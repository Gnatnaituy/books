package main.chapter.chapter14;

public class SimpleThread extends Thread {
    private int countDown = 5;
    private int threadNumber;
    private static int threadCount = 0;

    private SimpleThread() {
        threadNumber = ++threadCount;
        System.out.println("Making SimpleThread " + threadNumber);
    }

    public void run() {
        while (true) {
            System.out.println("SimpleThread " + threadNumber + "-" + countDown);
            if (--countDown == 0) return;
        }
    }

    public static void main(String[] args) {
        for(int i = 0; i < 5; i ++)
            new SimpleThread().start();
        System.out.println("All threads started");
    }
}
