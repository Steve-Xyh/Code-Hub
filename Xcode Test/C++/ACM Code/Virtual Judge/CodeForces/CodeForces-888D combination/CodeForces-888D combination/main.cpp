//
//  main.cpp
//  CodeForces-888D combination
//
//  Created by Steve X on 2018/2/12.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:错排,组合数,求最多有k个元素不满足a[i]=i的数列个数
//  错排公式D(n)=(n-1)*[D(n-2)+D(n-1)],D(1)=0,D(2)=1.

#include <iostream>
#define N 1010
using namespace std;
long long comb[N][5];

void getComblist()             //求组合数表
{
    comb[1][0]=comb[1][1]=1;
    for(int i=2;i<N;i++){
        comb[i][0]=1;
        for(int j=1;j<=4;j++)comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}

long long cntlist(int n,int k)
{
    long long ans=0;
    if(k>=1)ans++;             //12<-->12,每组有1种可能
    if(k>=2)ans+=comb[n][2];   //12<-->21,每组有1种可能
    if(k>=3)ans+=comb[n][3]*2; //123<-->231/312,每组有2种可能
    if(k>=4)ans+=comb[n][4]*9; //n个中选4个进行错排,每组有9种可能
    return ans;
}

int main()
{
    int n,k;
    getComblist();
    while(cin>>n>>k)cout<<cntlist(n,k)<<endl;
    return 0;
}
