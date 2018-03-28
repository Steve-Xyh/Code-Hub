//
//  main.cpp
//  HDU-1425 max n numbers
//
//  Created by Steve X on 2017/12/25.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 1000000
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,m,a[N];
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        for(int i=0;i<m;i++){
            if(i)cout << " ";
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
