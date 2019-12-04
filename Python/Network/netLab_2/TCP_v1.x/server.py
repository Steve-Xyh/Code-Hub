#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# server.py

import socket
import sys
import datetime


# 创建 socket 对象
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

# 获取本地主机名
host = socket.gethostname()
port = 9999

# 绑定端口号
serversocket.bind((host, port))

# 设置最大连接数，超过后排队
serversocket.listen(5)

while True:
    # 建立客户端连接
    clientsocket,addr = serversocket.accept()      

    msg='晚上好！！！！！！'
    print("连接地址: %s" % str(addr[0]) + '\t发送消息:\t' + msg)
    
    clientsocket.send(msg.encode('utf-8'))
    clientsocket.close()
