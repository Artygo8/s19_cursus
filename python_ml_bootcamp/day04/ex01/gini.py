import numpy as np


def gini(array):
    """
    Computes the gini impurity of a non-empty numpy.ndarray
    :param numpy.ndarray array:
    :return float: gini_impurity as a float or None if input is not a
    non-empty numpy.ndarray
    """
    G = 1
    for elem in np.unique(array):
        p = (array == elem).sum() / len(array)
        G -= p ** 2
    return (G)
