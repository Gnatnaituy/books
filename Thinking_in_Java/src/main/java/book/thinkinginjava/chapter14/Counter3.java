package main.java.book.thinkinginjava.chapter14;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Counter3 extends Applet implements Runnable {

    private int count = 0;
    private boolean runFlag = true;
    private Thread selfThread = null;
    private Button start = new Button("Start"),
                    onOff = new Button("Toggle");
    private TextField t = new TextField(8);

    public void init() {
        add(t);
        start.addActionListener(new StartL());
        add(start);
        onOff.addActionListener(new OnOffL());
        add(onOff);
    }

    public void run() {
        while (true) {
            try {
                selfThread.sleep(100);
            } catch (InterruptedException ignored) {}
            if (runFlag)
                t.setText(Integer.toString(count++));
        }
    }

    class StartL implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (selfThread == null) {
                selfThread = new Thread(Counter3.this::init);
                selfThread.start();
            }
        }
    }

    class OnOffL implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            runFlag = !runFlag;
        }
    }

    public static void main(String[] args) {
        Counter3 applet  = new Counter3();
        Frame aFrame = new Frame("Counter3");
        aFrame.addWindowListener(
                new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e) {
                        super.windowClosing(e);
                    }
                }
        );
        aFrame.add(applet, BorderLayout.CENTER);
        aFrame.setSize(300, 200);
        applet.init();
        applet.start();
        aFrame.setVisible(true);
    }
}
