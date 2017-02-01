# usr/bin/env python
# -*- coding: utf-8 -*-


class CircularQueue:

    class _Node:

        __slots__ = '_element', '_next'

        def __init__(self, e, next_node):
            self._element = e
            self._next = next_node

    def __init__(self):
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size

    # -----------------------------------Accessors-----------------------------------------
    def is_empty(self):
        return self._size == 0

    def first(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        return self._tail._next._element

    def last(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        return self._tail._element

    # -----------------------------------Mutators-------------------------------------------
    def dequeue(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        old_head = self._tail._next
        if self._size == 1:
            self._tail = None
        else:
            self._tail.next = old_head.next_node
            self._size -= 1
        return old_head._element

    def enqueue(self, e):
        new_node = self._Node(e, None)
        if self.is_empty():
            new_node._next = new_node
        else:
            new_node._next = self._tail._next
            self._tail._next = new_node
        self._tail = new_node
        self._size += 1

    def rotate(self):
        if self._size > 0:
            self._tail = self._tail._next
