//  NOIP 2001 普及组T4 雨神的视频
//  main.cpp
//  Box(lite 01bag)
//  http://blog.csdn.net/u012577123/article/details/39206877
//  Created by Steve X on 2018/2/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:简化版01背包,dp

#include <iostream>
#include <algorithm>
#define N 20000
using namespace std;

bool dp[N];                          //dp[j]表示能否组成体积j
int calvolume(int n,int vol,int v[])
{
    int maxv=0;
    dp[0]=1;
    for(int i=0;i<n;i++){            //就地滚动
        for(int j=vol;j>=v[i];j--){
            if(dp[j-v[i]]){          //第i个物品不放,则可构成体积j-v[i]
                dp[j]=1;             //第i个物品放,则可构成体积j
                maxv=max(maxv,j);    //找出使得dp[j]为1的最大j值
            }
        }
    }
    return vol-maxv;
}

int main()
{
    int n,vol,v[30];
    cin>>vol>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<calvolume(n,vol,v)<<endl;
    return 0;
}
