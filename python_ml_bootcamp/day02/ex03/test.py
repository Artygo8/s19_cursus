import numpy as np
from sigmoid import sigmoid_
from vec_log_loss import vec_log_loss_
# Test n.1
x = 4
y_true = 1
theta = 0.5
y_pred = sigmoid_(x * theta)
m = 1  # length of y_true is 1
print(vec_log_loss_(y_true, y_pred, m))
# 0.12692801104297152
# Test n.2
x = np.array([1, 2, 3, 4])
y_true = 0
theta = np.array([-1.5, 2.3, 1.4, 0.7])
y_pred = sigmoid_(np.dot(x, theta))
m = 1
print(vec_log_loss_(y_true, y_pred, m))
# 10.100041078687479
# Test n.3
x_new = np.arange(1, 13).reshape((3, 4))
y_true = np.array([1, 0, 1])
theta = np.array([-1.5, 2.3, 1.4, 0.7])
y_pred = sigmoid_(np.dot(x_new, theta))
# y_pred = [0.99995892 1.         1.        ]
# previous was y_pred = [0.9999589221322353, 0.9999999996234612, 0.9999999999999964]
m = len(y_true)
print(vec_log_loss_(y_true, y_pred, m))
# 7.233346147374828
