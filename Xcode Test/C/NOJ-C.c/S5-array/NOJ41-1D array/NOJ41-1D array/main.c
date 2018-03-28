//
//  main.c
//  NOJ41-1D array
//
//  Created by Steve X on 2017/10/29.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n],B[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        B[i]=A[i];
    }
    //B[n]=A[n];
    for(int i=0;i<n;i++){
        if(i%2==1)printf("%d ",B[i]);
    }
    printf("\n");
    return 0;
}
