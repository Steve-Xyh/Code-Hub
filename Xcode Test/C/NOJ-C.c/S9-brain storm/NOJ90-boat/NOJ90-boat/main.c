//
//  main.c
//  NOJ90-boat
//
//  Created by Steve X on 2017/11/18.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void QuickSort(int A[],int s,int m)  //插入排序,A[s]开始m个元素,s为左边界
{
    int i=s,j=m,t;
    if(s>m)return;                   //只有一位时，停止
    while(i!=j){
        while(A[j]>=A[s]&&i<j){
            j--;
        }
        while(A[i]<=A[s]&&i<j){
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

int main(){
    int max,n,A[300],x;
    scanf("%d%d",&max,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    QuickSort(A,0,n-1);
    if(n==1)printf("1\n");
    else{
        if(A[0]+A[1]>max)printf("%d\n",n);
        else{
            x=n;
            int i,j;
            for(i=0;i<n;i++){
                for(j=n-1;j>=0;j--){
                    if(A[i]+A[j]<=max&&i<j){
                        x--;
                        n--;
                        break;
                    }
                }
            }
            printf("%d\n",x);
        }
    }
    return 0;
}
