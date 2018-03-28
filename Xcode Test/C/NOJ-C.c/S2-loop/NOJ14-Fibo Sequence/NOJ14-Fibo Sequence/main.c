//
//  main.c
//  NOJ14-Fibo Sequence
//
//  Created by Steve X on 2017/10/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

double fibo(int x)
{
    int a=1,b=0,sum=1;
    for(int i=1;i<x;i++){
        sum=b+a;
        b=a;
        a=sum;
    }
    return sum;
}

int main()
{
    double a=0.0,sum=0.0;
    for(int i=1;i<=20;i++){
        a=fibo(i+2)/fibo(i+1);
        sum=sum+a;
    }
    printf("%.6lf\n",sum);
    return 0;
}
