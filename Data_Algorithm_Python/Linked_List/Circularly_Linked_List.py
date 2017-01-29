# usr/bin/env python
# -*- coding: utf-8 -*-


class CircularQueue:

    class Node:

        slots = 'element', 'next_node'

        def __init__(self, element, next_node):
            self.element = element
            self.next_node = next_node

    def __init__(self):
        self.tail = None
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def first(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        head = self.tail.next_node
        return head.element

    def dequeue(self):
        if self.is_empty():
            raise Exception('The Queue is empty !')
        old_head = self.tail.next_node
        if self.size == 1:
            self.tail = None
        else:
            self.tail.next = old_head.next_node
            self.size -= 1
        return old_head.element

    def enqueue(self, element):
        new_node = self.Node(element, None)
        if self.is_empty():
            new_node.next_node = new_node
        else:
            new_node.next_node = self.tail.next_node
            self.tail.next_node = new_node.next_node
        self.tail = new_node
        self.size += 1

    def rotate(self):
        if self.size > 0:
            self.tail = self.tail.next


if __name__ == '__main__':
    circularly_queue = CircularQueue()
    for i in range(5):
        circularly_queue.enqueue(i)
    circularly_queue.rotate()
