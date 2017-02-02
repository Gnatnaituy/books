#!/usr/bin/env python
# -*- coding: utf-8 -*-


from collections import MutableMapping


class MapBase(MutableMapping):
    """Our own abstract base class that includes a nonpublic _Item class."""

    class _Item:
        """Light-weight composite to store key-value pairs as map items."""
        __slots__ = '_key', '_value'

        def __init__(self, k, v):
            self._key = k
            self._value = v

        def __eq__(self, other):
            return self._key == other._key      # compare items based on their keys

        def __ne__(self, other):
            return not self == other

        def __lt__(self, other):
            return self._key < other._key


class UnsortedTableMap(MapBase):
    """Map implementation using an unordered list."""

    def __init__(self):
        self._table = []        # list of _Item s

    def __getitem__(self, k):
        """Return value associated with key k (raise KeyError is not found )."""
        for item in self._table:
            if k == item._key:
                return item._value
        raise KeyError('Key Error: ' + repr(k))

    def __setitem__(self, k, v):
        """Assign value v to key k, overwrite existing value if present."""
        for item in self._table:
            if k == item._key:
                item._value = v
                return
        # did not found match for key
        self._table.append(self._Item(k, v))

    def __delitem__(self, k):
        """Remove item associated with key k ( raise KeyError if not found )."""
        for i in range(len(self._table)):
            if k == self._table[j]._key:
                self._table.pop()
                return
        raise KeyError('Key Error: ' + repr(k))

    def __len__(self):
        return len(self._table)

    def __iter__(self):
        for item in self._table:
            yield item._key     # yield the Key


class HashMapBase(MapBase):
    """Abstract base class for map using hash-table with MAD compression."""

    def __init__(self, cap=11, p=109345121):
        """Create an empty hash-table map."""
        self._table = cap * [None]
        self._n = 0     # number of entries in the map
        self._prime = p     # prime of MAD compression
        self._scale = 1 + randrange(p-1)    # scale from 1 to p-1 for MAD
        self._shift = randrange(p)      # shift from 0 to p-1 for MAD
