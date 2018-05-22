# usr/bin/env python
# -*- coding: utf-8 -*-


from Data_Algorithm_Python.G_Linked_List.Positional_List import PositionalList


class FavoritesList(object):
    """List of elements ordered from most frequently accessed to least."""

    # ----------------------------Nested Item class----------------------------------
    class _Item:

        __slots__ = '_value', '_count'

        def __init__(self, e):
            self._value = e         # the user's element
            self._count = 0

    # -------------------------------nonpublic utilities-------------------------------
    def __init__(self):
        self._data = PositionalList()   # will be list of _Item instance

    def __len__(self):
        return len(self._data)

    def _find_position(self, e):
        walk = self._data.first()
        while walk is not None and walk.element()._value != e:
            walk = self._data.after(walk)
        return walk

    def _move_up(self, p):
        """Move item at Position p earlier in the list based on access count."""
        if p != self._data.first():
            cnt = p.element()._count
            walk = self._data.before(p)
            if cnt > walk.element()._count:     # must shift forward
                while walk != self._data.first() and \
                                cnt > self._data.before(walk).element()._count:
                    walk = self._data.before(walk)
                self._data.add_before(walk, self._data.delete(p))

    # ---------------------------------public utilities-----------------------------------
    def is_empty(self):
        return len(self._data) == 0

    def access(self, e):
        """Access element e, thereby increasing its access count."""
        p = self._find_position(e)
        if p is None:
            p = self._data.add_last(self._Item(e))      # if new, add to the last
        p.element()._count += 1
        self._move_up(p)

    def remove(self, e):
        """Remove element e from the list of favorites."""
        p = self._find_position(e)
        if p is not None:
            self._data.delete(p)

    def top(self, k):
        """Generate sequence of top k elements in terms of access count."""
        if not 1 <= k <= len(self):
            raise ValueError('illegal value for k')
        walk = self._data.first()
        for j in range(k):
            item = walk.element()
            yield item._value           # report user's element
            walk = self._data.after(walk)


class FavoritesListMtoT(FavoritesList):
    """List of elements ordered with move-to-front heuristic."""

    # we override _move_up to provide move-to-front semantics
    def _move_up(self, p):
        """Move accessed item at Position p to front of list."""
        if p != self._data.first():
            self._data.add_first(self._data.delete(p))              # delete/insert

    # override top because list is no longer sorted
    def top(self, k):
        """Generate sequence of top k elements in items of access count."""
        if not 1 <= k <= len(self):
            raise ValueError('illegal value for k.')

        # begin by making a copy of the original list
        temp = PositionalList()
        for item in self._data:
            temp.add_last(item)

        # we repeatedly find, report, and remove element with largest count
        for j in range(k):
            # find and report next highest from temp
            high_position = temp.first()
            walk = temp.after(high_position)
            while walk is not None:
                if walk.element()._count > high_position.element()._count:
                    high_position = walk
                walk = temp.after(walk)
            # after found the element with the highest count
            yield high_position.element()._value    # report element to user
            temp.delete(high_position)

