package main.java.book.thinkinginjava.chapter14;


import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class Ticker extends Thread {
    private TextField t = new TextField(10);
    private int count = 0;
    private boolean runFlag = true;

    Ticker(Container c) {
        Button b = new Button("Toggle");
        b.addActionListener(new ToggleL());
        Panel p = new Panel();
        p.add(t);
        p.add(b);
        c.add(p);
    }

    class ToggleL implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            runFlag = !runFlag;
        }
    }

    public void run() {
        while (true) {
            if (runFlag)
                t.setText(Integer.toString(count++));
            try {
                sleep(100);
            } catch (InterruptedException ignored) {}
        }
    }
}


public class Counter4 extends Applet {
    private Button start = new Button("Start");
    private boolean started = false;
    private Ticker[] s;
    private boolean isApplet = true;
    private int size;

    public void init() {
        if (isApplet)
            size = Integer.parseInt(getParameter("size"));
        s = new Ticker[size];
        for (int i = 0; i < s.length; i++)
            s[i] = new Ticker(this);
        start.addActionListener(new StartL());
        add(start);
    }

    public class StartL implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (!started) {
                started = true;
                for (Ticker value : s) value.start();
            }
        }
    }

    public static void main(String[] args) {
        Counter4 applet = new Counter4();
        applet.isApplet = false;
        applet.size = (args.length == 0 ? 5 : Integer.parseInt(args[0]));
        Frame aFrame = new Frame("Counter4");
        aFrame.addWindowListener(
                new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e) {
                        System.exit(0);
                    }
                }
        );
        aFrame.add(applet, BorderLayout.CENTER);
        aFrame.setSize(600, 600);
        applet.init();
        applet.start();
        applet.setVisible(true);
    }
}
