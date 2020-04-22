import numpy as np

# for (iteration in seq_len(n_iterations)) {
#   yhat               <- dot(x_b, theta)          # predict using weights in theta
#   residuals_b        <- yhat - y                 # calculate the residuals
#   gradients          <- 2/n * dot(t(x_b), residuals_b) # calculate the gradients of MSE w.r.t model weights
#   theta              <- theta - learning_rate * gradients # update theta
#
#   sse_i[[iteration]] <- sum((y - dot(x_b, theta))**2)
#   b0[[iteration]]    <- theta[2]
#   b1[[iteration]]    <- theta[1]
#
# }


def gradient(theta, X, y):
    diff = np.dot(X, theta) - y
    return (1. / len(X)) * np.dot(np.transpose(X), diff)


def fit_(theta, X, y, alpha=0.01, n_cycle=2000):
    X_b = np.c_[np.zeros((len(X), 1)) + 1, X]
    for i in range(n_cycle):
        theta = theta - alpha * gradient(theta, X_b, y) / 2
    return (theta)


X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
Y1 = np.array([[2.], [6.], [10.], [14.], [18.]])
theta1 = np.array([[1.], [1.]])
theta1 = fit_(theta1, X1, Y1, alpha=0.01, n_cycle=2000)
print(theta1)
# array([[2.0023..],[3.9991..]])
# predict_(theta1, X1)
# array([2.0023..], [6.002..], [10.0007..], [13.99988..], [17.9990..])

X2 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8.,
                                                                80.]])
Y2 = np.array([[19.6], [-2.8], [-25.2], [-47.6]])
theta2 = np.array([[42.], [1.], [1.], [1.]])
theta2 = fit_(theta2, X2, Y2, alpha=0.0005, n_cycle=42000)
# print(theta2)
# array([[41.99..], [0.97..], [0.77..], [-1.20..]])
# predict_(theta2, X2)
# array([[19.5937..], [-2.8021..], [-25.1999..], [-47.5978..]])
