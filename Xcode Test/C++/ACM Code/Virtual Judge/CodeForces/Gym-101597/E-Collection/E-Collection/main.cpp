//  Gym - 101597E
//  main.cpp
//  E-Collection
//  https://vjudge.net/contest/220847#problem/E
//  Created by Steve X on 2018/4/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:水题

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 200010
using namespace std;

int n,a[N];

int main()
{
    while(cin>>n){
        memset(a,0,n*sizeof(int));
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        
        int cnt=0;
        for(int i=0;i<n-1;i++)
            if(a[i]==a[i+1])cnt++;
        
        cout<<cnt<<endl;
    }
    return 0;
}
