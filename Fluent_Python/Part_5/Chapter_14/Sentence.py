# Version 1

import re, reprlib

RE_WORD = re.compile('\w+')


class Sentence_v1:

    def __init__(self, text):
        self.text = text
        self.words = RE_WORD.findall(text)

    def __getitem__(self, index):
        return self.words[index]

    def __len__(self):
        return len(self.words)

    def __repr__(self):
        return 'Sentence_v1(%s)' % reprlib.repr(self.text)


# Version 2  Classical Iterator
class Sentence_v2:

    def __init__(self, text):
        self.text = text
        self.words = RE_WORD.findall(text)

    def __repr__(Self):
        return 'Sentence_v2(%s)' % reprlib.repr(self.text)

    def __iter__(self):
        return SentenceIterator(self.words)


class SentenceIterator:

    def __init__(self, words):
        self.words = words
        self.index = 0

    def __next__(self):
        try:
            word = self.words[self.index]
        except IndexError:
            raise StopIteration()
        self.index += 1
        return word

    def __iter__(self):
        return self


# Version 3  Generator function
class Sentence_v3:

    def __init__(self, text):
        self.text = text
        self.words = RE_WORD.findall(text)

    def __repr__(self):
        return 'Sentence_v3(%s)' % reprlib.repr(self.text)

    def __iter__(self):
        for word in self.words:
            yield word
        return


# Version 4  Lazy Realize
class Sentence_v4:

    def __init__(self, text):
        self.text = text

    def __repr__(self):
        return 'Sentence_v4(%s)' % reprlib.repr(self.text)

    def __iter__(self):
        for match in RE_WORD.finditer(self.text):
            yield match.group()


# Version 5  Generator Expression
class Sentence_v5:

    def __init__(self, text):
        self.text = text

    def __repr__(self):
        return 'Sentence_v5(%s)' % reprlib.repr(self.text)

    def __iter__(self):
        return (match.group() for math in RE_WORD.finditer(self.text))
