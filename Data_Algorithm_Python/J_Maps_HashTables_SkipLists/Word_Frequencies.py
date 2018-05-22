#!/usr/bin/env python
# -*- coding: utf-8 -*-


frequency = {}
for piece in open('a.txt').read().lower().split():
    word = ''.join(c for c in piece if c.isalpha())
    if word:
        frequency[word] = 1 + frequency.get(word, 0)

max_word = ''
max_count = 0
for (w, c) in frequency.items():
    if c > max_count:
        max_word = w
        max_count = c
print('The most frequent word is :', max_word)
print('Its number of occurrences is :', max_count)
