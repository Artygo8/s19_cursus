import numpy as np
from sigmoid import sigmoid_
from vec_log_gradient import vec_log_gradient_
# Test n.1
x = np.array([1, 4.2])  # x[0] represent the intercept
y_true = 1
theta = np.array([0.5, -0.5])
y_pred = sigmoid_(np.dot(x, theta))
print(vec_log_gradient_(x, y_pred, y_true))
# [0.83201839 3.49447722]
# Test n.2
x = np.array([1, -0.5, 2.3, -1.5, 3.2])  # x[0] represent the intercept
y_true = 0
theta = np.array([0.5, -0.5, 1.2, -1.2, 2.3])
y_pred = sigmoid_(np.dot(x, theta))
print(vec_log_gradient_(x, y_true, y_pred))
# [ 0.99999686 -0.49999843 2.29999277 -1.49999528 3.19998994]
# Test n.3
x_new = np.arange(2, 14).reshape((3, 4))
x_new = np.insert(x_new, 0, 1, axis=1)
# first column of x_new are now intercept values initialized to 1
y_true = np.array([1, 0, 1])
theta = np.array([0.5, -0.5, 1.2, -1.2, 2.3])
y_pred = sigmoid_(np.dot(x_new, theta))
print(vec_log_gradient_(x_new, y_true, y_pred))
# [0.99994451 5.99988885 6.99983336 7.99977787 8.99972238]
