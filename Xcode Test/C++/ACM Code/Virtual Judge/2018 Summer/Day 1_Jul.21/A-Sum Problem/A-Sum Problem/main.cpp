//  Day 1
//  main.cpp
//  A-Sum Problem
//  https://vjudge.net/contest/239961#problem/A
//  Created by Steve X on 2018/7/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:W

#include <iostream>
using namespace  std;

int main()
{
    int n,sum;
    while(cin>>n){
        if(n&1)sum=(n+1)/2*n;
        else sum=n/2*(n+1);
        cout<<sum<<endl<<endl;
    }
    return 0;
}
