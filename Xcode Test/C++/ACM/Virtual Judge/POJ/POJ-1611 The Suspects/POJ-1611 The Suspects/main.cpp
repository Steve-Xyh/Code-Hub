//  kuangbin S5-B
//  main.cpp
//  POJ-1611 The Suspects
//  https://vjudge.net/contest/66964#problem/B
//  Created by Steve X on 2018/5/26.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集Union-Find Sets 查询i与0的关系

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
    for(int i=0;i<n;i++)pre[i]=i;
}

void MrgNode(int a,int b)   //合并m,n
{
    int x=fin(a);
    int y=fin(b);
    pre[x]=y;               //必要时可写成a[min(x,y)]=max(x,y);
}

int cntSuspect(int num)     //嫌疑人数量,0为感染者,i与0属于同一个集合时则为感染者
{
    int cnt=0;
    for(int i=0;i<num;i++)if(fin(i)==fin(0))cnt++;
    return cnt;
}

int main()
{
    int n,m;
    while(cin>>n>>m&&(n||m)){
        init(n);
        for(int i=0;i<m;i++){
            int k,a,b;
            cin>>k>>a;
            for(int i=1;i<k;i++){
                cin>>b;
                MrgNode(a,b);
            }
        }
        cout<<cntSuspect(n)<<endl;
    }
    return 0;
}
