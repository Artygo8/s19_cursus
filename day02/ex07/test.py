import numpy as np
from precision import precision_score_
from sklearn.metrics import precision_score
# Test n.1
y_pred = np.array([1, 1, 0, 1, 0, 0, 1, 1])
y_true = np.array([1, 0, 0, 1, 0, 1, 0, 0])
print(precision_score_(y_true, y_pred))
print(precision_score(y_true, y_pred))
# 0.4
# 0.4
# Test n.2
y_pred = np.array(['norminet', 'dog', 'norminet', 'norminet', 'dog', 'dog',
                   'dog', 'dog'])
y_true = np.array(['dog', 'dog', 'norminet', 'norminet', 'dog', 'norminet',
                   'dog', 'norminet'])
print(precision_score_(y_true, y_pred, pos_label='dog'))
print(precision_score(y_true, y_pred, pos_label='dog'))
# 0.6
# 0.6
# Test n.3
print(precision_score_(y_true, y_pred, pos_label='norminet'))
print(precision_score(y_true, y_pred, pos_label='norminet'))
# 0.6666666666666666
# 0.6666666666666666
