#一个函数中需要有一个 yield 语句即可将其转换为一个生成器。 跟普通函数不同的是，生成器只能用于迭代操作。

def frange(start, stop, increment):
    x = start
    while x < stop:
        yield x
        x += increment

def countdown(n):
    print('Starting to count down from', n)
    while n > 0:
        yield n
        n -= 1
    print('Done!')

if __name__ == '__main__':
    for n in frange(0, 8, 0.5):
        print(n)

    print(list(frange(0, 8, 0.5)))

    c = countdown(6)
    i = 6
    while (i > 0):
        next(c)
        i -= 1