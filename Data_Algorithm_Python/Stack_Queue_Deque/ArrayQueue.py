# usr/bin/env python
# -*- coding: utf-8 -*-


class ArrayQueue:
    """LILO queue implementation using a Python list as underlying storage."""

    DEFAULT_CAPACITY = 10

    def __init__(self):
        self._data = [None] * ArrayQueue.DEFAULT_CAPACITY
        self._size = 0
        self._front = 0

    def __len__(self):
        return self._size

    def increase_size(self):
        """Increase the queue by DEFAULT_CAPACITY"""

        old = self._data
        self._data = [None] * (self._size + ArrayQueue.DEFAULT_CAPACITY)
        walk = self._front
        for k in range(self._size):
            self._data[k] = old[walk]
            walk = (1 + walk) % len(old)
        self._front = 0

    def is_empty(self):
        return self._size == 0

    def first(self):
        """Return (But not remove ) the first element of the queue.
        Raise Empty exception if the queue is empty."""

        if self.is_empty():
            raise Exception('The queue is empty !!!')
        return self._data[self._front]

    def dequeue(self):
        """Return and Remove the first element of the queue."""

        if self.is_empty():
            raise Exception('The queue is empty !!!')
        answer = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1) % len(self._data)
        self._size -= 1
        return answer

    def enqueue(self, e):
        """Add an element to the back of the queue."""

        if self._size == len(self._data):
            self.increase_size()
        avail = (self._front + self._size) % len(self._data)
        self._data[avail] = e
        self._size += 1


if __name__ == '__main__':
    queue_example = ArrayQueue()
    print('Is queue_example empty :', queue_example.is_empty())
    for i in range(10):
        queue_example.enqueue(i)
    print('queue_example after enqueue: ', queue_example._data)
    queue_example.dequeue()
    print('queue_example after dequeue: ', queue_example._data)
    print('The first of queue_example :', queue_example.first())
    queue_example.increase_size()
