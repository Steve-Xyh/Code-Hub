//
//  main.cpp
//  K-factorial digit
//  https://vjudge.net/contest/205706#problem/K
//  Created by Steve X on 2018/2/22.
//  Copyright © 2018年 Steve X. All rights reserved.
//  n!的位数digit(n)=(int)lg(n)+1,digit(n!)=1+(int)lg(n*(n-1)*...*2*1)
//  digit(n!)=1+(int)(lg(n)+lg(n-1)...+lg(1))

#include <iostream>
#include <cmath>
using namespace std;

int digit(int n)                       //计算n!的位数
{
    double tmp=0;
    for(int i=1;i<=n;i++)tmp+=log10(i);
    return 1+(int)tmp;
}

int main()
{
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<digit(n)<<endl;
    }
    return 0;
}
