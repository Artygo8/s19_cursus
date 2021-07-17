import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import mean_squared_error
from mylinearregression import MyLinearRegression as MyLR

# data init
#
data = pd.read_csv("../are_blue_pills_magics.csv")
Xpill = np.array(data['Micrograms']).reshape(-1, 1)
Yscore = np.array(data['Score']).reshape(-1, 1)
#
# # Scattering
#
# # plt.scatter(Xpill, Yscore)
# # plt.plot()
# # plt.title('are_blue_pills_magics')
#
#
# # treating
#
# linear_model1 = MyLR(np.array([[89.0], [-8.7]]))
# linear_model2 = MyLR(np.array([[89.0], [-6]]))
# Y_model1 = linear_model1.predict_(Xpill)
# Y_model2 = linear_model2.predict_(Xpill)
#
# # plt.scatter(Xpill, Y_model1)
# # plt.plot(Xpill, Y_model1, 'r--')
# # plt.show()
#
# # J(theta)
#
# iter = [i for i in range(50)]
# iter = np.array(iter)
#
# base = np.array([[1], [1]])
# t0 = 0
# plt.plot(iter, [MyLR(np.array([[t0], [i]])).cost_(Xpill, Yscore)
#                 for i in iter])
#
# t0 = MyLR(np.array([[t0], [t0]])).mse_(Xpill, Yscore)
# print(t0)
# plt.plot(iter, [MyLR(np.array([[t0], [i]])).cost_(Xpill, Yscore)
#                 for i in iter])


# t0 = t1 * t0
# values = [MyLR(t0).mse_(Xpill, Yscore) for i in thetazeros]
# t1 = MyLR(t0).cost_(Xpill, Yscore)
# plt.plot(thetazeros, values, 'k')
#
# t0 = t1 * t0
# values = [MyLR(t0).mse_(Xpill, Yscore) for i in thetazeros]
# t1 = MyLR(t0).cost_(Xpill, Yscore)
# plt.plot(thetazeros, values, 'k')
#
# t0 = t1 * t0
# values = [MyLR(t0).mse_(Xpill, Yscore) for i in thetazeros]
# t1 = MyLR(t0).cost_(Xpill, Yscore)
# plt.plot(thetazeros, values, 'k')
#
# t0 = t1 * t0
# values = [MyLR(t0).mse_(Xpill, Yscore) for i in thetazeros]
# t1 = MyLR(t0).cost_(Xpill, Yscore)
# plt.plot(thetazeros, values, 'k')
#

plt.show()


fig = plt.figure()
ax = fig.gca(projection='3d')

# Make data.
X = np.arange(-5, 5, 0.25)
Y = np.arange(-5, 5, 0.25)
Z = MyLR(np.array([[Xi], [Yi]])).cost_(Xpill, Yscore)

# Plot the surface.
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm,
                       linewidth=0, antialiased=False)

# Customize the z axis.
ax.set_zlim(-1.01, 1.01)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

# Add a color bar which maps values to colors.
fig.colorbar(surf, shrink=0.5, aspect=5)

plt.show()


print(linear_model1.mse_(Xpill, Yscore))
# 57.60304285714282
print(mean_squared_error(Yscore, Y_model1))
# 57.603042857142825
print(linear_model2.mse_(Xpill, Yscore))
# 232.16344285714285
print(mean_squared_error(Yscore, Y_model1))
# 232.16344285714285
