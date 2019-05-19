//  https://vjudge.net/problem/POJ-2823
//  main.cpp
//  POJ-2823 Sliding Window
//
//  Created by Steve X on 2018/2/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:单调队列,双端队列deque保存数组下标,用stdio否则TE

#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

const int N=1e6+10;

void dispmax(int x[],int n,int k)                            //单调递减找窗口最大值
{
    deque<int>a;                                             //双端队列存数组下标
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!a.empty()&&a.back()-a.front()+1>=k)a.pop_front();//队列非空,长度超过窗口则队首出队
        cnt++;                                               //记录入队元素个数
        while(!a.empty()&&x[i]>x[a.back()])a.pop_back();     //新元素大于队尾元素则队尾出队
        a.push_back(i);                                      //新元素入队
        if(cnt>=k)printf("%d ",x[a.front()]);                //输出队首元素
    }
    printf("\n");
}

void dispmin(int x[],int n,int k)                            //单调递增找窗口最小值
{
    deque<int>a;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!a.empty()&&a.back()-a.front()+1>=k)a.pop_front();
        cnt++;
        while(!a.empty()&&x[i]<x[a.back()])a.pop_back();     //新元素小于队尾元素则队尾出队
        a.push_back(i);
        if(cnt>=k)printf("%d ",x[a.front()]);
    }
    printf("\n");
}

int main()
{
    int n,k,x[N];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&x[i]);
    dispmin(x,n,k);
    dispmax(x,n,k);
    return 0;
}
