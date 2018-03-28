//
//  main.c
//  NOJ44-array addition
//
//  Created by Steve X on 2017/10/30.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void add(int A[],int B[],int n)
{
    int C[100];
    for(int i=0;i<n;i++){
        C[i]=A[i]+B[i];
        printf("%d ",C[i]);
    }
}

int main()
{
    int A[100],B[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    add(A,B,n);
    printf("\n");
    return 0;
}
