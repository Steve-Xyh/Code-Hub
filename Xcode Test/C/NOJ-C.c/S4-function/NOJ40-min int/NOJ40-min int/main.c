//
//  main.c
//  NOJ40-min int
//
//  Created by Steve X on 2017/10/29.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int fceil(double x)
{
    return ceil(x);
}

int main()
{
    double x;
    scanf("%lf",&x);
    printf("%d\n",fceil(x));
    return 0;
}
