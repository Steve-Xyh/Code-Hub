//
//  main.c
//  NOJ43-swap sort
//
//  Created by Steve X on 2017/10/30.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int swap(int A[],int n)
{
    int s=0,k=0;
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
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){   //冒泡排序
            if(B[j]<B[j+1]){
                int t=B[j];
                B[j]=B[j+1];
                B[j+1]=t;
                k++;
            }
        }
    }
    if(s<k)return s;
    else return k;
}

int main()
{
    int A[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    /*int B[100];
     for(int i=0;i<n;i++){
        B[i]=A[i];
    }*/
    
    printf("%d\n",swap(A,n));
    /*for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
   
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){   //冒泡排序
            if(B[j]<B[j+1]){
                int t=B[j];
                B[j]=B[j+1];
                B[j+1]=t;
                k++;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",B[i]);
    }
    printf("\n%d\n",k);*/
    printf("\n");
    return 0;
}
