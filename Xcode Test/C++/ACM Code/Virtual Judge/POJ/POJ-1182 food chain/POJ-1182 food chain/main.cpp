//  POJ-1182 食物链    ##**TOP**## #TLE,huge IO#
//  main.cpp
//  POJ-1182 food chain
//  https://vjudge.net/contest/217087#problem/E
//  Created by Steve X on 2018/6/2.
//  Copyright © 2018年 Steve X. All rights reserved.
//  详细题解https://blog.csdn.net/niushuai666/article/details/6981689
//  思路:**UFS**并查集Union-Find Sets,向量偏移,iostream会TLE

#include <cstdio>
const int N=5e4+10;
using namespace std;

int sum=0;                          //谎言总数
struct NODE{                        //rlt=0,与根节点为同类
    int pre,rlt;                    //rlt=1,被根节点吃
    void ini(int i){                //rlt=2,吃根节点
        pre=i;                      //通过%3控制rlt在012范围内
        rlt=0;                      //pre初始化为自身,rlt初始化为0
    }
}p[N];

void InitialNode(int n)             //初始化n个结点
{
    sum=0;
    for(int i=1;i<=n;i++)p[i].ini(i);
}

int fin(int i)                      //递归查找根结点
{
    if(p[i].pre==i)return i;
    int tmp=p[i].pre;
    p[i].pre=fin(p[i].pre);
    p[i].rlt=(p[i].rlt+p[tmp].rlt)%3;
    return p[i].pre;                //关系域更新,向量rtx->x = fx->x + ffx->fx +...+ rtx->*
}

void MrgNode(int d,int x,int y)                     //合并,将y的根结点合并至x的根结点,rlt=d-1
{
    int rootx=fin(x),rooty=fin(y);                  //错写为rootx=fin(p[x].pre)导致WA到死
    if(rootx!=rooty){
        p[rooty].pre=rootx;
        p[rooty].rlt=(p[x].rlt+d-1+3-p[y].rlt)%3;   //rootx->rooty = rootx->x + x->y + y->rooty
    }else{
        if(d==1&&p[x].rlt!=p[y].rlt)sum++;          //xy同类同根,xy与根关系不同时为谎言
        if(d==2&&(3-p[x].rlt+p[y].rlt)%3!=d-1)sum++;//xy同根x->y = x->rootx + rootx->y =(3-x.rlt + y.rlt)%3
    }                                               //若d-1!=x->y则为谎言
}

int Solve(int n,int k)
{
    int d,x,y;
    InitialNode(n);
    while(k--){
        scanf("%d%d%d",&d,&x,&y);
        if(x>n||y>n)sum++;          //编号超过总数,是谎言
        else if(d==2&&x==y)sum++;   //吃同类,是谎言
        else MrgNode(d,x,y);        //判断具体关系
    }
    return sum;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);            //单组输入,否则WA到死
    printf("%d\n",Solve(n,k));
    return 0;
}
