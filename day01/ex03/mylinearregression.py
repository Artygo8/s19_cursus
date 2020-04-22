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
        res = new_table.dot(self.theta)
        return (res)

    def cost_elem_(self, X, Y):
        solution = []
        l = len(X)
        b = np.zeros((l, 1)) + 1
        X = np.c_[b, X]
        X = np.dot(X, self.theta)
        for i, j in zip(X, Y):
            solution.append((j - i) ** 2)
        solution = np.array(solution)
        return (0.5 / len(Y) * solution)

    def cost_(self, X, Y):
        solution = 0
        l = len(X)
        b = np.zeros((l, 1)) + 1
        X = np.c_[b, X]
        X = np.dot(X, self.theta)
        for i, j in zip(X, Y):
            solution += (j - i) ** 2
        return float(0.5 / len(Y) * solution)

    def gradient(self, X, y):
        diff = np.dot(X, self.theta) - y
        return (1. / len(X)) * np.dot(np.transpose(X), diff)

    def fit_(self, X, y, alpha=0.01, n_cycle=2000):
        X_b = np.c_[np.zeros((len(X), 1)) + 1, X]
        for i in range(n_cycle):
            self.theta = self.theta - alpha * self.gradient(X_b, y) / 2
        return (self.theta)


X = np.array([[1., 1., 2., 3.], [5., 8., 13., 21.], [34., 55., 89., 144.]])
Y = np.array([[23.], [48.], [218.]])
mylr = MyLinearRegression([[1.], [1.], [1.], [1.], [1]])
print(mylr.predict_(X))
# array([[8.], [48.], [323.]])
print(mylr.cost_elem_(X, Y))
# array([[37.5], [0.], [1837.5]])
print(mylr.cost_(X, Y))
# 1875.0
mylr.fit_(X, Y, alpha=1.6e-4, n_cycle=200000)
print(mylr.theta)
# array([[18.023..], [3.323..], [-0.711..], [1.605..], [-0.1113..]])
print(mylr.predict_(X))
# array([[23.499..], [47.385..], [218.079...]])
print(mylr.cost_elem_(X, Y))
# array([[0.041..], [0.062..], [0.001..]])
print(mylr.cost_(X, Y))
# 0.1056..
