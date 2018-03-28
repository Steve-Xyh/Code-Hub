//  HDU-1030
//  main.cpp
//  L-delta wave
//  https://vjudge.net/contest/205705#problem/L
//  Created by Steve X on 2018/2/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:类似坐标相减,3边,3个移动方向,找规律计算3个维度

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int caldistance(int a,int b)
{
    int rowa,rowb,la,lb,ra,rb,dis;           //行,左斜列,右斜列
    rowa=ceil(sqrt(a));
    rowb=ceil(sqrt(b));
    la=ceil((a-(rowa-1)*(rowa-1))/2.0);
    lb=ceil((b-(rowb-1)*(rowb-1))/2.0);
    ra=ceil((rowa*rowa-a+1)/2.0);
    rb=ceil((rowb*rowb-b+1)/2.0);
    dis=abs(rowa-rowb)+abs(la-lb)+abs(ra-rb);
    return dis;
}

int main()
{
    int m,n;
    while(cin>>m>>n){                        //巨坑题目,一定要多组数据！！
        cout<<caldistance(m,n)<<endl;
    }
    return 0;
}
