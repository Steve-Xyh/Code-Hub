//  顺序表的删除(严2.29)
//  main.cpp
//  NOJ-DS 3 delete list
//
//  Created by Steve X on 2018/3/17.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 100
using namespace std;

int m,n,p,a[N],b[N],c[N];

bool searchlist(int a[],int x)
{
    for(int i=0;i<n;i++)if(x==a[i])return true;
    return false;
}

void dellist()
{
    for(int i=0;i<m;i++)if(!(searchlist(b,a[i])&&searchlist(c,a[i])))cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>m>>n>>p;
    for(int i=0;i<m;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<p;i++)cin>>c[i];
    dellist();
    return 0;
}
