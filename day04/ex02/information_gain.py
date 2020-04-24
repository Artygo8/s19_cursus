import numpy as np
from math import log2


def entropy(array):
    """
    Computes the Shannon Entropy of a non-empty numpy.ndarray
    :param numpy.ndarray array:
    :return float: shannon's entropy as a float or None if input is not a
    non-empty numpy.ndarray
    """
    S = 0
    for elem in np.unique(array):
        p = (array == elem).sum() / len(array)
        S -= p * log2(p)
    return (S)


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


def information_gain(array_source, array_children_list, criterion='gini'):
    """
    Computes the information gain between the first and second array using
    the criterion ('gini' or 'entropy')
    :param numpy.ndarray array_source:
    :param list array_children_list: list of numpy.ndarray
    :param str criterion: Should be in ['gini', 'entropy']
    :return float: Shannon entropy as a float or None if input is not a
    non-empty numpy.ndarray or None if invalid input
    """
    if criterion == gini:
        IG = gini(array_source) - gini(array_children_list)
    elif criterion == entopy:
        IG = entropy(array_source) - entropy(array_children_list)
    return IG
