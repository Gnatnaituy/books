# usr/bin/env python
# -*- coding: utf-8 -*-


class Apple:

    def __init__(self):
        self.add = []


class Empty(Exception):
    """Error attempting to access an element from an empty stack."""
    pass


class ArrayStack:
    """LIFO Stack implementation using Python list as underlying storage."""

    def __init__(self):
        """Create an empty stack."""
        self.data = []


if __name__ == '__main__':
    a = Apple()
    print(type(a.add))
    b = ArrayStack()
    print(type(b.data))
