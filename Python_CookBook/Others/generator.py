def createGenerator():
    mylist = range(3)
    for i in mylist:
        yield i*i

my_generator = createGenerator()
print(my_generator)
for i in my_generator:
    print(i)


if my_generator:
    for j in my_generator:
        print(j)
else:
    print('MyGenerrator Disappeared.')
