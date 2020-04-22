import numpy as np


def vec_log_gradient_(x, y_true, y_pred):
    return np.dot((y_pred - y_true), x)
