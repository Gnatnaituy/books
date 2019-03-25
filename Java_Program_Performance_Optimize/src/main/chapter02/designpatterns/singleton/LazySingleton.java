package main.chapter02.designpatterns.singleton;

public class LazySingleton {

    private LazySingleton() {
        System.out.println("LazySingleton is created");
    }

    private static LazySingleton instance = null;

    // getInstance()方法必须同步
    public static synchronized LazySingleton getInstance() {
        if (instance == null)
            instance = new LazySingleton();

        return instance;
    }
}
