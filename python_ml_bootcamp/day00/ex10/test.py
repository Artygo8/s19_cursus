from vec_linear_mse import vec_linear_mse
import numpy as np


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
print(vec_linear_mse(X, Y, Z))
# 2641.0
W = np.array([0, 0, 0])
print(vec_linear_mse(X, Y, W))
# 130.71428571
