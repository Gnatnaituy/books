package main.chapter05;

public class TestStack {
    private static int count1 = 0;
    private static int count2 = 0;

    // 通过 -Xss 参数不断增加栈空间后, 栈深度会明显增加
    public static void main(String[] args) {
        try {
//            recursion();
//            recursionWithParaAndVars(1L, 2L, 3L);
            permGenGC();
        } catch (Throwable e) {
//            System.out.println("Depth of stack is " + count1);
//            System.out.println("Depth of stack is " + count2);
            //e.printStackTrace();
        }
    }

    private static void recursion() {
        count1++;
        recursion();
    }

    // 增加了参数和局部变量, 栈帧变大, 相同 -Xss 参数下, 栈深度明显减小
    private static void recursionWithParaAndVars(long a, long b, long c) {
        long d = 0;
        long e = 0;
        long f = 0;
        count2++;
        recursionWithParaAndVars(a, b, c);
    }

    private static void permGenGC() {
        for (int i = 0; i < Integer.MAX_VALUE; i++) {
            String t = String.valueOf(i).intern();
        }
    }
}
