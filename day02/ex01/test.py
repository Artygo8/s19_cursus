from sigmoid import sigmoid_
from log_loss import log_loss_

# Test n.1
x = 4
y_true = 1
theta = 0.5
y_pred = sigmoid_(x * theta)
m = 1  # length of y_true is 1
print(log_loss_(y_true, y_pred, m))
# 0.12692801104297152
# Test n.2
x = [1, 2, 3, 4]
y_true = 0
theta = [-1.5, 2.3, 1.4, 0.7]
x_dot_theta = sum([a * b for a, b in zip(x, theta)])
y_pred = sigmoid_(x_dot_theta)
m = 1
print(log_loss_(y_true, y_pred, m))
# 10.100041078687479
# Test n.3
x_new = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
y_true = [1, 0, 1]
theta = [-1.5, 2.3, 1.4, 0.7]
x_dot_theta = []
for i in range(len(x_new)):
    my_sum = 0
    for j in range(len(x_new[i])):
        my_sum += x_new[i][j] * theta[j]
    x_dot_theta.append(my_sum)

y_pred = sigmoid_(x_dot_theta)
print("y_pred = " + str(y_pred))
m = len(y_true)
print(log_loss_(y_true, y_pred, m))
# 7.233346147374828
