import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from MyLR.MyLR import MyLinearRegression


class MyRidge(MyLinearRegression):

    def __init__(self):
        super().__init__()
        init.alpha = 1
        init.max_iter = 1000
        init.tol = 0.001

    def get_params_(self):
        return getattr(self)

    def set_params_(self, **kwargs):
        for key, val in kwargs:
            setattr(self, key, val)

    fit_(self, lambda=1.0, max_iter=1000, tol=0.001):
    """
    Fit the linear model by performing Ridge regression (Tikhonov
   regularization).
    Args:
        lambda: has to be a float. max_iter: has to be integer.
        tol: has to be float.
    Returns:
        Nothing.
    Raises:
        This method should not raise any Exception.
    """
