//
//  main.c
//  NOJ82-factorial count
//
//  Created by Steve X on 2017/11/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int fractorial(int n)
{
    if(n==1)return 1;
    else return n*fractorial(n-1);
}

int main()
{
    int n,A[10];
    for(int i=0;i<10;i++){
        if(i==0)A[i]=0;
        else A[i]=fractorial(i);
    }
    scanf("%d",&n);
    
    if(n<=409113){
        int t=1,x=0;
        for(int i=1;i<9;i++){
            if(A[i]<=n&&A[i+1]>n)t=i;
            if(A[i+1]<n)t=i+1;
        }
        for(int i=t;i>0;i--){
            n-=A[i];
            if(n==0){
                printf("YES\n");
                x++;
                break;
            }
        }
        if(x==0)printf("NO\n");
    }
    
    else printf("NO\n");
    return 0;
}
