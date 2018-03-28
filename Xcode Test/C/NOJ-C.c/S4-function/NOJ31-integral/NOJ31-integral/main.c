//
//  main.c
//  NOJ31-integral
//
//  Created by Steve X on 2017/10/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

double f(double x)
{
    double f=1/(1+x*x);
    return f;
}

int main()
{
    double a,b,s=0,d=10000;
    scanf("%lf%lf",&a,&b);
    double i=a,j=a+(b-a)/d;
    while(j<=b){
        s=s+(f(i)+f(j))*(j-i)/2;
        i=j;
        j=i+(b-a)/d;
    }
    printf("%lf\n",s);
    return 0;
}
