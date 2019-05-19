//
//  main.cpp
//  HDU-2109 horse sort W
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100
using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    int n,a[N],b[N];
    while(cin>>n&&n!=0){
        int A=0,B=0;
        memset(a,0,N);
        memset(b,0,N);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        for(int i=0;i<n;i++){
            if(a[i]>b[i])A+=2;
            else if(a[i]<b[i])B+=2;
            else{
                A++;
                B++;
            }
        }
        cout<<A<<" vs "<<B<<endl;
    }
    return 0;
}
