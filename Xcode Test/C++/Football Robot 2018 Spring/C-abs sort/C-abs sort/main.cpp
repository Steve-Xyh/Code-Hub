//
//  main.cpp
//  C-abs sort
//
//  Created by Steve X on 2018/3/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#define N 110
using namespace std;

struct no{
    int v,ab;
}a[N];

bool cmp(no a,no b)
{
    return a.ab>b.ab;
}

int main()
{
    int n;
    while(cin>>n&&n!=0){
        for(int i=0;i<n;i++){
            cin>>a[i].v;
            a[i].ab=abs(a[i].v);
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<a[i].v;
        }
        cout<<endl;
    }
    return 0;
}
