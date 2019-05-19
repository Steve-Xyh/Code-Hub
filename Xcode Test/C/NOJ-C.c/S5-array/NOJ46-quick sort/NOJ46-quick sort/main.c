//
//  main.c
//  NOJ42-selection sort
//
//  Created by Steve X on 2017/10/29.
//  Copyright © 2017年 Steve X. All rights reserved.
//
//  快速排序
#include <stdio.h>

void QuickSort(int A[],int s,int m)  //插入排序,A[s]开始m个元素,s为左边界
{
    int i=s,j=m,t;
    if(s>m)return;                   //只有一位时，停止
    while(i!=j){
        while(A[j]<=A[s]&&i<j){
            j--;
        }
        while(A[i]>=A[s]&&i<j){
            i++;
        }
        if(i<j){
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
    t=A[s];                          //基准数归位
    A[s]=A[i];
    A[i]=t;
    
    QuickSort(A,s,i-1);              //递归调用
    QuickSort(A,i+1,m);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[100],s,m;
    
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d %d",&s,&m);
    //int r=s+m-1;
    QuickSort(A,s,m);
    
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    
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


