//
//  main.c
//  NOJ15-digit
//
//  Created by Steve X on 2017/10/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x;
    scanf("%lf",&x);
    int a;
    a=abs((int)x);
    int m=1;
    if(a<1)m=0;
    for(int i=1;a/10>0;i++){
        a=a/10;
        m++;
    }
    printf("%d\n",m);
    return 0;
}
