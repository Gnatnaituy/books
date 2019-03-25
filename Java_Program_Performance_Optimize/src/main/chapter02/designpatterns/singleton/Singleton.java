package main.chapter02.designpatterns.singleton;

public class Singleton {

    // 构造函数必须为private访问级别的
    private Singleton() {
        System.out.println("Singleton is created");
    }

    // instance成员变量和getInstance()方法必须是static的
    private static Singleton instance = new Singleton();

    public static Singleton getInstance() {
        return instance;
    }

    public static void createString() {
        System.out.println("createString in Singleton");
    }
}
