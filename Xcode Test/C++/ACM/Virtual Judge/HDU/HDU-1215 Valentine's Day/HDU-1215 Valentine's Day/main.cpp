//
//  main.cpp
//  HDU-1215 Valentine's Day
//
//  Created by Steve X on 2018/2/16.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:素因子分解

#include <iostream>
#include <cstring>
#define N 100
#define maxn 500000
using namespace std;

bool isprime[maxn+1];
int primenum[maxn],pcnt;

void Euler()                                  //欧拉筛法
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=maxn;i++){
        if(isprime[i]) primenum[++pcnt]=i;
        for(int j=1;j<=pcnt && i*primenum[j]<=maxn;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0) break;
        }
    }
}

int getFactor(int n)                          //素因子分解,求所有因子和
{
    int now=n,sum=1;
    for(int i=1;primenum[i]<=now;i++){
        if(now%primenum[i]==0){
            int temp=1,pi=primenum[i];
            while(now%primenum[i]==0){
                now/=primenum[i];
                temp+=pi;
                pi*=primenum[i];
            }
            sum*=temp;
        }
        if(now==1)break;
    }
    return sum-n;
}

int main()
{
    int T,n;
    Euler();
    cin>>T;
    while(T--){
        cin>>n;
        cout<<getFactor(n)<<endl;
    }
    return 0;
}
