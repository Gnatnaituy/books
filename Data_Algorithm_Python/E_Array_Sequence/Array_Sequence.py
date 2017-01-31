# usr/bin/env python
# -*- coding: utf-8 -*-


class GameEntry:
    """Represents one entry of a list of high scores."""

    def __init__(self, name, score):
        self._name = name
        self._score = score

    def get_name(self):
        return self._name

    def get_score(self):
        return self._score

    def __str__(self):
        return '({0}, {1})'.format(self._name, self._score)


class ScoreBoard:
    """Fixed-length sequence of high scores in nondecreasing order."""

    def __init__(self, capacity=10):
        """Initialize scoreboard with given maximum capacity.

        All entries are initially None."""
        self._board = [None] * capacity
        self._n = 0

    def __getitem__(self, k):
        """Return entry at index k."""
        return self._board[k]

    def __str__(self):
        """Return string representation of the high score list."""
        return '\n'.join(str(self._board[j]) for j in range(self._n))

    def add(self, entry):
        """Consider adding entry to high scores."""
        score = entry.get_score()

        # Does new entry qualify as a high score ?
        # answer is yes if board not full or score if higher than last entry
        good = self._n < len(self._board) or score > self._board[-1].get_score()

        if good:
            if self._n < len(self._board):          # no score drop from list
                self._n += 1                             # so overall number increase

                # shift lower scores rightward to make room for new entry
                j = self._n - 1
                while j > 0 and self._board[j-1].get_score() < score:
                    self._board[j] = self._board[j-1]   # shift entry from j-1 to j
                    j -= 1                                   # and decrement j
                self._board[j] = entry                # when done, add new entry


def insertion_sort(a):
    """Sort list of comparable elements into nondecreasing order."""
    for k in range(1, len(a)):
        cursor = a[k]           # current element to be inserted
        j = k           # find correct index j for current
        while j > 0 and a[j-1] > cursor:    # element a[j-1] must be after current
            a[j] = a[j-1]
            j -= 1
        a[j] = cursor       # cursor is now the right place


