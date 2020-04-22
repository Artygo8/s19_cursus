from math import log


def log_loss_(y_true, y_pred, m, eps=1e-15):
    if m == 1:
        return (-(y_true * log(y_pred + eps) + (1 - y_true) * log(1 - y_pred + eps)))
    solution = 0
    for yt, yp in zip(y_true, y_pred):
        solution -= yt * log(yp + eps) + (1 - yt) * log(1 - yp + eps)
    return solution * 1 / len(y_pred)
