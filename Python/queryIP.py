#!/usr/bin/env python3
import requests
import json
import sys
from IPy import IP

def formatDic(dic):
    try:
        print(dic['message'])
        exit(1)
    except KeyError:
        pass
    result = '-' * 79 + '\n'
    for inf in info:
        result += format(inf, '<20')
        try:
            result += format(dic[inf.lower()])
        except KeyError:
            result += '-'
        result += '\n'
    print(result)


def genResult(ip):
    try:
        formatDic(json.loads(requests.get(base_url + ip).text))
    except KeyboardInterrupt:
        exit(0)


base_url = 'https://api.ip.sb/geoip/'
info = [
    "ip",
    "country",
    "city",
    "region",
    "region_code",
    "postal_code",
    "continent_code",
    "latitude",
    "longitude",
    "dma_code",
    "area_code",
    "organization",
    "timezone",
    "offset",
]

try:
    ip = sys.argv[1]
except IndexError:
    genResult('')
    exit(0)

try:
    ip = IP(sys.argv[1])
except ValueError:
    pass

for i in ip:
    genResult(str(i))

print('-' * 79)