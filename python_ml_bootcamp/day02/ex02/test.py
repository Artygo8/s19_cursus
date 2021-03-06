from sigmoid import sigmoid_
from log_gradient import log_gradient_
# Test n.1
x = [1, 4.2]  # 1 represent the intercept
y_true = 1
theta = [0.5, -0.5]
x_dot_theta = sum([a * b for a, b in zip(x, theta)])
y_pred = sigmoid_(x_dot_theta)
print(log_gradient_(x, y_pred, y_true))
# [0.8320183851339245, 3.494477217562483]
# Test n.2
x = [1, -0.5, 2.3, -1.5, 3.2]
y_true = 0
theta = [0.5, -0.5, 1.2, -1.2, 2.3]
x_dot_theta = sum([a * b for a, b in zip(x, theta)])
y_pred = sigmoid_(x_dot_theta)
print(log_gradient_(x, y_true, y_pred))
# [0.99999685596372, -0.49999842798186, 2.299992768716556, -1.4999952839455801, 3.1999899390839044]
# Test n.3
x_new = [[1, 2, 3, 4, 5], [1, 6, 7, 8, 9], [1, 10, 11, 12, 13]]
# first column of x_new are intercept values initialized to 1
y_true = [1, 0, 1]
theta = [0.5, -0.5, 1.2, -1.2, 2.3]
x_new_dot_theta = []
for i in range(len(x_new)):
    my_sum = 0
    for j in range(len(x_new[i])):
        my_sum += x_new[i][j] * theta[j]
    x_new_dot_theta.append(my_sum)

y_pred = sigmoid_(x_new_dot_theta)
print(log_gradient_(x_new, y_true, y_pred))
# [0.9999445100449934, 5.999888854245219, 6.999833364290213, 7.999777874335206, 8.999722384380199]
