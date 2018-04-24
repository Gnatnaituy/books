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
        self._head.next_node = self.tail
        self._length = 0

    @property
    def head(self):
        return self._head

    @head.setter
    def head(self, node):
        if not isinstance(node, type(self._Node)):
            raise TypeError("Node type data accept only")
        self._head = node

    @property
    def tail(self):
        return self._tail

    @tail.setter
    def tail(self, node):
        if not isinstance(node, type(self._Node)):
            raise TypeError("Node type data accept only")
        self._tail = node

    @property
    def length(self):
        return self._length

    @length.setter
    def length(self, value):
        if not isinstance(value, int):
            raise TypeError("Int type data accept only")
        self._length = value

    def __len__(self):
        return self.length

    def is_empty(self):
        return self.length == 0

    def is_last(self):
        return self.tail.next_node

    def find_previous(self, value):
        p = self.head
        while p.next_node != self.tail and p.element != value:
            p = p.next_node
        return p

    def insert(self, previous_node, value):
        new_node = self._Node(value, previous_node.next_node)
        previous_node.next_node = new_node
        self.length += 1

    def append(self, value):
        new_node = self._Node(value, None)
        self.tail.next_node = new_node
        self.tail = new_node
        self.length += 1


class DoublyLinkedList:

    class _Node:

        __slots__ = '_previous_node', '_next_node', '_element'

        def __init__(self, element, previous_node, next_node):
            self._element = element
            self._previous_node = previous_node
            self._next_node = next_node

        @property
        def element(self):
            return self._element

        @element.setter
        def element(self, element):
            if not isinstance(element, int):
                raise TypeError("Int type data accept only")
            self._element = element

        @property
        def previous_node(self):
            return self._previous_node

        @previous_node.setter
        def previous_node(self, node):
            if not isinstance(node, type(self)):
                raise TypeError("Node type data accept only")
            self._previous_node = node

        @property
        def next_node(self):
            return self._next_node

        @next_node.setter
        def next_node(self, node):
            if not isinstance(node, type(self)):
                raise TypeError("Node type data accept only")
            self._next_node = node

    def __init__(self):
        self._head = self._Node(None, None, None)
        self._tail = self._Node(None, None, None)
        self._length = 0

    @property
    def tail(self):
        return self._tail

    @tail.setter
    def tail(self, node):
        if not isinstance(node, type(self)):
            raise TypeError("Node type data accept only")
        self._tail = node

    @property
    def head(self):
        return self._head

    @head.setter
    def head(self, node):
        if not isinstance(node, type(self)):
            raise TypeError("Node type data accept only")
        self._head = node

    @property
    def length(self):
        return self._length

    @length.setter
    def length(self, value):
        if not isinstance(value, int):
            raise ValueError("Int type data accept only")
        self._length = value

    def __len__(self):
        return self.length

    def is_empty(self):
        return self.length == 0

    def is_head(self):
        pass

    def is_tail(self):
        pass

    def find_previous(self):
        pass

    def find_next(self):
        pass

    def insert_between(self, previous_node, next_node, value):
        pass

    def append(self, value):
        pass


if __name__ == '__main__':
    my_list = SingleLinkedList()
    for i in range(1, 4):
        my_list.append(str(i) * 9)
    print(my_list)
