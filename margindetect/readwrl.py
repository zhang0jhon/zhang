import re
import numpy as np

class model:
	'''3d model data processing'''
	def __init__(self, filename='./999_3D_PS_2.wrl'):
		self.filename=filename
		self.vertex_num=0
		self.vertex=[]
		self.texture=[]
		self.face=[]

	def readwrl(self):
		file=open(self.filename,'r')
		incoord=False
		point_coor=r'(-?\d+\.\d+) (-?\d+\.\d+) (-?\d+\.\d+),'
		texture_coor=r'(-?\d+\.\d+) (-?\d+\.\d+),'
		face_index=r'(-?\d+) (-?\d+) (-?\d+) -1,'
		for line in file:
			if re.search(r'coordIndex',line) is not None:
				incoord=True
			elif incoord is True and re.search(r']',line) is not None:
				incoord=False

			m=re.search(point_coor,line) 
			if m is not None:
				self.vertex_num+=1
				self.vertex.append([float(i) for i in list(m.groups())])
				#print self.vertex
			else:
				n=re.search(texture_coor,line) 
				if n is not None:
					self.texture.append([float(i) for i in list(n.groups())])
					#print self.texture
				else:
					f=re.search(face_index,line) 
					if f is not None and incoord is True:
						self.face.append([int(i) for i in list(f.groups())])
						# print self.face
		file.close()
		print len(self.vertex),len(self.texture)

	def writeobj(self):
		obj_filename=self.filename[:-4]+'.obj'
		file=open(obj_filename,'w')
		for i in self.vertex:
			line=''
			for j in i:
				line+=repr(j)+' '
			line='v '+line+'\n'
			file.write(line)
		for i in self.texture:
			line=''
			for j in i:
				line+=repr(j)+' '
			line='vt '+line+'\n'
			file.write(line)
		file.close()

	def gettexture(self):
		return self.texture

	def removepoint(self,pointindex):
		# print pointindex
		for index,i in enumerate(pointindex):
			del self.vertex[i-index]
			del self.texture[i-index]