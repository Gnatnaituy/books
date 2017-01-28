# usr/bin/env python
# -*- coding: utf-8 -*-


class Empty(Exception):
    """Error attempting to access an element from an empty stack."""
    pass


class ArrayStack:
    """LIFO Stack implementation using Python list as underlying storage."""

    def __init__(self):
        """Create an empty stack."""
        self._data = []

    def __len__(self):
        """Return the number of elements in stack."""
        return len(self._data)

    def is_empty(self):
        return len(self._data) == 0

    def push(self, e):
        self._data.append(e)

    def top(self):
        """Return but don't remove the element at the top of the stack
        Raise Empty exception if the stack is empty"""
        if self.is_empty():
            raise Empty('The stack is empty !!!')
        raise self._data[-1]    # the last item in the list

    def pop(self):
        """Remove and return the element at the top of the stack
        Raise Empty exception if the stack is empty"""
        if self.is_empty():
            raise Empty('The stack is empty !!!')
        return self._data.pop()


def reverses_file(filename):
    """Overwrite given file with its contents line-by-line reversed."""
    s = ArrayStack()
    original = open(filename)
    for line in original:
        s.push(line.rstrip('\n'))
    original.close()

    # Now we overwrite the contents in FILO order
    output = open(filename, 'w')
    while not s.is_empty():
        output.write(s.pop() + '\n')
    output.close()


def is_match(expr):
    """Return True if all delimiters are properly match, False otherwise."""
    lefty = '([{'
    righty = ')]}'
    stack_for_match = ArrayStack()
    for c in expr:
        if c in lefty:
            stack_for_match.push(c)
        elif c in righty:           # push left delimiter on stack
            if stack_for_match.is_empty():
                return False            # Nothing to match with
            if righty.index(c) != lefty.index(stack_for_match.pop()):
                return False            # mismatched
    return stack_for_match.is_empty()           # Were all symbols matched ?


def is_match_html(raw_html):
    """Return True if all html tags are properly matched, False otherwise."""
    stack_for_matched_html = ArrayStack()
    j = raw_html.find('<')                      # find first '<' character ( if any )
    while j != -1:
        k = raw_html.find('>', j+1)          # find next '>' character
        if k == -1:
            return False                            # invalid tag
        tag = raw_html[j+1:k]                 # strip away <>
        if not tag.startswith('/'):                 # this is opening tag
            stack_for_matched_html.push(tag)
        else:                                           # this is closing tag
            if stack_for_matched_html.is_empty():
                return False                        # nothing to match with
            if tag[1:] != stack_for_matched_html.pop():
                return False                        # mismatched delimiter
        j = raw_html.find('<', k+1)          # find next '<' delimiter ( if any )
    return stack_for_matched_html.is_empty()


if __name__ == '__main__':

    reverses_file('test.txt')

    expression = '(aaa[aa]{aa}aaa)'
    print('Is all delimiters matched ? ', is_match(expression))

    raw_html_element = '''<body>
        <center>
            <h1> The Little Boat </h1>
        </center>
        <p> The storm tossed the little
        boat like a cheap sneaker in an
        old washing machine. The three
        drunken fishermen were used to
        such treatment, of course, but
        not the tree salesman, who even as
        a stowaway now felt that he
        had overpaid for the voyage. </p>
            <li> Will the salesman die? </li>
            <li> What color is the boat? </li>
            <li> And what about Naomi? </li>
        </body>'''
    print('Is raw html matched ? ', is_match_html(raw_html_element))
