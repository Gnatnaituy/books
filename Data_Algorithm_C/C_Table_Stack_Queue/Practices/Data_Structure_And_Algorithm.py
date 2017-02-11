# 解压赋值可用在任何可迭代对象上面 eg列表、元组、字符串、文件对象、迭代器和生成器

#星号表达式
def Drop_First_Last(grades):
	first, *middle, last = grades
	return middle

grades = ('123','99','125','145','90','122')
print(Drop_First_Last(grades))
# middle = ['99','125','145','90']
# middle永远为列表类型

def Sum(items):
	head, *tail = items
	return head + Sum(tail) if tail else head

items = ['1','2','34','45','56','67']
print(Sum(items)) #1234455667
numbers = (1,2,3,45,56,7,89,56)
print(Sum(numbers)) #259


#保留最后N个元素
from collections import deque

def search(lines, pattern, history=5):
	previous_lines = deque(maxlen=history)
	for li in lines:
		if pattern in li:
			yield li, previous_lines
		previous_lines.append(li)
