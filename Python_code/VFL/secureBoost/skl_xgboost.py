#!/usr/bin/env python
# -*- coding:utf-8 -*-
# @FileName  :skl_xgboost.py.py
# @Time      :2020/11/24 9:14 下午
# @Author    :wangjunhao


import xgboost
from numpy import loadtxt
from xgboost import XGBClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd
from sklearn.datasets import load_iris
import xgboost as xgb
from xgboost import plot_importance
import matplotlib.pyplot  as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score  # 准确率
import os, sys

# os.chdir(sys.path[0])

# # 载入数据集
# # dataset = loadtxt('pima-indians-diabetes.csv', delimiter=",")
train_data = pd.read_csv('data_a.csv').iloc[:, 1:]
train_label=pd.read_csv('data_b.csv').iloc[:, 1:]
# # split data into X and y
X = train_data.values
Y = train_label.values

# # 把数据集拆分成训练集和测试集
# seed = 7
# test_size = 0.33
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.1, random_state=0)
print(len(X_train))
# #
# 拟合XGBoost模型
model = XGBClassifier()
print(model)
model.fit(X_train, y_train)

# 对测试集做预测
y_pred = model.predict(X_test)
predictions = [round(value) for value in y_pred]

# 评估预测结果
accuracy = accuracy_score(y_test, predictions)
print("Accuracy: %.2f%%" % (accuracy * 100.0))



