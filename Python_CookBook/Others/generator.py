def createGenerator():
    mylist = range(3)
    for i in mylist:
        yield i*i

myGenerator = createGenerator()
print(myGenerator)
for i in myGenerator:
    print(i)

if myGenerator:
    for j in myGenerator:
        print(j)
else:
    print('MyGenerrator Disappeared.')
