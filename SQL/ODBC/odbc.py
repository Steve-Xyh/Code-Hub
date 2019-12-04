#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import psycopg2 as pg

spj_db = pg.connect(database = 'spj', user = 'postgres', password = '0807', host = '127.0.0.1', port = '5432')
spj = spj_db.cursor()
#student = student_db.cursor()
print ('ODBC连接成功')

spj_header = 'SNO\tSNAME\tSTATUS\tCITY\tPHONE'
lines = '-' * 100


def spj_select():
	print(spj_header)
	spj.execute('select * from s')
	spj_res = spj.fetchall()

	for row in spj_res:
		res = ''
		for i in row:
			res += str(i) + '\t'
		print(res)

	print('ODBC查询成功')


def spj_insert():
	print(lines)
	spj.execute("insert into s values ('S11','testODBC',10,'BJ')")
	spj_db.commit()
	print('ODBC插入结果:')
	spj_select()
	print('ODBC插入成功')
	print(lines)


def spj_update():
	print(lines)
	spj.execute("update s set status = 200 where sno = 'S11'")
	spj_db.commit()
	print('ODBC更新结果:')
	spj_select()
	print('ODBC更新成功')
	print(lines)


def spj_delete():
	print(lines)
	spj.execute("delete from s where sno = 'S11'")
	spj_db.commit()
	print('ODBC删除结果:')
	spj_select()
	print('ODBC删除成功')
	print(lines)
	

def spj_test():
	spj_select()
	spj_insert()
	spj_update()
	spj_delete()


spj_test()
spj_db.close()
#student_db.close()