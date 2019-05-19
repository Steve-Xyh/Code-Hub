//
//  main.cpp
//  A-01 Bag
//
//  Created by Steve X on 2018/10/12.
//  Copyright © 2018 Steve X. All rights reserved.
//
//  0-1背包问题
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 13000
using namespace std;

int dp[maxn],m[maxn],v[maxn];

int bag(int m[],int v[],int n,int c)
{
    int maxv=0;                                 //dp[j]表示占用不超过j体积物品的最大价值
    for(int i=0;i<n;i++){
        for(int j=c;j>=m[i];j--){
            dp[j]=max(dp[j-m[i]]+v[i],dp[j]);   //dp[j-m[i]]+v[i]表示放第i个物品,dp[j]表示不放
            maxv=max(maxv,dp[j]);               //求dp[j]的最大值
        }
    }
    return maxv;
}

int main()
{
    int n,c;                                    //物品种类数,背包容量,物品体积,物品价值
    while(cin>>n>>c&&(n||c)){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)cin>>m[i];
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<bag(m,v,n,c)<<endl;
    }
    return 0;
}
