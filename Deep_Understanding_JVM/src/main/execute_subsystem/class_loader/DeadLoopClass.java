package main.execute_subsystem.class_loader;

/**
 * @author yutiantang
 * @create 2021/7/11 19:19
 */
public class DeadLoopClass {

    static {
        if (true) {
            System.out.println(Thread.currentThread() + " init DeadLoopClass");
            while (true) {

            }
        }
    }

    public static void main(String[] args) {
        Runnable script = () -> {
            System.out.println(Thread.currentThread() + " start");
            DeadLoopClass dlc = new DeadLoopClass();
            System.out.println(Thread.currentThread() + " run over");
        };

        Thread t1 = new Thread(script);
        Thread t2 = new Thread(script);
        t1.start();
        t2.start();
    }
}
