import numpy as np
from confusion_matrix import confusion_matrix_
from sklearn.metrics import confusion_matrix


y_pred = np.array(['norminet', 'dog', 'norminet', 'norminet', 'dog', 'bird'])
y_true = np.array(['dog', 'dog', 'norminet', 'norminet', 'dog', 'norminet'])

print(confusion_matrix_(y_true, y_pred))
print(confusion_matrix(y_true, y_pred))
# [[0 0 0]
# [0 2 1]
# [1 0 2]]
# [[0 0 0]
# [0 2 1]
# [1 0 2]]
print(confusion_matrix_(y_true, y_pred, labels=['dog', 'norminet']))
print(confusion_matrix(y_true, y_pred, labels=['dog', 'norminet']))
# [[2 1]
# [0 2]]
# [[2 1]
# [0 2]]
