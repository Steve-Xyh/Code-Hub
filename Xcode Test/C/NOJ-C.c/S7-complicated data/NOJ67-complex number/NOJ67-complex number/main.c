//
//  main.c
//  NOJ67-complex number
//
//  Created by Steve X on 2017/11/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

typedef struct complex{
    double r;
    double i;
}COMPLEX;

void calculate(double a1,double b1,double a2,double b2)
{
    COMPLEX c1,c2;
    c1.r=a1;
    c1.i=b1;
    c2.r=a2;
    c2.i=b2;
    double suma=c1.r+c2.r,sumb=c1.i+c2.i,minusa=c1.r-c2.r,minusb=c1.i-c2.i;
    double xa=a1*a2-b1*b2,xb=a1*b2+a2*b1;
    double da=(a1*a2+b1*b2)/(a2*a2+b2*b2),db=(a2*b1-a1*b2)/(a2*a2+b2*b2);
    printf("(%.2lf+%.2lfi)+(%.2lf+%.2lfi)=(%.2lf%+.2lfi)\n",a1,b1,a2,b2,suma,sumb);
    printf("(%.2lf+%.2lfi)-(%.2lf+%.2lfi)=(%.2lf%+.2lfi)\n",a1,b1,a2,b2,minusa,minusb);
    printf("(%.2lf+%.2lfi)*(%.2lf+%.2lfi)=(%.2lf%+.2lfi)\n",a1,b1,a2,b2,xa,xb);
    printf("(%.2lf+%.2lfi)/(%.2lf+%.2lfi)=(%.2lf%+.2lfi)\n",a1,b1,a2,b2,da,db);
}

int main()
{
    double a1,b1,a2,b2;
    scanf("%lf %lf",&a1,&b1);
    scanf("%lf %lf",&a2,&b2);
    calculate(a1,b1,a2,b2);
    return 0;
}
