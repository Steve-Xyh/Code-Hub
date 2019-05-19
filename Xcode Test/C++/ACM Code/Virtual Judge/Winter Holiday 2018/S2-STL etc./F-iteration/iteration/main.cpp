//
//  main.cpp
//  iteration
//  https://vjudge.net/contest/205706#problem/F
//  Created by Steve X on 2018/2/22.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:第n条增加2*2(n-1)个交点,增加4(n-1)+1个部分,f(1)=2,f(n)=f(n-1)+4*(n-1)+1,n>=2

#include <iostream>
#define N 10010
using namespace std;

long long dp[N];
long long cal(long long n)
{
    dp[1]=2;
    if(dp[n])return dp[n];
    else return dp[n]=cal(n-1)+4*(n-1)+1;
}

int main()
{
    int T;
    long long n;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<cal(n)<<endl;
    }
    return 0;
}
