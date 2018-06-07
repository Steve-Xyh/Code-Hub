//  kuangbin-S5
//  main.cpp
//  POJ-1456 Supermarket
//  https://vjudge.net/contest/66964#problem/G
//  Created by Steve X on 2018/6/5.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心,按利润降序排列,利润相同则ddl靠前者优先

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=1e4+10;

bool day[N];                                    //day[i]表示第i天是否占用
struct Product{                                 //截止日期ddl,利润pro
    int ddl,pro;
}a[N];

bool cmp(Product a,Product b)
{
    return a.pro!=b.pro?a.pro>b.pro:a.ddl<b.ddl;//按利润降序排列,利润相同则截止日期靠前者优先
}

int profit(int n,int minD)
{
    int ans=0;
    memset(day,0,(minD+1)*sizeof(bool));
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=a[i].ddl;j>0;j--){            //每项商品从截止日期开始,若此日占用则向前查找一天
            if(day[j]==0){                      //若此日空闲则占用此日售卖此商品,结束查找
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
        int minD=0;
        memset(a,0,n*sizeof(Product));
        for(int i=0;i<n;i++){
            cin>>a[i].pro>>a[i].ddl;
            minD=max(minD,a[i].ddl);
        }
        cout<<profit(n,minD)<<endl;
    }
    return 0;
}
