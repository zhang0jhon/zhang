from PIL import Image
from pylab import *


im = array(Image.open('lena.jpg'))
print im.shape,im.dtype
im = array(Image.open('lena.jpg').convert('L'),'f')
print im.shape,im.dtype
imshow(im)
print 'Please click 3 points'
x = ginput(3)
print 'you clicked:',x
show()
