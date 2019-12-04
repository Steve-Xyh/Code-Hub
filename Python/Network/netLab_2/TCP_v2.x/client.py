#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# client.py

import socket
import sys
import datetime


def log(dic):
    """
    function by Sofee
    :param dic: log dict(e.g. {name: value})
    """
    res = datetime.datetime.now().strftime(
        '[\033[0;32;1m%y-%m-%d %H:%M:%S\033[0m]') + ' '
    for key in dic:
        flg = dic[key] is not None
        # res += format(key, ' <10')
        res += key + ' '
        res += format('\033[0;33;1m' + dic[key] +
                      '\033[0m' if flg else '', ' <20')
    print(res)


# 创建 socket 对象
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 获取本地主机名
host = socket.gethostname()

# 设置端口号
port = 9999

# 连接服务，指定主机和端口
s.connect((host, port))

# 接收小于 1024 字节的数据
msg = s.recv(1024)

log({'消息内容:': msg.decode('utf-8')})

msg_num = len(sys.argv) - 1
send_msg = str(msg_num) + '\n'

if msg_num > 1:
	# send_msg = sys.argv[1]
	print('向主机发送 %d 条消息:' % msg_num)
	for msg in sys.argv[1:]:
		send_msg += msg + '\n'
		print(msg)

	s.send(send_msg.encode('utf-8'))


s.close()
