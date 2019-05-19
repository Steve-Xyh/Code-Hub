//
//  main.cpp
//  H-Ryuji doesn't want to study
//  https://www.jisuanke.com/contest/1557/105561
//  Created by Steve X on 2018/9/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:Segment Tree

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1e5+10;
int a[maxn];

struct seg{
    int l,r,sum1,sum2;
}tree[maxn<<2];

void build(int p,int l,int r)
{
    tree[p].l=l;
    tree[p].r=r;
    if(l==r){tree[p].sum2 = tree[p].sum1=a[l];return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p].sum1=tree[p<<1].sum1+tree[p<<1|1].sum1;
    tree[p].sum2=(r-l-(tree[p<<1].r-tree[p<<1].l))*tree[p<<1].sum1
                    +tree[p<<1].sum2+tree[p<<1|1].sum2;
}


void change(int p,int x,int y)
{
    if(tree[p].l==tree[p].r){tree[p].sum2=tree[p].sum1=y;return;}
    int mid=(tree[p].l+tree[p].r)>>1;
    if(x<=mid)change(p<<1,x,y);
    else change(p<<1|1,x,y);
    tree[p].sum1=tree[p<<1].sum1+tree[p<<1|1].sum1;
    tree[p].sum2=(tree[p].r-tree[p].l-(tree[p<<1].r-tree[p<<1].l))*tree[p<<1].sum1
                    +tree[p<<1].sum2+tree[p<<1|1].sum2;
}

long long ask(int p,int l,int r,int k)                            //****************//
{
    if(l==tree[p].l && r==tree[p].r)
        return (k-(r-l+1))*tree[p].sum1+tree[p].sum2;
    int mid=(tree[p].l+tree[p].r)>>1;
    if(r<=mid)return ask(p<<1,l,r,k);
    else if(l>mid)return ask(p<<1|1,l,r,k);
    else return ask(p<<1,l,mid,k)+ask(p<<1|1,mid+1,r,k-(mid-l+1));
}

int main()
{
    int n,q,cmd,x,y;
    cin>>n>>q;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    while(q--){
        scanf("%d%d%d",&cmd,&x,&y);
        int len=y-x+1;
        if(cmd==1){
            long long ans=ask(1,x,y,len);
            printf("%lld\n",ans);
        }
        else change(1,x,y);
    }
    return 0;
}
