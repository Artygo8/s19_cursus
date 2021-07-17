import numpy as np
from ex12.vec_gradient import vec_gradient


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


def fit_(theta, X, y, alpha=0.01, n_cycle=2000):
    """
    Description:
        Performs a fit of Y(output) with respect to X.
    Args:
        theta: has to be a numpy.ndarray, a vector of dimension (number of
   features + 1, 1).
        X: has to be a numpy.ndarray, a matrix of dimension (number of
   training examples, number of features).
        Y: has to be a numpy.ndarray, a vector of dimension (number of
   training examples, 1).
    Returns:
        new_theta: numpy.ndarray, a vector of dimension (number of the
   features +1,1).
        None if there is a matching dimension problem.
    Raises:
        This function should not raise any Exceptio
    """
    m, nb_feat = X.shape
    if theta.shape != (nb_feat + 1, 1) or y.shape != (m, 1):
        return None
    X_b = np.c_[np.zeros((len(X), 1)) + 1, X]
    for i in range(n_cycle):
        theta = theta - alpha * vec_gradient(X_b, y, theta) / 2
    return (theta)
