//
//  main.c
//  NOJ7-taxi fee
//
//  Created by Steve X on 2017/10/12.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
int main()
{
    double s,x,a=7,b=1.5*13,c=0,sum;
    scanf("%lf",&s);
    if((int)s-s==0)x=(int)s;
    else x=(int)s+1;
    if(x<=2)b=c;
    if(x>=2&&x<=15)b=1.5*(x-2);
    if(x>15)c=2.1*(x-15);
    sum=a+b+c;
    printf("%.6lf",sum);
    return 0;
}
