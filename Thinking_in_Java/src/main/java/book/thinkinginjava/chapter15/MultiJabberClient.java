package main.java.book.thinkinginjava.chapter15;

import java.io.*;
import java.net.Inet4Address;
import java.net.Socket;

public class MultiJabberClient {
    private static final int MAX_THREADS = 40;

    public static void main(String[] args) throws IOException, InterruptedException {

        Inet4Address addr = (Inet4Address) Inet4Address.getByName(null);

        while (true) {
            if(JabberClientThread.threadCount() < MAX_THREADS)
                new JabberClientThread(addr);
            Thread.sleep(100);
        }
    }
}


class JabberClientThread extends Thread {
    private Socket          socket;
    private BufferedReader  in;
    private PrintWriter     out;
    private static int      counter         = 0;
    private int             id              = counter++;
    private static int      threadcount     = 0;

    static int threadCount() {
        return threadcount;
    }

    JabberClientThread(Inet4Address addr) {
        System.out.println("Making client " + id);
        threadcount++;

        try {
            socket = new Socket(addr, MultiJabberServer.PORT);
        } catch (IOException ignored) {}

        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
            start();
        } catch (IOException e) {
            try {
                socket.close();
            } catch (IOException ignored) {}
        }
    }

    public void run() {
        try {
            for (int i = 0; i < 25; i++) {
                out.println("Client " + id + ": " + i);
                String str = in.readLine();
                System.out.println(str);
            }
            out.println("END");
        } catch (IOException ignored) {
        } finally {
            try {
                socket.close();
            } catch (IOException ignored) {}
            threadcount++;
        }
    }
}