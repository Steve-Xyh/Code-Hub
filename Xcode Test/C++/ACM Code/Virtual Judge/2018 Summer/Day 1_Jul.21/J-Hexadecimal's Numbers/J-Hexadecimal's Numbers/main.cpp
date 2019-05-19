//  CodeForces-9C
//  main.cpp
//  J-Hexadecimal's Numbers
//  https://vjudge.net/contest/239961#problem/J
//  Created by Steve X on 2018/8/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:找出不大于于n最大的由0_1组成的数,并转为十进制

#include <iostream>
using namespace std;

int numto1_0(int n)             //找出不大于于n最大的由0_1组成的数
{
    int p=0,ans=0,num[10];
    while(n){                   //将n倒置存入数组
        num[p++]=n%10;
        n/=10;
    }
    int cnt=p;                  //cnt为数字位数
    while(p--){
        if(num[p]>1){           //若某位>1,将该位及其后续都置为1
            p++;
            while(p--)num[p]=1;
            break;
        }
    }
    for(int i=cnt-1;i>=0;i--)ans=ans*10+num[i];
    return ans;                 //将转换后的结果从数组中读取出来
}

int bintodec(int n)             //二进制转十进制
{
    int ans=0,r=0;
    n=numto1_0(n);
    while(n){
        ans+=n%10*(1<<r);
        r++;
        n/=10;
    }
    return ans;
}

int main()
{
    int n;
    while(cin>>n)cout<<bintodec(n)<<endl;
    return 0;
}
