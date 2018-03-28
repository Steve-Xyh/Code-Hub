//
//  main.c
//  NOJ38-loop move
//
//  Created by Steve X on 2017/10/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int move(int value,int n)
{
    int a,b,x,s=32;
    if(n<0){
        n=abs(n);
        a=value>>(s-n);
        b=value<<n;
    }
    else{
        a=value<<(s-n);
        b=value>>n;
    }
    x=a|b;
    if(n==0)x=value;
    return x;
}

int main()
{
    int value,n;
    scanf("%d%d",&value,&n);
    printf("%d\n",move(value,n));
    //printf("%o\n",value);
    //printf("%d\n",value<<n);
    //printf("%lu\n",sizeof(int));
    return 0;
}
