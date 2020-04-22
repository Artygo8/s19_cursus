import numpy as np


def mat_mat_prod(x, y):
    lst = []
    for i in range(len(x)):  # lines of x
        for j in range(len(y[0])):  # by columns of y
            solution = 0
            for k in range(len(y)):
                # each elem from line x (with a different col index)
                # times each elem from column y (with a different line index)
                solution += x[i][k] * y[k][j]
            lst.append(solution)
    return np.reshape(lst, (len(x), len(y[0])))  # lines of x vs columns of y


W = np.array([[-8, 8, -6, 14, 14, -9, -4],
              [2, -11, -2, -11, 14, -2, 14],
              [-13, -2, -5, 3, -8, -4, 13],
              [2, 13, -14, -15, -14, -15, 13],
              [2, -1, 12, 3, -7, -3, -6]])

Z = np.array([
    [-6, -1, -8, 7, -8],
    [7, 4, 0, -10, -10],
    [7, -13, 2, 2, -11],
    [3, 14, 7, 7, -4],
    [-1, -3, -8, -4, -14],
    [9, -14, 9, 12, -7],
    [-9, -4, -10, -3, 6]])

print(mat_mat_prod(W, Z))

"""
array([[ 45, 414, -3, -202, -163],
[-294, -244, -367, -79, 62],
[-107, 140, 13, -115, 385],
[-302, 222, -302, -412, 447],
[ 108, -33, 118, 79, -67]])


array([[ 45, 414, -3, -202, -163],
 [-294, -244, -367, -79, 62],
 [-107, 140, 13, -115, 385],
 [-302, 222, -302, -412, 447],
 [ 108, -33, 118, 79, -67]])
"""
print(mat_mat_prod(Z, W))
