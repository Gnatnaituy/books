# usr/bin/env python
# -*- coding: utf-8 -*-


from Data_Algorithm_Python.G_Linked_List.Doubly_Linked_List import DoublyLinkedBase


class PositionalList(DoublyLinkedBase):
    """A sequential container of elements allowing positional access."""

    # -----------------------Nested Position Class-------------------------------
    class Position:
        """An abstraction representing the location of a single element."""

        def __init__(self, container, node):
            """Constructor shouldn't be invoked by user."""
            self._container = container
            self._node = node

        def element(self):
            """Return the element stored at this Position."""
            return self._node._element

        def __eq__(self, other):
            return type(other) is type(self) and other._node == self._node

        def __ne__(self, other):
            return not(self == other)

    # ------------------------------Utility method----------------------------------
    def _validate(self, p):
        """Return Position's node, or raise appropriate error if invalid."""
        if not isinstance(p, self.Position):
            raise TypeError('p must be proper Position type !')
        if p._container is not self:
            raise ValueError('p does not belong to this container !')
        if p._node._next is None:
            raise ValueError('p is no longer valid !')
        return p._node

    def _make_position(self, node):
        """Return Position instance for given node ( or None if sentinel )."""
        if node is self._header or node is self._trailer:
            return None                              # boundary violation
        else:
            return self.Position(self, node)    # legitimate position

    # ---------------------------------Accessors---------------------------------------
    def first(self):
        return self._make_position(self._header._next)

    def last(self):
        return self._make_position(self._trailer._prev)

    def before(self, p):
        node = self._validate(p)
        return self._make_position(node._prev)

    def after(self, p):
        node = self._validate(p)
        return self._make_position(node._next)

    def __iter__(self):
        cursor = self.first()
        while cursor is not None:
            yield cursor.element()
            cursor = self.after(cursor)

    # -----------------------------------Mutators---------------------------------------
    # override inherited version of return Position , rather than Node
    def _insert_between(self, e, predecessor, successor):
        node = super()._insert_between(e, predecessor, successor)
        return self._make_position(node)

    def add_first(self, e):
        return self._insert_between(e, self._header, self._header._next)

    def add_last(self, e):
        return self._insert_between(e, self._trailer, self._trailer._prev)

    def add_before(self, p, e):
        original = self._validate(p)
        return self._insert_between(e, original._prev, original)

    def add_after(self, p, e):
        original = self._validate(p)
        return self._insert_between(e, original, original._next)

    def delete(self, p):
        original = self._validate(p)
        return self._delete_node(original)

    def replace(self, p, e):
        original = self._validate(p)
        old_value = original._element
        original._element = e
        return old_value

    @staticmethod
    def insertion_sort(alist):
        """Sort Positional List of comparable elements into nondecreasing order"""
        if len(alist) > 1:
            marker = alist.first()
            while marker != alist.last():
                pivot = alist.after(marker)
                value = pivot.element()
                if value > marker.element():
                    marker = pivot
                else:
                    walk = marker
                    while walk != alist.first() and alist.before(walk).element() > value:
                        walk = alist.before(walk)
                    alist.delete(pivot)
                    alist.add_before(walk, value)
