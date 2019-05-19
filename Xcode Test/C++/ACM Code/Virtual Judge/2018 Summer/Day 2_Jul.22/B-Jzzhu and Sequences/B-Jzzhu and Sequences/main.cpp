//  Day 2
//  main.cpp
//  B-Jzzhu and Sequences
//  https://vjudge.net/contest/240161#problem/B
//  Created by Steve X on 2018/7/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//  打表可知周期为6
//  #define TEST
#include <iostream>
#include <cstdio>
using namespace std;

const int p=1e9+7;
const int T=6;                  //找规律,周期为6

int fn(int x,int y,int n)
{
    int ans;
    if(n==1)ans=x%p;
    else if(n==2)ans=y%p;
    else{
        ans=(y-x)%p;
        for(int i=3;i<n;i++){
            x=y%p;
            y=ans%p;
            ans=(y-x)%p;
        }
    }
    return (p+ans)%p;           //保证ans为正数
}

int main()
{
    int x,y,n;
    
#ifdef TEST
    while(cin>>x>>y){
        cout<<"x="<<x<<",y="<<y<<":"<<endl<<endl;
        for(int i=1;i<=50;i++)printf("f%d=%d\n",i,fn(x,y,i));
    }
#endif
    
#ifndef TEST
    while(~scanf("%d%d%d",&x,&y,&n)){
        printf("%d\n",fn(x,y,(n-1)%T+1));   //保证n在1~T之内
    }
#endif
    
    return 0;
}
