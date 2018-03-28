//
//  main.c
//  NOJ19-equation
//
//  Created by Steve X on 2017/10/15.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double f(double x)
{
    double f=2*x*x*x-4*x*x+3*x-6;
    return f;
}

int main()
{
    double m,n,a,b,x=9;
    scanf("%lf%lf",&m,&n);
    a=m+n;
    b=fabs(m-n);
    while(b>0.0000000000000000000001){
        if(f(m)*f(a/2)<=0)n=a/2;
        else m=a/2;
        if(f(m)==0){
            x=m;
            break;
        }
        if(f(a/2)==0){
            x=a/2;
            break;
        }
        if(fabs(f(m))<fabs(f(a/2)))x=m;
        else x=a/2;
        a=m+n;
        b=fabs(m-n);
    }
    printf("%.2lf\n",x);
    return 0;
}
