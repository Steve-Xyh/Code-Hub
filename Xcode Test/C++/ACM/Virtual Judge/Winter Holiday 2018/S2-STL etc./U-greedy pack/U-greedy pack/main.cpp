//
//  main.cpp
//  U-greedy pack
//  https://vjudge.net/contest/205706#problem/U
//  Created by Steve X on 2018/2/24.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心

#include <iostream>
#include <algorithm>
#define N 100010
using namespace std;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

int minbox(int n,int vol)
{
    int p=0,q=n-1,cnt=0;
    sort(a,a+n,cmp);
    for(p=0;p<=q;p++){
        if(a[p]+a[q]<=vol)q--; //体积降序,每次选最大和最小装在一起,若2个体积超量则将最大的单独装箱
        cnt++;
    }
    return cnt;
}

int main()
{
    int n,vol;
    while(cin>>n>>vol){
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<minbox(n,vol)<<endl;
    }
    return 0;
}
