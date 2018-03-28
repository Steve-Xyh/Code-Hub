//
//  main.c
//  primary number2
//
//  Created by Steve X on 2017/10/2.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int primenumber(int n)
{
    int i=2;
    int x=abs(n);
    for(i=2;i<=x-1;i++){
        if(n%i==0)break;
    }
    if(x!=i)return 0;
    else return 1;
}

int main()
{
    for(;;){
    int a,X,Y;
    printf("Please input the domin,in the form of \"x,y\"\n\n");
    scanf("%d,%d",&X,&Y);
    if(X>Y){
        a=X;
        X=Y;
        Y=a;
    }
    int m=0;
    printf("\nThe prime numbers are as follows:\n\n");
    for(int n=X;n<=Y;n++){
        if(primenumber(n)==1){
            m++;
            printf("%d----No.%d\n",n,m);
        }
    }
    printf("\n区间内共有%d个素数\n\n",m);
    }
    return 0;
}
