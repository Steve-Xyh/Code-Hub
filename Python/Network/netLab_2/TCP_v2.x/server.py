#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# server.py

import socket
import sys
import datetime


def log(dic):
    """
    function by Sofee
    :param dic: log dict(e.g. {name: value})
    """
    res = datetime.datetime.now().strftime('[\033[0;32;1m%y-%m-%d %H:%M:%S\033[0m]') + ' '
    for key in dic:
        flg = dic[key] is not None
        # res += format(key, ' <10')
        res += key + ' '
        res += format('\033[0;33;1m' + dic[key] + '\033[0m' if flg else '', ' <20')
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
    clientsocket,addr = serversocket.accept()      

    msg='连接成功√'
    # print("连接地址: %s" % str(addr[0]) + '\t发送消息:\t' + msg)
    log({'连接地址:':addr[0], '\t发送消息: ':msg})
    msg += '\t主机地址 %s' % host_ip

    clientsocket.send(msg.encode('utf-8'))

    recv_msgs = clientsocket.recv(10240).decode('utf-8').splitlines()
    msg_num = int(recv_msgs[0])

    if msg_num >= 1:
        print('收到来自客户端 %s 的 %d 条消息:' % (addr[0], msg_num))
        # for i in range(msg_num):
        for recv_msg in recv_msgs[1:]:
            print(recv_msg)

        print('-'*10 + '接收完成' + '-'*10)

    clientsocket.close()