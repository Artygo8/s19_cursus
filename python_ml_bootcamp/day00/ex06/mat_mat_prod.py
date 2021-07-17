import numpy as np


def mat_mat_prod(x, y):
    """Computes the product of two non-empty numpy.ndarray, using a
   for-loop. The two arrays must have compatible dimensions.
    Args:
        x: has to be an numpy.ndarray, a matrix of dimension m * n.
        y: has to be an numpy.ndarray, a vector of dimension n * p.
    Returns:
        The product of the matrices as a matrix of dimension m * p.
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
    n, p = y.shape
    res = np.zeros((m, p))
    for mi in range(m):
        for ni in range(n):
            for pi in range(p):
                res[mi][pi] += x[mi][ni] * y[ni][pi]
    return res.astype(int)
