# 1.1 解压序列赋值给多个变量
p = (4, 5)
x, y = p  # x=4, y=5
# 如果变量个数和序列元素的个数不匹配，会产生一个异常。
data = ['ACME', 50, 91.1, (2012, 12, 31)]
name, shares, price, date = data # ...data=(2012, 12, 31)


# 1.2 解压可迭代对象赋值给多个变量
sales = [12,13,14,12,15,12,11,16]
*last_7_months, this_months = sales
last_7_months_avg = sum(last_7_months) / len(last_7_months)
print("last_7_months_avg: %s, this_months: %s" % (last_7_months_avg,
        this_months))

records = [('foo', 1, 2), ('bar', 'hello'), ('foo', 3, 4)]

def do_foo(x, y):
    print('foo', x, y)

def do_bar(s):
    print('bar', s)

for tag, *args in records:
    if tag == 'foo':
        do_foo(*args)
    elif tag == 'bar':
        do_bar(*args)

items = [1, 12, 16, 10, 33, 11, 90]
def sum(items):
    head, *tail = items
    return head + sum(tail) if tail else head
print(sum(items))


# 1.3 保留最后N个元素
from collections import deque

def search(lines, pattern, history=5):
    previous_lines = deque(maxlen = history)
    for li in lines:
        if pattern in li:
            yield li, previous_lines
        previous_lines.append(li)

with open(r'test.txt') as f:
    for line, previous_lines in search(f, 'Line', 5):
        for pline in previous_lines:
            print(pline, end=' ')
        print(line, end = ' ')
        print('-' * 20)


# 1.4 查找最大或做小的N个元素
import heapq

nums = [1,2,3,4,5,6,7,8,11,23,15,21,41,456,33331]
print(heapq.nlargest(3, nums))
print(heapq.nsmallest(4, nums))

portfolio = [
    {'name': 'IBM', 'shares': 100, 'price': 91.1},
    {'name': 'AAPL', 'shares': 50, 'price': 543.22},
    {'name': 'FB', 'shares': 200, 'price': 21.09},
    {'name': 'HPQ', 'shares': 35, 'price': 31.75},
    {'name': 'YHOO', 'shares': 45, 'price': 16.35},
    {'name': 'ACME', 'shares': 75, 'price': 115.65}
    ]
cheap = heapq.nsmallest(4, portfolio, key=lambda s: s['price'])
expensive = heapq.nlargest(4, portfolio, key=lambda s: s['price'])
print('Cheap: \n', cheap, '\n', 'Expensive: \n', expensive)


# 1.5 实现一个优先级队列
import heapq

class PriortyQueue:
    def __init__(self):
        self._queue = []
        self._index = 0

    def push(self, item, priorty):
        heapq.heappush(self._queue, (-priorty, self._index, item))
        self._index += 1

    def pop(self):
        return heapq.heappop(self._queue)[-1]

class Item:
    def __init__(self, name):
        self.name = name
    def __repr__(self):
        return 'Item({!r})'.format(self.name)

q = PriortyQueue()
q.push(Item('foo'), 1)
q.push(Item('bar'), 5)
q.push(Item('spam'), 3)
q.push(Item('grok'), 1)
for i in range(1, 5):
    print(q.pop())



# 1.6 字典中的键映射多个值
# 1.7 字典排序
from collections import OrderedDict
import json

d = OrderedDict() # 一个OrderedDict的大小是一个普通字典的两倍，因为它内部维护着另外一个链表
d['foo'] = 1
d['spam'] = 2
d['bar'] = 3
d['lan'] = 4
for key in d:
    print(key, d[key])
print(json.dumps(d))


# 1.8 字典的运算
prices = {
    'ACME': 45.23,
    'AAPL': 612.78,
    'IBM': 205.55,
    'HPQ': 37.20,
    'FB': 10.75
}

min_price = min(zip(prices.values(), prices.keys()))
max_price = max(zip(prices.values(), prices.keys()))
print('min_price:', min_price, 'max_price:', max_price, '\n')
prices_sorted = sorted(zip(prices.values(), prices.keys()))
print('prices_sorted:', prices_sorted, '\n')


# 1.9 查找两个字典的相同点
# 1.10 删除序列相同元素并保持顺序
def dedupe_hashable(items):
    seen = set()
    for item in items:
        if item not in seen:
            yield item
            seen.add(item)

a = [1,2,3,3,5,2,54,6,7]
print(list(dedupe_hashable(a)))

def dedupe_unhashable(items, key=None):
    seen = set()
    for item in items:
        val = item if key is None else key(item)
        if val not in seen:
            yield item
            seen.add(val)

a = [{'x':1, 'y':2}, {'x':1, 'y':3}, {'x':1, 'y':2}, {'x':2, 'y':4}]
print(list(dedupe_unhashable(a, key = lambda d: d['x'])))



# 1.12 序列中出现次数最多的元素
words = [
    'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
    'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
    'eyes', "don't", 'look', 'around', 'the', 'eyes', 'look', 'into',
    'my', 'eyes', "you're", 'under'
    ]
from collections import Counter
word_counter = Counter(words)
top_three = word_counter.most_common(3)
print(top_three)
print(word_counter['eyes']) # 8

morewords = ['why','are','you','not','looking','in','my','eyes']
for word in morewords:
    word_counter[word] += 1 # == word_counter.update(morewords)
print(word_counter['eyes'])


# 1.13 通过某个关键字排序一个字典列表
rows = [
        {'fname': 'Brian', 'lname': 'Jones', 'uid': 1003},
        {'fname': 'David', 'lname': 'Beazley', 'uid': 1002},
        {'fname': 'John', 'lname': 'Cleese', 'uid': 1001},
        {'fname': 'Big', 'lname': 'Jones', 'uid': 1004}
    ]
from operator import itemgetter
rows_by_fname = sorted(rows, key=itemgetter('fname'))
rows_by_uid = sorted(rows, key=itemgetter('uid'))
print('rows_by_fname:\n', rows_by_fname,'\n','rows_by_uid:\n',rows_by_uid,'\n')
rows_by_lfname = sorted(rows, key=itemgetter('lname','fname'))
print('rows_by_lfname:\n', rows_by_lfname)
min_uid = min(rows, key=itemgetter('uid'))
print('min_uid:', min_uid)


# 1.14 排序不支持原生排序的对象
class User:
    def __init__(self, user_id):
        self.user_id = user_id

    def __repr__(self):
        return 'User({})'.format(self.user_id)

def sorted_notcompare():
    print(users)
    print(sorted(users, key = lambda u: u.user_id))

users = [User(120), User(1), User(3)]
sorted_notcompare()

from operator import attrgetter
print(sorted(users, key=attrgetter('user_id')))
print(min(users, key=attrgetter('user_id')))


# 1.15 通过某个字段将记录分组
rows15 = [
    {'address': '5412 N CLARK', 'date': '07/01/2012'},
    {'address': '5148 N CLARK', 'date': '07/04/2012'},
    {'address': '5800 E 58TH', 'date': '07/02/2012'},
    {'address': '2122 N CLARK', 'date': '07/03/2012'},
    {'address': '5645 N RAVENSWOOD', 'date': '07/02/2012'},
    {'address': '1060 W ADDISON', 'date': '07/02/2012'},
    {'address': '4801 N BROADWAY', 'date': '07/01/2012'},
    {'address': '1039 W GRANVILLE', 'date': '07/04/2012'},
]

from itertools import groupby
# 因为 groupby()
# 仅仅检查连续的元素，如果事先并没有排序完成的话，分组函数将得不到想要的结果
rows15.sort(key=itemgetter('date'))
for date, items in groupby(rows15, key=itemgetter('date')):
    print(date)
    for i in items:
        print(' ', i)
