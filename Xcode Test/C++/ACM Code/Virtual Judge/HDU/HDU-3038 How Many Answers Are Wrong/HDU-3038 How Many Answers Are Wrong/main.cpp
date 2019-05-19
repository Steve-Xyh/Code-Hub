//  kuangbin S5-D   ##坑题##
//  main.cpp
//  HDU-3038 How Many Answers Are Wrong
//  https://vjudge.net/contest/66964#problem/D
//  Created by Steve X on 2018/5/27.
//  Copyright © 2018年 Steve X. All rights reserved.
//  详细题解:https://www.cnblogs.com/liyinggang/p/5327055.html
//  思路:并查集Union-Find Sets 向量偏移

#include <cstdio>
const int N=2e5+10;

int ans;
int pre[N],sum[N];              //根节点,sum[i]=i与pre[i]的距离
int fin(int n)                  //查找根结点(条件运算符的递归写法)
{
    if(pre[n]==n)return n;
    int tmp=pre[n];             //**一定按此步骤写,否则会WA到死       **不要写成:
    pre[n]=fin(pre[n]);         //**先找根结点,然后再回溯计算sum      ** if(pre[n]==n)return n;
    sum[n]+=sum[tmp];           //**a->ra=a->fa+fa->ffa+...+*->ra ** sum[n]+=sum[pre[n]];
    return pre[n];              //**                              ** return pre[n]=fin(pre[n]);
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
        sum[x]=-sum[a]+sum[b]+s;//a,b不同根x->y = b->y + a->b - a->x
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
        printf("%d\n",ans);
    }
    return 0;
}
