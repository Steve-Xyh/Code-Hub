//
//  main.cpp
//  D-complete bag
//  https://vjudge.net/contest/205708#problem/D
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:完全背包

#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
int add[200000],cost[10000],v[10000];
int n,money,d,years;

int maxprof()
{
    for(int i=1;i<=years;i++){
        n=money;
        n/=1000;
        memset(add,0,sizeof(add));
        for(int j=1;j<=d;j++){
            for(int k=cost[j];k<=n;k++){
                add[k]=max(add[k],add[k-cost[j]]+v[j]);
            }
        }
        money+=add[n];
    }
    return money;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>money>>years>>d;
        for(int i=1;i<=d;i++){
           cin>>cost[i]>>v[i];
            cost[i]/=1000;
        }
        cout<<maxprof()<<endl;
    }
    return 0;
}
