import asyncio, threading


# 协程
def consumer():                         #定义消费者，由于有yield，此消费者为一个生成器
    print("[Consumer] init Consumer ......")
    r = "init OK"                       #初始化返回结果，并在启动消费者时，返回给生产者
    while True:
        n = yield r                     #消费者通过yield接受生产者信息，同时返回给生产者结果
        print("[Consumer] consume n = %s, r = %s" % (n, r))
        r = "Consume %s OK" % n         #消费者消费结果，下个循环返回给生产者

def produce(c):                         #定义生产者，此时c为一个生成器
    print("[Producer] init Producer ......")
    r = c.send(None)                    #启动消费者生成器，同时第一次接受返回结果
    print("[Producer] start Consumer, return %s" % r)
    n = 0
    while n < 5:
        n += 1
        print("[Producer] while, Producing %s ......" % n)
        r = c.send(n)                   #向消费者发送信息并准备接收结果，此时会切换到消费者执行
        print("[Producer] Consumer return: %s" % r)
    c.close()
    print("[Producer] close Producer ......")

produce(consumer())


# #异步IO       Python3.4版本
# @asyncio.coroutine
# def hello(index):                       #通过装饰器asyncio.coroutine定义协程
#     print('Hello World! index = %s, thread = %s' % (index, threading.currentThread()))
#     yield from asyncio.sleep(1)         #模拟IO任务
#     print('Hello Again! index = %s, thread = %s' % (index, threading.currentThread()))

# loop = asyncio.get_event_loop()         #得到一个事件循环模型
# tasks = [hello(1), hello(2)]
# loop.run_until_complete(asyncio.wait(tasks))    #执行任务
# loop.close()                            #关闭事件循环列表


# 异步IO       Python3.5版本
# async关键字将一个函数声明为协程函数，函数执行时返回一个协程对象。
# await关键字将暂停协程函数的执行，等待异步IO返回结果。
async def hello(index):                       #通过关键字async定义协程
    print('Hello World! index = %s, thread = %s' % (index, threading.currentThread()))
    await asyncio.sleep(1)         #模拟IO任务
    print('Hello Again! index = %s, thread = %s' % (index, threading.currentThread()))

loop = asyncio.get_event_loop()         #得到一个事件循环模型
tasks = [hello(1), hello(2)]
loop.run_until_complete(asyncio.wait(tasks))    #执行任务
loop.close()                            #关闭事件循环列表

# EventLoop是一个程序结构，用于等待和发送消息和事件。简单说，就是在程序中设置两个线程：一个负责程序本身的运行，
#称为"主线程"；另一个负责主线程与其他进程（主要是各种I/O操作）的通信，被称为"Event Loop线程"（可以译为"消息线程"）。
