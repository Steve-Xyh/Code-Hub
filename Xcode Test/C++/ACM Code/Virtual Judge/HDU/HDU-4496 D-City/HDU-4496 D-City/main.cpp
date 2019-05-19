//  2013 ACM-ICPC 吉林通化全国邀请赛 #TLE,huge IO#
//  main.cpp
//  HDU-4496 D-City
//  https://vjudge.net/problem/HDU-4496
//  Created by Steve X on 2018/6/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:Union-Find Sets,reversely process,rebuild edges
//  iostream results in TLE,and DO NOT use cntSet() every time

#include <iostream>
using namespace std;

const int N=1e4+10;
const int M=1e5+10;

int pre[N],ans[M];

struct Edge{
    int u,v;                                //Two vertices of an edge
}e[M];

void init(int n)
{
    for(int i=0;i<n;i++)pre[i]=i;
}

int fin(int n)
{
    return pre[n]==n?n:pre[n]=fin(pre[n]);
}

void MrgNode(int x,int y)
{
    int rootx=fin(x),rooty=fin(y);
    if(rootx!=rooty)pre[rootx]=rooty;
}

int cntSet(int n)                           //Count the number of sets
{
    int cnt=0;
    for(int i=0;i<n;i++)if(pre[i]==i)cnt++;
    return cnt;
}

void solve(int n,int m)
{
    init(n);
    int cnt=cntSet(n);
    for(int i=0;i<m;i++)scanf("%d%d",&e[i].u,&e[i].v);
    for(int i=m-1;i>=0;i--){
        ans[i]=cnt;                         //Store ans reversely
        if(fin(e[i].u)!=fin(e[i].v))cnt--;  //None-Circuit edges reduce the number of sets
        MrgNode(e[i].u,e[i].v);             //Rebuild edges
    }
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))solve(n,m);
    return 0;
}
