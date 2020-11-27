import torch
from torch.autograd import Variable

# Create Variable
x = Variable(torch.Tensor([1]), requires_grad=True)
w = Variable(torch.Tensor([2]), requires_grad=True)
b = Variable(torch.Tensor([3]), requires_grad=True)

# Build a computational graph
y = w*x + b     #  y = 2*x +3

# Compute gradients
# 自动求导，直接对所有的需要梯度的变量自动求导，得到梯度；
y.backward() # 等价于y.backward(torch.FloatTensor([1]))

# print out the gradients
print(x.grad) #得到x的梯度
print(w.grad)
print(b.grad)

# 矩阵求导
x = torch.randn(3)
x = Variable(x, requires_grad=True)

y = x*2
print(y)

# 相当于给一个三维向量去做运算，得到结果y是一个向量
# 对y求导要传入参数申明，结果就是每个分量的梯度
y.backward(torch.FloatTensor([1,0.1,0.01]))
print(x.grad)

