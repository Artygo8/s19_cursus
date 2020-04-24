import numpy as np


def sigmoid_(x):
    if (type(x) != list and type(x) != np.ndarray):
        return (1 / (1 + np.exp(x * -1)))
    else:
        lst = []
        for xi in x:
            lst.append(1 / (1 + np.exp(xi * -1)))
        return (lst)
