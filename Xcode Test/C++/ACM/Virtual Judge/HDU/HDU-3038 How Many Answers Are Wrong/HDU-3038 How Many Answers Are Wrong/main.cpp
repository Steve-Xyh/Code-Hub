//  kuangbin S5-D
//  main.cpp
//  HDU-3038 How Many Answers Are Wrong
//  https://vjudge.net/contest/66964#problem/D
//  Created by Steve X on 2018/5/27.
//  Copyright © 2018年 Steve X. All rights reserved.
//  题解:https://www.cnblogs.com/liyinggang/p/5327055.html
//  思路:并查集Union-Find Sets 向量偏移

#include <iostream>
#include <cstdio>
#define N (int)(2e5+10)
using namespace std;

int ans;
int pre[N],sum[N];              //根节点,sum[i]=i与pre[i]的距离
int fin(int n)                  //查找根结点(条件运算符的递归写法)
{
    if(pre[n]==n)return n;
    sum[n]+=sum[pre[n]];
    return pre[n]=fin(pre[n]);
}

void init(int n)                //初始化
{
    ans=0;
    for(int i=0;i<=n;i++){
        pre[i]=i;
        sum[i]=0;
    }
}

void MrgNode(int a,int b,int s) //合并m,n
{
    int x=fin(a);
    int y=fin(b);
    if(x==y&&(sum[a]-sum[b]!=s))ans++;
    else{                       //a,b同根时a->b = a->x - b->y = a->x - b->x
        pre[x]=y;
        sum[x]=s+sum[b]-sum[a]; //a,b不同根x->y = b->y + a->b - a->x
    }
}

int main()
{
    int n,m,a,b,s;
    while(~scanf("%d%d",&n,&m)){
        init(n);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&s);
            MrgNode(a-1,b,s);
        }
        cout<<ans<<endl;
    }
    return 0;
}
