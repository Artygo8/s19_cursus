import numpy as np


def predict_(theta, X):
    b = []
    l = len(X)
    b = np.zeros((l, 1), dtype=int) + 1
    new_table = np.c_[b, X]
    res = new_table.dot(theta)
    return (res)


X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
theta1 = np.array([[2.], [4.]])
res = predict_(theta1, X1)
print(res)

X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
theta1 = np.array([[2.], [4.]])
predict_(theta1, X1)
array([[2], [6], [10], [14.], [18.]])
X2 = np.array([[1], [2], [3], [5], [8]])
theta2 = np.array([[2.]])
predict_(theta2, X2)
Incompatible dimension match between X and theta.
None
X3 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8., 80.]])
theta3 = np.array([[0.05], [1.], [1.], [1.]])
predict_(theta3, X3)
array([[22.25], [44.45], [66.65], [88.85]])
