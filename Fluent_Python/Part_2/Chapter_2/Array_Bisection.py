import bisect
import sys

HAYSTACK = [1, 2, 3, 4, 5, 7, 9, 12, 15, 19, 22, 32, 35, 38]
NEEDLES = [0, 1, 2, 3, 6, 9, 13, 16, 28, 39]

ROW_FORMAT = '{0:2d} @ {1:2d}    {2}{0:<2d}'


def demo(bisect_fn):
    for needle in reversed(NEEDLES):
        position = bisect_fn(HAYSTACK, needle)
        offset = position * '  |'
        print(ROW_FORMAT.format(needle, position, offset))


if __name__ == '__main__':
    if sys.argv[-1] == 'left':
        bisect_function = bisect.bisect_left
    else:
        bisect_function = bisect.bisect

    print('DEMO:', bisect_function.__name__)
    print('haystack ->', ' '.join('%2d' % n for n in HAYSTACK))
    demo(bisect_function)
