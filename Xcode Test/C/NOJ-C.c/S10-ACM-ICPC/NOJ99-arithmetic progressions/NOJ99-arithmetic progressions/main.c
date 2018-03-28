//
//  main.c
//  NOJ99-arithmetic progressions
//
//  Created by Steve X on 2017/12/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 1000000
int A[N],B[N];                             //函数中数组长度过长，故定义为全局变量

/*void mset(int A[],int x,int n)
{
    for(int i=0;i<n;i++){
        A[i]=x;
    }
}

void primelist(int A[])                  //埃氏筛法
{
    mset(A,1,N);
    A[0]=A[1]=0;
    for(int i=2;i<=N/i;i++){
        if(A[i]){
            for(int j=i*i;j<=N;j+=i){
                A[j]=0;
            }
        }
    }
}*/

int main()
{
    int C[200],m;
    //primelist(B);
    //mset(A,1,N);
    
    for(int i=0;i<N;i++){                  //数组初始化为1
        B[i]=1;
    }
    
    B[0]=B[1]=0;                           //埃氏筛法
    for(int i=2;i<=N/i;i++){
        if(B[i]){
            for(int j=i*i;j<=N;j+=i){
                B[j]=0;
            }
        }
    }
    
    for(m=0;;m++){
        int a,d,n,cnt=0;
        scanf("%d%d%d",&a,&d,&n);
        if(a==0&&d==0&&n==0)break;
        
        for(int i=0;i<N;i++){
            A[i]=a+i*d;                    //创建等差数列
            if(B[A[i]])cnt++;
            if(cnt==n){
                C[m]=A[i];                 //寻找第n个素数
                printf("%d\n",C[m]);
                break;
            }
        }
        
    }
    /*
    for(int i=0;i<m;i++){
        printf("%d\n",C[i]);
    }*/
    return 0;
}
