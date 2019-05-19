//
//  main.cpp
//  POJ-1088 skiing dp
//  https://vjudge.net/problem/POJ-1088
//  Created by Steve X on 2018/2/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:dp,计算每个点四个方向可滑行的最大长度

#include <iostream>
#include <algorithm>
#define N 100
using namespace std;

int dp[N][N],a[N][N],R,C;
int callength(int x,int y)
{
    if(dp[x][y])return dp[x][y];
    dp[x][y]=1;
    if((x>=1)&&a[x-1][y]<a[x][y])dp[x][y]=max(dp[x][y],callength(x-1,y)+1);
    if((x<R-1)&&a[x+1][y]<a[x][y])dp[x][y]=max(dp[x][y],callength(x+1,y)+1);
    if((y>=1)&&a[x][y-1]<a[x][y])dp[x][y]=max(dp[x][y],callength(x,y-1)+1);
    if((y<C-1)&&a[x][y+1]<a[x][y])dp[x][y]=max(dp[x][y],callength(x,y+1)+1);
    return dp[x][y];
}

int calmaxl(int R,int C)
{
    int maxl=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)maxl=max(maxl,callength(i,j));
    }
    return maxl;
}

int main()
{
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cin>>a[i][j];
    }
    cout<<calmaxl(R,C)<<endl;
    return 0;
}
