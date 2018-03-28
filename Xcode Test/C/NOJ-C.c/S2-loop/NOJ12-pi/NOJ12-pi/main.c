//
//  main.c
//  NOJ12-pi
//
//  Created by Steve X on 2017/10/13.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    double pi,sum=0,a=1,b=-1;
    for(a=1;a<=1000000;a=a+2){
        b=-1*b;
        sum=sum+b/a;
    }
    pi=4*sum;
    printf("%.6lf",pi);
    return 0;
}
