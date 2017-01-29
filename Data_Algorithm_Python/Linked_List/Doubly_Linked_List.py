# usr/bin/env python
# -*- coding: utf-8 -*-


class DoublyLinkedBase:
    """A base class providing a doubly linked list  representation."""

    class Node:

        def __init__(self, element, prev_node, next_node):
            self.element = element
            self.prev_node = prev_node
            self.next_node = next_node

    def __init__(self):
        self.header = self.Node(None, None, None)
        self.trailer = self.Node(None, None, None)
        self.header.next_node = self.trailer
        self.trailer.prev_node = self.header
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def insert_between(self, element, predecessor, successor):
        """Add element between two existing Nodes."""
        new_node = self.Node(element, predecessor, successor)
        predecessor.next_node = new_node
        successor.prev_node = new_node
        self.size += 1
        return new_node

    def delete_node(self, node):
        predecessor = node.prev_node
        successor = node.next_node
        predecessor.next_node = successor
        successor.prev_node = predecessor
        self.size -= 1
        element = node.element
        node.prev_node = node.next_node = node.element = None
        return element


class DoublyLinkedQueue(DoublyLinkedBase):
    """Doubly ended queue implementation based on doubly linked list."""

    def first(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self.header.next_node.element

    def last(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self.trailer.prev_node.element

    def insert_first(self, element):
        self.insert_between(element, self.header, self.header.next_node)

    def insert_last(self, element):
        self.insert_between(element, self.trailer.prev_node, self.trailer)

    def delete_first(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self.delete_node(self.header.next_node)

    def delete_last(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self.delete_node(self.trailer.prev_node)


if __name__ == '__main__':

    doubly_linked_queue = DoublyLinkedQueue()
    for i in range(10):
        doubly_linked_queue.insert_first(i)
    while not doubly_linked_queue.is_empty():
        doubly_linked_queue.delete_last()

