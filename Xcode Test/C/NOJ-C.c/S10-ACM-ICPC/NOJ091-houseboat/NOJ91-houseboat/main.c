//
//  main.c
//  NOJ91-houseboat
//
//  Created by Steve X on 2017/11/22.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define PI 3.1415926

typedef struct tagpoint{
    double x;
    double y;
}POINT;

int main()
{
    int n,Y[100];
    double S[100];
    POINT A[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&A[i].x,&A[i].y);
        S[i]=PI*(A[i].x*A[i].x+A[i].y*A[i].y)/2.0;
        Y[i]=ceil(S[i]/50.0);
    }
    for(int i=0;i<n;i++){
        printf("%d %d\n",i+1,Y[i]);
    }
    return 0;
}
