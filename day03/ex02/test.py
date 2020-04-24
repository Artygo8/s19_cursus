import numpy as np
from reg_mse import reg_mse


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
print(reg_mse(X, Y, Z, 0))
# 2641.0
print(reg_mse(X, Y, Z, 0.1))
# 2641.6464285714287
print(reg_mse(X, Y, Z, 0.5))
# 2644.2321428571427
