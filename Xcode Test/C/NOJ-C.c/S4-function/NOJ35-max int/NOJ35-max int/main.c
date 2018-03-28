//
//  main.c
//  NOJ35-max int
//
//  Created by Steve X on 2017/10/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int getfloor(double x)
{
    if(x>=0)return (int)x;
    else return (int)x-1;
}

int main()
{
    double x;
    scanf("%lf",&x);
    printf("%d\n",getfloor(x));
    return 0;
}
