import subprocess
# 变量：
# python中变量不用事先声明其名称和类型，直接赋值即可，变量的类型也可以随时变换
# 原因：python是基于值得内存管理模式，变量不直接存储值，而是存储值的内存地址或者引用
# python中变量名对大小写敏感

x = 3
print("type of x :", type(x))
x = 'Hello'
print("new type of x :", type(x))
subprocess.call("pause", shell='true')

# 数的表示和运算：
# python中应该尽量避免直接在实数之间进行相等性测试，而是以两者之差是否足够小作为依据

x = 0.4 - 0.1
print("0.4 - 0.1 =", x) # 由于精度的问题，对于实数的运算有误差
print("x == 0.3 ?", x == 0.3)
print("x == 0.3 ?", abs(x-0.3) < 1e-6)
subprocess.call("pause", shell='true')

# python中支持复数的运算，使用j/J表示复数的虚部

x = 3+2j
y = 5+6j

print("x的实部：", x.real)
print("x的虚部：", x.imag)
print("x的模：", abs(x)) # abs()函数可用于计算复数的模
print("y的实部：", y.real)
print("y的虚部：", y.imag)
print("x+y =", x+y)
subprocess.call("pause", shell='true')

# 标准库fractions中的Fraction对象支持分数运算
# 标准库fractions中的Decimal类支持高精度运算

from fractions import Fraction
from fractions import Decimal

x = Fraction(3,5)
print(x)

y = Decimal(1/3)
print(1/3)
print(y)
subprocess.call("pause", shell='true')

# 字符串：
# python中没有字符的概念，只有字符串类型的常量和变量；
# 使用'',"",作为定界符，不同的定界符之间可以嵌套

# 运算符：
# // ：求整商，操作数中有实数的时候转化为实数形式的整数

print("15 // 4 =", 15//4) 
print("15.0 // 4 =", 15.0//4) 
print("-15 // 4 =", -15//4) # 向下取整
subprocess.call("pause", shell='true')

# ** ：幂运算，等价于内置函数pow()

print("(-9)^0.5 = ", (-9)**0.5) # 可以计算复数的平方根
subprocess.call("pause", shell='true')

# in ：成员测试运算符，用于判定一个对象是否为另一个对象的元素
# is ：测试两个对象是否为同一个，如果两个对象是同一个，那么两个对象拥有相同的内存地址（基于值的内存管理）

print("range(1, 10, 1) :")
for i in range(1, 10, 1): # 成员遍历，range()用于生成指定范围数字的内置函数
    print(i, end = '\t')
print()

print("3 in range(1, 10, 1) ?", 3 in range(1, 10, 1)) 
subprocess.call("pause", shell='true')

x = [100, 100, 100]
print("x :", x)
print("x[0] is x[1] ?", x[0] is x[1])

y = [100, 100, 100]
print("y :", y)
print("x is y ?", x is y)
subprocess.call("pause", shell='true')

# @ ： 矩阵乘法运算，由于python中没有内置矩阵类型，常与numpy联合使用
# python中不支持 ++ 和 -- 运算符
