def dot(x, y):
    """Computes the dot product of two non-empty numpy.ndarray, using a
   for-loop. The two arrays must have the same dimensions.
    Args:
        x: has to be an numpy.ndarray, a vector.
        y: has to be an numpy.ndarray, a vector.
    Returns:
        The dot product of the two vectors as a float.
        None if x or y are empty numpy.ndarray.
        None if x and y does not share the same dimensions.
    Raises:
        This function should not raise any Exception.
    """
    tot = 0
    if len(x) == 0 or len(y) != len(x):
        return None
    for xi, yi in zip(x, y):
        tot += xi * yi
    return float(tot)
