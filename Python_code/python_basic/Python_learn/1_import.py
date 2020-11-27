# 模块的导入

# 基本模式： import 模块名 [ as 别名 ]
import subprocess
import math
print("sin(0.5) =", math.sin(0.5))
subprocess.call("pause",shell=True) # 让python脚本暂停执行

import numpy as np
a = np.array((1,2,3,4))
print("a =", a)
subprocess.call("pause",shell=True)

# 进一步的，为了导入明确指定的对象，减少查询次数，提高访问速度，我们有：
# from 模块名 import 对象名 [ as 别名 ]
# 这样不需要模块名作为前缀
from math import sin
print("sin(0.5) =", sin(0.5))
subprocess.call("pause",shell=True)

# 一次导入模块中的所有对象，不推荐使用
# from 模块名 import * 
from math import *
print("sin(0.5) + cos(0.5) =", sin(0.5) + cos(0.5))
subprocess.call("pause",shell=True)

# 导入其他.py文件，直接当作一个模块进行导入，具体还可以导入其中的某个具体的类
import hello  # 注意输出
