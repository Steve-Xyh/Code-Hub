#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
自动填表
"""
from selenium import webdriver
from selenium.common.exceptions import *
from time import sleep

name = input('姓名:')
idNum = input('身份证:')
telNum = input('手机号:')

d = webdriver.Chrome()

def submitinfo(url):
    d.get(url)
    try:
        d.find_element_by_id('name').send_keys(name)
        d.find_element_by_id('sn').send_keys(idNum)
        d.find_element_by_id('tel').send_keys(telNum)
        d.find_element_by_class_name('g-btn').click()
    except NoSuchElementException:
        sleep(1)

while True:
    submitinfo('http://1.duotucms.com')
    submitinfo('http://2.duotucms.com')
    submitinfo('http://4.duotucms.com')
    submitinfo('http://5.duotucms.com')
    submitinfo('http://6.duotucms.com')
    submitinfo('http://7.duotucms.com')
    pass

d.close()
