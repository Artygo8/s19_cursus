import numpy as np


def reg_logistic_grad(x, y, theta, lambda_):
    m, n = x.shape
    res = np.zeros((n, 1))
    for j in range(n):
        for i in range(m):
            res[j] += (np.dot(theta, x[i]) - y[i]) * x[i, j]
            + lambda_ * theta[j]
    return res / m
