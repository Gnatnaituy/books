package main.chapter04;

import java.util.List;
import java.util.Vector;
import java.util.concurrent.*;

public class ThreadPoolDemo {

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 1000; i++) {
            new Thread(new MyThread("testNoThreadPool" + i)).start();
        }
        System.out.println("Create 1000 threads without ThreadPool: "
                + (System.currentTimeMillis() - start) + "ms");

        start = System.currentTimeMillis();
        for (int i = 0; i < 1000; i++) {
            ThreadPool.getInstance().start(new MyThread("testThreadPool" + i));
        }
        System.out.println("Create 1000 threads with ThreadPool: "
                + (System.currentTimeMillis() - start) + "ms");

        ExecutorService executorService = Executors.newCachedThreadPool();
        start = System.currentTimeMillis();
        for (int i = 0; i < 1000; i++) {
            executorService.execute(new MyThread("testJDKThreadPool" + i));
        }
        System.out.println("Create 1000 threads with JDKThreadPool: "
                + (System.currentTimeMillis() - start) + "ms");

        ExecutorService executorServicePriority = new ThreadPoolExecutor(100,
                200, 1L, TimeUnit.SECONDS,
                new PriorityBlockingQueue<>());
        for (int i = 0; i < 1000; i++) {
            executorServicePriority.execute(new MyThread("testThreadPoolExecutorPriority_" + (999 - i)));
        }
    }


    static class ThreadPool {
        private static ThreadPool instance = null;

        // 空闲的线程列队
        private List<PThread> idleThreads;
        // 已有的线程总数
        private int threadCounter;
        private boolean isShutDown = false;

        private ThreadPool() {
            this.idleThreads = new Vector<>(5);
            threadCounter = 0;
        }

        public int getCreatedThreadCount() {
            return threadCounter;
        }

        /**
         * 取得线程池实例
         */
        synchronized static ThreadPool getInstance() {
            if (instance == null)
                instance = new ThreadPool();

            return instance;
        }

        /**
         * 将线程放入池中
         */
        synchronized void repool(PThread repoolingThread) {
            if (!isShutDown) {
                idleThreads.add(repoolingThread);
            } else {
                repoolingThread.shutDown();
            }
        }

        /**
         * 停止池中所有线程
         */
        public synchronized void shutdown() {
            isShutDown = true;
            for (PThread thread : idleThreads) {
                thread.shutDown();
            }
        }

        /**
         * 执行任务
         */
        synchronized void start(Runnable target) {
            PThread thread;

            // 如果有空闲线程, 则直接使用
            if (idleThreads.size() > 0) {
                int lastIndex = idleThreads.size() - 1;
                thread = idleThreads.get(lastIndex);
                idleThreads.remove(lastIndex);
                // 立即执行这个任务
                thread.setTarget(target);
            } else {
                // 没有空闲线程, 则创建新线程
                threadCounter++;
                thread = new PThread(target, "PThread #" + threadCounter, this);
                thread.start();
            }
        }

    }


    /**
     * 这是一个永不退出的线程, 该线程在手动关闭前永不结束, 并一直等待新任务达到
     */
    static class PThread extends Thread {
        private ThreadPool threadPool;
        private Runnable target;
        private boolean isShutDown = false;
        private boolean isIdle = false;

        PThread(Runnable target, String name, ThreadPool threadPool) {
            super(name);
            this.threadPool = threadPool;
            this.target = target;
        }

        public Runnable getTarget() {
            return target;
        }

        public boolean isIdle() {
            return isIdle;
        }

        @Override
        public void run() {
            while (!isShutDown) {
                isIdle = false;
                if (target != null) {
                    target.run();
                }
                // 任务运行结束, 到闲置状态
                isIdle = true;
                try {
                    // 该任务结束后, 不关闭线程, 而是放入线程池空闲列队
                    threadPool.repool(this);
                    synchronized (this) {
                        wait();
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                isIdle = false;
            }
        }

        synchronized void setTarget(java.lang.Runnable newTarget) {
            target = newTarget;
            // 设置任务后, 通知run方法, 开始执行这个任务
            notifyAll();
        }

        /**
         * 关闭线程
         */
        synchronized void shutDown() {
            isShutDown = true;
            notifyAll();
        }
    }



    static class MyThread implements Runnable, Comparable<MyThread> {
        String name;

        public MyThread() {}

        MyThread(String name) {
            this.name = name;
        }

        @Override
        public void run() {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        @Override
        public int compareTo(MyThread o) {
            int me = Integer.parseInt(this.name.split("_")[1]);
            int other = Integer.parseInt(o.name.split("_")[1]);

            return Integer.compare(me, other);
        }
    }
}
