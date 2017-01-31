# usr/bin/env python
# -*- coding: utf-8 -*-


from .General_Tree import LinkedBinaryTree


class ExpressionTree(LinkedBinaryTree):
    """An Arithmetic expression tree."""

    def __init__(self, token, left=None, right=None):
        """Create an expression tree.

        In a single parameter form, token should be a leaf value ( eg: '42' ),
        and the expression tree will have that value at an isolate node.

        In  a three-parameter version, token should be an operator,
        and eft and right should be existing Expression H_Tree instances
        that become the operands for the binary operator."""

        super().__init__()                               # LinkedBinaryTree initialization
        if not isinstance(token, str):
            raise TypeError('Token must be a string !')
        self._add_root(token)                          # use inherited, nonpublic method
        if left is not None:                              # presumably three-parameter form
            if token not in '+-*x/':
                raise ValueError('Token must be valid operator !')
            self._attach(self.root(), left, right)

    def __str__(self):
        """Return string representation of the expression."""
        pieces = []                             # sequence of piecewise strings to compose
        self._parenthesize_recur(self.root(), pieces)
        return ''.join(pieces)

    def _parenthesize_recur(self, p, result):
        """Append piecewise representation of p's subtree to resulting list."""
        if self.is_leaf(p):
            result.append(str(p.element()))         # leaf value as a string
        else:
            result.append('(')
            self._parenthesize_recur(self.left(p), result)
            result.append(p.element())
            self._parenthesize_recur(self.right(p), result)
            result.append(')')

    def evaluate(self):
        """Return the numeric result of the expression."""
        return self._evaluate_recur(self.root())

    def _evaluate_recur(self, p):
        """Return the numeric result of subtree rooted a p."""
        if self.is_leaf(p):
            return float(p.element())
        else:
            op = p.element()
            left_val = self._evaluate_recur(self.left(p))
            right_val = self._evaluate_recur(self.right(p))
            if op == '+':
                return left_val + right_val
            elif op == '-':
                return left_val - right_val
            elif op == '*':
                return left_val * right_val
            else:
                return left_val / right_val


def build_expression_tree(tokens):
    """Return an Expression H_Tree based upon by a tokenized expression."""
    s = []
    for t in tokens:
        if t in '+-*/x':
            s.append(t)
        elif t not in '()':
            s.append(ExpressionTree(t))
        elif t == ')':
            right = s.pop()
            op = s.pop()
            left = s.pop()
            s.append(ExpressionTree(op, left, right))
    return s.pop()

