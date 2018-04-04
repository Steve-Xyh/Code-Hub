//  POJ-1182 食物链
//  main.cpp
//  POJ-1182 food chain
//  https://vjudge.net/contest/217087#problem/E
//  Created by Steve X on 2018/3/29.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集Union-Find Sets

#include <iostream>
#define MaxN 50010
using namespace std;

int N,K;

int deg[MaxN+1];               //结点度数
int pre[MaxN+1];               //pre[a]=b表示a的父结点是b
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



int main()
{
    
    
    return 0;
}

