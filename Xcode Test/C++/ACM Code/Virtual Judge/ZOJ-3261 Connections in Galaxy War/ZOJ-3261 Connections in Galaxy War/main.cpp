//  ZOJ-3261 Connections in Galaxy War  #TOP##TLE,huge IO#
//  main.cpp
//  ZOJ-3261 Connections in Galaxy War
//  https://vjudge.net/contest/66964#problem/L
//  Created by Steve X on 2018/6/2.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集Union-Find Sets,逆向并查集,从反向读取操作,反向存储答案
//  #**#iostream results in Time Limit Exceeded!!!#**#

#include <cstdio>
#include <algorithm>
#include <map>
const int N=1e4+10;
const int Hash=1e4;
using namespace std;

int pre[N],pwr[N],tag=0;            //Array of parent node and power value

struct Edge{
    int u,v;                        //The start and end point of a edge
}e[2*N];
map<int,bool>mmp;

struct Oprt{
    char str[10];                   //Whether "query" or "destroy"
    int a,b;                        //Two nodes of an operation
}op[5*N];

void InitialNode(int n)             //Initialize n nodes
{
    for(int i=0;i<n;i++){
        pre[i]=i;
        scanf("%d",&pwr[i]);
    }
}

int fin(int i)
{
    return pre[i]==i?i:pre[i]=fin(pre[i]);
}

void MrgNode(int x,int y)           //Find the most powerful rescue star with the smallest number
{                                   //Store rescue star as its parent node
    int rootx=fin(x),rooty=fin(y);
    if(rootx!=rooty){
        if(pwr[rootx]!=pwr[rooty]){
            if(pwr[rootx]>pwr[rooty])pre[rooty]=rootx;
            else pre[rootx]=rooty;
        }else pre[max(rootx,rooty)]=min(rootx,rooty);
    }
}

void InitInput(int n,int &m,int &q) //Pre-process the input info
{
    InitialNode(n);
    mmp.clear();
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&e[i].u,&e[i].v);
        if(e[i].u>e[i].v)swap(e[i].u,e[i].v);
    }                               //Limit the order of 2 nodes
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%s%d",op[i].str,&op[i].a);
        if(op[i].str[0]=='d'){
            scanf("%d",&op[i].b);
            if(op[i].a>op[i].b)swap(op[i].a,op[i].b);
            mmp[op[i].a*Hash+op[i].b]=true;
        }                           //Hash method:store u->v as a unique integer "Hash*u+v"
    }
}

void Build(int m)                   //Build tunnels which have not been destroyed
{
    for(int i=0;i<m;i++)if(!mmp[e[i].u*Hash+e[i].v])MrgNode(e[i].u,e[i].v);
}

void solve(int n)
{
    int m,q,ans[5*N],cnt=0;
    if(tag++)printf("\n");          //Print a blank line between multiple cases
    InitInput(n,m,q);
    Build(m);
    for(int i=q-1;i>=0;i--){
        if(op[i].str[0]=='d')MrgNode(op[i].a,op[i].b);
        else{                                     //|* Reverse method:from end to the start,*|
            int fa=fin(op[i].a);                  //|* if destroy tunnel X,rebuild it       *|
            if(pwr[fa]>pwr[op[i].a])ans[cnt++]=fa;//|* else find the rescue star            *|
            else ans[cnt++]=-1;                   //|* Then store the ans,output reversely  *|
        }                                         //|* Null rescue star is represented by -1*|
    }
    for(int i=cnt-1;i>=0;i--)printf("%d\n",ans[i]);
}

int main()
{
    int n;
    while(~scanf("%d",&n))solve(n);
    return 0;
}
