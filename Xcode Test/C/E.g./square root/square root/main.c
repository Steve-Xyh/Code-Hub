//
//  main.c
//  square root
//
//  Created by Steve X on 2017/9/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double root(double x,double y)
{
    if(x>=y)return sqrt(x-y);
    else return sqrt(y-x);
}
int main()
{
    double a,b;
    printf("请输入a和b\na=");
    scanf("%lf",&a);
    printf("\nb=");
    scanf("%lf",&b);
    printf("\n算术平方根sqr(|a-b|)=%lf\n",root(a,b));
    return 0;
}
