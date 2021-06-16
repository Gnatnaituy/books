package main.chapter.chapter15;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class JabberServer {
    static final int PORT = 4399;

    public static void main(String[] args) throws IOException  {
        ServerSocket s = new ServerSocket(PORT);
        System.out.println("Started:  " + s);
        try (s) {
            // Blocks until a connection occurs
            try (Socket socket = s.accept()) {
                System.out.println("Connection accepted: " + socket);
                BufferedReader in =
                        new BufferedReader(
                                new InputStreamReader(
                                        socket.getInputStream()));

                // Output is automatically flushed by PrintWriter
                PrintWriter out =
                        new PrintWriter(
                                new BufferedWriter(
                                        new OutputStreamWriter(
                                                socket.getOutputStream())), true);

                while (true) {
                    String str = in.readLine();
                    if (str.equals("END"))
                        break;
                    System.out.println("Echoing: " + str);
                    out.println(str);
                }
                // always close the two sockets
            } finally {
                System.out.println("Closing...");
            }
        }
    }
}
