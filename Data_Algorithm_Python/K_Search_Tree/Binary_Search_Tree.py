#!/usr/bin/env python
# -*- coding: utf-8 -*-


from Data_Algorithm_Python.H_Tree.General_Tree import LinkedBinaryTree
from Data_Algorithm_Python.J_Maps_HashTables_SkipLists.Maps import MapBase


class TreeMap(LinkedBinaryTree, MapBase):
    """Sorted Map implementation using a binary search  tree."""

    class Position(LinkedBinaryTree.Position):
        def key(self):
            """Return key for map's key-value pair."""
            return self.element()._key

        def value(self):
            """Return value for map's key-value pair."""
            return self.element()._value

    def _subtree_search(self, p, k):
        """Return Position of p's subtree having key k, or last node searched."""
        if k == p.key():        # found match
            return p
        elif k < p.key():       # search left subtree
            if self.left(p) is not None:
                return self._subtree_search(self.left(p), k)
        else:       # search right subtree
            if self.right(p) is not None:
                return self._subtree_search(self.right(p), k)
        return p        # unsuccessful search

    def _subtree_first_position(self, p):
        """Return Position of first item in subtree rooted at p."""
        walk = p
        while self.left(walk) is not None:      # keep walking left
            walk = self.left(walk)
        return walk

    def _subtree_last_position(self, p):
        """Return Position of last item in subtree rooted at p."""
        walk = p
        while self.right(walk) is not None:     # keep walking right
            walk = self.right(walk)
        return walk

    def first(self):
        """Return the first Position in the tree ( or None if empty )."""
        return self._subtree_first_position(self.root()) if len(self) > 0 else None

    def last(self):
        """Return the last Position in the tree ( or None if empty )."""
        return self._subtree_last_position(self.root()) if len(self) > 0 else None

    def before(self, p):
        """Return te Position just before p in the natural order.

        Return None if p is the first Position."""
        self._validate(p)
        if self.left(p):
            return self._subtree_last_position(self.left(p))
        else:
            # walk upward
            walk = p
            above = self.parent(walk)
            while above is not None and walk == self.left(above):
                walk = above
                above = self.parent(walk)
            return above

    def after(self, p):
        """Return the Position just after p in the natural order.

        Return None if p is the last Position."""
        self._validate(p)
        if self.right(p):
            return self._subtree_last_position(self.right(p))
        else:
            # walk upward
            walk = p
            above = self.parent(walk)
            while above is not None and walk == self.right(above):
                walk = above
                above = self.parent(walk)
            return above

    def find_position(self, k):
        """Return Position with key k, or else neighbor ( or None if empty )."""
        if self.is_empty():
            return None
        else:
            p = self._subtree_search(self.root(), k)
            self._rebalance_access(p)       # hook for balanced tre subclasses
            return p

    def find_min(self):
        """Return ( key, value ) pair with minimum key ( or None if empty )."""
        if self.is_empty():
            return None
        else:
            p = self.first()
            return p.key(), p.value()

    def find_ge(self, k):
        """Return ( key, value ) pair with least key greater than or equal to k.

        Return None if there does't exist such a key."""
        if self.is_empty():
            return None
        else:
            p = self.find_position(k)       # may not found exact match
            if p.key() < k:     # p's key is too small
                p = self.after(p)
            return p.key(), p.value() if p is not None else None

    def find_range(self, start, stop):
        """Iterate all ( key, value ) pairs such that start <= key < stop.

        If start is None, iteration begins with minimum key of map.
        If stop is None, iteration stops with maximum key of map.
        """
        if not self.is_empty():
            if start is None:
                p = self.first()
            else:
                # we initialize p with logic similar to find_ge
                p = self.find_position(start)
                if p.key() < start:
                    p = self.after(p)
            while p is not None and ( stop is None or p.key() < stop ):
                yield p.key(), p.value()
                p = self.after(p)

    def __getitem__(self, item):
        if self.is_empty():
            raise KeyError('KeyError: ' + repr(item))
        else:
            p = self._subtree_search(self.root(), item)
            self._rebalance_access(item)
            if item != p.key():
                raise KeyError('KeyError: ' + repr(item))
            return item.value()

    def __setitem__(self, key, value):
        if self.is_empty():
            leaf = self._add_root(self._Item(key, value))
        else:
            p = self._subtree_search(self.root(), key)
            if p.key() == key:
                p.element()._value = value
                self._rebalance_access(p)
                return
            else:
                item = self._Item(key, value)
                if p.key() < key:
                    leaf = self._add_right(p, item)
                else:
                    leaf = self._add_left(p, item)
        self._rebalanec_insert(leaf)

    def __iter__(self):
        p = self.first()
        while p is not None:
            yield p.key()
            p = self.after(p)

    def delete(self, p):
        self._validate(p)
        if self.left(p) and self.right(p):
            replacement = self._subtree_last_position(self.left(p))
            self._replace(p, replacement.element())
            p = replacement
        # noe p has at most one element
        parent = self.parent(p)
        self.delete(p)
        self._rebalance_delete(parent)

    def __delitem__(self, key):
        if not self.is_empty():
            p = self._subtree_search(self.root(), key)
            if key == p.key():
                self.delete(p)
                return
            self._rebalance_access(p)
        raise KeyError('KeyError :' + repr(key))

    def _rebalance_insert(self, p): pass

    def _rebalance_access(self, p): pass

    def _rebalance_delete(self, p): pass

    def _relink(self, parent, child, make_left_child):
        """Relink parent node with child code ( we allow child to be None )."""
        if make_left_child:     # make it a left child
            parent._left = child
        else:       # make it a right child
            parent._right = child
        if child is not None:      # make child point to parent
            child._parent = parent

    def _rotate(self, p):
        """Rotate Position p above its parent."""
        x = p._node
        y = x._parent       # we assume this exists
        z = y._parent       # grandparent ( possibly None )
        if z is None:
            self._root = x      # x becomes root
            x._parent = None
        else:
            self._relink(z, x, y == z._left)        # x become a direct child for z

