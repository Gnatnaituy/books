#!/usr/bin/env python
# -*- coding: utf-8 -*-


from collections.abc import MutableMapping
from random import randrange


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

    def __len__(self):
        return self._n

    def __getitem__(self, k):
        j = self._hash_function(k)
        return self._bucket_getitem(j, k)       # may raise KeyError

    def __setitem__(self, k, v):
        j = self._hash_function(k)
        self._bucket_setitem(j, k, v)      # subroutine maintains self._n
        if self._n > len(self._table) // 2:     # keep load factor <= 0.5
            self._resize(2 * len(self._table) - 1)      # umber 2^x - 1 is often prime

    def __delitem__(self, k):
        j = self._hash_function(k)
        self._bucket_delitem(j, k)
        self._n -= 1

    def _bucket_getitem(self, j, k):
        pass

    def _bucket_setitem(self, j, k, v):
        pass

    def _bucket_delitem(self, j, k):
        pass

    def _hash_function(self, k):
        # MAD method:       [ ( ai + b ) mod p ] mod N
        return hash((k * self._scale + self._shift) % self._prime % len(self._table))

    def _resize(self, c):        # resize bucket array to capacity c
        old = list(self.items())        # user iteration to record existing items
        self._table = c * [None]
        self._n = 0     # n recomputed during subsequent adds
        for (k, v) in old:
            self[k] = v      # reinsert old key-value pair


class ChainHashMap(HashMapBase):
    """Hash Map implementation with separate chaining for collision resolution."""

    def _bucket_getitem(self, j, k):
        bucket = self._table[j]
        if bucket is None:
            raise KeyError('Key Error: ' + repr(k))     # no match found
        return bucket[k]        # may raise KeyError

    def _bucket_setitem(self, j, k, v):
        if self._table is None:
            self._table = UnsortedTableMap()        # bucket is new to the table
        old_size = len(self._table[j])
        self._table[j][k] = v
        if len(self._table[j]) > old_size:       # key was new to the table
            self._n += 1        # increase overall map size

    def _bucket_delitem(self, j, k):
        bucket = self._table[j]
        if bucket is None:
            raise KeyError('Key Error: ' + repr(k))
        del bucket[k]       # may raise KeyError

    def __iter__(self):
        for bucket in self._table:
            if bucket is not None:
                for key in bucket:
                    yield key


class LinearProbeHashMap(HashMapBase):
    """Hash map implementation with linear probing for collision resolution."""

    _AVAIL = object()       # sentinal marks locations of previous deletion

    def _is_available(self, j):
        """Return True if index j is available in table."""
        return self._table[j] is None or self._table[j] is LinearProbeHashMap._AVAIL

    def _find_slot(self, j, k):
        """Search for key k in bucket at index j.

        Return  (success, index) tuple, described as follows:
        If match was found, success is True and index denotes its location.
        If no match found, success is False and index denotes first available slot."""

        firstAvail = None
        while True:
            if self._is_available(j):
                if firstAvail is None:
                    firstAvail = j
                if self._table[j] is None:
                    return False, firstAvail
            elif k == self._table[j]._key:
                return True, j
            j = (j + 1) % len(self._table)      # keep looking (cyclically)

    def _bucket_getitem(self, j, k):
        found, s = self._find_slot(j, k)
        if not found:
            raise KeyError('KeyError: ' + repr(k))
        return self._table[s]._value

    def _bucket_setitem(self, j, k, v):
        found, s = self._find_slot(j, k)
        if not found:
            self._table[s] = self._Item(k, v)       # insert new item
            self._n += 1
        else:
            self._table[s]._value = v       # overwrite existing

    def _bucket_delitem(self, j, k):
        found, s = self._find_slot(j, k)
        if not found:
            raise KeyError('KeyError: ' + repr(k))
        self._table[s] = LinearProbeHashMap._AVAIL      # mark as vacated

    def __iter__(self):
        for j in range(len(self._table)):       # scan entire table
            if not self._is_available(j):
                yield self._table[j]._key


class SortedTableMap(MapBase):
    """Map implementation using a sorted table."""

    def _find_index(self, k, low, high):
        """Return index of the leftmost item with key greater than or equal to k.

        Return high+1 if no such items qualifies.

        That is, j will be returned such that:
            all items of slice table[low:j] have key < k
            all items of slice table[j:high+1] have key >= k
        """
        if high < low:
            return high + 1     # no element qualifies
        else:
            mid = (low + high) // 2
            if k == self._table[mid]._key:
                return mid      # found exact match
            elif k < self._table[mid]._key:
                return self._find_index(k, low, mid - 1)        # note: may return mid
            else:
                return self._find_index(k, mid + 1, high)       # answer is right of mid

    def __init__(self):
        self._table = []

    def __len__(self):
        return len(self._table)

    def __getitem__(self, k):
        j = self._find_index(k, 0, len(self._table) - 1)
        if j == len(self._table) or self._table[j]._key != k:
            raise KeyError('KeyError: ' + repr(k))
        return self._table[j]._value

    def __setitem__(self, k, v):
        j = self._find_index(k, 0, len(self._table) - 1)
        if j < len(self._table) and self._table[j]._key == k:
            self._table[j]._value = v
        else:
            self._table.insert(j, self._Item(k, v))

    def __delitem__(self, k):
        j = self._find_index(k, 0, len(self._table) - 1)
        if j == len(self._table) or self._table[j]._key != k:
            raise KeyError('KeyError: ' + repr(k))
        self._table.pop()

    def __iter__(self):
        for item in self._table:
            yield item._key

    def __reversed__(self):
        for item in reversed(self._table):
            yield item._key

    def find_min(self):
        if len(self._table) > 0:
            return self._table[0]._key, self._table[0]._value
        else:
            return None

    def find_max(self):
        if len(self._table) > 0:
            return self._table[0]._key, self._table[0]._value
        else:
            return None

    def find_gt(self, k):
        j = self._find_index(k, 0, len(self._table)-1)
        if j < len(self._table) and self._table[j]._key == k:
            j += 1
        if j < len(self._table):
            return self._table[j]._key, self._table[j]._value
        else:
            return None

    def find_ge(self, k):
        j = self._find_index(k, 0, len(self._table)-1)
        if j < len(self._table):
            return self._table[j]._key, self._table[j]._value
        else:
            return None

    def find_lt(self, k):
        j = self._find_index(k, 0, len(self._table)-1)
        if j > 0:
            return self._table[j-1]._key, self._table[j-1]._value
        else:
            return None

    def find_le(self, k):
        j = self._find_index(k, 0, len(self._table)-1)
        if j > 0:
            return self._table[j]._key, self._table[j]._value
        else:
            return None

    def find_range(self, start, stop):
        """Iterate all (key, value) pairs such that start <= key <= stop.

        If start is None, iteration begins with minimum key of map.
        If stop is None, iteration continues through the maximum key of map.
        """
        if start is None:
            j = 0
        else:
            j = self._find_index(start, 0, len(self._table)-1)
        while j < len(self._table) and (stop is None or self._table[j]._key < stop):
            yield self._table[j]._key, self._table[j]._value
            j += 1
