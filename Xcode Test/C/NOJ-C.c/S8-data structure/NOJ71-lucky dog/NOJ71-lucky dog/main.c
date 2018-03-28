//
//  main.c
//  NOJ71-lucky dog
//
//  Created by Steve X on 2017/11/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void deletechar(int A[],int n)
{
    for(int i=n;i<50;i++){
        A[i]=A[i+1];
    }
}

int main()
{
    int j=0,B[51],N,X,A[20];
    scanf("%d%d",&N,&X);
    int n=N;
    for(int i=1;i<=N;i++){
        B[i]=i;
    }
    for(int i=0;i<20;i++){
        scanf("%d",&A[i]);
    }
    while(n>X){
        int a=0;
        for(int i=1;i*A[j]<=N;i++){
            deletechar(B,i*A[j]-a);
            a++;
            n--;
            if(n<=X)break;
        }
        N=n;
        j++;
    }
    for(int i=1;i<N;i++){
        printf("%d ",B[i]);
    }
    printf("%d\n",B[N]);
    return 0;
}
