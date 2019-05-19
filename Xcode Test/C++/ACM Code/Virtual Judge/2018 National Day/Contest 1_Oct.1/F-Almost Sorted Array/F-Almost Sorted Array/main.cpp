//
//  main.cpp
//  F-Almost Sorted Array
//
//  Created by Steve X on 2018/10/1.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=1e5+10;
const int INF=0x3f3f3f3f;
int n,a[N];

bool ascend(int n)
{
    int cnt=0;
    a[0]=-INF;a[n+1]=INF;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            if(cnt)return false;
            cnt++;
            if(a[i+1]>=a[i-1]||a[i]>=a[i-2])continue;
            else return false;
        }
    }
    return true;
}

bool descend(int n)
{
    int cnt=0;
    a[0]=INF;a[n+1]=-INF;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            if(cnt)return false;
            cnt++;
            if(a[i+1]<=a[i-1]||a[i]<=a[i-2])continue;
            else return false;
        }
    }
    return true;
}

void solve(int n)
{
    if(ascend(n)||descend(n))printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        solve(n);
    }
    return 0;
}
