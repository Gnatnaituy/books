package main.java.book.thinkinginjava.chapter15;

import java.io.*;
import java.net.Inet4Address;
import java.net.Socket;

public class JabberClient {
    public static void main(String[] args) throws IOException {

        Inet4Address addr = (Inet4Address) Inet4Address.getByName(null);
        System.out.println("addr: " + addr);

        try (Socket socket = new Socket(addr, JabberServer.PORT)) {

            System.out.println("socket = " + socket);

            BufferedReader in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));

            PrintWriter out = new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    socket.getOutputStream())), true);

            for (int i = 0; i < 10; i++) {
                out.println("Howdy " + i);
                String str = in.readLine();
                System.out.println(str);
            }
            out.println("END");
        } finally {
            System.out.println("Closing...");
        }
    }
}
