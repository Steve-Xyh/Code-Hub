//  kuangbin S5-A
//  main.cpp
//  POJ-2236 Wireless Network
//  https://vjudge.net/contest/66964#problem/A
//  Created by Steve X on 2018/5/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集Union-Find Sets 结构体

#include <iostream>
#define N 1010
using namespace std;

int num,d;                  //结点个数num,最远通信距离d
struct NODE{
    int x,y,pre;
    bool sta;
}a[N];                      //父亲结点

int fin(int n)              //查找根结点(条件运算符的递归写法)
{
    return a[n].pre==n?n:a[n].pre=fin(a[n].pre);
}

void init(int n)            //初始化
{
    for(int i=1;i<=n;i++){
        a[i].pre=i;
        a[i].sta=false;     //默认状态为不可用
        cin>>a[i].x>>a[i].y;
    }
}

void MrgNode(NODE m,NODE n) //合并m,n
{
    if((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y)>d*d)return;
    int x=fin(m.pre);
    int y=fin(n.pre);
    a[x].pre=y;             //必要时可写成a[min(x,y)]=max(x,y);
}

void Solve(char c)
{
    int p,q;
    if(c=='O'){
        cin>>p;
        a[p].sta=true;
        for(int i=1;i<=num;i++)if(a[i].sta&&i!=p)MrgNode(a[p],a[i]);
    }else if(c=='S'){
        cin>>p>>q;
        if(fin(p)==fin(q))cout<<"SUCCESS"<<endl;
        else cout<<"FAIL"<<endl;
    }
}

int main()
{
    char c;
    cin>>num>>d;
    init(num);
    while(cin>>c)Solve(c);
    return 0;
}
