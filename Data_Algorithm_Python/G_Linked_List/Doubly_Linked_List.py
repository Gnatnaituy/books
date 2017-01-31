# usr/bin/env python
# -*- coding: utf-8 -*-


class DoublyLinkedBase:
    """A base class providing a doubly linked list  representation."""

    class Node:

        def __init__(self, element, prev_node, next_node):
            self._element = element
            self._prev_node = prev_node
            self._next_node = next_node

    def __init__(self):
        self._header = self.Node(None, None, None)
        self._trailer = self.Node(None, None, None)
        self._header._next_node = self._trailer
        self._trailer._prev_node = self._header
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def _insert_between(self, element, predecessor, successor):
        """Add element between two existing Nodes."""
        new_node = self.Node(element, predecessor, successor)
        predecessor._next_node = new_node
        successor._prev_node = new_node
        self._size += 1
        return new_node

    def _delete_node(self, node):
        predecessor = node._prev_node
        successor = node._next_node
        predecessor._next_node = successor
        successor._prev_node = predecessor
        self._size -= 1
        element = node._element
        node._prev_node = node._next_node = node._element = None
        return element


class DoublyLinkedQueue(DoublyLinkedBase):
    """Doubly ended queue implementation based on doubly linked list."""

    def first(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._header._next_node._element

    def last(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._trailer._prev_node._element

    def insert_first(self, element):
        self._insert_between(element, self._header, self._header._next_node)

    def insert_last(self, element):
        self._insert_between(element, self._trailer._prev_node, self._trailer)

    def delete_first(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._delete_node(self._header._next_node)

    def delete_last(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._delete_node(self._trailer._prev_node)
