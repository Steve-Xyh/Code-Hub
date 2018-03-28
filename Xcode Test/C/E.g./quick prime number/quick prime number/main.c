//
//  main.c
//  quick prime number
//
//  Created by Steve X on 2017/12/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 1000000

void primelist(int B[])              //埃氏筛法
{
    int A[N],cnt=0;
    memset(A,1,sizeof(A));
    A[0]=A[1]=0;
    for(int i=2;i<=N/i;i++){
        if(A[i]){
            for(int j=i*i;j<=N;j+=i){
                A[j]=0;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(A[i])B[cnt++]=i;           //创建素数表
    }
}

int main()
{
    int B[N/10];
    primelist(B);
    for(int i=0;B[i]<N&&B[i]>B[i-1];i++){
        printf("No.%d--%d\n",i+1,B[i]);
    }
    
    return 0;
}
