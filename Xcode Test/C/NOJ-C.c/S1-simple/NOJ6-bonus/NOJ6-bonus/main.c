//
//  main.c
//  NOJ6-bonus
//
//  Created by Steve X on 2017/10/12.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
int main()
{
    double l,a=0.1*10,b=0.075*10,c=0.05*20,d=0.03*20,e=0.015*40,f=0,sum;
    scanf("%lf",&l);
    if(l<=10){
        a=0.1*l;
        b=c=d=e=f;
    }
    if(l>10&&l<20){
        b=0.075*(l-10);
        c=d=e=f;
    }
    if(l>=20&&l<40){
        c=0.05*(l-20);
        d=e=f;
    }
    if(l>=40&&l<60){
        d=0.03*(l-40);
        e=f;
    }
    if(l>=60&&l<100)e=0.015*(l-60);
    if(l>=100)f=0.01*(l-100);
    sum=a+b+c+d+e+f;
    printf("%.6lf",sum);
    return 0;
}
