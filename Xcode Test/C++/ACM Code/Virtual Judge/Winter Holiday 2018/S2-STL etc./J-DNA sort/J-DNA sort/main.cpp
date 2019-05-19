//
//  main.cpp
//  J-DNA sort
//  https://vjudge.net/contest/205706#problem/J
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  逆序数为字母顺序降序的个数,水题

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct DNA
{
    char s[55];
    int cnt;
}a[110];
bool cmp(DNA m,DNA n)
{
    return m.cnt<n.cnt;
}
int main()
{
    int m,n,i,j,k;
    char s[10];
    cin>>n>>m;
    gets(s);
    for(i=0;i<m; ++i){
        gets(a[i].s);
        a[i].cnt=0;
        for(j=0;j<n;++j)
            for(k=j+1; k<n; k++)if(a[i].s[j]>a[i].s[k])a[i].cnt++;
    }
    sort(a,a+m,cmp);
    for(i=0;i<m;++i)cout<<a[i].s<<endl;
    return 0;
}
