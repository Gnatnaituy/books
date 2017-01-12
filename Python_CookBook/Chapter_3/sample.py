# 3.1 数字的四舍五入
# round(value, ndigits)
round(1.23, 1) # 1
round(-1.23634, 3) # -1.236
# 对1.5或者2.5的舍入运算都会得到2

# 如果只是需要输出一定宽度的数
x = 1.2345678
format(x, '0.2f') # '1.23'
format(x, '0.4f') # '1.2345'


# 3.2 执行精确的浮点运算
from decimal import Decimal

a = Decimal('4.2')
b = Decimal('3.1')
a + b  # Decimal('7.3')
print(a + b) # 7.3


# 3.4 二八十六进制整数
x = 1234
bin(x) # ob10011010010
oct(x) # 0o2322
hex(x) # 0x4d2
format(x, 'b') # 10011010010
format(x, 'o') # 2322
format(x, 'x') # 4d2
hex(-1234) # -0x4d2


# 3.5 字节到大整数的打包与解包
data = b'\x00\x124V\x00x\x90\xab\x00\xcd\xef\x01\x00#\x004'
print(len(data)) # 16
print(int.from_bytes(data, 'little')) # 69120565665751139577663547927094891008
print(int.from_bytes(data, 'big')) # 94522842520747284487117727783387188
x = 94522842520747284487117727783387188
print(x.to_bytes(16, 'big')) #


# 3.11 随机选择
import random

values = [1,2,3,4,5,6,6,3,2,1,45,56]
print(random.choice(values))
print(random.choice(values))
print(random.sample(values, 3))
print(random.sample(values, 2))
print(random.shuffle(values)) # 打乱顺序
print(random.randint(0, 100)) # 随机生成整数
print(random.random()) # 0到1随机浮点数
print(random.getrandbits(100)) # 获取N位随机位整数


# 3.12 基本的日期与时间转换
from datetime import timedelta, datetime

a = timedelta(days=2, hours=6)
b = timedelta(hours=4.5)
c = a + b
c.days  # 2
c.seconds # 378000
c.seconds/3600 # 10.5
c.total_seconds()/3600 # 58.5

d = datetime(2017, 1, 12)
print(d + timedelta(days=10)) # 2017-1-22 00:00:00
e = datetime(2016, 1, 12)
f = d - e
print(f.days) # 366
now = datetime.today()
print(now) # 2017-01-12 10:52:10.076965
print(now + timedelta(minutes = 30))


# 3.13 计算最后一个周五的日期
weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday',
                    'Friday', 'Saturday', 'Sunday']

def get_previous_by_day(dayname, start_date=None):
    if start_date is None:
        start_date = datetime.today()
    day_num = start_date.weekday()
    day_num_target = weekdays.index(dayname)
    days_ago = (7 + day_num - day_num_target) % 7
    if days_ago == 0:
        days_ago = 7
    target_date = start_date - timedelta(days = days_ago)
    return target_date

print(get_previous_by_day('Monday'))
