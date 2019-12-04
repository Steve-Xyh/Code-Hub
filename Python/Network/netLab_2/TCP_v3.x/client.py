#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# client.py

import socket
import os
import sys
import datetime
from processBar import process_bar


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

log({'': msg.decode('utf-8')})

if len(sys.argv) == 2:
    if not os.path.isfile(sys.argv[1]):
        sys.exit(1)

    # filesize = os.path.getsize(sys.argv[1])
    with open(sys.argv[1],'rb') as file_send:
        for data in file_send:
            s.send(data)
            # data_size = len(data)
            # process_bar(data_size/filesize)

    file_send.close()
    print('\n' + sys.argv[1] + '\t发送完成')

s.close()
