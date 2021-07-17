import numpy as np


def reg_mse(x, y, theta, lambda_):
    """Computes the regularized mean squared error of three non-empty
   numpy.ndarray, without any for-loop. The three arrays must have compatible
   dimensions.
    Args:
        y: has to be a numpy.ndarray, a vector of dimension m * 1.
        x: has to be a numpy.ndarray, a matrix of dimesion m * n.
        theta: has to be a numpy.ndarray, a vector of dimension n * 1.
        lambda: has to be a float.
    Returns:
        The mean squared error as a float.
        None if y, x, or theta are empty numpy.ndarray.
        None if y, x or theta does not share compatibles dimensions.
    Raises:
        This function should not raise any Exception.
    """
    if len(x) == 0:
        return(0)
    m, n = x.shape
    if (y.shape != (m,) and y.shape != (m, 1)) or (theta.shape != (n,) and theta.shape != (n, 1)):
        return None
    xt = np.dot(x, theta)
    res = np.dot(np.transpose(xt - y), (xt - y)) + \
        np.dot(lambda_ * theta, theta)
    return res / m
