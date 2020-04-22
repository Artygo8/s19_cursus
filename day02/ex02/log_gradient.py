def log_gradient_(x, y_true, y_pred):
    if (type(y_true) == list):
        lst = []
        for i in range(len(x[0])):
            sum = 0
            for j in range(len(y_pred)):
                sum += (float((y_pred[j] - y_true[j]) * x[j][i]))
            lst.append(sum)
        return (lst)
    if (type(x) == list):
        lst = []
        for i in range(len(x)):
            lst.append(float((y_pred - y_true) * x[i]))
        return (lst)
