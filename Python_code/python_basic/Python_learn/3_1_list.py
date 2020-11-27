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