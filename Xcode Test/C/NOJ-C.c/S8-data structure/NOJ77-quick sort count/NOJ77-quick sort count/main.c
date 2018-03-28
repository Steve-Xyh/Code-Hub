//
//  main.c
//  NOJ77-quick sort count
//
//  Created by Steve X on 2017/11/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int swap(int A[],int n)
{
    int s=0;
    int B[100];
    for(int i=0;i<n;i++){
        B[i]=A[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){   //冒泡排序
            if(A[j]>A[j+1]){
                int t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
                s++;
            }
        }
    }
    return s;
}

int main()
{
    int A[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("%d\n",swap(A,n));
    printf("\n");
    return 0;
}
