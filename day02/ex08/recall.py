def recall_score_(y_true, y_pred, pos_label=1):
    i = 0
    j = 0
    for elem in y_true:
        if elem == pos_label:
            j += 1
    for x, y in zip(y_true, y_pred):
        if x == pos_label and x == y:
            i += 1
    return float(i / j)
