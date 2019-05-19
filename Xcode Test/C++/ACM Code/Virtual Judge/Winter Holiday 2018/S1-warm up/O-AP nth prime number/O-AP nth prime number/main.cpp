//
//  main.cpp
//  O-AP nth prime number
//
//  Created by Steve X on 2018/1/1.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 1000000
int A[N],B[N];                             //函数中数组长度过长，故定义为全局变量

int main()
{
    int C[200],m;
    for(int i=0;i<N;i++)B[i]=1;            //数组初始化为1

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
    return 0;
}
