import numpy as np


def vec_gradient(x, y, theta):
    shape = np.shape(x)
    theta_x = np.dot(theta, np.reshape(x, (shape[1], shape[0])))
    tot = np.dot(np.reshape(x, (shape[1], shape[0])), (theta_x - y))
    print(tot)
    return np.sum(tot, axis=0) / len(x)


X = np.array([
    [-6, -7, -9],
    [13, -2, 14],
    [-7, 14, -1],
    [-8, -4, 6],
    [-5, -9, 6],
    [1, -5, 11],
    [9, -11, 8]])
Y = np.array([2, 14, -13, 5, 12, 4, -19])
Z = np.array([3, 0.5, -6])
print(vec_gradient(X, Y, Z))
array([-37.35714286, 183.14285714, -393.])

W = np.array([0, 0, 0])
vec_gradient(X, Y, W)
array([0.85714286, 23.28571429, -26.42857143])

vec_gradient(X, X.dot(Z), Z)
array([0., 0., 0.])
