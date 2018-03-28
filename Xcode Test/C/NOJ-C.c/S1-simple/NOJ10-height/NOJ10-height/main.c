//
//  main.c
//  NOJ10-height
//
//  Created by Steve X on 2017/10/12.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
int tower(double x,double y)
{
    double d1,d2,d3,d4;
    d1=(x-2)*(x-2)+(y-2)*(y-2);
    d2=(x+2)*(x+2)+(y-2)*(y-2);
    d3=(x+2)*(x+2)+(y+2)*(y+2);
    d4=(x-2)*(x-2)+(y+2)*(y+2);
    if(d1<=1||d2<=1||d3<=1||d4<=1)return 10;
    else return 0;
}

int main()
{
    double x,y;
    scanf("%lf,%lf",&x,&y);
    printf("%d",tower(x,y));
    return 0;
}
