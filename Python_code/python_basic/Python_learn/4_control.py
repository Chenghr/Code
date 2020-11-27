import subprocess
# python中关系运算符可以连用，且符合人类的思维方式，不过不建议使用
# python中在条件表达式(if语句)中，不允许使用赋值运算符'='
print(1 < 2 < 3) # 等价于 1<2 and 2>3
print(1 < 2 > 3)
print(1 < 3 > 2)
subprocess.call("pause", shell=True)

# 多选择分支结构
# if 表达式1：
#       语句块1
# elif 表达式2：
#       语句块2
# ...
# else：
#       语句块n
# 其中关键词 elif 是 else if 的缩写

# 选择结构可以通过嵌套结构来实现复杂的业务逻辑

# 循环结构：

# for 取值 in 序列或者迭代对象：
#   循环体
# [else:
#   else 子句代码块]

# while 条件表达式：
#   循环体
# [else:
#   else 子句代码块]

# 对于带有else子句的循环结构，循环因为 表达式不成立 或者 序列遍历自然结束 时会执行
# 如果是break语句导致循环 提前结束 则不会执行

# break语句：执行后，所属层次的循环结构提前结束；
# continue语句：执行后，提前结束本次循环，忽视之后的所有语句，提前进入下一次循环

# 循环中应尽量引用局部变量，局部变量的查询和访问速度比全局变量略快

# 示例：快速判断一个数是否为素数

n = input('Input an integer: ')
n = int(n)

if n == 2:
    print('Yes')
elif n%2 == 0:
    # 偶数必定不是素数
    print('No')
else:
    # 大于5的素数必然出现在6的倍数两侧
    # 因为 6x+2, 6x+3, 6x+4 肯定不是素数，假设x为大于1的自然数
    m = n % 6
    if m != 1 and m != 5:
        print('No')
    else:
        for i in range(3, int(n**0.5)+1, 2):
            if n%i == 0:
                print('No')
                break
        else:
            # for循环结构的else分支
            print('Yes')