package main.chapter04.designpattern;

import java.util.*;
import java.util.concurrent.ConcurrentLinkedDeque;

public class MasterWorkerDemo {

    public static void main(String[] args) {
        // Store the final calculate result
        int res = 0;
        Master master = new Master(new PlusWorker(), 5);

        // Submit 100 subtasks
        for (int i = 0; i < 100; i++) {
            master.submit(i);
        }
        master.execute();

        Iterator<Map.Entry<String, Object>> iterator = master.getResultMap().entrySet().iterator();
        while (iterator.hasNext() || !master.isComplete()) {
            res += (Integer) master.getResultMap().get(iterator.next().getKey());
            iterator.remove();
        }

        System.out.println(res);
    }


    static class Master {
        Queue<Object> workQueue = new ConcurrentLinkedDeque<>();
        Map<String, Thread> threadMap = new HashMap<>();    // Worker Thread Map
        Map<String, Object> resultMap = new HashMap<>();    // Result set of subtasks

        /**
         * Master's Constructor
         * @param worker        A subclass of Worker that implemented handle()
         * @param countWorker   Worker count initialized
         */
        Master(Worker worker, int countWorker) {
            worker.setWorkQueue(workQueue);
            worker.setResultMap(resultMap);

            for (int i = 0; i < countWorker; i++) {
                threadMap.put(Integer.toString(i), new Thread(worker, Integer.toString(i)));
            }
        }

        /**
         * Submit a job
         * @param job subtask
         */
        void submit(Object job) {
            workQueue.add(job);
        }

        /**
         * Judge if all the subtasks accomplished
         * @return res
         */
        boolean isComplete() {
            for (Map.Entry<String, Thread> entry : threadMap.entrySet()) {
                if (entry.getValue().getState() != Thread.State.TERMINATED) {
                    return false;
                }
            }

            return true;
        }

        /**
         * @return Result set of subtasks
         */
        Map<String, Object> getResultMap() {
            return resultMap;
        }

        /**
         * Execute all the Worker Thread
         */
        void execute() {
            for (Map.Entry<String, Thread> entry : threadMap.entrySet()) {
                entry.getValue().start();
            }
        }
    }


    static class Worker implements Runnable {
        Queue<Object> workQueue;
        Map<String, Object> resultMap;

        void setWorkQueue(Queue<Object> workQueue) {
            this.workQueue = workQueue;
        }

        void setResultMap(Map<String, Object> resultMap) {
            this.resultMap = resultMap;
        }

        /**
         * Subtask's processing flow, should be implemented in subclass
         * @param input input element
         * @return result
         */
        public Object handle(Object input) {
            return input;
        }

        @Override
        public void run() {
            while (true) {
                // Get subtask
                Object input = workQueue.poll();
                if (input == null) break;
                // Handle subtask
                Object res = handle(input);
                // Write result to result set
                resultMap.put(Integer.toString(input.hashCode()), res);
                // Imitate a complex work
                try {
                    Thread.sleep(5);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }


    /**
     * Implement a subclass of Worker
     */
    static class PlusWorker extends Worker {
        public Object handle(Object input) {
            Integer integer = (Integer) input;
            return integer * integer * integer;
        }
    }
}
