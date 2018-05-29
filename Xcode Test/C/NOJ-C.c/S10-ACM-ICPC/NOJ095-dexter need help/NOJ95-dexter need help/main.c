//
//  main.c
//  NOJ95-dexter need help
//
//  Created by Steve X on 2017/12/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 100

int game(int n)                //递归
{
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;          //此条及下条可省略，为加快调用速度保留
    if(n==3)return 2;
    else return game(n/2)+1;   //将一串连续的自然数切割两半，+1步化为两段相同的数列，随后进行相同递归
    return 0;
}

int main()
{
    int A[N],m=0;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(A[i]==0)break;
        m++;
    }
    for(int i=0;i<m;i++){
        printf("%d\n",game(A[i]));
    }
    //printf("%d\n",game( ));
    return 0;
}
