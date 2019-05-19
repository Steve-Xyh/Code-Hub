//
//  main.cpp
//  HDU-2107 max W
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100
using namespace std;

int main()
{
    int n,a[N];
    while(cin>>n&&n!=0){
        memset(a,0,N);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<a[n-1]<<endl;
    }
    return 0;
}
