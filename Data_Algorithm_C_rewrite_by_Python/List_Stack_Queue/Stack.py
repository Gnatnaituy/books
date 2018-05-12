class Stack:

    class _Node:

        __slots__ == '_element'

        def __init__(self, element, next_node):
            self._element = element
            self._next_node = next_node

        @property
        def element(self):
            return self._element

        @element.setter
        def element(self, element):
            self._element = element
