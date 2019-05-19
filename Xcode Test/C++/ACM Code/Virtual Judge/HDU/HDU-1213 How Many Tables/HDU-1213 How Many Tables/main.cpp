//  kuangbin S5-C
//  main.cpp
//  HDU-1213 How Many Tables
//  https://vjudge.net/contest/66964#problem/C
//  Created by Steve X on 2018/5/27.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集Union-Find Sets 裸题

#include <iostream>
#define N 30010
using namespace std;

int pre[N];
int fin(int n)              //查找根结点(条件运算符的递归写法)
{
    return pre[n]==n?n:pre[n]=fin(pre[n]);
}

void init(int n)            //初始化
{
    for(int i=1;i<=n;i++)pre[i]=i;
}

void MrgNode(int a,int b)   //合并m,n
{
    int x=fin(a);
    int y=fin(b);
    pre[x]=y;               //必要时可写成a[min(x,y)]=max(x,y);
}

int cntSet(int n)           //集合数量
{
    int cnt=0;
    for(int i=1;i<=n;i++)if(fin(i)==i)cnt++;
    return cnt;
}

int main()
{
    int T,n,m,a,b;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init(n);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            MrgNode(a,b);
        }
        cout<<cntSet(n)<<endl;
    }
    return 0;
}
