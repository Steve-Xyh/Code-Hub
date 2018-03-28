//
//  main.cpp
//  A-Graveyard Design
//
//  Created by Steve X on 2018/2/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:n分解为连续平方和,尺取法,移动左右端点

#include <cstdio>
#include <cstring>
#include <cmath>
#define N 2000
long long n,sum=0;
int a[N],b[N],cnt=0;

void display(int a,int b)
{
    printf("%d",b-a+1);
    for(int i=a;i<=b;i++)printf(" %d",i);
    printf("\n");
}

void searchsum(long long n)
{
    long long i=1,j=1;
    while(j<=sqrtl(n)+1){
        while(sum<n&&j<=sqrtl(n)+1){
            sum+=j*j;
            j++;              //移动右端点
        }
        if(sum==n){
            a[cnt]=(int)i;
            b[cnt++]=(int)j-1;
        }
        sum-=i*i;
        i++;                  //移动左端点
    }
}

int main()
{
    while(~scanf("%lld",&n)){
        searchsum(n);
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)display(a[i],b[i]);
        sum=0;
        cnt=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}
