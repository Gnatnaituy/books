package main.chapter02.designpatterns.singleton;

public class StaticSingleton {

    private StaticSingleton() {
        System.out.println("StaticSingleton created");
    }

    private static class SingletonHolder {
        private static StaticSingleton instance = new StaticSingleton();
    }

    public static StaticSingleton getInstance() {
        return SingletonHolder.instance;
    }
}
