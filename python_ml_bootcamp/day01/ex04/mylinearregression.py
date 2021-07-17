import numpy as np


class MyLinearRegression():
    """
    Description:
    My personnal linear regression class to fit like a boss.
    """

    def __init__(self, theta):
        self.theta = theta

    def predict_(self, X):
        new_table = np.c_[np.ones((len(X), 1)), X]
        res = np.dot(new_table, self.theta)
        return (res)

    def cost_elem_(self, X, Y):
        solution = []
        X_b = np.c_[np.ones((len(X), 1)), X]
        theta_x = np.dot(X_b, self.theta)
        for i, j in zip(theta_x, Y):
            solution.append((j - i) ** 2)
        solution = np.array(solution)
        return (0.5 / len(Y) * solution)

    def cost_(self, X, Y):
        solution = 0
        print(self.theta)
        X_b = np.c_[np.ones((len(X), 1)), X]
        theta_x = np.dot(X_b, self.theta)
        for i, j in zip(theta_x, Y):
            solution += (j - i) ** 2
        return float(0.5 / len(Y) * solution)

    def gradient(self, X, y):
        X_b = np.c_[np.zeros((len(X), 1)) + 1, X]
        diff = np.dot(X_b, self.theta) - y
        return (1. / len(X)) * np.dot(np.transpose(X), diff)

    def linear_mse(self, x, y):
        xb = np.c_[np.zeros((len(x), 1)) + 1, x]
        tot = np.dot(xb, self.theta) - y
        tot = np.dot(tot, np.transpose(tot))
        return tot / len(xb)

    def mse_(self, x, y):
        y_hat = self.predict_(x)
        solution = 0
        for i, j in zip(y, y_hat):
            solution += (j - i) ** 2
        return float(1 / len(y) * solution)

    def fit_(self, X, y, alpha=0.01, n_cycle=2000):
        X_b = np.c_[np.zeros((len(X), 1)) + 1, X]
        theta = self.theta
        for i in range(n_cycle):
            theta = theta - alpha * self.gradient(X, y) / 2
        return (theta)
