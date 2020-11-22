import torch
import numpy as np
from torch.autograd import Variable
import matplotlib.pyplot as plt

# 定义一个多变量函数

w_target = np.array([0.5, 3, 2.4]) # 定义参数
b_target = np.array([0.9]) # 定义参数

f_des = 'y = {:.2f} + {:.2f} * x + {:.2f} * x^2 + {:.2f} * x^3'.format(
    b_target[0], w_target[0], w_target[1], w_target[2]) # 打印出函数的式子

print(f_des)

# 画出这个函数的曲线
x_sample = np.arange(-3, 3.1, 0.1)
y_sample = b_target[0] + w_target[0] * x_sample + w_target[1] * x_sample ** 2 + w_target[2] * x_sample ** 3

plt.plot(x_sample, y_sample, label='real curve')
plt.legend()
plt.show()

# 构建数据 x 和 y
# x 是一个如下矩阵 [x, x^2] ,即用一个二次多项式去逼近三次多项式
# y 是函数的结果 [y]
x_train = np.stack([x_sample ** i for i in range(1, 3)], axis=1)
x_train = torch.from_numpy(x_train).float() # 转换成 float tensor

y_train = torch.from_numpy(y_sample).float().unsqueeze(1) # 转化成 float tensor 

# 定义参数和模型
w = Variable(torch.randn(2, 1), requires_grad=True) # 二次多项式，w改为2*1的系数矩阵
b = Variable(torch.zeros(1), requires_grad=True)

# 将 x 和 y 转换成 Variable
x_train = Variable(x_train)
y_train = Variable(y_train)

def multi_linear(x):
    return torch.mm(x, w) + b # torch.mm(,) 两个矩阵相乘  torch.mul(,) 矩阵的对应位相乘

# 画出更新之前的模型
y_pred = multi_linear(x_train)

plt.plot(x_train.data.numpy()[:, 0], y_pred.data.numpy(), label='fitting curve', color='r')
plt.plot(x_train.data.numpy()[:, 0], y_sample, label='real curve', color='b')
plt.legend()
plt.show()

# 计算误差，这里的误差和一元的线性模型的误差是相同的，前面已经定义过了 get_loss
def get_loss(y_, y):
    return torch.mean((y_ - y_train) ** 2)  # torch.mean() 是一个均值函数

loss = get_loss(y_pred, y_train)
print(loss)

# 自动求导
loss.backward()

# 查看一下 w 和 b 的梯度
print(w.grad)
print(b.grad)

# 更新一下参数
w.data = w.data - 0.001 * w.grad.data
b.data = b.data - 0.001 * b.grad.data

# 画出更新一次之后的模型
y_pred = multi_linear(x_train)

plt.plot(x_train.data.numpy()[:, 0], y_pred.data.numpy(), label='fitting curve', color='r')
plt.plot(x_train.data.numpy()[:, 0], y_sample, label='real curve', color='b')
plt.legend()
plt.show()

# 进行 epoch_time 次参数更新
epoch_time = 100
for e in range(epoch_time):
    y_pred = multi_linear(x_train)
    loss = get_loss(y_pred, y_train)
    
    w.grad.data.zero_()
    b.grad.data.zero_()
    loss.backward()
    
    # 更新参数
    w.data = w.data - 0.001 * w.grad.data
    b.data = b.data - 0.001 * b.grad.data
    if (e + 1) % 20 == 0:
        print('epoch {}, Loss: {:.5f}'.format(e+1, loss.data))

# 画出更新之后的结果
y_pred = multi_linear(x_train)

plt.plot(x_train.data.numpy()[:, 0], y_pred.data.numpy(), label='fitting curve', color='r')
plt.plot(x_train.data.numpy()[:, 0], y_sample, label='real curve', color='b')
plt.legend()
plt.show()
