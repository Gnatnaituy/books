def add_two_func(func1, func2):
    def inner():
        print('add func1 and func2')
        ret1 = func1()
        ret2 = func2()
        return ret1 + ret2
    return inner

def foo1():
    return 12

def foo2():
    return 23

dec = add_two_func(foo1, foo2)
print(dec()) #35


class Coordibate(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return "Coord: " + str(self.__dict__)

def add(a, b):
    return Coordibate(a.x + b.x, a.y + b.y)

def sub(a, b):
    return Coordibate(a.x - b.x, a.y - b.y)

one = Coordibate(100, 300)
two = Coordibate(200, 400)
print(add(one, two))
print(sub(one, two))

def wrapper(func):
    def chocker(a, b):
        if a.x < 0 or a.y < 0:
            a = Coordibate(a.x if a.x > 0 else 0, a.y if a.y > 0 else 0)
        if b.x < 0 or b.y < 0:
            b = Coordibate(b.x if b.x > 0 else 0, b.y if b.y > 0 else 0)
        ret = func(a, b)
        if ret.x < 0 or ret.y < 0:
            ret = Coordibate(ret.x if ret.x > 0 else 0, ret.y if ret.y > 0 else
                    0)
        return ret
    return chocker

add = wrapper(add)
sub = wrapper(sub)
print(sub(one, two))


def logger(func):
    def inner(*args, **kwargs):
        print("Arguments were: %s, %s" % (args, kwargs))
        return func(*args, **kwargs)
    return inner

@logger
def foo1(x , y = 1):
    return x * y

@logger
def foo2():
    return 2

print(foo1(3))
print(foo2())
