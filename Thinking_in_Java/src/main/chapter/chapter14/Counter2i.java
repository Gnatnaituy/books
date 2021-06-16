package main.chapter.chapter14;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Counter2i extends Applet {

    private class SeparateSubTask extends Thread {
        int count = 0;
        boolean runFlag = true;

        SeparateSubTask() {
            start();
        }

        public void run() {
            while (true) {
                try {
                    sleep(100);
                } catch (InterruptedException ignored) {}
                if (runFlag)
                    t.setText(Integer.toString(count++));
            }
        }
    }

    private SeparateSubTask sp = null;
    private TextField t  = new TextField(5);
    private Button onOff = new Button("Toggle"),
                    start = new Button("Start");

    public void init() {
        add(t);
        start.addActionListener(new StartL());
        add(start);
        onOff.addActionListener(new OnOffL());
        add(onOff);
    }

    class StartL implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (sp == null)
                sp = new SeparateSubTask();
        }
    }

    class OnOffL implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (sp != null)
                sp.runFlag = !sp.runFlag;
        }
    }

    public static void main(String[] args) {
        Counter2i applet = new Counter2i();
        Frame aFrame = new Frame("Counter2i");
        aFrame.addWindowListener(
                new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e) {
                        super.windowClosing(e);
                    }
                }
        );
        aFrame.add(applet, BorderLayout.CENTER);
        aFrame.setSize(240, 320);
        applet.init();
        applet.start();
        aFrame.setVisible(true);
    }
}
