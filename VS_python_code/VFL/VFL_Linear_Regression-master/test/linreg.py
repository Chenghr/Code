## Import stuff

import numpy as np
from sklearn import datasets, linear_model, metrics
from sklearn.metrics import r2_score

################################################################

## Load the diabetes dataset
diabetes = datasets.load_diabetes()
diabetes_X = diabetes.data # matrix of dimensions 442x10

# Split the data into training/testing sets
diabetes_X_train = diabetes_X[:-20]
diabetes_X_test = diabetes_X[-20:]

# Split the targets into training/testing sets
diabetes_y_train = diabetes.target[:-20]
diabetes_y_test = diabetes.target[-20:]

################################################################
## Our own implementation

# train
X = diabetes_X_train
y = diabetes_y_train

# train: init
# Intialize weights
W = np.random.uniform(low=-0.1, high=0.1, size=diabetes_X.shape[1])
b = 0.0

learning_rate = 0.1
epochs = 100000

# train: gradient descent

for i in range(epochs):

    # calculate predictions
    y_predict = X.dot(W) + b

    # calculate error and cost (mean squared error)
    error = y - y_predict

    mean_squared_error = np.mean(np.power(error, 2))

    # calculate gradients
    W_gradient = -(1.0/len(X)) * error.dot(X)
    b_gradient = -(1.0/len(X)) * np.sum(error)

    # update parameters

    W = W - (learning_rate * W_gradient)
    b = b - (learning_rate * b_gradient)

    # diagnostic output
    if i % 5000 == 0: 
       print("Epoch %d: %f" % (i, mean_squared_error))

# test

X = diabetes_X_test
y = diabetes_y_test

y_predict = X.dot(W) + b

error = y - y_predict

mean_squared_error = np.mean(np.power(error, 2))

print("Mean squared error: %.2f" % mean_squared_error)
print('r2 score:', r2_score(diabetes_y_test, y_predict))
print('model params: {}'.format(W))

print("="*120)