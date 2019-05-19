//
//  main.cpp
//  E-greedy sort
//  https://vjudge.net/contest/205706#problem/E
//  Created by Steve X on 2018/2/22.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心,结构体sort

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 1010
using namespace std;

struct stuff
{
    int m,p;                                       //质量,价格,性价比
    double val;
};

bool cmp(stuff a,stuff b)
{
    return a.val>b.val;                            //性价比降序
}

int main()
{
    int v,n;
    stuff a[N];
    while(cin>>v>>n&&v!=-1&&n!=-1){
        double sum=0,vol=0,dv;
        memset(a,0,n);
        for(int i=0;i<n;i++){
            cin>>a[i].m>>a[i].p;
            a[i].val=1.0*a[i].m/a[i].p;            //性价比
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            dv=a[i].p<(v-vol)?a[i].p:v-vol;
            sum+=a[i].p>(v-vol)?a[i].val*dv:a[i].m;
            vol+=dv;
            if(vol==v)break;
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
