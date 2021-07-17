import numpy as np
from dot import dot


X = np.array([0, 15, -9, 7, 12, 3, -21])
Y = np.array([2, 14, -13, 5, 12, 4, -19])
print(dot(X, Y))
# 917.0
print(np.dot(X, Y))
# 917

print(dot(X, X))
# 949.0
print(np.dot(X, X))
# 949

print(dot(Y, Y))
# 915.0
print(np.dot(Y, Y))
# 915
