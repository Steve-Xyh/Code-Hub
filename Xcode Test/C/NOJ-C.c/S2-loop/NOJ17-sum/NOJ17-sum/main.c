//
//  main.c
//  NOJ17-sum
//
//  Created by Steve X on 2017/10/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double A(int n)
{
    double a,b,c;
    a=pow(-1,n-1)*pow(2,n);
    b=pow(2,n)+pow(-1,n);
    c=pow(2,n+1)+pow(-1,n+1);
    return a/(b*c);
}

int main()
{
    int n;
    double sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum=sum+A(i);
    }
    printf("%6lf\n",sum);
    return 0;
}
