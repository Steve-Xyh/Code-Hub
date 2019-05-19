//  HDU-1166 敌兵布阵 ##Segment Tree## ##ST## ##线段树## ##TLE,huge IO##
//  main.cpp
//  HDU-1166 Enemy Troop
//  https://vjudge.net/contest/235902#problem/I
//  Created by Steve X on 2018/8/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:线段树裸题

#include <iostream>
#include <cstdio>
using namespace std;

const int N=5e5+10;
int a[N],tree[N<<2];

void build(int p,int l,int r)               //建树
{
    if(l==r){tree[p]=a[l];return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p]=tree[p<<1]+tree[p<<1|1];
}

void add(int p,int l,int r,int x,int num)   //修改
{
    if(l==r){tree[p]+=num;return;}
    int mid=(l+r)>>1;
    if(x<=mid)add(p<<1,l,mid,x,num);
    else add(p<<1|1,mid+1,r,x,num);
    tree[p]=tree[p<<1]+tree[p<<1|1];
}

int ask(int p,int l,int r,int x,int y)      //查询
{
    if(l==x&&r==y)return tree[p];
    int mid=(l+r)>>1;
    if(y<=mid)return ask(p<<1,l,mid,x,y);
    if(x>mid)return ask(p<<1|1,mid+1,r,x,y);
    return ask(p<<1,l,mid,x,mid)+ask(p<<1|1,mid+1,r,mid+1,y);
}

int main()
{
    int T,cnt=1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",cnt++);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,1,n);
        char s[10];
        int x,y;
        while(~scanf("%s",s)&&s[0]!='E'){
            scanf("%d%d",&x,&y);
            if(s[0]=='A')add(1,1,n,x,y);
            else if(s[0]=='S')add(1,1,n,x,-y);
            else printf("%d\n",ask(1,1,n,x,y));
        }
    }
    return 0;
}
