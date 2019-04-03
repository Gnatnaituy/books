package main.chapter04.designpattern;

public class FutureDemo {

    public static void main(String[] args) {
        Client client = new Client();
        Data data = client.request("Hasaker");
        System.out.println("Query Completed!");

        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Data = " + data.getResult());
    }


    interface Data {
        String getResult();
    }


    static class RealData implements Data {
        final String result;

        RealData(String para) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 10; i++) {
                sb.append(para);
                try {
                    Thread.sleep(100);  // 这里用sleep代替耗时的操作
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            result = sb.toString();
        }

        public String getResult() {
            return result;
        }
    }

    static class FutureData implements Data {
        RealData realData = null; // FutureData类是RealData类的包装
        boolean isReady = false;

        synchronized void setRealData(RealData realData) {
            if (isReady) {
                return;
            }
            this.realData = realData;
            isReady = true;
            notifyAll(); // realData已被注入, 通知getResult()
        }

        public synchronized String getResult() {
            while (!isReady) { // 一直等待, 直到realData被注入
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            return realData.result;
        }
    }
    

    static class Client {
        Data request(final String queryStr) {
            final FutureData futureData = new FutureData();

            new Thread(() -> {
                RealData realData = new RealData(queryStr);
                futureData.setRealData(realData);
            }).start();

            return futureData;
        }
    }
}