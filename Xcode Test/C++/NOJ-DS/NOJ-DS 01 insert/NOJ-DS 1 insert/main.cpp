//  顺序表的插入运算(耿2.4)
//  main.cpp
//  NOJ-DS 1 insert
//
//  Created by Steve X on 2018/3/15.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 1000
using namespace std;

int main()
{
    int n,x,a[N],tag=1;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>x;
    for(int i=0;i<n;i++){
        if(x<a[i]&&tag){
            cout<<x<<" ";
            tag=0;
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

