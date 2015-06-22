import matplotlib.pyplot as plt
import matplotlib.cm as cm
from readwrl import model
from PIL import Image
import numpy as np

m=model('./999_3D_PS_2.wrl')
m.readwrl()
m.writeobj()
im=np.array(Image.open('./face_margin.bmp').convert('L'))
# im = plt.imread('./face_margin.bmp')
# figure()
# texture=np.array(m.gettexture())
[height,width]=im.shape
# print height,width
texture=[[int(i[0]*width),int((1-i[1])*height)] for i in m.gettexture()]
print len(texture)
# plt.imshow(im,cmap=cm.gray,norm=plt.Normalize(vmin=0,vmax=255))
# plt.show()
threshold=[]

for j in range(height):
	flag=False
	for i in range(width):
		if im[j,i]==255:
			threshold.append(i)
			flag=True
			break
	if flag is False:
		threshold.append(0)

remove_index=[]
for index , coordinate in enumerate(texture):
	# x=coordinate[0]   y=coordinate[1]
	# print index
	if threshold[coordinate[1]]>coordinate[0]:
		# print index
		remove_index+=[index]

m.removepoint(remove_index)
m.writeobj()
