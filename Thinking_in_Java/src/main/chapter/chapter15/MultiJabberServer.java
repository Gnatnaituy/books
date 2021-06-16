package main.chapter.chapter15;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;


public class MultiJabberServer {
    static final int PORT = 8080;

    public static void main(String[] args) throws IOException {
        System.out.println("Started...");
        try (ServerSocket s = new ServerSocket(PORT)) {
            while (true) {
                Socket socket = s.accept();
                try {
                    new ServeOneJabber(socket);
                } catch (IOException e) {
                    socket.close();
                }
            }
        }
    }
}


class ServeOneJabber extends Thread {
    private Socket          socket;
    private BufferedReader  in;
    private PrintWriter     out;

    ServeOneJabber(Socket s) throws IOException {
        socket = s;
        in  = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        start();
    }

    public void run() {
        try {
            while (true) {
                String str = in.readLine();
                if (str.equals("END")) break;
                System.out.println("Echoing: " + str);
                out.println(str);
            }
            System.out.println("Closing...");
        } catch (IOException ignored) {
        } finally {
            try {
                socket.close();
            } catch (IOException ignored) {}
        }
    }
}
