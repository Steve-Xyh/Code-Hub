//  HDU-5969
//  main.cpp
//  F-bit or
//
//  Created by Steve X on 2018/1/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:找出按位或的特点,根据区间左右边界值即可得出最大的位或值

#include <iostream>
using namespace std;

int bidigit(long long n)                   //计算二进制位数
{
    int cnt=0;
    while(n){
        cnt++;
        n/=2;
    }
    return cnt;
}

long long common(long long n,long long m)  //按位异或,保留共同前缀,其余位清零
{
    long long ans=n>m?n:m;
    int t=bidigit(n^m);
    for(int i=0;i<t;i++)ans/=2;
    for(int i=0;i<t;i++)ans*=2;
    return ans;
}

long long power(long long a,long long n)
{
    long long ans=1;
    while(n--)ans*=a;
    return ans;
}

int main()
{
    int T;
    long long l,r,ans=0;
    cin>>T;
    while(T--){
        cin>>l>>r;
        if(l==r)ans=r;
        else if(bidigit(l)<bidigit(r))ans=power(2,bidigit(r))-1;
        else if(bidigit(l)==bidigit(r))ans=common(l,r)+power(2,bidigit(l^r))-1;
        cout<<ans<<endl;
    }
    return 0;
}
