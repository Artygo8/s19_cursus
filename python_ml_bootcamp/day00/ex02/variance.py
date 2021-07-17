from ex01.mean import mean


def variance(x):
    """Computes the variance of a non-empty numpy.ndarray, using a for-loop.
    Args:
        x: has to be an numpy.ndarray, a vector.
    Returns:
        The variance as a float.
        None if x is an empty numpy.ndarray.
    Raises:
        This function should not raise any Exception.
    """
    if len(x) == 0:
        return None
    mu = mean(x)
    tot = 0
    for xi in x:
        tot += (xi - mu) ** 2
    return tot / len(x)
