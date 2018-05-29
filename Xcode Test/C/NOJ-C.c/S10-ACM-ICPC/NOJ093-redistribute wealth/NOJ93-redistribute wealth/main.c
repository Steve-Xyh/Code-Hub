//
//  main.c
//  NOJ93-redistribute wealth
//
//  Created by Steve X on 2017/11/22.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1001

void distribute(int s[10][N],int j,int i,unsigned long num[],int n)
{
    if(s[j][i]>s[j][n]){
        s[j][i]--;
        s[j][n]++;
        num[j]++;
    }
    else if(s[j][i]<s[j][n]){
        s[j][n]--;
        s[j][i]++;
        num[j]++;
    }
}

int main()
{
    int n,s[10][N],sum[10],ave[10],j=0;
    unsigned long num[10];
    
    for(int i=0;i<10;i++){
        sum[i]=0;
        ave[i]=0;
        num[i]=0;
    }
    
    while(1){
        scanf("%d",&n);
        if(n<=0)break;
        sum[j]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&s[j][i]);
            sum[j]+=s[j][i];
        }
        ave[j]=sum[j]/n;
        
        for(int i=0;;i++){
            
            int x=0;
            for(int m=0;m<n;m++){
                if(s[j][m]!=ave[j])x++;
                if(x>0||x>=n){
                    break;
                }
            }
            if(x==0)break;
            if(s[j][i]==ave[j])continue;
            
                if(i==n)i=0;
                int left=i-1,right=i+1;
                if(i==0)left=n-1;
                if(i==n-1)right=0;
            //if(s[j][left]<=s[j][right]&&s[j][i]<s[j][left]&&s[j][i]!=ave[j]){
                distribute(s,j,i,num,left);
                distribute(s,j,i,num,right);
            //}
            /*
            else if(s[j][i]!=ave[j]){
                distribute(s,j,i,num,right);
                distribute(s,j,i,num,left);
            }*/
            
        }
        j++;
    }
    for(int i=0;i<j;i++){
        printf("%lu\n",num[i]);
    }
    return 0;
}
