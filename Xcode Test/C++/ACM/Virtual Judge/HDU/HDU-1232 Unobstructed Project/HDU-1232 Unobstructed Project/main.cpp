//  浙大计算机研究生复试上机考试-2005年  畅通工程
//  main.cpp
//  HDU-1232 Unobstructed Project
//  https://vjudge.net/problem/HDU-1232
//  Created by Steve X on 2018/6/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:Union-Find Sets,the ans is cntSet()-1

#include <iostream>
using namespace std;

const int N=1e4+10;

int pre[N];

void init(int n)
{
    for(int i=1;i<=n;i++)pre[i]=i;          //Nodes are numbered from 1 to n
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
    for(int i=1;i<=n;i++)if(pre[i]==i)cnt++;
    return cnt;
}

void solve(int n,int m)
{
    int u,v;
    init(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        MrgNode(u,v);
    }
    printf("%d\n",cntSet(n)-1);
}

int main()
{
    int n,m;
    while(~scanf("%d",&n)&&n&&~scanf("%d",&m))solve(n,m);
    return 0;
}
