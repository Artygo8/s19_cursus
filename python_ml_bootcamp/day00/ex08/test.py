import numpy as np
from vec_mse import vec_mse


X = np.array([0, 15, -9, 7, 12, 3, -21])
Y = np.array([2, 14, -13, 5, 12, 4, -19])
print(vec_mse(X, Y))
# 4.285714285714286
print(vec_mse(X, X))
# 0.0
