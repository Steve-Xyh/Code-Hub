//
//  main.cpp
//  M-prime friend
//  https://vjudge.net/contest/205706#problem/M
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  输入a,b,寻找一个最小的素数s使得a+s和b+s为素数并且为相邻的素数

#include <iostream>
#include <cstring>
#define N 20000010
using namespace std;

bool isprime[N];
int primenum[N/10],cnt;
void Euler()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=N;i++){
        if(isprime[i]) primenum[++cnt]=i;
        for(int j=1;j<=cnt&&i*primenum[j]<=N;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0) break;
        }
    }
}

int main()
{
    int T,a,b,cntc=1;
    Euler();
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a>b){
            int t=a;
            a=b;
            b=t;
        }
        int tag=-1;
        for(int i=0;i<cnt-1;i++){
            if(primenum[i]>=a&&primenum[i+1]>=b){
                if((primenum[i]-a)==(primenum[i+1]-b)){
                    tag=primenum[i]-a;
                    break;
                }
            }
        }
        cout<<"Case "<<cntc<<": "<<tag<<endl;
        cntc++;
    }
    return 0;
}
