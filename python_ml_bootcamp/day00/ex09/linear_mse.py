import numpy as np


def linear_mse(x, y, theta):
    """Computes the mean squared error of three non-empty numpy.ndarray,
   using a for-loop. The three arrays must have compatible dimensions.
    Args:
    y: has to be an numpy.ndarray, a vector of dimension m * 1.
    x: has to be an numpy.ndarray, a matrix of dimesion m * n.
    theta: has to be an numpy.ndarray, a vector of dimension n * 1.
    Returns:
    The mean squared error as a float.
    None if y, x, or theta are empty numpy.ndarray.
    None if y, x or theta does not share compatibles dimensions.
    Raises:
    This function should not raise any Exception.
    """
    if len(x) == 0:
        return None
    m, n = x.shape
    if y.shape != (m,) or theta.shape != (n,):
        return None
    tot = 0
    for i in range(m):
        tot += (np.dot(theta, x[i]) - y[i]) ** 2
    return tot / m
