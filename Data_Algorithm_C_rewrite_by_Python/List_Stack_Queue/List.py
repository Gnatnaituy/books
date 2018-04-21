# Linked list
class SingleLinkedList:

    class _Node:
        """Node's information store here"""

        __slots__ = '_element', '_next_node'

        def __init__(self, element, next_node):
            self._element = element
            self._next_node = next_node

    def __init__(self):
        self._head = self._Node(None, None)
        self._tail = self._Node(None, None)
        self._head._next_node = self._tail
        self._length = 0

    def __len__(self):
        return self._length

    def is_empty(self):
        return self._length == 0

    def is_last(self):
        return self._tail._next_node

    def find_previous(self, value):
        p = self._head
        while(p._next_node != self._tail and p._element != value):
            p = p._next_node
        return p

    def insert(self, previous_node, value):
        new_node = self._Node(value, previous_node._next_node)
        previous_node._next_node = new_node
        self._length += 1

    def append(self, value):
        new_node = self._Node(value, None)
        self._tail._next_node = new_node
        self._tail = new_node
        self._length += 1


if __name__ == '__main__':
    my_list = SingleLinkedList()
    for i in range(3):
        my_list.append(str(i) * 9)
    print(my_list)
