//
//  main.cpp
//  HDU-2111 bag W
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//
//0-1背包问题
#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100
using namespace std;

struct stuff
{
    int p,m;
    bool operator < (const stuff &a) const
    {
        return p!=a.p ? p>a.p : m>a.m;
    }
};

int main()
{
    int v,n;
    stuff a[N];
    while(cin>>v&&v!=0&&cin>>n){
        int sum=0,vol=0,dv;
        memset(a,0,N);
        for(int i=0;i<n;i++){
            cin>>a[i].p>>a[i].m;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            dv=a[i].m<(v-vol)?a[i].m:v-vol;
            sum+=a[i].p*dv;
            vol+=dv;
            if(vol==v)break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
