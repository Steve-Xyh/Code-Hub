//  kuangbin S5-M
//  main.cpp
//  HDU-1272 Maze to Tree
//  https://vjudge.net/contest/66964#problem/M
//  Created by Steve X on 2018/5/28.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集Union-Find Sets 同POJ-1308 判断是否为树,是树则形成符合条件的迷宫
//#include <bits/stdc++.h>      //不加则CE
#include <iostream>
#include <algorithm>
#include <set>
const int N=1e5+10;
using namespace std;

set<int>node;                   //结点编号集合
set<int>::iterator it;

int pre[N];
int fin(int n)                  //查找根结点
{
    return pre[n]==n?n:pre[n]=fin(pre[n]);
}

void init(int n)                //初始化
{
    for(int i=0;i<n;i++)pre[i]=i;
}

void MrgNode(int a,int b)       //合并m,n
{
    int x=fin(a);
    int y=fin(b);
    pre[x]=y;
}

bool cntSet()                   //集合数量,判断是否为森林
{
    int cnt=0;
    for(it=node.begin();it!=node.end();it++){
        if(fin(*it)==*it)cnt++;
        if(cnt>1)return false;  //***空树(cnt==0)和cnt==1时是树,cnt>1时不是树***
    }
    return true;
}

int main()
{
    int a,b,tag=1;
    init(N);
    while(cin>>a>>b){
        if(a<0&&b<0)break;      //a,b同时为负数时结束输入
        if(!a&&!b){             //a,b同时为0时结束本组
            if(!cntSet())tag=0;
            if(tag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            init(N);            //为下一组初始化
            tag=1;
            node.clear();
            continue;
        }
        node.insert(a);         //保存结点编号
        node.insert(b);
        if(fin(a)==fin(b))tag=0;//输入a,b前若a,b属于同一集合则形成环或自回路,不是树
        else MrgNode(a,b);
    }
    return 0;
}
