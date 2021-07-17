import numpy as np


def sigmoid_(x):
    if (type(x) != list and type(x) != np.ndarray):
        return (1 / (1 + np.exp(x * -1)))
    else:
        lst = []
        for xi in x:
            lst.append(1 / (1 + np.exp(xi * -1)))
        return (lst)


def reg_logistic_grad(x, y, theta, lambda_):
    return (np.dot(np.transpose(x), sigmoid_(np.dot(x, theta)) - y) + lambda_ * theta) / len(x)
