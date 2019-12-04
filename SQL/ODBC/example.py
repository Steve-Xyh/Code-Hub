#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import psycopg2 as pg

spj_db = pg.connect(database = 'spj', user = 'postgres', password = '0807', host = '127.0.0.1', port = '5432')
spj = spj_db.cursor()
print ('ODBC连接成功')

spj_header = 'SNO\tSNAME\tSTATUS\tCITY\tPHONE'
lines = '-' * 100


def spj_select():
	# print(spj_header)
	spj.execute('select count(*) from s')
	spj_res = spj.fetchall()

	for row in spj_res:
		res = ''
		for i in row:
			res += 'The count of tuples in table s: ' + str(i) + '\t'
		print(res)


def spj_test():
	spj_select()
	

spj_test()
spj_db.close()
#student_db.close()