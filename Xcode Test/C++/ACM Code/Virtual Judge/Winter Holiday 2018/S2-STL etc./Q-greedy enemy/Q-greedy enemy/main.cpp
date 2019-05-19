//  HDU-4310
//  main.cpp
//  Q-greedy enemy
//  https://vjudge.net/contest/205706#problem/Q
//  Created by Steve X on 2018/2/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 30
using namespace std;

struct ENEMY{
    int hp,dps;
}a[N];

bool cmp(ENEMY a,ENEMY b)
{
    return a.hp*b.dps<a.dps*b.hp;   //dps/hp比值大的优先攻击
}

int score(int n)
{
    int ans=0,cnt=0;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        ans+=(cnt+a[i].hp)*a[i].dps;//第i个敌人已经存活cnt次攻击,还将存活a[i].hp次攻击
        cnt+=a[i].hp;               //经过a[i].hp次攻击
    }
    return ans;
}

int main()
{
    int n;
    while(cin>>n){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)cin>>a[i].dps>>a[i].hp;
        cout<<score(n)<<endl;
    }
    return 0;
}
