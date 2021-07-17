import numpy as np


def cost_elem_(theta, X, Y):
    """
    Description:
        Calculates all the elements 0.5*M*(y_pred - y)^2 of the cost
   function.
    Args:
        theta: has to be a numpy.ndarray, a vector of dimension (number of
   features + 1, 1).
        X: has to be a numpy.ndarray, a matrix of dimension (number of
   training examples, number of features).
    Returns:
        J_elem: numpy.ndarray, a vector of dimension (number of the training
   examples,1).
        None if there is a dimension matching problem between X, Y or theta.
    Raises:
        This function should not raise any Exception.
    """
    m, nb_feat = X.shape
    if theta.shape != (nb_feat + 1, 1):
        return None
    theta_x = np.dot(np.c_[np.ones((m, 1)), X], theta)
    return ((1 / (2 * m)) * (theta_x - Y) ** 2)


def cost_(theta, X, Y):
    """
    Description:
        Calculates the value of cost function.
    Args:
        theta: has to be a numpy.ndarray, a vector of dimension (number of
   features + 1, 1).
        X: has to be a numpy.ndarray, a vector of dimension (number of
   training examples, number of features).
    Returns:
        J_value : has to be a float.
        None if X does not match the dimension of theta.
    Raises:
        This function should not raise any Exception.
    """
    m, nb_feat = X.shape
    if theta.shape != (nb_feat + 1, 1):
        return None
    theta_x = np.dot(np.c_[np.ones((m, 1)), X], theta)
    return ((1 / (2 * m)) * (theta_x - Y) ** 2).sum()
