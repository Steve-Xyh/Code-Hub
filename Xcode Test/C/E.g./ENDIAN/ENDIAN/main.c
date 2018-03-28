//
//  main.c
//  ENDIAN
//
//  Created by Steve X on 2017/11/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

typedef union endian
{
    char c;
    int num;
}ENDIAN;

int main()
{
    ENDIAN a;
    a.c=1;
    if(a.num==1)printf("little endian\n");
    else printf("big endian\n");
    printf("%d\n",a.num);
    return 0;
}
