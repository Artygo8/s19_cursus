import numpy as np
from mse import *


X = np.array([0, 15, -9, 7, 12, 3, -21])
Y = np.array([2, 14, -13, 5, 12, 4, -19])
print(mse(X, Y))
# 4.285714285714286
print(mse(X, X))
# 0.0
