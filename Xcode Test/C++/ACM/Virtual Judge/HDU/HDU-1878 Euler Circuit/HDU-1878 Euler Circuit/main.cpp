//  HDU-1878 欧拉回路
//  main.cpp
//  HDU-1878 Euler Circuit
//
//  Created by Steve X on 2018/3/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//  并查集union-find sets
//  一个无向连通图存在欧拉回路,当且仅当该图所有顶点度数都为偶数
//  一个有向连通图存在欧拉回路,当且仅当所有顶点的入度等于出度

#include <iostream>
#define N 1000
using namespace std;

int deg[N+1];               //结点度数
int pre[N+1];               //pre[a]=b表示a的父结点是b
void InitialNode(int n)     //初始化n个结点
{
    for(int i=1;i<=n;i++){
        pre[i]=i;
        deg[i]=0;
    }
}

int fin(int i)              //递归查找根结点
{
    return pre[i]==i?i:pre[i]=fin(pre[i]);
}

void MergeNode(int a,int b) //合并,将a的根结点合并至b的根结点
{
    int x=fin(a),y=fin(b);
    pre[x]=y;
}

int cntset(int n)           //计算集合数量
{
    int sum=0;
    for(int i=1;i<=n;i++)if(fin(i)==i)sum++;
    return sum;
}

bool judge(int n)           //判断是否存在欧拉回路
{
    for(int i=1;i<=n;i++)if(deg[i]&1)return false;
    if(cntset(n)!=1)return false;
    return true;
}

int main()
{
    int n,m;
    while(cin>>n&&n){
        cin>>m;
        InitialNode(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            MergeNode(a,b);
            deg[a]++;
            deg[b]++;
        }
        cout<<judge(n)<<endl;
    }
    return 0;
}
