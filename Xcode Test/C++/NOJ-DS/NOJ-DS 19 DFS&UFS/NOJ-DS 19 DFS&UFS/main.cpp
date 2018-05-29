//  基于图的深度优先搜索策略(耿7.10) ##special##
//  main.cpp
//  NOJ-DS 19 DFS&UFS
//
//  Created by Steve X on 2018/5/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集

#include <iostream>
const int N=1000;
using namespace std;

int pre[N];
int fin(int n)                  //查找根结点
{
    return pre[n]==n?n:pre[n]=fin(pre[n]);
}

void init(int n)                //初始化
{
    for(int i=0;i<n;i++)pre[i]=i;
}

void MrgNode(int a,int b)       //合并m,n
{
    int x=fin(a);
    int y=fin(b);
    pre[x]=y;
}

int main()
{
    int n,m,a,b,c,d;
    init(N);
    cin>>n>>m;
    cin>>a>>b>>c>>d;
    while(m--){
        cin>>a>>b;
        MrgNode(a,b);
    }
    cin>>a>>b;
    if(fin(a)==fin(b))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
