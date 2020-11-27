import torch
import numpy as np
from torch.autograd import Variable
import matplotlib.pyplot as plt
# %matplotlib inline 原本用于内部输出图像，此处不适用，故注释掉

torch.manual_seed(2017)  # 设置随机数种子，保证每次生成的随机数是一样的

# 读入数据 x 和 y
x_train = np.array([[3.3], [4.4], [5.5], [6.71], [6.93], [4.168],
                    [9.779], [6.182], [7.59], [2.167], [7.042],
                    [10.791], [5.313], [7.997], [3.1]], dtype=np.float32)

y_train = np.array([[1.7], [2.76], [2.09], [3.19], [1.694], [1.573],
                    [3.366], [2.596], [2.53], [1.221], [2.827],
                    [3.465], [1.65], [2.904], [1.3]], dtype=np.float32)

# 画出图像
plt.plot(x_train, y_train, 'bo')
# 显示图像
plt.show()

# 转换成 Tensor
x_train = torch.from_numpy(x_train)
y_train = torch.from_numpy(y_train)

# 定义参数 w 和 b
w = Variable(torch.randn(1), requires_grad=True)  # 随机初始化
b = Variable(torch.zeros(1), requires_grad=True)  # 使用 0 进行初始化

# 构建线性回归模型
x_train = Variable(x_train)
y_train = Variable(y_train)


def linear_model(x):
    return x * w + b


y_ = linear_model(x_train)

# 输出初始预测模型
plt.plot(x_train.data.numpy(), y_train.data.numpy(), 'bo', label='real')
# plt.show()
plt.plot(x_train.data.numpy(), y_.data.numpy(), 'ro', label='estimated')
# plt.show()
plt.legend()  # 给图像加上Label 例如此处就分别指出了红/蓝的label
plt.show()

# 计算误差


def get_loss(y_, y):
    return torch.mean((y_ - y_train) ** 2)  # torch.mean() 是一个均值函数


loss = get_loss(y_, y_train)
print(loss)

# 自动求导
loss.backward()

# 查看 w 和 b 的梯度
print(w.grad)
print(b.grad)

# 更新一次参数
w.data = w.data - 1e-2 * w.grad.data
b.data = b.data - 1e-2 * b.grad.data

y_ = linear_model(x_train)

# 输出更新一次参数的后的预测模型
plt.plot(x_train.data.numpy(), y_train.data.numpy(), 'bo', label='real')
plt.plot(x_train.data.numpy(), y_.data.numpy(), 'ro', label='estimated')
plt.legend()
plt.show()

epoch_time = 10
for e in range(epoch_time):  # 进行 epoch_time 次更新
    y_ = linear_model(x_train)
    loss = get_loss(y_, y_train)

    w.grad.zero_()  # 记得归零梯度
    b.grad.zero_()  # 记得归零梯度
    loss.backward()

    w.data = w.data - 1e-2 * w.grad.data  # 更新 w
    b.data = b.data - 1e-2 * b.grad.data  # 更新 b
    print('epoch: {}, loss: {}'.format(e, loss.data))

y_ = linear_model(x_train)

plt.plot(x_train.data.numpy(), y_train.data.numpy(), 'bo', label='real')
plt.plot(x_train.data.numpy(), y_.data.numpy(), 'ro', label='estimated')
plt.legend()
plt.show()
