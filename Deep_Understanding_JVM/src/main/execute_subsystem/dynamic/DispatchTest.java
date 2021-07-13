package main.execute_subsystem.dynamic;

import java.lang.invoke.MethodHandle;
import java.lang.invoke.MethodHandles;
import java.lang.invoke.MethodType;
import java.lang.reflect.Field;

/**
 * @author yutiantang
 * @create 2021/7/13 10:00
 */
public class DispatchTest {

    class GrandFather {
        void thinking() {
            System.out.println("Grand father thinking");
        }
    }

    class Father extends GrandFather {
        void thinking() {
            System.out.println("Father thinking");
        }
    }

    class Son extends Father {
        void thinking() {
            // 如何在 Son 中调用 GrandFather 的 thinking ?
            System.out.println("Son thinking");

            try {
                MethodType methodType = MethodType.methodType(void.class);
                Field lookupImpl = MethodHandles.Lookup.class.getDeclaredField("IMPL_LOOKUP");
                lookupImpl.setAccessible(true);
                MethodHandle methodHandle = ((MethodHandles.Lookup) lookupImpl.get(null)).findSpecial(GrandFather.class, "thinking", methodType, getClass());
                methodHandle.invoke(this);
            } catch (Throwable throwable) {
                throwable.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        new DispatchTest().new Son().thinking();
    }
}
