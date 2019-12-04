import requests
import time
import json
import sys
import getpass


def get_cookies():
    """获得cookies"""
    # url = 'https://uis.nwpu.edu.cn/cas/login'
    url = 'http://202.117.88.170/loginall.aspx'
    s = requests.session()
    # print(s.post((url)).text)
    s.get(url)


    cookie_dict = requests.utils.dict_from_cookiejar(
        s.cookies)   # 将jar格式转化为dict
    cookie = 'JSESSIONID=' + cookie_dict['JSESSIONID']         # 重组cookies
    return cookie


def Login(name, passwd, cookies):
    url = 'https://uis.nwpu.edu.cn/cas/login?service=http://202.117.88.170'
    head = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'zh-CN,zh;q=0.9',
        'Cache-Control': 'max-age=0',
        'Connection': 'keep-alive',
        'Content-Length': '134',
        'Content-Type': 'application/x-www-form-urlencoded',
        'Cookie': cookies,
        'Host': '202.117.88.170',
        # 'Origin': 'https://uis.nwpu.edu.cn',
        # 'Referer': 'https://uis.nwpu.edu.cn/cas/login?service=http://202.117.88.170/loginall.aspx',
        'Sec-Fetch-Mode': 'navigate',
        'Sec-Fetch-Site': 'same-origin',
        'Sec-Fetch-User': '?1',
        'Upgrade-Insecure-Requests': '1',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.97 Safari/537.36',
    }
    param = {'username': name, 'password': passwd}
    post_txt = requests.post(url, headers=head, data=json.dumps(param))
    res = requests.get(url, headers=head, data=json.dumps(param))
    # return res.text
    return post_txt.url


def Res(cookies):
    url = 'http://202.117.88.170/ClientWeb/pro/ajax/reserve.aspx'
    head = {
        'Accept': 'application/json, text/javascript, */*; q=0.01',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'zh-CN,zh;q=0.9',
        'Connection': 'keep-alive',
        'Cookie': cookies,
        'Host': '202.117.88.170',
        # 'Referer': 'http://202.117.88.170/ClientWeb/xcus/ic2/Default.aspx',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.97 Safari/537.36',
        'X-Requested-With': 'XMLHttpRequest'
    }

    param = {
        'dialogid': '',
        'dev_id': '857229',
        'lab_id': '857069',
        'kind_id': '959784',
        'room_id': '',
        'type': 'dev',
        'prop': '',
        'test_id': '',
        'term': '',
        'number': '',
        'classkind': '',
        'test_name': 'hhhhhh',
        'min_user': '2',
        'max_user': '8',
        'mb_list': '2017302341%2C2018302987',
        'start': '2019-11-29+13%3A00',
        'end': '2019-11-29+14%3A00',
        'start_time': '1300',
        'end_time': '1400',
        'up_file': '',
        'memo': '',
        'act': 'set_resv',
        # '_': '1574858425406'
    }

    # print(param)
    res = requests.post(url, data=json.dumps(param), headers=head)
    # return res.url
    return 'reservation'


if __name__ == '__main__':
    name = str(input('学号:'))
    passwd = str(getpass.getpass('密码:'))
    cookie = get_cookies()

    print(cookie)
    print(Login(name, passwd, cookie))
    print(Res(cookie))
