class countdown:
    def __init__(self, start):
        self.start = start

    # Forward Iterator
    def __iter__(self):
        n = self.start
        while n > 0:
            yield n
            n -= 1

    # Reversed Iterator
    def __reversed__(self):  #reversed() 为内置函数
        n = 1
        while n <= self.start:
            yield n
            n += 1

for rr in reversed(countdown(30)):
    print(rr)
for rr in countdown(30):
    print(rr)
