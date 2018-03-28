//
//  main.c
//  NOJ42-selection sort
//
//  Created by Steve X on 2017/10/29.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void InsertionSort(int A[],int n,int s,int m)  //插入排序,A[s]开始m个元素
{
    int k,t;
    int B[1000];
    for(int i=0;i<n;i++){
        B[i]=A[i];
    }
    
    for(int i=s+1;i<s+m;i++){
        t=B[i];
        k=i-1;
        while(t>B[k]){
            B[k+1]=B[k];
            k--;
            if(k<s)break;
        }
        B[k+1]=t;
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",B[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[1000],s,m;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d %d",&s,&m);
    InsertionSort(A,n,s,m);
    return 0;
}


/*void BubbleSort(int n,int A[1000],int s,int m)  //冒泡排序
 {
 int B[1000];
 for(int i=0;i<n;i++){
 B[i]=A[i];
 }
 for(int i=s;i<s+m;i++){
 for(int j=s;j<s+m-1;j++){
 if(B[j]<B[j+1]){
 int t=B[j];
 B[j]=B[j+1];
 B[j+1]=t;
 }
 }
 }
 for(int i=0;i<n;i++){
 printf("%d ",B[i]);
 }
 printf("\n");
 }*/

