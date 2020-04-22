import numpy as np


def gradient(x, y, theta):
    """Computes a gradient vector from three non-empty numpy.ndarray, using
   a for-loop. The two arrays must have the compatible dimensions.
    Args:
        x: has to be an numpy.ndarray, a matrice of dimension m * n.
        y: has to be an numpy.ndarray, a vector of dimension m * 1.
        theta: has to be an numpy.ndarray, a vector n * 1.
    Returns:
        The gradient as a numpy.ndarray, a vector of dimensions n * 1.
        None if x, y, or theta are empty numpy.ndarray.
        None if x, y and theta do not have compatible dimensions.
    Raises:
        This function should not raise any Exception.
    """
    if len(x) == 0:
        return None
    m, n = x.shape
    if y.shape != (m,) or theta.shape != (n,):
        return None
    res = np.zeros((n,))
    for i in range(m):
        tx = np.dot(theta, x[i])
        res = np.add(res, np.dot((tx - y[i]), x[i]))
    return res / len(x)
