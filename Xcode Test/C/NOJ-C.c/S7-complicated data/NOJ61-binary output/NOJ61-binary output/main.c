//
//  main.c
//  NOJ61-binary output
//
//  Created by Steve X on 2017/11/4.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void binary(int n)
{
    char A[1000];
    int i=0;
    while(n/2!=0){
        A[i]=n%2;
        n=n/2;
        i++;
    }
    i--;
    printf("1");
    for(int j=i;j>=0;j--){
        printf("%d",A[j]);
    }
}

int main()
{
    
    int n;
    scanf("%d",&n);
    binary(n);
    printf("\n");
    return 0;
}
