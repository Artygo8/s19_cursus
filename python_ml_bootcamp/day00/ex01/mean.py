def mean(x):
    """Computes the mean of a non-empty numpy.ndarray, using a for-loop.
    Args:
        x: has to be an numpy.ndarray, a vector.
    Returns:
        The mean as a float.
        None if x is an empty numpy.ndarray.
    Raises:
        This function should not raise any Exception.
    """
    tot = 0
    if len(x) == 0:
        return None
    for xi in x:
        tot += xi
    return tot / len(x)
