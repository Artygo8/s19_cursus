import numpy as np
from sum import sum_


X = np.array([0, 15, -9, 7, 12, 3, -21])
print(sum_(X, lambda x: x))
# 7.0
X = np.array([0, 15, -9, 7, 12, 3, -21])
print(sum_(X, lambda x: x**2))
# 949.0
