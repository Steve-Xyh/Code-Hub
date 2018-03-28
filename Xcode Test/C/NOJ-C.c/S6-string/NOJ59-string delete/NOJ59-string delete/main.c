//
//  main.c
//  NOJ59-string delete
//
//  Created by Steve X on 2017/11/3.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void del(char A[],char c)
{
    for(int j=0;A[j]!='\0';j++){
        if(A[j]!=c)printf("%c",A[j]);
    }
    printf("\n");
}

int main()
{
    char A[100],c;
    gets(A);
    scanf("%c",&c);
    del(A,c);
    return 0;
}
