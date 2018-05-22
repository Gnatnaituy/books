# usr/bin/env python
# -*- coding: utf-8 -*-


class LinkedStack:
    """LIFO Stack using a singly linked list as storage."""

    class _Node:
        """Lightweight, nonpublic class for storing a singly linked Node."""

        __slots__ = '_element', '_next'

        def __init__(self, e, next_node):
            self._element = e
            self._next = next_node

    def __init__(self):
        """Create an empty stack."""
        self._head = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def push(self, e):
        self._head = self._Node(e, self._head)    # Create and link a new Node
        self._size += 1

    def top(self):
        if self.is_empty():
            raise Exception('The Stack is empty !')
        return self._head._element

    def pop(self):
        if self.is_empty():
            raise Exception('The Stack is empty !')
        the_element = self._head._element
        self._head = self._head._element
        self._size -= 1
        return the_element


class LinkedQueue:

    class _Node:

        __slots__ = '_element', '_next'

        def __init__(self, e, next_node):
            self._element = e
            self._next = next_node

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def first(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        return self._head.element

    def dequeue(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        the_element = self._head.element
        self._head = self._head._next
        self._size -= 1
        if self.is_empty():
            self._tail = None
        return the_element

    def enqueue(self, e):
        new_node = self._Node(e, None)
        if self.is_empty():
            self._head = new_node
        else:
            self._tail._next = new_node
        self._tail = new_node
        self._size += 1


if __name__ == '__main__':

    stack = LinkedStack()
    for i in range(1, 6):
        stack.push(i)
    pop = stack.top()

    queue = LinkedQueue()
    for i in range(1, 6):
        queue.enqueue(i)
