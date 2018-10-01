#!/usr/bin/python
# -*- coding: utf-8 -*-
import enchant

d = enchant.Dict('en_GB')
words = input('Enter the jumbled word: ')
words = list(words)


def permutation(lst):

    if len(lst) == 0:
        return []

    if len(lst) == 1:
        return [lst]

    l = []

    for i in range(len(lst)):
        m = lst[i]

        remLst = lst[:i] + lst[i + 1:]

        for p in permutation(remLst):
            l.append([m] + p)
    return l

correct = []
for p in permutation(words):
    word = ''.join(p)
    out = d.check(word)
    if out == True:
        correct.append(word)
    else:
        pass

print(correct)
