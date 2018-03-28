//
//  main.cpp
//  B-set A-B
//
//  Created by Steve X on 2018/3/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m&&(m+n)!=0){
        int a[100],b[100];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        sort(a,a+n);
        sort(b,b+m);
        int t,j,cnt=0;
        for(int i=0;i<n;i++){
            t=a[i];
            for(j=0;j<m;j++)if(t==b[j]){cnt++;break;}
            if(cnt==n)cout<<"NULL";
            if(j<m)continue;
            else cout<<t<<" ";
        }
        cout<<endl;
    }
    return 0;
}
