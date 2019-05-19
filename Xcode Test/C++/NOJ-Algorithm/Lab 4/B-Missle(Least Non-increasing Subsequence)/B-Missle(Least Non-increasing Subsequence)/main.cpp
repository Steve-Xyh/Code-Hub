//
//  main.cpp
//  B-Missle(Least Non-increasing Subsequence)
//
//  Created by Steve X on 2018/11/14.
//  Copyright © 2018 Steve X. All rights reserved.
//
//  防卫导弹
#include <iostream>
#include <algorithm>
using namespace std;

const int N=110;
int a[N],dp[N];         //dp[j]表示前j+1个元素(下标为0~j)的LNS

int LNS(int n)          //最长非上升子序列
{
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]>=a[i])dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    while((cin>>n)&&n){
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<LNS(n)<<endl;
    }
    return 0;
}
