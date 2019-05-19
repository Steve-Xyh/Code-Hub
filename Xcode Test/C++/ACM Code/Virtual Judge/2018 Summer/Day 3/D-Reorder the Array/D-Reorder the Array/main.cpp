//  CodeForces-1007A
//  main.cpp
//  D-Reorder the Array
//  https://vjudge.net/contest/240521#problem/D
//  Created by Steve X on 2018/8/5.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e5+10;
int a[N];

void solve(int n)
{
    sort(a,a+n);                                //升序排列
    int ans=0;
    for(int i=1;i<n;i++)if(a[i]>a[ans])ans++;   //从最小的开始,对于每个a查找大于a的最小值,继续查找下一个
    cout<<ans<<endl;
}

int main()
{
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        solve(n);
    }
    return 0;
}
