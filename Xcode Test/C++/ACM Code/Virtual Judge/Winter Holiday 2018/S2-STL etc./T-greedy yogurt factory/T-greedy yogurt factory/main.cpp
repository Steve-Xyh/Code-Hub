//
//  main.cpp
//  T-greedy yogurt factory
//  https://vjudge.net/contest/205706#problem/T
//  Created by Steve X on 2018/2/24.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心,对于每周,判断产和存哪个成本低

#include <iostream>
#include <algorithm>
#define N 10010
using namespace std;

int c[N],y[N];

long long cost(int n,int s)
{
    long long sum=0;
    for(int i=0;i<n;i++)
        sum+=y[i]*(i==0?c[i]:min(c[i],c[i-1]+s));//对于每周,判断产和存哪个成本低
    return sum;
}

int main()
{
    int n,s;
    while(cin>>n>>s){
        for(int i=0;i<n;i++)cin>>c[i]>>y[i];
        cout<<cost(n,s)<<endl;
    }
    return 0;
}
