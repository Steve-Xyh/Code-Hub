//
//  main.cpp
//  A-Baidu Unmanned Car
//
//  Created by Steve X on 2018/5/12.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 20000
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,a[N];
    long long p,s,t;
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>p>>s;
        t=s/p;
        sort(a,a+n,cmp);
        while(t){
            int i;
            for(i=0;i<n-1&&a[i]==a[i+1];i++);
            for(int j=0;j<=i;j++){
                int d=a[j]-a[i+1];
                if(d<=t){
                    t-=d;
                    a[j]-=d;
                }
                else{
                    a[j]-=t;
                    t=0;
                }
                if(t<=0)break;
            }
        }
        cout<<a[0]<<endl;
    }
    return 0;
}
