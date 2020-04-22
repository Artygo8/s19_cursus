import numpy as np


def mat_vec_prod(x, y):
    """Computes the product of two non-empty numpy.ndarray, using a
   for-loop. The two arrays must have compatible dimensions.
    Args:
        x: has to be an numpy.ndarray, a matrix of dimension m * n.
        y: has to be an numpy.ndarray, a vector of dimension n * 1.
    Returns:
        The product of the matrix and the vector as a vector of dimension m * 1.
        None if x or y are empty numpy.ndarray.
        None if x and y does not share compatibles dimensions.
    Raises:
        This function should not raise any Exception.
    """
    if len(x) == 0 or len(y) == 0:
        return None
    m, n = x.shape
    if n != len(y):
        return None
    res = np.zeros((m, 1))
    for mi in range(m):
        for ni in range(n):
            res[mi] += x[mi][ni] * y[ni]
    return res.astype(int)
