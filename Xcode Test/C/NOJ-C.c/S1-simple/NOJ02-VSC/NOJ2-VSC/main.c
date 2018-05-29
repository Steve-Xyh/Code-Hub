//
//  main.c
//  NOJ2-VSC
//
//  Created by Steve X on 2017/10/12.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define pi 3.1415926
int main()
{
    double r,h,l,s,sq,vq,vz;
    scanf("%lf%lf",&r,&h);
    l=2*pi*r;
    s=pi*r*r;
    sq=4*s;
    vq=pi*r*r*r*4/3;
    vz=s*h;
    printf("%.2lf\n",l);
    printf("%.2lf\n",s);
    printf("%.2lf\n",sq);
    printf("%.2lf\n",vq);
    printf("%.2lf\n",vz);
    return 0;
}

