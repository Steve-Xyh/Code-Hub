//
//  main.c
//  NOJ96-checksum algorithm
//
//  Created by Steve X on 2017/11/30.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define X 100
#define Y 256

int num(char c)
{
    int num=0;
    if('A'<=c&&c<='Z')num=c-'A'+1;
    return num;
}

int Quicksum(char str[])
{
    int sum=0;
    for(int i=0;i<strlen(str);i++){
        sum+=(i+1)*num(str[i]);
    }
    return sum;
}

int main()
{
    char A[X][Y];
    int sum[X],i;
    for(i=0;i<X;i++){
        gets(A[i]);
        if(strcmp(A[i],"#")==0)break;
        sum[i]=Quicksum(A[i]);
    }
    for(int j=0;j<i;j++){
        printf("%d\n",sum[j]);
    }
    return 0;
}
