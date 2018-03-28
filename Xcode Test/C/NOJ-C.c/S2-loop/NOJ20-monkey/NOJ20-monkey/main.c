//
//  main.c
//  NOJ20-monkey
//
//  Created by Steve X on 2017/10/15.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int monkey(int n)
{
    int i;
    for (i=1;i<=5;i++){
        if ((n-1)%5==0)n=4.0/5.0*(n-1);
        else break;
    }
    if (i==6)return 1;
    else return 0;
}

int main()
{
    int n=6;
    while (monkey(n)==0){
        n++;
    }
    int a=0,b=n,sum=0;
    if (monkey(n)==1){
        for (int i=1;i<=5;i++){
            a=(b-1)/5.0;
            sum=sum+a+1;
            b=4.0*a;
        }
    }
    printf("%d %d\n",n,n-sum);
    return 0;
}
