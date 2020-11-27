import numpy as np
from sklearn import linear_model, metrics
from sklearn import datasets
from sklearn.metrics import r2_score

diabetes_X, diabetes_y = datasets.load_diabetes(return_X_y=True)
diabetes_X_train = diabetes_X[:-20]
diabetes_y_train = diabetes_y[:-20]
diabetes_X_test = diabetes_X[-20:]
diabetes_y_test = diabetes_y[-20:]

regr = linear_model.LinearRegression()
regr.fit(diabetes_X_train, diabetes_y_train)

print(regr.coef_)
diabetes_y_pred = regr.predict(diabetes_X_test)
mean_square_error = metrics.mean_squared_error(diabetes_y_test, diabetes_y_pred)
print('mean square error:{}'.format(mean_square_error))
print('r2 score: {}'.format(r2_score(diabetes_y_test, diabetes_y_pred)))
