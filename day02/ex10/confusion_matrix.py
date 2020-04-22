import numpy as np


def confusion_matrix_(y_true, y_pred, labels=None):
    all_labels = np.unique(np.c_[y_pred, y_true])
    if labels:
        all_labels = labels
    all_labels.sort()
    new = np.zeros((len(all_labels), len(all_labels)))
    for i in range(len(all_labels)):
        for j in range(len(all_labels)):
            for yt, yp in zip(y_true, y_pred):
                if (all_labels[i] == yt and all_labels[j] == yp):
                    new[i][j] += 1
    return new.astype(int)
