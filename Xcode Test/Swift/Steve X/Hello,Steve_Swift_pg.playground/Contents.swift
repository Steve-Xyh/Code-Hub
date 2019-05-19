//: Playground - noun: a place where people can play

import Cocoa

var str = "Hello, playground"
var str2 = "Hello, Steve"

var cnt=0
cnt+=1
for _ in 1...10{
    cnt+=1
}
cnt

var a=0,b=1
var fibo=a+b
for _ in 1...10{
    print(fibo)
    a=b
    b=fibo
    fibo=a+b
}
print(fibo)
