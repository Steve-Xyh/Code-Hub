//  https://vjudge.net/contest/205705#problem/K
//  main.cpp
//  K-next_permutation
//
//  Created by Steve X on 2018/2/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:STL<algorithm> next_permutation排列函数找出第m个排列

#include <iostream>
#include <algorithm>
#define N 1000
using namespace std;
int a[N];

void CreateS(int a[],int n)
{
    for(int i=0;i<n;i++)a[i]=i+1;
}

int main()
{
    int n,m;
    while(cin>>n>>m){
        CreateS(a,n);
        for(int i=0;i<m-1;i++)next_permutation(a,a+n);
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
