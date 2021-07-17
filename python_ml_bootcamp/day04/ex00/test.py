import numpy as np
from entropy import entropy


# print(entropy(np.array([])))
# None
# print(entropy(np.array({1, 2})))
# None
# print(entropy(np.array('bob')))
# None
print(entropy(np.array([0, 0, 0, 0, 0, 0])))
# 0.0
print(entropy(np.array([6])))
# 0.0
print(entropy(np.array(['a', 'a', 'b', 'b'])))
# 1.0
print(entropy(np.array(['0', '0', '1', '0', 'bob', '1'])))
# 1.4591479170272448
print(entropy(np.array([0, 0, 1, 0, 2, 1])))
# 1.4591479170272448
print(entropy(np.array(['0', 'bob', '1'])))
# 1.584962500721156
print(entropy(np.array([1., 1., 1., 1., 1., 1., 1., 1., 1., 1.])))
# 0.0
print(entropy(np.array([0., 1., 1., 1., 1., 1., 1., 1., 1., 1.])))
# 0.4689955935892812
print(entropy(np.array([0, 0, 1])))
# 0.9182958340544896
