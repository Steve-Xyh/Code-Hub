//
//  main.cpp
//  V-The Fun Number System
//
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  水题

#include <iostream>
using namespace std;

int main()
{
    long long n;
    int T,p;
    char s[100];
    cin>>T;
    while(T--){
        cin>>p>>s>>n;
        while(p--){
            if(n%2){
                if(s[p]=='n')
                    n++;
                s[p]='1';
            }
            else s[p]='0';
            n>>=1;
        }
        if(n)cout<<"Impossible"<<endl;
        else cout<<s<<endl;
    }
}
