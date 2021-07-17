class LogisticRegressionBatchGd:
    def __init__(self, alpha=0.001, max_iter=1000, verbose=False,
                 learning_rate='constant'):
    self.alpha = alpha
    self.max_iter = max_iter
    self.verbose = verbose
    self.learning_rate = learning_rate  # can be 'constant' or 'invscaling'
    self.thetas = []
    # Your code here (e.g. a list of loss for each epochs...)

    def fit(self, x_train, y_train):
        """
         Fit the model according to the given training data.
         Args:
         x_train: a 1d or 2d numpy ndarray for the samples
         y_train: a scalar or a numpy ndarray for the correct labels
         Returns:
         self : object
         None on any error.
         Raises:
         This method should not raise any Exception.
         """
        return
    # Your code here

    def predict(self, x_train):
    """
 Predict class labels for samples in x_train.
 Arg:
 x_train: a 1d or 2d numpy ndarray for the samples
 Returns:
 y_pred, the predicted class label per sample.
 None on any error.
 Raises:
 This method should not raise any Exception.
 """
    # Your code here

    def score(self, x_train, y_train):
    """
 Returns the mean accuracy on the given test data and labels.
 Arg:
 x_train: a 1d or 2d numpy ndarray for the samples
 y_train: a scalar or a numpy ndarray for the correct labels
 Returns:
 Mean accuracy of self.predict(x_train) with respect to y_true
 None on any error.
 Raises:
 This method should not raise any Exception.
 """
    # Your code here
