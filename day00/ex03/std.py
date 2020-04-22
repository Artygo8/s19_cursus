from ex02.variance import variance


def std(x):
    """Computes the standard deviation of a non-empty numpy.ndarray, using a
   for-loop.
    Args:
        x: has to be an numpy.ndarray, a vector.
    Returns:
        The standard deviation as a float.
        None if x is an empty numpy.ndarray.
    Raises:
        This function should not raise any Exception.
    """
    if len(x) == 0:
        return None
    return variance(x) ** (1 / 2)
