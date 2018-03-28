//
//  main.c
//  NOJ42-selection sort
//
//  Created by Steve X on 2017/10/29.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void SelectionSort(int A[],int n,int s,int m)  //选择排序
{
    int k;
    int B[1000];
    for(int i=0;i<n;i++){
        B[i]=A[i];
    }
    for(int i=s;i<s+m-1;i++){
        k=i;
        for(int j=i+1;j<=s+m-1;j++){
            if(B[j]>B[k])k=j;
        }
        if(i!=k){
            int t=B[i];
            B[i]=B[k];
            B[k]=t;
        }
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
    SelectionSort(A,n,s,m);
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
