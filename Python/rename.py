#!/usr/bin/python
# -*- coding:utf-8 -*-
 

import os
 
outer_path = '/Users/apple/Desktop/Listening 2/T1-2'
folderlist = os.listdir(outer_path)        	#列举文件夹
total_num_file = len(folderlist)       		#单个文件夹内文件的总数
filelist = outer_path       				#列举图片

 
i = 0
form = '.aiff'
book = 9
testNum = 1
sectionNum = 1
cnt = 0


folderlist.sort()
for fileName in folderlist:
	print(str(fileName))

print("\n\n")
	

while not folderlist[cnt].endswith('aiff'):
	cnt += 1



for test in range(testNum,testNum + 2):
	for section in range(sectionNum, sectionNum + 4):
		item = folderlist[cnt]

		print('now in ' + str(item) + ',section = ' + str(section))

		if item.endswith('aiff'):
			print('visited %s,expect to C%d-T%d-%d%s' % (item,book,test,section,form))
			src = os.path.join(os.path.abspath(filelist), item)           #原图的地址
			dst = os.path.join(os.path.abspath(filelist), 'C' + str(book) + '-T' + str(test) + '-' + str(section) + str(form))        #新图的地址（这里可以把str(folder) + '_' + str(i) + '.jpg'改成你想改的名称）
			try:
				os.rename(src, dst)
				print ('converting %s to %s ...\n\n' % (src, dst))
				i += 1
			except:
				continue

		
		cnt += 1

print ('total %d to rename & converted %d jpgs' % (total_num_file, i))
	




'''
import os
 
outer_path = '/home/lincanran/cls_exp/place100'
folderlist = os.listdir(outer_path)          #列举文件夹
 
for folder in folderlist:     
	inner_path = os.path.join(outer_path, folder)
	total_num_folder = len(folderlist)       #文件夹的总数
	print 'total have %d folders' % (total_num_folder)   #打印文件夹的总数
	
	filelist = os.listdir(inner_path)        #列举图片
	i = 0
	for item in filelist:
		total_num_file = len(filelist)       #单个文件夹内图片的总数
		if item.endswith('.jpg'):
			src = os.path.join(os.path.abspath(inner_path), item)           #原图的地址
			dst = os.path.join(os.path.abspath(inner_path), str(folder) + '_' + str(i) + '.jpg')        #新图的地址（这里可以把str(folder) + '_' + str(i) + '.jpg'改成你想改的名称）
			try:
				os.rename(src, dst)
				print 'converting %s to %s ...' % (src, dst)
				i += 1
			except:
				continue
	print 'total %d to rename & converted %d jpgs' % (total_num_file, i)
'''