#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
自动填表
"""
import datetime

from selenium import webdriver
from selenium.common.exceptions import *
from time import sleep


name = input('姓名:')
idNum = input('身份证:')
telNum = input('手机号:')
'''
setTime = datetime.datetime(2019,9,8,23,39,30,0)
endTime = datetime.datetime(2019,9,8,23,40,30,0)
'''
def submitinfo(url):
    d.get(url)
    try:
        d.find_element_by_id('name').send_keys(name)
        d.find_element_by_id('sn').send_keys(idNum)
        d.find_element_by_id('tel').send_keys(telNum)
        d.find_element_by_class_name('g-btn').click()
        print('Submit successfully on ' + url)
    except NoSuchElementException:
        #sleep(1)
        pass


def autoSubmit():    
    while True:
        submitinfo('http://1.duotucms.com')
        submitinfo('http://2.duotucms.com')
        submitinfo('http://4.duotucms.com')
        submitinfo('http://5.duotucms.com')
        submitinfo('http://6.duotucms.com')
        submitinfo('http://7.duotucms.com')


if __name__ == '__main__':
    while True:
        #currentTime = datetime.datetime.now()
        #if currentTime >= setTime:
        opt = webdriver.ChromeOptions()
        opt.add_argument('--headless')
        #d = webdriver.Chrome(options=opt)
        d = webdriver.Chrome()
        autoSubmit()
        #else:
        print(setTime - currentTime)
        sleep(1)
        #if currentTime >= endTime:
        #    break
    d.close()
