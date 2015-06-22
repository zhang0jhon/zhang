import numpy as np

def func(i,j):
	return (i+1)*(j+1)

print np.fromfunction(func,(9,9))
print np.arange(0, 60, 10).reshape(-1, 1) + np.arange(0, 6)

persontype=np.dtype({'names':['name','age','weight'],\
	'formats':['S32','i','f']})
a=np.array([("Zhang",32,75.5),("Wang",24,65.2)],dtype=persontype)
print a[0]['name'],a.dtype
a.tofile('test.bin')
print np.dtype([('f1', [('f2', np.int16)])])
print np.dtype([('f0', 'i4'), ('f1', 'f8', (2, 3))])
print np.dtype({'surname':('S25',0),'age':(np.uint8,25)})
print a.strides

x = np.linspace(0, 2*np.pi, 10)
y = np.sin(x)
y=x*y
print y
x = np.linspace(0, 2, 1000)
def triangle_func(c, c0, hc):
    def trifunc(x):
        x = x - int(x) 
        if x >= c: r = 0.0
        elif x < c0: r = x / c0 * hc
        else: r = (c-x) / (c-c0) * hc
        return r
    return np.frompyfunc(trifunc, 1, 1)

y2 = triangle_func(0.6, 0.4, 1.0)(x)
y2.astype(np.float64)
print y2.dtype

def triangle_func(c, c0, hc):
    def trifunc(x):
        x = x - int(x)
        if x >= c: r = 0.0
        elif x < c0: r = x / c0 * hc
        else: r = (c-x) / (c-c0) * hc
        return r
    return np.frompyfunc(trifunc, 1, 1)

y2 = triangle_func(0.6, 0.4, 1.0)(x)
print type(y2)

x, y = np.ogrid[0:1:4j, 0:1:3j]
print x,y

print np.add.reduce([[1,2,3],[4,5,6]], axis=1)
print np.add.accumulate([[1,2,3],[4,5,6]], axis=1)

a = np.random.rand(10,10)
b = np.random.rand(10)
x = np.linalg.solve(a,b).reshape(-1,1)
print x

x = np.random.rand(8)
print x
xf = np.fft.fft(x)
print xf
np.fft.ifft(xf)