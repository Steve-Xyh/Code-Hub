//
//  main.cpp
//  G-Do not pour out
//
//  Created by Steve X on 2018/10/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cmath>

const double eps=1e-10;
const double pi=acos(-1);

double f(double x)
{
    double ans=x;
    
    return ans;
}

double solve(double l,double r)
{
    double mid=l;
    while(f(mid)>=eps){
        mid=(l+r)/2;
        if(f(l)*f(mid)*f(r)<eps){
            if(f(l)<=eps)return l;
            else if(f(mid)<eps)return mid;
            else if(f(r)<eps)return r;
        }else{
            if(f(mid)*f(l)<0)r=mid;
            else l=mid;
        }
    }
    return mid;
}

int main()
{
    
    
    return 0;
}
