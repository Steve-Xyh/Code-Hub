//  装载问题
//  main.cpp
//  B-Boat Load
//
//  Created by Steve X on 2018/10/12.
//  Copyright © 2018 Steve X. All rights reserved.
//  思路:0-1背包求第一艘船最多载重,判断第二艘能否装其余货物

#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1010;
int dp[maxn],m[maxn];

int bag(int n,int c)
{
    memset(dp,0,sizeof(dp));
    int maxv=0;                                 //dp[j]表示占用不超过j体积物品的最大价值
    for(int i=0;i<n;i++){
        for(int j=c;j>=m[i];j--){
            dp[j]=max(dp[j-m[i]]+m[i],dp[j]);   //dp[j-m[i]]+v[i]表示放第i个物品,dp[j]表示不放
            maxv=max(maxv,dp[j]);               //求dp[j]的最大值
        }
    }
    return maxv;
}

void solve(int c1,int c2,int n,int sum)
{
    int max1=bag(n,c1);
    if(sum-max1<=c2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    int c1,c2,n;
    while(cin>>c1>>c2>>n&&(c1||c2||n)){
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>m[i];
            sum+=m[i];
        }
        solve(c1,c2,n,sum);
    }
    return 0;
}
