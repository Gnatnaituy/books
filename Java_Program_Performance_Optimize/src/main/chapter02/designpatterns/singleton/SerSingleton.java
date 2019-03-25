package main.chapter02.designpatterns.singleton;

public class SerSingleton implements java.io.Serializable {
    private String name;

    private SerSingleton() {
        System.out.println("Singleton is created");
        name = "SerSingleton";
    }

    private static SerSingleton instance = new SerSingleton();

    public static SerSingleton getInstance() {
        return instance;
    }

    public static void createString() {
        System.out.println("CreateString in Singleton");
    }

    private Object readResolve() {
        return instance;
    }
}
