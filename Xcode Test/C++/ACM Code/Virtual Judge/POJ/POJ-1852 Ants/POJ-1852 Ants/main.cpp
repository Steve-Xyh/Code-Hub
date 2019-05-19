//
//  main.cpp
//  POJ-1852 Ants
//  https://vjudge.net/problem/POJ-1852
//  Created by Steve X on 2018/2/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:最短时间为距离最近端点距离最大值,最长时间为距离最远端点最大值

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 1000000
using namespace std;

void dispTime(int L,int n,int x[])
{
    int mint=0,maxt=0;
    for(int i=0;i<n;i++){
        mint=max(mint,min(x[i],L-x[i]));
        maxt=max(maxt,max(x[i],L-x[i]));
    }
    cout<<mint<<" "<<maxt<<endl;
}

int main()
{
    int T,l,n,x[N];
    cin>>T;
    while(T--){
        memset(x,0,sizeof(x));
        cin>>l>>n;
        for(int i=0;i<n;i++)cin>>x[i];
        dispTime(l,n,x);
    }
    return 0;
}
