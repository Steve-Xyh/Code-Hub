//
//  main.cpp
//  W-Circumference of triangle's Circle
//  https://vjudge.net/contest/205705#problem/W
//  Created by Steve X on 2018/2/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:数学推导运用正弦定理&海伦公式,R=abc/4S,s=sqrt(p(p-a)(p-b)(p-c)),p=(a+b+c)/2

#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.141592653589793
using namespace std;

struct POINT{double x,y;};

double caledge(POINT a,POINT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double calR(POINT X,POINT Y,POINT Z)
{
    double a=caledge(X,Y),b=caledge(X,Z),c=caledge(Y,Z);
    double p=(a+b+c)/2.0,S=sqrt(p*(p-a)*(p-b)*(p-c));
    return a*b*c/(4.0*S);
}

double calC(double R)
{
    return 2*PI*R;
}

int main()
{
    POINT a,b,c;
    double fdata;
    while(cin>>fdata){
        a.x=fdata;
        cin>>a.y>>b.x>>b.y>>c.x>>c.y;
        printf("%.2f\n",calC(calR(a,b,c)));
    }
    return 0;
}
