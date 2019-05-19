//
//  main.cpp
//  I-LCM of n numbers
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;    //先除后乘更安全
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int ans=1,x,n;
        cin>>n;
        while(n--){
            cin>>x;
            ans=lcm(ans,x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
