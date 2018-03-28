//
//  main.cpp
//  Z-bitset
//  https://vjudge.net/contest/205706#problem/Z
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:水题,打表

#include <iostream>
#define N 1010
using namespace std;

long long b[N];
void binarylist()                          //b[i]为i的二进制形式,打表
{
    b[0]=0;
    b[1]=1;
    for(int i=2;i<N;i++)b[i]=10*b[i/2]+i%2;
}

int main()
{
    binarylist();
    int n;
    while(cin>>n)cout<<b[n]<<endl;
    return 0;
}
