package main.chapter04.designpattern;

import java.util.LinkedList;

public class GuardedSuspensionDemo {

    public static void main(String[] args) {
        RequestQueue requestQueue = new RequestQueue();

        for (int i = 0; i < 10; i++) {
            new ServerThread(requestQueue, "ServerThread" + i).start();
        }

        for (int i = 0; i < 10; i++) {
            new ClientThread(requestQueue, "ClientThread" + i).start();
        }
    }

    static class Request {
        private String name;

        public Request(String name) {
            this.name = name;
        }

        public String getName() {
            return name;
        }

        @Override
        public String toString() {
            return "[Request " + name + "]";
        }
    }


    static class RequestQueue {
        private LinkedList<Request> queue = new LinkedList<>();

        public synchronized Request getRequest() {
            // Wait until new Request added
            while (queue.size() == 0) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            // Return the first Request in queue
            return queue.remove();
        }

        public synchronized void addRequest(Request request) {
            queue.add(request);
            notifyAll();
        }
    }


    static class ServerThread extends Thread {
        private RequestQueue requestQueue;

        public ServerThread(RequestQueue requestQueue, String name) {
            super(name);
            this.requestQueue = requestQueue;
        }

        @Override
        public void run() {
            while (true) {
                final Request request = requestQueue.getRequest();
                try {
                    // Imitate cost time for handle request
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName() + " handles " + request);
            }
        }
    }


    static class ClientThread extends Thread {
        private RequestQueue requestQueue;

        public ClientThread(RequestQueue requestQueue, String name) {
            super(name);
            this.requestQueue = requestQueue;
        }

        @Override
        public void run() {
            for (int i = 0; i < 10; i++) {
                Request request = new Request("RequestID:" + i
                        + "  ThreadName: " + Thread.currentThread().getName());
                System.out.println(Thread.currentThread().getName() + " requests " + request);
                requestQueue.addRequest(request);
                try {
                    // The speed of requests produced from Client is faster than
                    // the speed of requests handled by Server
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("ClientThread Name is: " + Thread.currentThread().getName());
            }
            System.out.println(Thread.currentThread().getName() + " request end");
        }
    }
}
