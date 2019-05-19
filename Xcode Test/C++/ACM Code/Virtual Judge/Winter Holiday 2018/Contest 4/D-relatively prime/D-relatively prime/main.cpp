//  LightOJ-1370
//  main.cpp
//  D-relatively prime
//
//  Created by Steve X on 2018/1/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:欧拉函数F(p)=p-1,给定F找出使得F(n)>=F的最小n值,即从F+1开始找最小的素数p

#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000011
using namespace std;

//*****//Euler筛法
bool isprime[N];
int primenum[N],cnt;
void Euler()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=N;i++){
        if(isprime[i]) primenum[++cnt]=i;
        for(int j=1;j<=cnt && i*primenum[j]<=N;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0) break;
        }
    }
}

int money(int n)                 //找比n大的最小素数
{
    int i=n+1;
    while(isprime[i]!=true)i++;
    return i;
}

int main()
{
    int T,n,x,c=1;
    Euler();
    scanf("%d",&T);
    while(T--){
        long long m=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            m+=money(x);
        }
        printf("Case %d: %lld Xukha\n",c++,m);
    }
    return 0;
}
