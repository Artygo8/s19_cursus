import numpy as np
from std import std


X = np.array([0, 15, -9, 7, 12, 3, -21])
print(std(X))
# 11.600492600378166
print(np.std(X))
# 11.600492600378166

Y = np.array([2, 14, -13, 5, 12, 4, -19])
print(std(Y))
# 11.410700312980492
print(np.std(Y))
# 11.410700312980492
