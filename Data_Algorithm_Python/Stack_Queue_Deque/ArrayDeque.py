# usr/bin/env python
# -*- coding: utf-8 -*-


class ArrayDeque:
    """Double ended queue implementation using
    Python list as underlying storage"""

    DEFAULT_CAPACITY = 10

    def __init__(self):
        self.data = [None] * ArrayDeque.DEFAULT_CAPACITY
        self.size = 0
        self.front = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def increase_size(self):
        """Increase the queue by DEFAULT_CAPACITY"""

        old = self.data
        self.data = [None] * (self.size + ArrayDeque.DEFAULT_CAPACITY)
        walk = self.front
        for k in range(self.size):
            self.data[k] = old[walk]
            walk = (1 + walk) % len(old)
        self.front = 0

    def first(self):
        if self.is_empty():
            raise Exception('The deque is empty !')
        return self.data[self.front]

    def last(self):
        if self.is_empty():
            raise Exception('The deque is empty !')
        return self.data[self.size]

    def add_first(self, element):
        pass

    def add_last(self, element):
        """Add an element to the back of the deque."""

        if self.size == len(self.data):
            self.increase_size()
        avail = (self.front + self.size) % len(self.data)
        self.data[avail] = element
        self.size += 1

    def delete_first(self):
        pass

    def delete_last(self):
        pass
