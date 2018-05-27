//  循环右移(耿5.2)
//  main.cpp
//  NOJ-DS 11 Circular Right Moving
//
//  Created by Steve X on 2018/4/17.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 200
using namespace std;

int main()
{
    int k,n,a[N],cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    while(cnt<n){
        cout<<a[(n*N-k)%n]<<" ";    //右移k位相当于i左移k位即-k,通过+n*N来保证模n运算正常进行
        if(k==0)k=n-1;
        else k=(k-1)%n;             //通过模n加法实现循环
        cnt++;
    }
    cout<<endl;
    return 0;
}
