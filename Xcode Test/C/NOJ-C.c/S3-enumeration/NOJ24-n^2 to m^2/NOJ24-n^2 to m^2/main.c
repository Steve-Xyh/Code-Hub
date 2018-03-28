//
//  main.c
//  NOJ24-n^2 to m^2
//
//  Created by Steve X on 2017/10/19.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

double A(int n)
{
    double A=1.0/n*1.0/n;
    return A;
}

int main()
{
    int m,n;
    double sum=0;
    scanf("%d%d",&m,&n);
    for (int i=m;i<=n;i++){
        sum=sum+A(i);
    }
    printf("%.5lf\n",sum);
    return 0;
}
