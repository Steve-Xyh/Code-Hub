# -*- coding:utf-8 -*-
 
import os
import sys
from struct import *
 
#intel-hex 格式
#:LLAAAARRDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDZZ
#LL——长度,单位，byte
#AAAA——16 bit 地址
#RR——类型
# - 00 数据记录 (data record)
# - 01 结束记录 (end record)
# - 02 扩展段地址记录 (paragraph record)
# - 03 转移地址记录 (transfer address record)
# - 04 扩展线性地址记录 (expand address record)
#DD——16byte数据
#ZZ——校验
 
last_size = 0
last_addr = 0
cur_size  = 0
cur_addr  = 0
high_addr = 0
expand_f  = 0
 
#hex to bin
def hex_bin(hexfile,binfile):
  #declare global var
  global last_size
  global last_addr
  global cur_size
  global cur_addr
  global high_addr
  global expand_f
  fin = open(hexfile)
  fout = open(binfile,'wb')
  result =''
  #read every lines
  for hexstr in fin.readlines():
    #去空格\n\r\t
    # print hexstr
    hexstr = hexstr.strip()
    size = int(hexstr[1:3],16)
    #RR是数据
    if int(hexstr[7:9],16) == 0:
      #expand addr deal
      if expand_f == 1:
        cur_addr = int(hexstr[3:7],16)
        #data skipped
        need_wr_size = high_addr+cur_addr-(last_addr+last_size)
        if need_wr_size != 0:
          if need_wr_size > 1000:
            print ("skipped data too large !!!")
          else:
            result=''
            for dr in range(0,need_wr_size):
              #empty space write 0xff
              b = int("0xff",16)
              result = pack('B',b)
              fout.write(result)        
          #end else  
        expand_f = 0
      last_size = size
      last_addr = int(hexstr[3:7],16)
 
      for h in range(0, size):
        b = int(hexstr[(9+h*2):(9+h*2+2)],16)
        result += pack('B',b)
      #end if
      fout.write(result)
      result=''
    #RR是结束
    elif int(hexstr[7:9],16) == 1:
      end_f = 1
    #RR是扩展地址
    elif int(hexstr[7:9],16) == 4:
      high_addr = int(hexstr[9:13],16)
      if high_addr:
        expand_f = 1
      # print hexstr,hex(high_addr),expand_f
    #end if    
  #end for
  fin.close()
  fout.close()
 
# bin to hex
def bin_hex(binfile,hexfile):
  fbin = open(binfile,'rb')
  fhex = open(hexfile,'w')
  offset = 0
  seg_addr = 0
  while 1:
    checksum=0 
    result = ':'
    bindata = fbin.read(0x10)
    if len(bindata) == 0 :
      break
    #end if
    result += '%02X' % len(bindata)
    result += '%04X' % offset
    result += '00'
    checksum = len(bindata)
    checksum += (offset & 0xff) + (offset >> 8)
 
    for i in range(0,len(bindata)):
      byte = unpack('B',bindata[i])
      result+='%02X' % byte
      checksum += byte[0]
    #end for    
    checksum = 0x01 + ~checksum
    checksum = checksum & 0xff
    result += '%02X\n' % checksum 
    fhex.write(result)
    offset += len(bindata)
    if offset == 0x10000:
      offset = 0            
      seg_addr += 1
      result = ':02000004'
      result += '%02X%02X' % ((seg_addr>>8) & 0xff,seg_addr & 0xff)
      checksum = 0x02 + 0x04 + (seg_addr>>8) + seg_addr & 0xff            
      checksum = -checksum
      result+='%02X' % (checksum & 0xff)
      result += '\n'
      fhex.write(result)
    #end if    
    if len(bindata) < 0x10:
      break
    #end if    
  #end while    
  fhex.write(':00000001FF')
  fbin.close()
  fhex.close()
#end for
 
if len(sys.argv) != 4 or (sys.argv[1] != '-h' and sys.argv[1] != '-b'):
  print 'usage:'
  print 'convert binary format to hexadecimal format: '
  print ' hexbin.py -h binfile hexfile'
  print 'convert hexadecimal format to binary format:'
  print ' hexbin.py -b hexfile binfile'
  exit(0)
 
if sys.argv[1] == '-h':
  bin_hex(sys.argv[2],sys.argv[3])
else:
  hex_bin(sys.argv[2],sys.argv[3])



