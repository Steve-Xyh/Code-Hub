//  [NWPU2018]组队训练赛第六场  ##DNF##
//  main.cpp
//  A-Chat Group
//  https://vjudge.net/contest/249510#problem/A
//  Created by Steve X on 2018/8/31.
//  Copyright © 2018年 Steve X. All rights reserved.
//  逆元打表,反向求解ans=2^n-tmp

#include <iostream>
#define LL long long
using namespace std;

const int p=1e9+7;
const int N=1e5+10;
LL inv[N];

void initInv()              //n%p乘法逆元打表
{
    inv[1]=1;
    for(int i=2;i<=N;i++)inv[i]=(p-p/i)*inv[p%i]%p;
}

LL pow_mod(LL a,LL x)       //快速幂
{
    if(x==0)return 1;
    LL tmp=pow_mod(a,x/2);
    tmp=tmp*tmp%p;
    if(x&1)tmp=tmp*a%p;
    return tmp;
}
/*
LL getComb(LL n,LL m)
{
    if(n<m)return 0;
    if(m>n-m)m=n-m;
    LL a=1,b=1;
    for(LL i=n;i>=n-m+1;i--)a=a*i%p;
    for(LL i=m;i>=1;i--)b=b*i%p;
    return a*inv[b%p]%p;
}

LL Lucas(LL n,LL m)         //Lucas定理求C[n][m]%p,(n<=1e18,p<=1e6)
{
    LL ans=1;
    while(n!=0&&m!=0){
        ans=ans*getComb(n%p,m%p);
        n/=p;m/=p;
    }
    return ans;
}*/
LL getComb(LL n,LL m)
{
    if(m>n-m)m=n-m;
    LL a=1,b=1;
    for(LL i=n;i>=n-m+1;i--)a*=i;
    for(LL i=m;i>=1;i--)b*=i;
    return a/b;
}

int main()
{
    int T,n,k,cnt=1;
    initInv();
    cin>>T;
    while(T--){
        cin>>n>>k;
        LL tmp=0,sum=pow_mod(2,n);
        for(int i=0;i<k;i++)tmp=(tmp+Lucas(n,i))%p;
        LL ans=(p+sum-tmp)%p;
        cout<<"Case #"<<cnt++<<": "<<ans<<endl;
    }
    return 0;
}
