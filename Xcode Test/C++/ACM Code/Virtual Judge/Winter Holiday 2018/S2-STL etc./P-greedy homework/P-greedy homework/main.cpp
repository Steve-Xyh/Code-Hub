//
//  main.cpp
//  P-greedy homework
//  https://vjudge.net/contest/205706#problem/P
//  Created by Steve X on 2018/2/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 1010
using namespace std;

bool day[N];                            //day[i]表示第i天是否占用
struct Homework{                        //截止日期ddl,分数scr
    int ddl,scr;
}a[N];

bool cmp(Homework a,Homework b)
{
    if(a.scr!=b.scr)return a.scr>b.scr; //按分数降序排列
    else return a.ddl<b.ddl;            //分数相同则截止日期靠前者优先
}

int penalty(int n)
{
    int ans=0;
    memset(day,0,sizeof(day));
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=a[i].ddl;j>0;j--){    //每项作业从截止日期开始,若此日占用则向前查找一天
            if(day[j]==0){              //若此日空闲则占用此日,结束查找
                day[j]=1;
                break;
            }
            if(j==1)ans+=a[i].scr;      //若查找到第一天仍占用,则放弃此项作业,扣分
        }
    }
    return ans;
}

int main()
{
    int T,n;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i].ddl;
        for(int i=0;i<n;i++)cin>>a[i].scr;
        cout<<penalty(n)<<endl;
    }
    return 0;
}
