package test.chapter02;

import main.chapter02.designpatterns.singleton.LazySingleton;
import main.chapter02.designpatterns.singleton.SerSingleton;
import main.chapter02.designpatterns.singleton.Singleton;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class SingletonTest implements Runnable {

    public static void main(String[] args) throws Exception {
        long beginTime = System.currentTimeMillis();
        for (int i = 0; i < 5; i++) {
            new SingletonTest().run();
        }

        System.out.println("Cost time: " + (System.currentTimeMillis() - beginTime) + " ms");

        testSerSingleton();
    }

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            Singleton.getInstance();
            LazySingleton.getInstance();
        }
    }

    public static void testSerSingleton() throws Exception {
        SerSingleton s1 = null;
        SerSingleton s = SerSingleton.getInstance();

        FileOutputStream fos = new FileOutputStream("SerSingleton.txt");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(s);
        oos.flush();
        oos.close();

        FileInputStream fis = new FileInputStream("SerSingleton.txt");
        ObjectInputStream ois = new ObjectInputStream(fis);
        s1 = (SerSingleton) ois.readObject();

        System.out.println(s.equals(s1));
    }
}
