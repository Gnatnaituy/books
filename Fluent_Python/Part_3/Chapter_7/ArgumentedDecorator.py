registry = set()

def register(active=True):
    def decorate(func):
        print('running register(active=%s) -> decorate(%s)' %(active, func))
        if active:
            registry.add(func)
        else:
            registry.discard(func)
        return func
    return decorate


@register(active=False)
def f1():
    print('running f1()')


@register()
def f2():
    print('running f2()')


if __name__ == '__main__':
    f1()
    f2()

