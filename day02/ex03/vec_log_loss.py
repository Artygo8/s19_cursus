import numpy
from math import log


def vec_log_loss_(y_true, y_pred, m, eps=1e-15):
    if m != 1:
        sum = 0
        for yp, yt in zip(y_pred, y_true):
            sum -= (yt * log(yp) + (1 - yt) * log(1 - yp))
        return sum / m
    else:
        res = -(y_true * log(y_pred + eps) +
                (1 - y_true) * log(1 - y_pred + eps))
    return (res)
