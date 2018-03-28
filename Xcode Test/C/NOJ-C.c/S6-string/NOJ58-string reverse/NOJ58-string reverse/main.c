//
//  main.c
//  NOJ58-string reverse
//
//  Created by Steve X on 2017/11/3.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int i;

void reverse(char A[])
{
    for(int j=i;j>=0;j--){
        printf("%c",A[j]);
    }
    printf("\n");
}

int main()
{
    char A[100];
    i=0;
    while((A[i++]=getchar())){
        if(A[i-1]=='=')break;
    }
    i=i-2;
    reverse(A);
    return 0;
}
