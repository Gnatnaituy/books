package main.java.book.thinkinginjava.chapter15;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;
import java.net.SocketException;

public class NameCollector {
	final static int COLLECTOR_PORT = 8080;
	final static int BUFFER_SIZE	= 1000;
	byte			 buf[]			= new byte[BUFFER_SIZE];

	DatagramPacket dp = new DatagramPacket(buf, buf.length);
	// can listen and send to the same socket
	DatagramSocket 	socket;
	Process 		listmgr;
	PrintStream		nameList;
	DataInputStream	addResult;

	public NameCollector() {
		try {
			listmgr 	= Runtime.getRuntime().exec("listmgr.exe");
			nameList 	= new PrintStream(new BufferedOutputStream(listmgr.getOutputStream()));
			addResult	= new DataInputStream(new BufferedInputStream(listmgr.getInputStream()));
		} catch (IOException e) {
			System.err.println("Can't start listmgr");
			System.exit(1);
		}

		try {
			socket = new DatagramSocket(COLLECTOR_PORT);
			System.out.println("NameCollector server started...");
			while (true) {
				// block until a datagram appears
				socket.receive(dp);
				String rcvd = new String(dp.getData(), 0, 0, dp.getLength());
				// send to listmgr standard input
				nameList.println(rcvd.trim());
				nameList.flush();
				byte[] 	resultBuf	= new byte[BUFFER_SIZE];
				int 	byteCount 	= addResult.read(resultBuf);
				if (byteCount != -1) {
					String result = new String(resultBuf, 0).trim();
					// extract the address and port from the received datagram to find out where to send the reply
					Inet4Address senderAddress = (Inet4Address) dp.getAddress();
					int 	senderPort 	= dp.getPort();
					byte[] 	echoBuf 	= new byte[BUFFER_SIZE];
					result.getBytes(0, byteCount, echoBuf, 0);
					DatagramPacket echo = new DatagramPacket(echoBuf, echoBuf.length, senderAddress, senderPort);
					socket.send(echo);
				} else {
					System.out.println("Unexpected lack of result from listmgr");
				}
			}
		} catch (SocketException e) {
			System.err.println("Can't open socket");
			System.exit(1);
		} catch (IOException e) {
			System.err.println("Communication error");
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new NameCollector();
	}
}
