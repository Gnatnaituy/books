def average(x, y):
    a = (x + y) / 2
    return a

def improve(guess, x):
    return average(guess, x/guess)

def good_enough(guess, x):
    if abs(x - guess*guess) < 0.001:
        return True
    else:
        return False

def sqrt_iter(guess, x):
    if good_enough(guess, x): 
        return guess
    else:
        sqrt_iter(improve(guess, x), x)

def sqrt_a_number(x):
    return sqrt_iter(1.0, x)

if __name__ == '__main__':
    print(average(23,234))
    print(improve(23,234))
    print(good_enough(23,234))
    print(sqrt_iter(23,234))
    print(sqrt_a_number(102))

