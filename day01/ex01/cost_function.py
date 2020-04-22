import numpy as np


def cost_elem_(theta, X, Y):
    solution = []
    X_b = np.c_[np.ones((len(X), 1)), X]
    theta_x = np.dot(X_b, theta)
    for i, j in zip(theta_x, Y):
        solution.append((j - i) ** 2)
    solution = np.array(solution)
    return (0.5 / len(Y) * solution)


def cost_(theta, X, Y):
    solution = 0
    X_b = np.c_[np.ones((len(X), 1)), X]
    theta_x = np.dot(X_b, theta)
    for i, j in zip(theta_x, Y):
        solution += (j - i) ** 2
    return float(0.5 / len(Y) * solution)
