//
//  main.cpp
//  A
//
//  Created by Steve X on 2018/3/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

char num(int n)
{
    if(n<10) return n+'0';
    return n-10+'A';
}

void trans(int n,int r)
{
    int cnt=0;
    char a[15];
    if(n<0){
        n*=-1;
        cout<<"-";
    }
    for(int i=0;i<15;i++)a[i]='\0';
    while(n){
        a[cnt++]=num(n%r);
        n/=r;
    }
    for(int i=cnt-1;i>=0;i--)cout<<a[i];
    cout<<endl;
}

int main()
{
    int n,r;
    while(cin>>n>>r)trans(n,r);
    return 0;
}
