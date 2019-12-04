#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import threading
import random
from time import sleep

maxCollision = 16
maxSend = 5

global Bus
Bus = 0


class myThread (threading.Thread):

    def __init__(self, threadID, name):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        
        #自定义数据
        self.sendCounter = 0
        self.collisionCounter = 0
        self.collisionWindow = 0.0000000512
        self.randNum = random.randint(0,2)


    def run(self):
        global Bus
        print ("开始线程:\t" + self.name)
        # print_time(self.name, self.counter, 5)

        while self.sendCounter < maxSend:
            sleep(0)
            if Bus == 0:
                Bus |= self.threadID
                sleep(0.001)

                #成功发送
                if Bus == self.threadID:
                    print(str(self.threadID) + '\tSend succeed')
                    self.collisionCounter = 16
                    sleep(random.randint(0,9)/10)
                    self.sendCounter += 1
                    Bus = 0
                    print('主机\t' + self.name + '\t发送成功次数 = ' + str(self.sendCounter))

                #冲突
                else:
                    print(str(self.threadID) + '\tSend collision')
                    Bus = 0
                    self.collisionCounter += 1
                    if self.collisionCounter < maxCollision:
                        sleepTime = random.randint(0, 1 << (10 if self.collisionCounter > 10 else self.collisionCounter)) * self.randNum * self.collisionWindow
                        sleep(sleepTime/1000)

                    else:
                        print(str(self.threadID) + '\tSend failure')
                        break

        print ("退出线程:\t" + self.name)


# 创建新线程
thread1 = myThread(1, "Host-A")
thread2 = myThread(2, "Host-B")
thread3 = myThread(3, "Host-C")

# 开启新线程
thread1.start()
thread2.start()
thread3.start()

thread1.join()
thread2.join()
thread3.join()
print ("退出主线程")