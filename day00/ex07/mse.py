import numpy as np


def mse(y, y_hat):
    """Computes the mean squared error of two non-empty numpy.ndarray, using
   a for-loop. The two arrays must have the same dimensions.
    Args:
        y: has to be an numpy.ndarray, a vector.
        y_hat: has to be an numpy.ndarray, a vector.
    Returns:
        The mean squared error of the two vectors as a float.
        None if y or y_hat are empty numpy.ndarray.
        None if y and y_hat does not share the same dimensions.
    Raises:
        This function should not raise any Exception.
    """
    if len(y) == 0 or y.shape != y_hat.shape:
        return None
    return sum([(y_hati - yi) ** 2 for yi, y_hati in zip(y, y_hat)]) / len(y)
