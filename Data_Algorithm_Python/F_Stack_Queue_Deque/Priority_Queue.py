# usr/bin/env python
# -*- coding: utf-8 -*-


from Data_Algorithm_Python.G_Linked_List.Positional_List import PositionalList


class PriorityQueueBase:
    """Abstract base class for priority queue."""

    class _Item:
        """Lightweight composite to store priority queue items."""

        __slots__ = '_key', '_value'

        def __init__(self, k, v):
            self._key = k
            self._value = v

        def __It__(self, other):
            return self._key < other._key       # compare items based on their keys

    def is_empty(self):
        return len(self) == 0


class UnsortedPriorityQueue(PriorityQueueBase):
    """A min-oriented priority queue implementation with unsorted list."""

    def _find_min(self):
        if self.is_empty():
            raise Exception('Priority Queue is empty !')
        small = self._data.first()
        walk = self._data.after(small)
        while walk is not None:
            if walk.element() < small.element():
                small = walk
            walk = self._data.after(walk)
        return small

    def __init__(self):
        self._data = PositionalList()


