//
//  main.cpp
//  T-ex_gcd
//  https://vjudge.net/contest/205708#problem/T
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:ex_gcd,找最优解

#include <iostream>
using namespace std;

long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    else{
        long long r=ex_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

int main()
{
    long long x,y,m,n,l;
    long long X,Y;
    while(cin>>x>>y>>m>>n>>l){
        long long M = ex_gcd(n-m,l,X,Y);
        if((x-y)%M||(m==n)){
            cout<<"Impossible"<<endl;
            continue;
        }
        else{
            long long s=l/M;
            X=X*(x-y)/M;
            X=(X%s+s)%s;
            cout<<X<<endl;
        }
    }
    return 0;
}
