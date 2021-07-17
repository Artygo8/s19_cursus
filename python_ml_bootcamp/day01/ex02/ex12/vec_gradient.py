import numpy as np


def vec_gradient(x, y, theta):
    """Computes a gradient vector from three non-empty numpy.ndarray,
   without any for-loop. The three arrays must have the compatible dimensions.
    Args:
        x: has to be an numpy.ndarray, a matrice of dimension m * n.
        y: has to be an numpy.ndarray, a vector of dimension m * 1.
        theta: has to be an numpy.ndarray, a vector n * 1.
    Returns:
        The gradient as a numpy.ndarray, a vector of dimensions n * 1, containg
   the result of the formula for all j.
        None if x, y, or theta are empty numpy.ndarray.
        None if x, y and theta do not have compatible dimensions.
    Raises:
        This function should not raise any Exception.
    """
    if len(x) == 0:
        return None
    m, n = x.shape
    if y.shape[0] != m or theta.shape[0] != n:
        return None
    return np.dot(np.transpose(x), (np.dot(x, theta) - y)) / m
