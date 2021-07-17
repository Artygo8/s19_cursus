def precision_score_(y_true, y_pred, pos_label=1):
    tot = 0
    count = 0
    for yt, yp in zip(y_true, y_pred):
        if yp == pos_label:
            if yt == yp:
                count += 1
            tot += 1
    return count / tot
