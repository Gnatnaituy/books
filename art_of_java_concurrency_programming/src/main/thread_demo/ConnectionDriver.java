package main.thread_demo;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.sql.Connection;
import java.util.Objects;
import java.util.concurrent.TimeUnit;

/**
 * @author yutiantang
 * @create 2021/9/2 17:22
 */
public class ConnectionDriver {

    static class ConnectionHandler implements InvocationHandler {

        @Override
        public Object invoke(Object proxy, Method method, Object[] args) throws InterruptedException {
            if (Objects.equals("commit", method.getName())) {
                TimeUnit.MILLISECONDS.sleep(100);
            }
            return null;
        }
    }

    public static Connection createConnection() {
        ClassLoader classLoader = ConnectionDriver.class.getClassLoader();
        Class[] classes = {Connection.class};
        ConnectionHandler connectionHandler = new ConnectionHandler();
        return (Connection) Proxy.newProxyInstance(classLoader, classes, connectionHandler);
    }
}
