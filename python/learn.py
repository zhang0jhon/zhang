# # print 'hello world!'
# # print(abs(-4))
# # mystring ='hello world'
# # print mystring
# # print "%s is number %d!" %("python",1)
# # import sys
# # logfile=open('/home/zhang/zhang/python/mylog.txt','a')
# # print >>logfile,'error'
# # logfile.close()
# # num=raw_input('login name:')
# # print 'login name is :%d' %(int(num)*2)
# # print 2<4
# # ptr='python'
# # print ptr[2:5]
# # aDict={'host':'earth'}
# # aDict['port']=80
# # for key in aDict:
# # 	print key,aDict[key]
# # string = 'abc'
# # for i,ch in enumerate(string):
# # # 	print  ch, i
# # sudEvens=[x**2 for x in range(8) if not x % 2]
# # for x in sudEvens:
# # 	print x;
# # try:
# # 	file = open('./mylog.txt','r')
# # 	for eachLine in file:
# # 		print eachLine,
# # 	file.close()
# # except IOError, e:
# # 	print 'file open error' , e
# # def addMe2Me(x):
# # 	'apply + operation to argument'
# # 	return (x + x)
# # print addMe2Me([-1,'abc'])
# class fooClass(object):
# 	"""my very first class: FooClass"""
# 	version = 0.1 # class (data) attribute
# 	def __init__(self, nm='John Doe'):
# 		"""constructor"""
# 		self.name = nm # class instance (data) attribute
# 		print 'Created a class instance for', nm
# 	def showname(self):
# 		"""display instance attribute and class name"""
# 		print 'Your name is', self.name
# 		print 'My name is', self.__class__.__name__
# 	def showver(self):
# 		"""display class(static) attribute"""
# 		print 'version is :',self.version
# 	 # references FooClass.version
# 	def addMe2Me(self, x): # does not use 'self'
# 		"""apply + operation to argument"""
# 		return x + x

# foo1=fooClass('zhang')
# foo1.showname()
# foo1.showver()
# print foo1.addMe2Me('zhang')
# print 'zhang	\
# zhang'
# dir()
# print type(type(foo1))
# import cv
# #print eval(repr(foo1))
# print type(10.1)
# print 1.0/2
# print coerce(1+1j,32)
# print divmod(13,5)
# import math
# for eachNum in range(10):
# 	print round(math.pi,eachNum)
# print ord('a')  #ascii
# num=raw_input('input:')
# print num
# string ='hello world'
# print string[1:5:2], string[6:]
# hi = '''hi \nthere'''
# print hi # repr()
# hi = 'hi \nthere'
# print hi # repr()
# s=set('cheeseshop')
# t=frozenset('bookshop')
# print s
# print t
# print map(lambda x: x ** 2, range(6))
# print [x ** 2 for x in range(6)]
# f=open('mylog.txt','r')
# print sum((len(word) for line in f for word in line.split()))
# print max(len(x.strip()) for x in open('mylog.txt'))
# f.close()
# import os
# print os.path.expanduser('~/zhang/python')
# multiprocessing
def newfoo(arg1, arg2, *nkw, **kw):
	'display regular aDictrgs and all variable args'
	print 'arg1 is:', arg1 ,
	print 'arg2 is:', arg2 
	for eachNKW in nkw:
		print 'additional non-keyword arg:', eachNKW
	for eachKW in kw.keys():
		print "additional keyword arg '%s': %s" % \
		(eachKW, kw[eachKW])
print newfoo('wolf', 3, 'projects', freud=90, gamble=96)
print map(lambda x, y: (x+y, x-y), [1,3,5], [2,4,6])
print 'the total is:', reduce((lambda x,y: x+y), range(5))
from functools import partial
baseTwo = partial(int, base=2)
print baseTwo('10010')

import re
pi_patt = '3\.14'
m = re.match(pi_patt, '3.14')
if m is not None: 
	print m.group()
m = re.search(r'\Bthe', 'bitethe dog')
if m is not None: 
	print m.group()
print re.subn('X', 'Mr. Smith', 'attn: X\n\nDear X,\n')
print re.split(':', 'str1:str2:str3')
#import multiprocessing

from PIL import Image
image=Image.open('lena.jpg')
