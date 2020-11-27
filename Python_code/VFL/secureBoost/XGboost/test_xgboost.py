#!/usr/bin/env python
# -*- coding:utf-8 -*-
# @FileName  :test_xgboost.py.py
# @Time      :2020/11/24 8:59 下午
# @Author    :wangjunhao


import pandas as pd
import matplotlib.pyplot as plt
from utils import train_test_split
from utils import mean_squared_error,accuracy_score
from xgboost import XGBoost

if __name__=="__main__":

    # Load temperature data
    train_data = pd.read_csv('../data_a.csv').iloc[:, 1:]
    train_label = pd.read_csv('../data_b.csv').iloc[:, 1:]
    train_data = train_data.values
    train_label = train_label.values
    X_train, X_test, y_train, y_test = train_test_split(train_data, train_label, test_size=0.9)

    model = XGBoost(n_estimators=100,learning_rate=0.1,max_depth=3)
    print(model)
    print("begin train")
    model.fit(X_train, y_train)
    print("end train")
    y_pred = model.predict(X_train)
    acc = accuracy_score(y_pred,y_train)
    print("accuracy:", acc)

