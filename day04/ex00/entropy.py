from math import log2
import numpy as np


def entropy(array):
    """
    Computes the Shannon Entropy of a non-empty numpy.ndarray
    :param numpy.ndarray array:
    :return float: shannon's entropy as a float or None if input is not a
    non-empty numpy.ndarray
    """
    if type(array) != ndarray:
        return None
    S = 0
    for elem in np.unique(array):
        p = (array == elem).sum() / len(array)
        S -= p * log2(p)
    return (S)
