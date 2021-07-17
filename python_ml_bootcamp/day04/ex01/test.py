import numpy as np
from gini import gini


# print(gini(np.array([])))
# None
# print(gini(np.array({1, 2})))
# None
# print(gini(np.array('bob')))
# None
print(gini(np.array([0, 0, 0, 0, 0, 0])))
# 0.0
print(gini(np.array([6])))
# 0.0
print(gini(np.array(['a', 'a', 'b', 'b'])))
# 1.0
print(gini(np.array(['0', '0', '1', '0', 'bob', '1'])))
# 1.4591479170272448
print(gini(np.array([0, 0, 1, 0, 2, 1])))
# 1.4591479170272448
print(gini(np.array(['0', 'bob', '1'])))
# 1.584962500721156
print(gini(np.array([1., 1., 1., 1., 1., 1., 1., 1., 1., 1.])))
# 0.0
print(gini(np.array([0., 1., 1., 1., 1., 1., 1., 1., 1., 1.])))
# 0.4689955935892812
print(gini(np.array([0, 0, 1])))
# 0.9182958340544896
