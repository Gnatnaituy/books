from math import hypot

class Vector:

    def __init__(self, x=0, y=0):
        self.x, self.y = x, y

    def __repr__(self):
        return 'Vector(%s, %s)' % (self.x, self.y)

    def __abs__(self):
        return hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))
    
    def __add__(self, other):
        x, y = self.x + other.x, self.y + other.y
        return Vector(x, y)
    
    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)
