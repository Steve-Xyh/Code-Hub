//
//  main.c
//  NOJ100-sum of consecutive
//
//  Created by Steve X on 2017/12/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 10000

int max(int a,int b)
{
    return a>b?a:b;
}

void primelist(int B[N])              //埃氏筛法
{
    int A[N],cnt=0;
    memset(A,1,sizeof(A));
    A[0]=A[1]=0;
    for(int i=2;i<N/i;i++){
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

int dpjudge(int a[],int n)
{
    if(n==0)return 0;
    int dp[N],cnt=0,j=0;              //dp[i]表示以第i个元素为结尾的连续素数和
    for(int i=j+1;i<=n&&j<=n;i++)
    {
        dp[j]=a[j];
        dp[i]=dp[i-1]+a[i];
        if(a[j]>n)break;
        if(dp[i]>=n||dp[j]>=n){
            if(dp[i]==n||dp[j]==n)cnt++;
            j++;
            i=j;
        }
    }
    return cnt;
}

int main()
{
    int A[N],B[100],cnt;
    primelist(A);
    for(cnt=0;cnt<100;cnt++){
        scanf("%d",&B[cnt]);
        if(B[cnt]==0)break;
        B[cnt]=dpjudge(A,B[cnt]);
    }
    for(int i=0;i<cnt;i++){
        printf("%d\n",B[i]);
    }
    return 0;
}
