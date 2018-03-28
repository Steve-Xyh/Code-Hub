//
//  main.cpp
//  C-sort
//
//  Created by Steve X on 2018/3/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 100
using namespace std;

int main()
{
    int n,m,a[N];
    while(cin>>n>>m&&n!=0&&m!=0){
        a[0]=m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a,a+n+1);
        for(int i=0;i<=n;i++){
            if(i!=0)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
