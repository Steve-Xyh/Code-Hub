//
//  main.c
//  NOJ18-sum
//
//  Created by Steve X on 2017/10/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int A(int n)
{
    int a=1,b=1,sum=1;
    for(int i=3;i<=n;i++){
        sum=a+2*b;
        a=b;
        b=sum;
    }
    return sum;
}

int S(int n)
{
    int S=0;
    for(int i=1;i<=n;i++){
        S=S+A(i);
    }
    return S;
}

int main()
{
    int n=1;
    while (!(S(n)<100&&S(n+1)>=100)){
        n++;
    }
    printf("%d\n",n);
    while (!(S(n)<1000&&S(n+1)>=1000)){
        n++;
    }
    printf("%d\n",n);
    while (!(S(n)<10000&&S(n+1)>=10000)){
        n++;
    }
    printf("%d\n",n);
    return 0;
}
