import numpy as np
import pandas as pd
from sklearn.model_selection import LeaveOneOut
from sklearn.linear_model import Ridge

data = pd.read_csv("../resources/data.csv")

r = Ridge()
r.set_params(alpha=10)
print(r.get_params()['alpha'])
