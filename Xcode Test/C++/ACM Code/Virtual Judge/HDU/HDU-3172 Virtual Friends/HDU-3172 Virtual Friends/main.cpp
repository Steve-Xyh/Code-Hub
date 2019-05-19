//  ##DNF##
//  main.cpp
//  HDU-3172 Virtual Friends
//
//  Created by Steve X on 2018/6/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int N=1e4+10;

int pre[N];
map<string,int>name;

void init(int n)
{
    for(int i=1;i<=n;i++)pre[i]=i;          //Nodes are numbered from 1 to n
}

int fin(int n)
{
    return pre[n]==n?n:pre[n]=fin(pre[n]);
}

void MrgNode(int x,int y)
{
    int rootx=fin(x),rooty=fin(y);
    if(rootx!=rooty)pre[rootx]=rooty;
}

int cntSet(int n)                           //Count the number of sets
{
    int cnt=0;
    for(int i=1;i<=n;i++)if(pre[i]==i)cnt++;
    return cnt;
}



int main()
{
    
    
    
    return 0;
}
