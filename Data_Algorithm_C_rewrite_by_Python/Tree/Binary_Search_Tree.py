class BinarySearchTree:

    class _Node:

        __slots__ = '_element', '_left_child', '_right_child'

        def __init__(self, element, left_child, right_child):
            self._element = element
            self._left_child = left_child
            self._right_child = right_child

        @property
        def element(self):
            return self._element

        @element.setter
        def element(self, value):
            if not isinstance(value, int):
                raise TypeError("Int value accept only")
            self._element = value

        @property
        def left_child(self):
            return self._left_child

        @left_child.setter
        def left_child(self, node):
            if not isinstance(node, type(self)):
                raise TypeError("Child should be a Node.")
            self._left_child = node

        @property
        def right_child(self):
            return self._right_child

        @right_child.setter
        def right_child(self, node):
            if not isinstance(node, type(self)):
                raise TypeError("Child should be a Node.")
            self._right_child = node

