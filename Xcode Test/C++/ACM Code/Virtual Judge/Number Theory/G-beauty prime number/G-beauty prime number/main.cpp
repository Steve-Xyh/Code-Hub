//
//  main.cpp
//  G-beauty prime number
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//
//区间内美素数个数:一个各位数字都是素数的素数称为美素数

#include <iostream>
#include <ctime>
#include <cstring>
#define N 100
#define maxn 1000000
#define Npr 100000
using namespace std;

bool isprime[maxn+1],isbp[maxn];                       //bool型素数表,美素数表
int primenum[Npr],beautipri[Npr],pcnt,bcnt;            //素数表，美素数表

bool getnum(int n)
{
    int b,sum=0;
    while(n>0){
        b=n%10;
        sum+=b;
        n/=10;
    }
    if(isprime[sum])return true;
    else return false;
}

void Euler()                                           //欧拉筛法+同时判断美素数
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=maxn;i++){
        if(isprime[i]){
            primenum[++pcnt]=i;
            if(getnum(i)){
                beautipri[bcnt++]=i;
                isbp[i]=true;
            }
        }
        for(int j=1;j<=pcnt && i*primenum[j]<=maxn;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0) break;                //最为关键的一句话
        }
    }
}

int bpsum(int a,int b)                                 //求区间内美素数个数
{
    int sum=0,i,j,k;
    for(i=a;i<=b;i++){                                 //找到第一个素数
        if(isprime[i])break;
    }
    if(isprime[i]){                                    //找到第一个素数下标
        for(j=0;j<pcnt;j++){
            if(primenum[j]==i)break;
        }
        for(;j<pcnt;j++){                              //找到第一个美素数
            if(isbp[primenum[j]])break;
        }
        if(isbp[primenum[j]]){                         //在美素数表里计数(逐级加速)
            for(k=0;beautipri[k]<=b;k++){
                if(beautipri[k]>=primenum[j])sum++;
            }
        }
    }
    return sum;
}

int main()
{
    Euler();
    int T,L,R;
    cin>>T;
    //T=1e4;
    for(int i=1;i<=T;i++){
        cin>>L>>R;
        //scanf("%d%d",&L,&R);
        //L=1,R=1e6;
        cout<<"Case #"<<i<<": "<<bpsum(L,R)<<endl;
        //printf("Case #%d: %d\n",i,bpsum(L,R));
    }
    
    /*for(int i=0;i<bcnt;i++){
        cout<<i<<":"<<beautipri[i]<<endl;
    }*/
    
    return 0;
}
