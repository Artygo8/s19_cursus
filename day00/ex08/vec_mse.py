import numpy as np


def vect_mse(y, y_hat):
    diff = y_hat - y
    res = np.dot(diff, np.reshape(diff, (len(diff), 1)))
    return float(1 / len(y) * res)


X = np.array([0, 15, -9, 7, 12, 3, -21])
Y = np.array([2, 14, -13, 5, 12, 4, -19])
print(vect_mse(X, Y))
4.285714285714286
print(vect_mse(X, X))
0.0
