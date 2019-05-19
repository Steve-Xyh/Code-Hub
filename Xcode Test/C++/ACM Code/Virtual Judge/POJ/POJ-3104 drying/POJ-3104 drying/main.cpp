//
//  main.cpp
//  POJ-3104 drying
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100000
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,a[N],k;
    memset(a,0,N);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    cin>>k;
    for(int i=0;i<n;i++){
        
        
    }
    return 0;
}
