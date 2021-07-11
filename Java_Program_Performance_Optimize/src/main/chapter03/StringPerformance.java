package main.chapter03;

import java.util.Vector;

public class StringPerformance {

    /*
    String对象的的特点
        - 不变性
        - 针对常量池优化
        - 类的final定义
     */

    public static void main(String[] args) {
        Vector<String> hanlder1 = new Vector<>();
        Vector<String> handler2 = new Vector<>();

        long begin = System.currentTimeMillis();
        for (int i = 0; i < 1000; i++) {
            HugeStr hugeStr = new HugeStr();
            hanlder1.add(hugeStr.getSubString(1, 5));
        }
        System.out.println("HugeStr: " + (System.currentTimeMillis() - begin) + " ms");

        begin = System.currentTimeMillis();
        for (int i = 0; i < 1000; i++) {
            ImprovedHugeStr improvedHugeStr = new ImprovedHugeStr();
            handler2.add(improvedHugeStr.getSubString(1, 5));
        }
        System.out.println("ImprovedHugeStr: " + (System.currentTimeMillis() - begin) + " ms");
    }

    static class HugeStr {
        private final String str = new String(new char[100000]);

        public String getSubString(int begin, int end) {
            return str.substring(begin, end);
        }
    }

    static class ImprovedHugeStr {
        private final String str = new String(new char[100000]);

        public String getSubString(int begin, int end) {
            return new String(str.substring(begin, end));
        }
    }
}
