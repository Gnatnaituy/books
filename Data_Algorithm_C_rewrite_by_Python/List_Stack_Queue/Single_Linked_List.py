# Linked list
class SingleLinkedList:

    class _Node:
        """Node's information store here"""

        __slots__ = '_element', '_next_node'

        def __init__(self, element, next_node):
            self._element = element
            self._next_node = next_node

        @property
        def element(self):
            return self._element

        @element.setter
        def element(self, value):
            self._element = value

        @property
        def next_node(self):
            return self._next_node

        @next_node.setter
        def next_node(self, node):
            if not isinstance(node, type(self)):
                raise TypeError("Node type data accept only")
            self._next_node = node

    def __init__(self):
        self._head = self._Node(None, None)
        self._tail = self._Node(None, None)
        self._head._next_node = self._tail
        self._length = 0

    def __len__(self):
        return self._length

    def _find_node(self, element):
        this_node = self._head
        while this_node.next_node is not self._tail and this_node.element != element:
            this_node = this_node.next_node
        return this_node

    def is_empty(self):
        return self._length == 0

    def insert_after(self, element, value):
        the_node = self._find_node(element)
        new_node = self._Node(value, the_node.next_node)
        the_node.next_node = new_node
        self._length += 1

    def append(self, value):
        new_node = self._Node(value, None)
        self._tail.next_node = new_node
        self._tail = new_node
        self._length += 1

