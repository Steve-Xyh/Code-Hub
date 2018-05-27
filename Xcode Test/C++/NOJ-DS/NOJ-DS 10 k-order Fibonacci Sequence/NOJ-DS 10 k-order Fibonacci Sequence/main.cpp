//  k阶斐波那契数列(严3.32)
//  main.cpp
//  NOJ-DS 10 k-order Fibonacci Sequence
//
//  Created by Steve X on 2018/4/18.
//  Copyright © 2018年 Steve X. All rights reserved.
//  ①:f(m)=f(m-1)+f(m-2)+…+f(m-k)
//  ②:f(m-1)=f(m-2)+f(m-3)+…+f(m-k-1)
//  ①-②:f(m)-f(m-1)=f(m-1)-f(m-k-1)
//  f(m)=2f(m-1)-f(m-k-1)


#include <iostream>
#define N 1000
using namespace std;

int f[N];
void CreateKFibo(int maxn,int k)
{
    int n;
    for(int i=0;i<k-1;i++)f[i]=0;                   //前k-2项为0,f[k-1]=f[k]=1
    f[k-1]=f[k]=1;
    for(n=k+1;(f[n]=2*f[n-1]-f[n-k-1])<=maxn;n++);
    n--;
    for(int i=n-k+1;i<=n;i++)cout<<f[i]<<" ";
    cout<<endl;
}

int main()
{
    int maxn,k;
    cin>>maxn>>k;
    CreateKFibo(maxn,k);
    return 0;
}
