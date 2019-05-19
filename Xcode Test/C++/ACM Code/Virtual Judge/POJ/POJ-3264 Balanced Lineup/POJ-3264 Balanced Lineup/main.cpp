//  ##Segment Tree## ##ST## ##线段树## ##TLE,huge IO##
//  main.cpp
//  POJ-3264 Balanced Lineup
//  https://vjudge.net/contest/235902#problem/K
//  Created by Steve X on 2018/8/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:线段树维护区间最大最小值

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=5e5+10;
int a[N];

struct Seg{
    int l,r,max,min;
}tree[N<<2];

void build(int p,int l,int r)               //建树
{
    tree[p].l=l;tree[p].r=r;
    if(l==r){
        tree[p].max=tree[p].min=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p].max=max(tree[p<<1].max,tree[p<<1|1].max);
    tree[p].min=min(tree[p<<1].min,tree[p<<1|1].min);
}

int askmax(int p,int l,int r)               //询问区间[l,r]最大值
{
    if(l<=tree[p].l&&tree[p].r<=r)return tree[p].max;
    int mid=(tree[p].l+tree[p].r)>>1;       //不可写成mid=(l+r)>>1
    if(r<=mid)return askmax(p<<1,l,r);
    if(l>mid)return askmax(p<<1|1,l,r);
    return max(askmax(p<<1,l,mid),askmax(p<<1|1,mid+1,r));
}

int askmin(int p,int l,int r)               //询问区间[l,r]最小值
{
    if(l<=tree[p].l&&tree[p].r<=r)return tree[p].min;
    int mid=(tree[p].l+tree[p].r)>>1;       //不可写成mid=(l+r)>>1
    if(r<=mid)return askmin(p<<1,l,r);
    if(l>mid)return askmin(p<<1|1,l,r);
    return min(askmin(p<<1,l,mid),askmin(p<<1|1,mid+1,r));
}

int main()
{
    int n,m,x,y;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,1,n);
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            printf("%d\n",askmax(1,x,y)-askmin(1,x,y));
        }
    }
    return 0;
}
