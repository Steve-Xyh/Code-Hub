//  实验1.1 合并有序数组
//  main.cpp
//  NOJ-DS 27 array merge
//
//  Created by Steve X on 2018/3/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 20
using namespace std;

int main()
{
    int n,m;
    int a[N],b[N],c[2*N];
    cin>>n;
    for(int i=0;i<n;i++){   //输入a[N]
        cin>>a[i];
        c[i]=a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){   //输入b[N]
        cin>>b[i];
        c[i+n]=b[i];
    }
    sort(c,c+m+n);          //排序
    for(int i=0;i<m+n;i++)cout<<c[i]<<endl;
    return 0;
}
