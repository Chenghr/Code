import subprocess

# python中，同一个列表中的元素的数据类型可以不同
# list中所有元素在一对方括号[]中
# 可以用list()函数将其他可迭代对象转换为列表

a = list(range(1, 10, 2)) # range对象转换为列表
print(a)

a = list({'a':1, 'b':2, 'c':3}) # 将字典的“键”转换为列表
print(a)

a = list({'a':1, 'b':2, 'c':3}.items()) # 将字典的“键：值”对转换为字典，通过字典对象的items()方法
print(a)

print(a[-1], a[-2])

subprocess.call("pause", shell=True)

# list中常用方法：

# 添加：
# append() : 向列表尾部追加一个元素
# insert() : 向列表指定位置插入元素
# extent() : 将另一个列表中的所有元素追加到当前列表尾部
# 以上三个方法均为原地操作，不影响列表再内存中的起始地址

# 删除：
# pop() :
# remove() :
# clear() : 

# 计数：
# count() :
# index() :

# 排序：
# sort() :
# reverse() :

# 复制：
# copy() :
# 浅复制：
# 深复制：

# 运算符：
# + ；
# += ：
# * ：
# *= ：

# 列表推导式
# 语法形式：
# [expression for expr1 in sequence1 if condition1
#             for expr2 in sequence2 if condition2
#             ...
#             for exprN in sequenceN if conditionN]

# 逻辑上等价于一个循环语句，形式上更加简洁
# 常用于过滤不符合条件的元素
# 列表推导式中可以使用函数或复杂表达式

aList = [(x,y) for x in [1,2,3]
                for y in [1,2,3] if x != y]
print(aList)

# 形式上等价于：
aList = []
for x in [1,2,3]:
    for y in [1,2,3]:
    if x != y:
        aList.append((x,y))

# 切片：
# 形式：[start: end: step]
# 参数意义：
#       start：开始位置，默认为0
#       end：  结束位置（不办含），默认为列表长度
#       step： 切片步长，默认为1；为负时表示反向切片；可省略，省略时最后一个冒号也省略

# 切片操作不会因为下标越界而抛出异常
# 切片操作得到的是浅复制