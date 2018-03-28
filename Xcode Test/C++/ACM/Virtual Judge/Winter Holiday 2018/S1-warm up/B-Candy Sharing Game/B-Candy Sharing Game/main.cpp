//
//  main.cpp
//  B-Candy Sharing Game
//
//  Created by Steve X on 2018/1/2.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:模n运算,每次各元素减半,然后加上前驱元素

#include <iostream>
#define N 100
using namespace std;

struct candy {
    int ori,add,min,cur;                              //初始,增加,减少,当前
}a[N];

int share(int n,candy a[])                            //一次循环交换糖果
{
    for(int i=0;i<n;i++)a[i].min=a[i].ori/2;          //每次减少一半给右边
    for(int i=0;i<n;i++){
        int p=i>0?i-1:n-1;
        a[i].add=a[p].min;
        a[i].cur=a[i].ori-a[i].min+a[i].add;
        if(a[i].cur%2!=0)a[i].cur++;                  //如果出现奇数,则增加一颗糖
        a[i].ori=a[i].cur;                            //更新糖果初始值
    }
    int tag=1;
    for(int t=1;t<n;t++)if(a[0].cur==a[t].cur)tag++;  //与第一个糖果数比较
    if(tag==n)return 1;                               //如果全部相等,返回1,否则返回0
    return 0;
}

int main()
{
    int n;
    while(cin>>n&&n>0){
        for(int i=0;i<n;i++)cin>>a[i].ori;
        int cnt=1;
        while(share(n,a)==0)cnt++;
        cout<<cnt<<" "<<a[0].cur<<endl;
    }
    return 0;
}
