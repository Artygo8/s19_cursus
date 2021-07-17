import numpy as np


def predict_(theta, X):
    """
    Description:
        Prediction of output using the hypothesis function (linear model).
    Args:
        theta: has to be a numpy.ndarray, a vector of dimension (number of
   features + 1, 1).
        X: has to be a numpy.ndarray, a matrix of dimension (number of
   training examples, number of features).
    Returns:
        pred: numpy.ndarray, a vector of dimension (number of the training
   examples,1).
        None if X does not match the dimension of theta.
    Raises:
        This function should not raise any Exception.
    """
    m, n = X.shape
    if theta.shape != (n + 1, 1):
        return print("Incompatible dimension match between X and theta")
    Xl = np.c_[np.ones((len(X), 1), dtype=int), X]
    return (np.dot(Xl, theta))
