package main.thread_demo;

import java.sql.Connection;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * @author yutiantang
 * @create 2021/9/2 17:33
 */
public class ConnectionTest {
    static ConnectionPool pool = new ConnectionPool(50);
    static CountDownLatch start = new CountDownLatch(1);
    static CountDownLatch end;

    public static void main(String[] args) throws Exception {
        int threadCount = 20;
        end = new CountDownLatch(threadCount);
        int fetchCount = 20;
        AtomicInteger got = new AtomicInteger();
        AtomicInteger notGot = new AtomicInteger();
        for (int i = 0; i < threadCount; i++) {
            Thread thread = new Thread(new ConnectionRunner(fetchCount, got, notGot), "ConnectionRunner-");
            thread.start();
        }
        System.out.println("generate " + threadCount + " threads finished");
        start.countDown();
        end.await();
        System.out.println("thread count:       " + threadCount);
        System.out.println("total invoke:       " + (threadCount * fetchCount));
        System.out.println("got connection:     " + got);
        System.out.println("not got connection: " + notGot);
        System.out.println("not got percent:    " + ((double) notGot.intValue() / (double) (threadCount * fetchCount)) * 100 + "%");
    }

    static class ConnectionRunner implements Runnable {
        int fetchCount;
        AtomicInteger got;
        AtomicInteger notGot;

        public ConnectionRunner(int fetchCount, AtomicInteger got, AtomicInteger notGot) {
            this.fetchCount = fetchCount;
            this.got = got;
            this.notGot = notGot;
        }

        @Override
        public void run() {
            try {
                start.await();
            } catch (Exception e) {

            }

            while (fetchCount > 0) {
                try {
                    Connection connection = pool.fetchConnection(1000);
                    if (connection != null) {
                        try {
                            connection.createStatement();
                            connection.commit();
                        } finally {
                            pool.releaseConnection(connection);
                            got.incrementAndGet();
                        }
                    } else {
                        notGot.incrementAndGet();
                    }
                } catch (Exception e) {

                } finally {
                    fetchCount--;
                }
            }

            end.countDown();
        }
    }
}
