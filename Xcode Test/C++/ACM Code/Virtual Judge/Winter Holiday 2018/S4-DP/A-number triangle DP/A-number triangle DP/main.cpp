//
//  main.cpp
//  A-number triangle DP
//  https://vjudge.net/contest/205708#problem/A
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:自底向上dp

#include <iostream>
#include <cstring>
#define N 100
using namespace std;

int dp[N+1][N+1],a[N+1][N+1],ans;
int maxl(int n)
{
    for(int i=N;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]=a[i][j];
            if(i!=N)dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[1][1];
}

int main()
{
    int n;
    while(cin>>n){
        ans=0;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)cin>>a[i][j];
        }
        cout<<maxl(n)<<endl;
    }
    return 0;
}
