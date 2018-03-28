//  https://vjudge.net/contest/205705#problem/G
//  main.cpp
//  G-Sort score
//
//  Created by Steve X on 2018/1/28.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:结构体sort

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100000
using namespace std;

struct TEAM{
    char name[50];
    int in,lost,net,score;                        //进球数,输球数,净进球,得分
}a[N];                                            //定义net=in-lost为无效操作

bool cmp(TEAM x,TEAM y)
{
    if(x.score!=y.score)return x.score>y.score;   //分数高排前面
    if(x.net!=y.net)return x.net>y.net;           //分数相同则净进球高排前面
    if(x.in!=y.in)return x.in>y.in;               //净进球相同则进球多排前面
    return strcmp(x.name,y.name)<0;               //进球相同则按字母顺序排列
}

int Tsearch(TEAM x,TEAM a[],int n)                //搜索前面的名单是否有此队
{
    for(int i=0;i<n;i++)if(strcmp(x.name,a[i].name)==0)return i;
    return -1;
}

void Tmatch(TEAM x,TEAM y,TEAM a[],int n,int &cnt)
{
    int tx=Tsearch(x,a,n),ty=Tsearch(y,a,n);
    x.lost=y.in;                           //计算lost,net
    y.lost=x.in;
    x.net=x.in-x.lost;
    y.net=y.in-y.lost;
    x.score=y.score=0;
    if(x.in>y.in)x.score=3;                //计算score,赢得3分,输得0分,平局1分
    if(x.in<y.in)y.score=3;
    if(x.in==y.in){x.score++;y.score++;}
    
    if(tx==-1)a[++cnt]=x;                  //若名单中不存在则将该队数据添加其中
    else{
        a[tx].in+=x.in;
        a[tx].lost+=x.lost;
        a[tx].net+=x.net;
        a[tx].score+=x.score;
    }
    if(ty==-1)a[++cnt]=y;
    else{
        a[ty].in+=y.in;
        a[ty].lost+=y.lost;
        a[ty].net+=y.net;
        a[ty].score+=y.score;
    }
}

int main()
{
    int n;
    TEAM t[2];
    while(~scanf("%d",&n)){
        int cnt=-1;
        memset(a,0,sizeof(a));             //将a[],t[],cnt初始化
        memset(t,0,sizeof(t));
        for(int i=0;i<n*(n-1);i++){
            scanf("%s VS %s %d:%d",t[0].name,t[1].name,&t[0].in,&t[1].in);  //输入每场比赛
            Tmatch(t[0],t[1],a,n,cnt);
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)cout<<a[i].name<<" "<<a[i].score<<endl;
        cout<<endl;
    }
    return 0;
}
