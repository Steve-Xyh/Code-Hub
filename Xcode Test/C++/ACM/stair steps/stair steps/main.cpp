//
//  main.cpp
//  stair steps
//
//  Created by Steve X on 2017/12/21.
//  Copyright © 2017年 Steve X. All rights reserved.
//
//走楼梯问题:一个人每次只能走1阶或2阶台阶,走到第n阶台阶一共有多少种不同方法?
#include <iostream>
#define N 92
using namespace std;
long long dp[N];                                //全局变量初值为0

long long steps(int n)                          //递归+记忆化搜索写法
{
    dp[1]=1;
    dp[2]=2;
    if(dp[n]!=0)return dp[n];
    return dp[n]=steps(n-1)+steps(n-2);
}

long long steps2(int n)                          //循环写法
{
    long long f[N];
    f[0]=0;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main()
{
    int n;
    while(cin>>n&&n!=0&&n<N){
        cout<<n<<"阶台阶有"<<steps(n)<<"种不同走法"<<endl;
    }
    return 0;
}
