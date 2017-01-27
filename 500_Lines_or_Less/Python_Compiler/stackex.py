class Stackex:

    def __init__(self):
        self.stack = [1,2,3,4,5]
        self.enviroment = {}

    def add(self):
        val = self.stack.pop()
        print(val)



aa = Stackex()
aa.add()
