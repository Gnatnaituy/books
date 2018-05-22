#!/usr/bin/env python
# -*- coding: utf-8 -*-


class DoublyLinkedBase:
    """A base class providing a doubly linked list  representation."""

    class _Node:

        __slots__ = '_element', '_prev', '_next'

        def __init__(self, e, prev_node, next_node):
            self._element = e
            self._prev = prev_node
            self._next = next_node

    def __init__(self):
        self._header = self._Node(None, None, None)
        self._trailer = self._Node(None, None, None)
        self._header._next = self._trailer
        self._trailer._prev = self._header
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def _insert_between(self, e, predecessor, successor):
        """Add element between two existing Nodes."""
        new_node = self._Node(e, predecessor, successor)
        predecessor._next = new_node
        successor._prev = new_node
        self._size += 1

    def _delete_node(self, node):
        """Delete node and return its element."""
        predecessor = node._prev
        successor = node._next
        predecessor._next = successor
        successor._prev = predecessor
        self._size -= 1
        element = node._element
        node._prev = node._next = node._element = None
        return element


class DoublyLinkedQueue(DoublyLinkedBase):
    """Doubly ended queue implementation based on doubly linked list."""

    def first(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._header._next._element

    def last(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._trailer._prev._element

    def insert_first(self, element):
        self._insert_between(element, self._header, self._header._next)

    def insert_last(self, element):
        self._insert_between(element, self._trailer._prev, self._trailer)

    def delete_first(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._delete_node(self._header._next)

    def delete_last(self):
        if self.is_empty():
            raise Exception('Empty Queue !')
        return self._delete_node(self._trailer._prev)

