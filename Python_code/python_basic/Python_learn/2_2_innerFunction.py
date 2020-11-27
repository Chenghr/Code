import subprocess
# 基本的是输入输出函数
# input() : 输入函数，不论输入的是什么内容，一律按照字符串对待；可以用int()等函数对输入的内容进行类型转换

x = input('Please input: ')
print(x, type(x))
subprocess.call("pause", shell=True)

# print() : 输出函数，输出信息到标准控制台或者指定文件
# print(val1, val2, ..., sep=' ', end='\n', file=sys.stdout, flush=False)
# val1, val2,... 为需要输出的内容；
# sep参数用于指定数据之间的分隔符，默认为空格；
# file参数用于指定输出位置，默认为控制台，也可以重定向输出到文件；

print(1, 3, 5, 7, sep=' /') # 修改默认分隔符
subprocess.call("pause", shell=True)

for i in range(10):
    print(i, end=' ') # 修改end参数，每个输出后不换行
subprocess.call("pause", shell=True)

with open('test.txt', 'a+') as fp: # vscode中相对路径默认文件和.vscode位于同一个文件目录下，此处可以注意test.txt的位置
    print('Hello World! ', file=fp) # 重定向，将文件输出到文件中
subprocess.call("pause", shell=True)

# map() : 把一个函数func依次映射到序列或者迭代器对象的每个元素上，返回一个可迭代的map对象作为结果
# reduce() : 将一个接受两个参数的函数以迭代累积的方式从左到右一次作用到一个序列或者迭代器对象的所有元素上，允许指定一个初值
# filter() : 将一个单参数函数作用到一个序列上，返回该序列中是的该函数返回值为true的元素组成的filter对象；

x = list(map(str, range(5))) # 把列表中的元素转换成字符串
print(x)
subprocess.call("pause", shell=True)

def add5(v): # 单参数函数，值+5
    return v+5
x = list(map(add5, range(10))) # 把单参数函数映射到一个序列的所有元素
print(x)
subprocess.call("pause", shell=True)

from functools import reduce # 导入reduce函数
x = reduce(lambda x,y: x+y, [1,2,3,4]) # 计算(((1+2)+3)+4)
print(x)
subprocess.call("pause", shell=True)

seq = ['hello', 'world', '...', '!~!']

def func(x):
    return x.isalnum() # 测试是否为字母或数字

x = filter(func, seq) # 返回filter对象
print(x)

y = list(filter(lambda x: x.isalnum(), seq)) # 将filter对象转换为列表，且使用lambda表达式实现相同功能
print(y)
subprocess.call("pause", shell=True)

# range() : 语法格式为 range([start,] end [,step])
# 返回具有惰性求值特点的range对象，包含[start, end)内以step为步长的整数
# start默认为0，step默认为1
# 惰性求值：表达式不会在它被绑定到变量之后就立即求值，而是等用到时再求值

x = range(9, 0, -2) # 步长为负数时，start应该比end大
print(x)

# range()函数常用来在循环中控制循环次数
for i in range(4): # 循环4次
    print(9, end=' ') 
subprocess.call("pause", shell=True)

# zip() : 把多个可迭代对象中的元素压缩在一起，返回一个可迭代的zip对象
# 理解：把多个序列的元素左对齐，然后从左向右遍历，经过每个序列中相同位置的元素放到一个元组中
# 只要有一个序列中的元素处理完了就停止遍历，返回包含若干个元组的zip对象

x = list(zip('abcd', [1,2,3])) # 压缩字符串和列表，其中d被丢失
print(x) 

x = zip('abcd', '1234')
print(list(x))
print(list(x)) # zip对象只能遍历一次

# eval() : 用来计算字符串的值，也可以用来将数字字符串转换成数字，但不允许以0开头的数字

x = eval(b'3+5') # 输出8
print(x) 

print(eval('9')) # 数字字符串转换为数字

x = int('09') # x = eval('09')会报错，但是用int()转换是合法的