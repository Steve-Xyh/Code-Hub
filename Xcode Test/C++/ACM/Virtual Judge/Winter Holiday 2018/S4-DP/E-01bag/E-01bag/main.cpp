//
//  main.cpp
//  E-01bag
//  https://vjudge.net/contest/205708#problem/E
//  Created by Steve X on 2018/2/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:01背包,dp,一维滚动数组

#include <iostream>
#include <algorithm>
#define maxn 13000
using namespace std;
int dp[maxn],m[maxn],v[maxn];

int bag(int m[],int v[],int N,int Vol)
{
    int maxv=0;                              //dp[j]表示占用不超过j体积物品的最大价值
    for(int i=0;i<N;i++){
        for(int j=Vol;j>=m[i];j--){
            dp[j]=max(dp[j-m[i]]+v[i],dp[j]);//dp[j-m[i]]+v[i]表示放第i个物品,dp[j]表示不放
            maxv=max(maxv,dp[j]);            //求dp[j]的最大值
        }
    }
    return maxv;
}

int main()
{
    int N,Vol;                               //物品种类数,背包容量,物品体积,物品价值
    cin>>N>>Vol;
    for(int i=0;i<N;i++)cin>>m[i]>>v[i];
    cout<<bag(m,v,N,Vol)<<endl;
    return 0;
}
