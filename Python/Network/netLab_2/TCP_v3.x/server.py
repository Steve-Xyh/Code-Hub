#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# server.py

import socket
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
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 获取本地主机名及IP
host = socket.gethostname()
port = 9999
host_ip = socket.gethostbyname(host)

# 绑定端口号
serversocket.bind((host, port))

# 设置最大连接数，超过后排队
serversocket.listen(5)

while True:
    # 建立客户端连接
    clientsocket, addr = serversocket.accept()

    msg = '连接成功√'
    # print("连接地址: %s" % str(addr[0]) + '\t发送消息:\t' + msg)
    log({'连接地址:': addr[0], '\t发送消息: ': msg})
    msg += '\t主机地址 %s' % host_ip

    clientsocket.send(msg.encode('utf-8'))

    t = datetime.datetime.now()
    timestr = '%d-%d-%d_%d.%d.%d' % (t.year, t.month, t.day, t.hour, t.minute, t.second)
    fileName = 'new_file' + timestr

    while True:
        with open(fileName,'ab') as file_recv:
            data = clientsocket.recv(1024)
            if not data:
                break

            file_recv.write(data)

    print(fileName + '\t接收完成')
    file_recv.close()

    clientsocket.close()
