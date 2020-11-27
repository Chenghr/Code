import torch

a = torch.Tensor([[2,3],[4,8],[7,9]])   #默认为floatTensor数据类型
print('a is: {}'.format(a))     
print('a size is: {}'.format(a.size())) 

b = torch.IntTensor([[2,3],[4,8],[7,9]])
print('b is: {}'.format(a)) 

c = torch.zeros((3,2))  #创建一个全0的空TensorI
print('zero tensor: {}'.format(c))

d = torch.randn((3,2))  #取一个正态分布作为随机初始值
print('normal tensor: {}'.format(d))