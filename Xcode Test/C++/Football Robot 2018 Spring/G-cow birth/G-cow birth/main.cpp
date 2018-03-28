//
//  main.cpp
//  G-cow birth
//  https://vjudge.net/contest/214515#problem/G
//  Created by Steve X on 2018/3/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

int cnt(int n)
{
    if(n<=4)return n;
    return 2*n-4;
}
int main()
{
    int n;
    while(cin>>n&&n!=0)cout<<cnt(n)<<endl;
    return 0;
}
