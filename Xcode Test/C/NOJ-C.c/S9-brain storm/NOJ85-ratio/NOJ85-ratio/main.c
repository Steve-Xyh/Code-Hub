//
//  main.c
//  NOJ85-ratio
//
//  Created by Steve X on 2017/11/21.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    int a,b;
    double c,x,y,k;
    scanf("%d%d",&a,&b);
    c=1.0*a/b;
    k=a/b;
    printf("%.lf/1\n",k);
    for(y=1;y<=b;y++){
        for(x=1;x/y<=c+1;x++){
            if(fabs(x/y-c)<fabs(k-c)){
                printf("%.lf/%.lf\n",x,y);
                k=x/y;
            }
        }
    }
    return 0;
}
