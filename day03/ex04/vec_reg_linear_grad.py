import numpy as np


def vec_reg_linear_grad(x, y, theta, lambda_):
    """Computes the regularized linear gradient of three non-empty
   numpy.ndarray, without any for-loop. The three arrays must have compatible
   dimensions.
    Args:
        y: has to be a numpy.ndarray, a vector of dimension m * 1.
        x: has to be a numpy.ndarray, a matrix of dimesion m * n.
        theta: has to be a numpy.ndarray, a vector of dimension n * 1.
        alpha: has to be a float.
        lambda_: has to be a float.
    Returns:
        A numpy.ndarray, a vector of dimension n * 1, containing the results of
   the formula for all j.
        None if y, x, or theta are empty numpy.ndarray.
        None if y, x or theta does not share compatibles dimensions.
    Raises:
        This function should not raise any Exception.µ
    """
    if len(x) == 0:
        return None
    m, n = x.shape
    if y.shape != (m,):
        return None
    return (np.dot(np.transpose(x), np.dot(x, theta) - y) + lambda_ * theta) / m
