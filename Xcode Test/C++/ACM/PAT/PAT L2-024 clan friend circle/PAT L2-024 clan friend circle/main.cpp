//  PAT L2-024 部落
//  main.cpp
//  PAT L2-024 clan friend circle
//  https://www.patest.cn/contests/gplt/L2-024
//  Created by Steve X on 2018/3/29.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:并查集 Union-Find Sets

#include <iostream>
#include <algorithm>
#define N 10000
using namespace std;

int n,k,a,b,maxv;
int pre[N+1];               //pre[a]=b表示a的父结点是b
void InitialNode(int n)     //初始化n个结点
{
    for(int i=1;i<=n;i++)pre[i]=i;
}

int fin(int i)              //递归查找根结点
{
    return pre[i]==i?i:pre[i]=fin(pre[i]);
}

void MergeNode(int a,int b) //合并,将a的根结点合并至b的根结点
{
    int x=fin(a),y=fin(b);
    pre[x]=y;
}

int cntset(int n)           //计算集合数量
{
    int sum=0;
    for(int i=1;i<=n;i++)if(fin(i)==i)sum++;
    return sum;
}

void InputNode()            //输入部落成员
{
    InitialNode(N);
    maxv=0;
    while(n--){
        cin>>k;
        cin>>a;
        maxv=max(maxv,a);
        for(int i=1;i<k;i++){
            cin>>b;
            maxv=max(maxv,b);
            MergeNode(a,b);
        }
    }
    cout<<maxv<<" "<<cntset(maxv)<<endl;
}                           //输出人数及朋友圈数量

void AskCircle()            //检查两人是否为同一圈内
{
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(fin(a)==fin(b))cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
}

int main()
{
    while(cin>>n){
        InputNode();
        AskCircle();
    }
    return 0;
}
