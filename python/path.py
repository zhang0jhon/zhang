#!/usr/bin/env python

import os
for tmpdir in ('/tmp', r'c:\temp'):
	if os.path.isdir(tmpdir):
		break
	else:
		print 'no temp directory available'
		tmpdir = ''

if tmpdir:
	os.chdir(tmpdir)
	cwd = os.getcwd()
	print '*** current temporary directory'
	print cwd

# print '*** creating example directory...'
# os.mkdir('example')
# os.chdir('example')
# cwd = os.getcwd()
# print '*** new working directory:'
# print cwd
# print '*** original directory listing:'
# print os.listdir(cwd)

# print '*** creating test file...'
# fobj = open('test', 'w')
# fobj.write('foo\n')
# fobj.write('bar\n')
# fobj.close()
# print '*** updated directory listing:'
# print os.listdir(cwd)

