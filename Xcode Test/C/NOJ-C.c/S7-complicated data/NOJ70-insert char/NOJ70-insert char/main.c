//
//  main.c
//  NOJ70-insert char
//
//  Created by Steve X on 2017/11/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    char *p,A[80],x;
    int i;
    p=A;
    gets(A);
    scanf("%c%d",&x,&i);
    for(int j=0;j<i;j++){
        printf("%c",*(p+j));
    }
    printf("%c",x);
    printf("%s\n",p+i);
    return 0;
}
