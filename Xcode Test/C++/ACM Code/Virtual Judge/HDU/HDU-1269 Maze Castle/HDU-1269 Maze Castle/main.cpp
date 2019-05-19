//  强连通图 Strongly Connected Graph ##DNF##
//  main.cpp
//  HDU-1269 Maze Castle
//  https://vjudge.net/problem/HDU-1269
//  Created by Steve X on 2018/6/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:Two-direction Union-Find Sets

#include <iostream>
#include <algorithm>
using namespace std;

const int N=1e4+10;

int pre[2][N],cir=0;

void init(int n)
{
    for(int k=0;k<2;k++)for(int i=1;i<=n;i++)pre[k][i]=i;          //Nodes are numbered from 1 to n
}

int fin(int n,int k)
{
    return pre[k][n]==n?n:pre[k][n]=fin(pre[k][n],k);
}

void MrgNode(int x,int y)
{
    if(x<y){
        int rootx=fin(x,0),rooty=fin(y,0);
        if(rootx!=rooty)pre[0][min(rootx,rooty)]=max(rootx,rooty);
    }else{
        int rootx=fin(x,1),rooty=fin(y,1);
        if(rootx!=rooty)pre[1][max(rootx,rooty)]=min(rootx,rooty);
    }
}

bool judge(int n,int k)                           //Count the number of sets
{
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(pre[k][i]==i)cnt++;
        if(cnt>1)return false;
    }
    return true;
}

void solve(int n,int m)
{
    int u,v;
    init(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        MrgNode(u,v);
    }
    if(judge(n,0)&&judge(n,1))printf("Yes\n");
    else printf("No\n");
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n||m))solve(n,m);
    return 0;
}
