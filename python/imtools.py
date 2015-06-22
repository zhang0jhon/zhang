import os

def get_imlist(path):
	"""return .jpg filelist"""
	return [os.path.join(path,f) \
	for f in os.listdir(path) if f.endswith('.jpg')]

print get_imlist(".")