//
//  main.cpp
//  R-greedy task
//  https://vjudge.net/contest/205706#problem/R
//  Created by Steve X on 2018/2/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100010
using namespace std;

struct PROJECT{
    int t,lv;                  //时间,等级
    bool ocp;                  //是否占用/完成
}ma[N],ta[N];

int money(PROJECT a)           //计算单个任务的收益
{
    return 500*a.t+2*a.lv;
}

bool cmp(PROJECT a,PROJECT b)
{
    if(a.t!=b.t)return a.t>b.t;//工作时间降序,时间相同则等级降序
    else return a.lv>b.lv;
}

int level[110];
void profit(int n,int m)       //计算总利润
{
    long long sum=0,cnt=0;
    sort(ma,ma+n,cmp);
    sort(ta,ta+m,cmp);
    int maxlv=0,tagmax=0;
    for(int i=0;i<n;i++)if(ma[i].lv>=maxlv)tagmax=i;
    for(int i=0,j=0;i<m;i++){
        while (j<n && ma[j].t>=ta[i].t) {
            level[ma[j].lv]++;
            j++;
        }
        for(int k=ta[i].lv;k<=100;k++){
            if(level[k]){      //对于每个任务,选择满足条件最低级别的机器占用
                level[k]--;
                sum+=money(ta[i]);
                cnt++;
                break;
            }
        }
    }
    printf("%lld %lld\n",cnt,sum);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        memset(level,0,sizeof(level));
        for(int i=0;i<n;i++)scanf("%d%d",&ma[i].t,&ma[i].lv);
        for(int i=0;i<m;i++)scanf("%d%d",&ta[i].t,&ta[i].lv);
        profit(n,m);
    }
    return 0;
}
