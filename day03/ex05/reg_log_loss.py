from math import log
import numpy as np


def reg_log_loss_(y_true, y_pred, m, theta, lambda_, eps=1e-15):
    if m == 1:
        return (-(y_true * log(y_pred + eps) + (1 - y_true) * log(1 - y_pred + eps)))
    solution = 0
    for yt, yp in zip(y_true, y_pred):
        solution -= yt * log(yp + eps) + (1 - yt) * \
            log(1 - yp + eps) - lambda_ * np.dot(theta, theta) / m
    return solution / m
