//
//  main.cpp
//  C-Valentine's Day
//
//  Created by Steve X on 2017/12/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstring>
#define N 100
#define maxn 500000
using namespace std;

bool isprime[maxn+1];
int primenum[maxn],pcnt;

void Euler()                                           //欧拉筛法
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=maxn;i++){
        if(isprime[i]) primenum[++pcnt]=i;
        for(int j=1;j<=pcnt && i*primenum[j]<=maxn;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0) break;                //最为关键的一句话
        }
    }
}

int getFactor(int n)         //素因子分解,求所有因子和
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
    //int p[N],a[N],s[N],cnt;
    Euler();
    cin>>T;
    
    /*T=5e5;
    clock_t start,finish;
    start=clock();*/
    
    while(T--){
        cin>>n;
        //n=5e5;
        cout<<getFactor(n)<<endl;
    }
    
    /*finish=clock();
    cout << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;*/
    
    return 0;
}

/*void getFactor(int n,int p[],int a[],int &cnt)         //素因子分解
{
    int now=n;
    for(int i=2;i<=n/i;i++){
        if(now%i==0){
            p[++cnt]=i;
            a[cnt]=0;
            while(now%i==0){
                a[cnt]++;
                now/=i;
            }
        }
    }
    if(now!=1){
        p[++cnt]=now;
        a[cnt]=1;
    }
}*/
