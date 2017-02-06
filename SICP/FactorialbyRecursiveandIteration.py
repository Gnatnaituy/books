# By Recursive
def factorial_recursivel(n):
    if n == 1:
        return 1
    else:
        return factorial_recursivel(n-1) * n
print(factorial_recursivel(10))


# By Iteration
def factorial_iteration(n):
    def fact_iter(product, counter):
        if counter > n:
            return product
        else:
            fact_iter(product * counter, counter + 1)
    fact_iter(1, 1)

print(factorial_iteration(10))
