import numpy as np
from variance import variance


X = np.array([0, 15, -9, 7, 12, 3, -21])
print(variance(X))
# 134.57142857142858
print(np.var(X))
# 134.57142857142858
print(variance(X / 2))
# 33.642857142857146
print(np.var(X / 2))
# 33.642857142857146
