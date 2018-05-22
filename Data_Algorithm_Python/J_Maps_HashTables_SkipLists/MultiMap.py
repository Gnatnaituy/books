#!/usr/bin/env python
# -*- coding: utf-8 -*-


class MultiMap(object):
    """ A MultiMap class built upon use of an underlying map of storage."""

    _MapType = dict     # maptype can  be redefined by subclass

    def __int__(self):
        """Create an new empty multimap instance."""
        self._map = self._MapType()     # create map instance for storage
        self._n = 0

    def __iter__(self):
        for k, secondary in self._map._items():
            for v in secondary:
                yield k, v

    def add(self, k, v):
        container = self._map.setdefault(k, [])     # create empty list, if needed
        container.append(v)
        self._n += 1

    def pop(self, k):
        secondary = self._map[k]
        v = secondary.pop()
        if len(secondary) == 0:
            del self._map[k]
        self._n -= 1
        return k, v

    def find(self, k):
        secondary = self._map[k]
        return k, secondary[0]

    def find_all(self, k):
        secondary = self._map.get(k, [])        # empty list by default
        for v in secondary:
            yield k, v
