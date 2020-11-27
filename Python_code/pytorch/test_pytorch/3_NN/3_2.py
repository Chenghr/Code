import torch
from torch.autograd import Variable
import numpy as np
import matplotlib.pyplot as plt
import torch.nn.functional as F
from torch import nn
import time

# 设定随机种子
torch.manual_seed(2020)

# 从 data.txt 中读入点
# 文件路径要使用绝对路径，相对路径会查找main.py下的文件，此处会报错（我也不知道为什么）

with open('D:/Code/VS_python_code/pytorch/test_pytorch/3_NN/data_3_2.txt', 'r') as f:
    data_list = [i.split('\n')[0].split(',')
                 for i in f.readlines()]  # split() 方法使用一个字符对文本进行分割
    data = [(float(i[0]), float(i[1]), float(i[2])) for i in data_list]

# 标准化

x0_max = max([i[0] for i in data])
x1_max = max([i[1] for i in data])

data = [(i[0]/x0_max, i[1]/x1_max, i[2]) for i in data]

x0 = list(filter(lambda x: x[-1] == 0.0, data))  # 选择第一类的点
x1 = list(filter(lambda x: x[-1] == 1.0, data))  # 选择第二类的点 
# 数组下表为 -1 表示数组的最后一行数据 , 这里其实等价于 x[2]

plot_x0 = [i[0] for i in x0]
plot_y0 = [i[1] for i in x0]
plot_x1 = [i[0] for i in x1]
plot_y1 = [i[1] for i in x1]

# 输出样本数据

plt.plot(plot_x0, plot_y0, 'ro', label='x_0')
plt.plot(plot_x1, plot_y1, 'bo', label='x_1')
plt.legend(loc='best')
plt.show()

np_data = np.array(data, dtype='float32')  # 转换成 numpy array
x_data = torch.from_numpy(np_data[:, 0:2])  # 转换成 Tensor, 大小是 [100, 2]
# 转换成 Tensor，大小是 [100, 1]
y_data = torch.from_numpy(np_data[:, -1]).unsqueeze(1) # 在第 2 维（下标为1）上增加要一个维度
print(x_data)
print(y_data)

# 定义 sigmoid 函数
def sigmoid(x):
    return 1 / (1 + np.exp(-x)) # numpy.exp(x) 表示 e^x 


# 画出 sigmoid 的图像
plot_x = np.arange(-10, 10.01, 0.01)
plot_y = sigmoid(plot_x)

plt.plot(plot_x, plot_y, 'r')
plt.show()

x_data = Variable(x_data)
y_data = Variable(y_data)

# 定义 logistic 回归模型
w = Variable(torch.randn(2, 1), requires_grad=True)
b = Variable(torch.zeros(1), requires_grad=True)


def logistic_regression(x):
    return F.sigmoid(torch.mm(x, w) + b)


# 画出参数更新之前的结果
w0 = w[0].data[0]
w1 = w[1].data[0]
b0 = b.data[0]

plot_x = np.arange(0.2, 1, 0.01)
plot_y = (-w0 * plot_x - b0) / w1

plt.plot(plot_x, plot_y, 'g', label='cutting line')
plt.plot(plot_x0, plot_y0, 'ro', label='x_0')
plt.plot(plot_x1, plot_y1, 'bo', label='x_1')
plt.legend(loc='best')
plt.show()

# 定义loss函数，计算loss
# clamp()函数限制了输出数字中的大小范围，具体可以看官方文档
def binary_loss(y_pred, y):
    logits = (y * y_pred.clamp(1e-12).log() + (1 - y)
              * (1 - y_pred).clamp(1e-12).log()).mean()
    return -logits

y_pred = logistic_regression(x_data)
loss = binary_loss(y_pred, y_data)
print(loss)

# 自动求导并更新参数
loss.backward()
w.data = w.data - 0.1 * w.grad.data
b.data = b.data - 0.1 * b.grad.data

# 算出一次更新之后的loss
y_pred = logistic_regression(x_data)
loss = binary_loss(y_pred, y_data)
print(loss)

# 使用 torch.optim 更新参数
w = nn.Parameter(torch.randn(2, 1))
b = nn.Parameter(torch.zeros(1))


def logistic_regression(x):
    return F.sigmoid(torch.mm(x, w) + b)


optimizer = torch.optim.SGD([w, b], lr=1.)

# 进行 1000 次更新

start = time.time()  # time.time() 是统计的wall time(即墙上时钟)，也就是系统时钟的时间戳
for e in range(1000):
    # 前向传播
    y_pred = logistic_regression(x_data)
    loss = binary_loss(y_pred, y_data)  # 计算 loss
    # 反向传播
    optimizer.zero_grad()  # 使用优化器将梯度归 0
    loss.backward()
    optimizer.step()  # 使用优化器来更新参数
    # 计算正确率
    mask = y_pred.ge(0.5).float()
    acc = (mask == y_data).sum().item() / y_data.shape[0]
    if (e + 1) % 200 == 0:
        print('epoch: {}, Loss: {:.5f}, Acc: {:.5f}'.format(e+1, loss.item(), acc))

during = time.time() - start  # 进行1000次更新所用的时间
print()
print('During Time: {:.3f} s'.format(during))

# 画出更新之后的结果
w0 = w[0].data[0]
w1 = w[1].data[0]
b0 = b.data[0]

plot_x = np.arange(0.2, 1, 0.01)
plot_y = (-w0 * plot_x - b0) / w1

plt.plot(plot_x, plot_y, 'g', label='cutting line')
plt.plot(plot_x0, plot_y0, 'ro', label='x_0')
plt.plot(plot_x1, plot_y1, 'bo', label='x_1')
plt.legend(loc='best')

# 使用自带的loss
criterion = nn.BCEWithLogitsLoss()  # 将 sigmoid 和 loss 写在一层，有更快的速度、更好的稳定性

w = nn.Parameter(torch.randn(2, 1))
b = nn.Parameter(torch.zeros(1))


def logistic_reg(x):
    return torch.mm(x, w) + b


optimizer = torch.optim.SGD([w, b], 1.)

y_pred = logistic_reg(x_data)
loss = criterion(y_pred, y_data)
print(loss.data)

# 同样进行 1000 次更新

start = time.time()
for e in range(1000):
    # 前向传播
    y_pred = logistic_reg(x_data)
    loss = criterion(y_pred, y_data)
    # 反向传播
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    # 计算正确率
    mask = y_pred.ge(0.5).float()
    acc = (mask == y_data).sum().item() / y_data.shape[0]
    if (e + 1) % 200 == 0:
        print('epoch: {}, Loss: {:.5f}, Acc: {:.5f}'.format(e+1, loss.item(), acc))

during = time.time() - start
print()
print('During Time: {:.3f} s'.format(during))
