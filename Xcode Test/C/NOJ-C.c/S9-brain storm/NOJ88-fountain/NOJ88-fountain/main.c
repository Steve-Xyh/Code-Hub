//
//  main.c
//  NOJ88-fountain
//
//  Created by Steve X on 2017/11/22.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void sortR(double R[],int n)
{
    double t;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(R[i]<R[j]){
                t=R[i];
                R[i]=R[j];
                R[j]=t;
            }
        }
    }
}

int main()
{
    int n,i=0;
    double R[600],x=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&R[i]);
    }
    sortR(R,n);
    for(i=0;x<20;i++){
        x+=sqrt(4*R[i]*R[i]-4);
    }
    if(i>0)i--;
    printf("%d\n",i);
    return 0;
}
