# import numpy as np
# from enthought.mayavi import mlab

# x, y = np.ogrid[-2:2:20j, -2:2:20j]
# z = x * np.exp( - x**2 - y**2)

# pl = mlab.surf(x, y, z, warp_scale="auto")
# mlab.axes(xlabel='x', ylabel='y', zlabel='z')
# mlab.outline(pl)
import numpy as np
from scipy.optimize import leastsq
import pylab as pl

def func(x, p):
    A, k, theta = p
    return A*np.sin(2*np.pi*k*x+theta)   

def residuals(p, y, x):
    return y - func(x, p)

x = np.linspace(0, -2*np.pi, 100)
A, k, theta = 10, 0.34, np.pi/6
y0 = func(x, [A, k, theta])
y1 = y0 + 2 * np.random.randn(len(x)) 

p0 = [7, 0.2, 0]


plsq = leastsq(residuals, p0, args=(y1, x))

print [A, k, theta] 
print plsq[0]

pl.plot(x, y0, label="data")
pl.plot(x, y1, label="data with noise")
pl.plot(x, func(x, plsq[0]), label="fitting data")
pl.legend()
pl.show()