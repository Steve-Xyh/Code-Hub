//
//  main.cpp
//  fraction cal
//
//  Created by Steve X on 2018/3/26.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;

void menu()
{
    cout<<"Please input your option"<<endl;
    for(int i=0;i<12;i++)cout<<"--";
    cout<<endl<<"|"<<endl;
    cout<<"|1---addition"<<endl;
    cout<<"|2---subtraction"<<endl;
    cout<<"|3---multiplication"<<endl;
    cout<<"|4---division"<<endl;
}

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;    //先除后乘更安全
}

void add(LL x1,LL y1,LL x2,LL y2)
{
    LL X,l=lcm(y1,y2),t1=l/y1,t2=l/y2;
    cout<<x1<<"/"<<y1<<"+"<<x2<<"/"<<y2<<"=";
    x1*=t1;
    x2*=t2;
    X=x1+x2;
    X/=gcd(x1+x2,l);
    l/=gcd(x1+x2,l);
    if(l==1){
        cout<<X<<endl;
        return;
    }
    cout<<X<<"/"<<l<<endl;
}

void sub(LL x1,LL y1,LL x2,LL y2)
{
    LL X,l=lcm(y1,y2),t1=l/y1,t2=l/y2;
    cout<<x1<<"/"<<y1<<"+"<<x2<<"/"<<y2<<"=";
    x1*=t1;
    x2*=t2;
    X=x1+x2;
    X/=gcd(x1+x2,l);
    l/=gcd(x1+x2,l);
    if(l==1){
        cout<<X<<endl;
        return;
    }
    cout<<X<<"/"<<l<<endl;
}

int main()
{
    LL x1,y1,x2,y2;
    menu();
    scanf("%lld/%lld+%lld/%lld",&x1,&y1,&x2,&y2);
    add(x1,y1,x2,y2);
    return 0;
}
