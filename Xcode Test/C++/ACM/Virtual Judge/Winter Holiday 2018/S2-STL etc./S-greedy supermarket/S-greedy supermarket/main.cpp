//
//  main.cpp
//  S-greedy supermarket
//  https://vjudge.net/contest/205706#problem/S
//  Created by Steve X on 2018/2/24.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 10010
using namespace std;

bool day[N];                            //day[i]表示第i天是否占用
struct Product{                         //截止日期ddl,利润pro
    int ddl,pro;
}a[N];

bool cmp(Product a,Product b)
{
    if(a.pro!=b.pro)return a.pro>b.pro; //按利润降序排列
    else return a.ddl<b.ddl;            //利润相同则截止日期靠前者优先
}

int profit(int n)
{
    int ans=0;
    memset(day,0,sizeof(day));
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=a[i].ddl;j>0;j--){    //每项商品从截止日期开始,若此日占用则向前查找一天
            if(day[j]==0){              //若此日空闲则占用此日售卖此商品,结束查找
                day[j]=1;
                ans+=a[i].pro;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    while(cin>>n){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)cin>>a[i].pro>>a[i].ddl;
        cout<<profit(n)<<endl;
    }
    return 0;
}
